<?php

use Illuminate\Support\Facades\Schema;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class AutolavadoSetupTables extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        Schema::create('usuarios', function (Blueprint $table) {
            $table->bigIncrements('id');
            $table->unsignedBigInteger('idUser')->unique();
            $table->foreign('idUser')->references('id')->on('users');
            $table->string('nombre', 100);

            $table->string('avatar', 500)->nullable();
            $table->boolean('activo')->default(true);
            $table->timestamps();
            $table->softDeletes();
        });

        Schema::create('paises', function (Blueprint $table) {
            $table->bigIncrements('id');
            $table->string('nombre');
            $table->string('codigo');
            $table->boolean('activo')->default(true);
            $table->timestamps();
            $table->softDeletes();
        });
        Schema::create('estados', function (Blueprint $table) {
            $table->bigIncrements('id');
            $table->unsignedBigInteger('idPais')->nullable();
            $table->foreign('idPais')->references('id')->on('paises');
            $table->string('nombre');
            $table->string('codigo', 2);
            $table->string('nombreCorto', 20);
            $table->boolean('activo')->default(true);
            $table->timestamps();
            $table->softDeletes();
        });
        Schema::create('monedas', function (Blueprint $table) {
            $table->bigIncrements('id');
            $table->string('nombre', 100);
            $table->string('codigo', 10);
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
        Schema::dropIfExists('usuarios');
        Schema::dropIfExists('estados');
        Schema::dropIfExists('paises');
        Schema::dropIfExists('monedas');
    }
}
