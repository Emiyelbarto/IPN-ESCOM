<?php

namespace App\Repositories\v1\Impl\Usuario;

use App\Models\Usuario;
use Illuminate\Support\Facades\Auth;
use Illuminate\Support\Facades\DB;
use Illuminate\Support\Facades\Log;
use Illuminate\Support\Facades\Storage;
use Illuminate\Support\Facades\URL;

class ProfileRepository implements \App\Repositories\v1\Interfaces\Usuario\ProfileRepositoryInterface
{
    public function myprofile()
    {
        $user = Auth::user()->load(['usuario', 'roles'])->toArray();
        return $user;
    }

    public function updateProfile($request)
    {
        $result = [];
        $result['error'] = 1;
        try {
            DB::beginTransaction();
                
            $data = $request->all();
            $user = Auth::user();
            $usuario = $user->usuario;

            $avatar = null;
            if ($request->hasFile('avatar')) {
                $path = $request->avatar->store('images', ['disk' => 'public']);
                $avatar = URL::asset('storage/'.$path);
            }

            if(!empty($avatar))
                $data['avatar'] = $avatar;

            $usuario->fill($data);
            $usuario->save();

            if(!empty($data['password'])) {
                $user->password = bcrypt($data['password']);
                $user->save();
            }

            DB::commit();
            $result['error'] = 0;

        } catch (\Exception $e) {
            DB::rollBack();
        }

        return $result;
    }

    public function updatePassword($request)
    {
        $result = [];
        $result['error'] = 1;
        try {
            DB::beginTransaction();
                
            $data = $request->all();
            if(empty($data['password'])) return $result;
            
            $user = Auth::user();

            $user->password = bcrypt($data['password']);
            $user->passwordTemporal = 0;

            $user->save();

            DB::commit();
            $result['error'] = 0;

        } catch (\Exception $e) {
            DB::rollBack();
        }

        return $result;
    }

}
