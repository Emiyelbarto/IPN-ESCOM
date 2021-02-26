<?php

namespace App\Repositories\v1\Impl\Admin;

use Kreait\Firebase;
use Kreait\Firebase\Factory;
use Kreait\Firebase\ServiceAccount;
use App\Models\Autolavado\Paquete;
use Illuminate\Support\Carbon;
use Illuminate\Support\Facades\Auth;
use Illuminate\Support\Facades\DB;
use Illuminate\Support\Facades\Log;
use Illuminate\Support\Facades\URL;

class PaqueteRepository implements \App\Repositories\v1\Interfaces\Admin\PaqueteRepositoryInterface
{
    public function index($page, $limit)
    {
        return Paquete::paginate($limit, ['*'], 'page', $page);
    }

    public function view($id)
    {
        return Paquete::find($id);
    }

    public function all()
    {
        return Paquete::get();
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


            // $path = "Paquetes/banner";
            // $file = $this->uploadFile($request->foto, $path);
            // if(!empty($file)) {
            //     $data->foto = $file;
            // }

            $result['data'] = Paquete::create( $data );

            DB::commit();
            $result['error'] = 0;

        } catch (\Exception $e) {
            DB::rollBack();
            Log::channel('daily')->debug($e);
            dd($e);
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
            $Paquete = Paquete::find( $id );
            //dd($package);
            if(empty($Paquete)) return $result;

            //dd($data);

            $Paquete->fill($data);

            $path = "Paquetes/banner";
            $file = $this->uploadFile($request->imagen, $path);
            if(!empty($file)) {
                $data['avatar'] = $file;
            }

            $Paquete->save();
            $result['data'] = $Paquete;

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

            $result = Paquete::destroy( $id );

            DB::commit();

        } catch (Exception $e) {
            DB::rollBack();
        }

        return $result;
    }

}
