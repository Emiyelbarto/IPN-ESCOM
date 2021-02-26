<?php

namespace App\Repositories\Impl;

use App\User;
use App\Models\Usuario;
use Illuminate\Support\Facades\Log;

class UserRepository implements \App\Repositories\Interfaces\UserRepositoryInterface
{

    /**
     * Get's all users.
     *
     * @return mixed
     */
    public function all()
    {
        return User::all();
    }

    /**
     * Add a user.
     *
     * @param App\User
     * @param mixed $role
     * 
     * @return 
     */
    public function create($data, $role)
    {
        Log::channel('daily')->debug($data);
        $user = User::create($data);
        $user->attachRole($role);

        if($role == 'proveedor' && empty($data['idProveedor'])) {
            abort(400, 'Usuario sin proveedor');
        }

        Usuario::updateOrCreate(
            ['idUser' => $user->id],
            [
                'nombre' => $user->name, 
                'idUser' => $user->id,
                'idProveedor' => $data['idProveedor'],
            ]
        );

        return $user;
    }

}