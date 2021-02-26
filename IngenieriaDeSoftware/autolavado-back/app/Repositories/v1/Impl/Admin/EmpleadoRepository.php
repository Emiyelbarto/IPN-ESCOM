<?php

namespace App\Repositories\v1\Impl\Admin;

use Kreait\Firebase;
use Kreait\Firebase\Factory;
use Kreait\Firebase\ServiceAccount;
use App\Models\Autolavado\Empleado;
use Illuminate\Support\Carbon;
use Illuminate\Support\Facades\Auth;
use Illuminate\Support\Facades\DB;
use Illuminate\Support\Facades\Log;
use Illuminate\Support\Facades\URL;

class EmpleadoRepository implements \App\Repositories\v1\Interfaces\Admin\EmpleadoRepositoryInterface
{
    public function index($page, $limit)
    {
        return Empleado::paginate($limit, ['*'], 'page', $page);
    }

    public function view($id)
    {
        return Empleado::find($id);
    }

    public function all()
    {
        return Empleado::get();
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

            $result['data'] = Empleado::create( $data );

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
            $Empleado = Empleado::find( $id );
            if(empty($Empleado)) return $result;

            $Empleado->fill($data);

            $Empleado->save();
            $result['data'] = $Empleado;

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

            $result = Empleado::destroy( $id );

            DB::commit();

        } catch (Exception $e) {
            DB::rollBack();
        }

        return $result;
    }

}
