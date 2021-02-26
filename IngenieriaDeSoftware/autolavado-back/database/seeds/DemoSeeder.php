<?php

use Illuminate\Database\Seeder;
use Spatie\Permission\Models\Role;
use Spatie\Permission\Models\Permission;

class DemoSeeder extends Seeder
{

    /**
     * Run the database seeds.
     *
     * @return void
     */
    public function run()
    {

        $role = Role::create(['name' => 'Super Admin']);
        //$permission = Permission::create(['name' => 'full_access']);

        // Users
        $users = [
            ['name' => 'Admin', 'email' => 'admin@autolavado.io'],
        ];


        $i = 1;
        foreach($users as $user):
            $tblUser = \App\User::create([
                'name' => ucwords(str_replace('_', ' ', $user['name'])),
                'email' => $user['email'],
                'password' => bcrypt('autolavado')
            ]);

            if($i == 1) $tblUser->assignRole('Super Admin');
            // if($i >= 2 && $i <= 6) $tblUser->attachRole($roleVendedor);
            // if($i == 7) $tblUser->attachRole($roleUsuario);

            $usuario = [
                'idUser' => $tblUser->id,
                'nombre' => $user['name'],
            ];
            DB::table('usuarios')->insert($usuario);
            $i++;
        endforeach;
    }
}
