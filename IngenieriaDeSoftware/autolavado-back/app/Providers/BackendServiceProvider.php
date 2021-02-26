<?php

namespace App\Providers;

use Illuminate\Support\ServiceProvider;

class BackendServiceProvider extends ServiceProvider
{
    /**
     * Register services.
     *
     * @return void
     */
    public function register()
    {
        $this->app->bind(
            'App\Repositories\v1\Interfaces\Admin\PaqueteRepositoryInterface',
            'App\Repositories\v1\Impl\Admin\PaqueteRepository'
        );
        $this->app->bind(
            'App\Repositories\v1\Interfaces\Admin\EmpleadoRepositoryInterface',
            'App\Repositories\v1\Impl\Admin\EmpleadoRepository'
        );
        $this->app->bind(
            'App\Repositories\v1\Interfaces\Admin\ArticuloRepositoryInterface',
            'App\Repositories\v1\Impl\Admin\ArticuloRepository'
        );
        $this->app->bind(
            'App\Repositories\v1\Interfaces\Admin\CompraRepositoryInterface',
            'App\Repositories\v1\Impl\Admin\CompraRepository'
        );
        $this->app->bind(
            'App\Repositories\v1\Interfaces\Admin\LavadoRepositoryInterface',
            'App\Repositories\v1\Impl\Admin\LavadoRepository'
        );
        $this->app->bind(
            'App\Repositories\Interfaces\UserRepositoryInterface',
            'App\Repositories\Impl\UserRepository'
        );
        // Conectar Controller de Paquetes Landing
        $this->app->bind(
            'App\Repositories\v1\Interfaces\Landing\PaqueteRepositoryInterface',
            'App\Repositories\v1\Impl\Landing\PaqueteRepository'
        );
        // Conectar Controller de PDF
        $this->app->bind(
            'App\Repositories\v1\Interfaces\Admin\PDFRepositoryInterface',
            'App\Repositories\v1\Impl\Admin\PDFRepository'
        );
    }
}
