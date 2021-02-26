<?php

namespace App\Repositories\v1\Impl\Admin;

use Kreait\Firebase;
use Kreait\Firebase\Factory;
use Kreait\Firebase\ServiceAccount;
use App\Models\Autolavado\Articulo;
use Illuminate\Support\Carbon;
use Illuminate\Support\Facades\Auth;
use Illuminate\Support\Facades\DB;
use Illuminate\Support\Facades\Log;
use Illuminate\Support\Facades\URL;

class ArticuloRepository implements \App\Repositories\v1\Interfaces\Admin\ArticuloRepositoryInterface
{
    public function index($page, $limit)
    {
        return Articulo::paginate($limit, ['*'], 'page', $page);
    }

    public function view($id)
    {
        return Articulo::find($id);
    }

    public function all()
    {
        return Articulo::get();
    }

    public function create($request)
    {
        $result = [];
        $result['error'] = 1;
        try {
            DB::beginTransaction();

            $data = $request->all();
            $user = Auth::user();
            $data['idUsuario'] = $user->usuario->id;

            $path = "Articulos/banner";
            $file = $this->uploadFile($request->imagen, $path);
            if(!empty($file)) {
                $data['avatar'] = $file;
            }

            $result['data'] = Articulo::create( $data );

            DB::commit();
            $result['error'] = 0;

        } catch (\Exception $e) {
            DB::rollBack();
            Log::channel('daily')->debug($e);
        }

        return $result;
    }

    public function update($id, $request)
    {
        $result = [];
        $result['error'] = 1;
        try {
            DB::beginTransaction();

            $data = $request->all();
            $Articulo = Articulo::find( $id );
            //dd($package);
            if(empty($Articulo)) return $result;

            //dd($data);

            $Articulo->fill($data);

            $path = "Articulos/banner";
            $file = $this->uploadFile($request->imagen, $path);
            if(!empty($file)) {
                $data['avatar'] = $file;
            }

            $Articulo->save();
            $result['data'] = $Articulo;

            DB::commit();
            $result['error'] = 0;

        } catch (Exception $e) {
            DB::rollBack();
        }

        return $result;
    }

    public function delete($id, $request)
    {
        $result = null;
        try {
            DB::beginTransaction();

            $result = Articulo::destroy( $id );

            DB::commit();

        } catch (Exception $e) {
            DB::rollBack();
        }

        return $result;
    }

}
