<?php

namespace App\Repositories\v1\Impl\Admin;

use Kreait\Firebase;
use Kreait\Firebase\Factory;
use Kreait\Firebase\ServiceAccount;
use App\Models\Autolavado\Compra;
use Illuminate\Support\Carbon;
use Illuminate\Support\Facades\Auth;
use Illuminate\Support\Facades\DB;
use Illuminate\Support\Facades\Log;
use Illuminate\Support\Facades\URL;

class CompraRepository implements \App\Repositories\v1\Interfaces\Admin\CompraRepositoryInterface
{
    public function index($page, $limit)
    {
        return Compra::paginate($limit, ['*'], 'page', $page);
    }

    public function view($id)
    {
        return Compra::find($id);
    }

    public function all()
    {
        return Compra::get();
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

            $result['data'] = Compra::create( $data );

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
            $Compra = Compra::find( $id );
            if(empty($Compra)) return $result;
            $Compra->fill($data);

            $Compra->save();
            $result['data'] = $Compra;

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

            $result = Compra::destroy( $id );

            DB::commit();

        } catch (Exception $e) {
            DB::rollBack();
        }

        return $result;
    }

}
