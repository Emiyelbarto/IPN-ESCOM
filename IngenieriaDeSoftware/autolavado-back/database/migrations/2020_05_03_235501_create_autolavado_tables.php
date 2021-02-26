<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

class CreateAutolavadoTables extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        Schema::create('paquetes', function (Blueprint $table) {
            $table->bigIncrements('id');
            $table->unsignedBigInteger('idUsuario');
            $table->foreign('idUsuario')->references('id')->on('usuarios');
            $table->string('titulo', 500);
            $table->text('contenido');
            $table->string('banner', 500)->nullable();
            $table->boolean('activo')->default(true);
            $table->timestamps();
            $table->softDeletes();
        });

        Schema::create('empleados', function (Blueprint $table) {
            $table->bigIncrements('id');
            $table->unsignedBigInteger('idUsuario');
            $table->foreign('idUsuario')->references('id')->on('usuarios');
            $table->string('nombre', 500);
            $table->string('CURP', 18);
            $table->date('fecha_nacimiento');
            $table->string('usuario', 50);
            $table->string('password', 50);
            $table->string('correo', 500);
            $table->text('NFC_data');
            $table->boolean('activo')->default(true);
            $table->timestamps();
            $table->softDeletes();
        });

        Schema::create('articulos', function (Blueprint $table) {
            $table->bigIncrements('id');
            $table->unsignedBigInteger('idUsuario');
            $table->foreign('idUsuario')->references('id')->on('usuarios');
            $table->string('nombre', 500);
            $table->text('descripcion');
            $table->float('precio', 8, 2);
            $table->decimal('cantidad');
            $table->string('foto', 500);
            $table->boolean('activo')->default(true);
            $table->timestamps();
            $table->softDeletes();
        });

        Schema::create('compras', function (Blueprint $table) {
            $table->bigIncrements('id');
            $table->unsignedBigInteger('idUsuario');
            $table->foreign('idUsuario')->references('id')->on('usuarios');
            $table->string('nombre', 500);
            $table->string('direccion', 500);
            $table->text('descripcion');
            $table->float('cantidad', 8, 2);
            $table->boolean('activo')->default(true);
            $table->timestamps();
            $table->softDeletes();
        });

        Schema::create('lavado', function (Blueprint $table) {
            $table->bigIncrements('id');
            $table->unsignedBigInteger('idUsuario');
            $table->foreign('idUsuario')->references('id')->on('usuarios');
            // $table->unsignedBigInteger('idSupervisor');
            // $table->foreign('idSupervisor')->references('id')->on('supervisor');
            // $table->unsignedBigInteger('idEncargado');
            // $table->foreign('idEncargado')->references('id')->on('encargado');
            $table->unsignedBigInteger('idPaquete');
            $table->foreign('idPaquete')->references('id')->on('paquetes');
        // 'idSupervisor',
        // 'idEncargado',
        // 'placas',
        // 'fecha',
        // 'hora_inicio',
        // 'hora_fin',
        // 'lote'
            $table->string('placas', 500);
            $table->date('fecha', 500);
            $table->dateTime('hora_inicio');
            $table->dateTime('hora_fin');
            $table->decimal('lote');
            $table->boolean('activo')->default(true);
            $table->timestamps();
            $table->softDeletes();
        });

    }

    /**
     * Reverse the migrations.
     *
     * @return void
     */
    public function down()
    {
        Schema::dropIfExists('paquetes');
    }
}
