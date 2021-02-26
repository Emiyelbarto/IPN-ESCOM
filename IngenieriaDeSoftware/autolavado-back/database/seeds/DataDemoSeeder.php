<?php

use Illuminate\Database\Seeder;

class DataDemoSeeder extends Seeder
{

    /**
     * Run the database seeds.
     *
     * @return void
     */
    public function run()
    {
        // Users
        $users = [
            ['name' => 'Admin', 'email' => 'admin@autolavado.io'],
        ];

        $roleAdmin = \App\Role::where('name', 'administrator')->first();
        // $roleVendedor = \App\Role::where('name', 'vendedor')->first();
        // $roleUsuario = \App\Role::where('name', 'usuario')->first();

        $i = 1;
        foreach($users as $user):
            $tblUser = \App\User::create([
                'name' => ucwords(str_replace('_', ' ', $user['name'])),
                'email' => $user['email'],
                'password' => bcrypt('autolavado')
            ]);

            if($i == 1) $tblUser->attachRole($roleAdmin);
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
