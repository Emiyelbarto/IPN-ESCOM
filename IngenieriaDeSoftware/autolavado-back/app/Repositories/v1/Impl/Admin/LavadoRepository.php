<?php

namespace App\Repositories\v1\Impl\Admin;

use Kreait\Firebase;
use Kreait\Firebase\Factory;
use Kreait\Firebase\ServiceAccount;
use App\Models\Autolavado\Lavado;
use Illuminate\Support\Carbon;
use Illuminate\Support\Facades\Auth;
use Illuminate\Support\Facades\DB;
use Illuminate\Support\Facades\Log;
use Illuminate\Support\Facades\URL;

class LavadoRepository implements \App\Repositories\v1\Interfaces\Admin\LavadoRepositoryInterface
{
    public function index($page, $limit)
    {
        return Lavado::paginate($limit, ['*'], 'page', $page);
    }

    public function view($id)
    {
        return Lavado::find($id);
    }

    public function all()
    {
        return Lavado::get();
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

            $result['data'] = Lavado::create( $data );

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
            $Lavado = Lavado::find( $id );
            if(empty($Lavado)) return $result;

            $Lavado->fill($data);

            $Lavado->save();
            $result['data'] = $Lavado;

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

            $result = Lavado::destroy( $id );

            DB::commit();

        } catch (Exception $e) {
            DB::rollBack();
        }

        return $result;
    }

}
