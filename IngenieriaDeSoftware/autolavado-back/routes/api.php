<?php

use Illuminate\Http\Request;

/*
|--------------------------------------------------------------------------
| API Routes
|--------------------------------------------------------------------------
|
| Here is where you can register API routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| is assigned the "api" middleware group. Enjoy building your API!
|
*/

Route::group(['prefix' => 'v1'], function() {

    Route::middleware('auth:api')->get('/user', function (Request $request) {
        return $request->user();
    });

    Route::prefix('auth')->group(function () {
        Route::post('login', 'Auth\LoginController@login');
        Route::post('login-redes', 'Auth\LoginController@loginRedes');

        Route::post('signup', 'Auth\RegisterController@signup');
        Route::post('signup-redes', 'Auth\RegisterController@signupRedes');

        Route::post('password-create', 'Auth\ForgotPasswordController@create');
        Route::get('password/find/{token}', 'Auth\ForgotPasswordController@find');
        Route::post('password-reset', 'Auth\ForgotPasswordController@reset');

        Route::group(['middleware' => 'auth:api'], function() {
            Route::get('me', 'Auth\MeController@me');
            Route::post('logout', 'Auth\MeController@logout');
        });
    });

    Route::prefix('admin')->group(function () {
        Route::group(['middleware' => ['auth:api']], function () {
            //  Servicio para conseguir los paquetes del autolavado
            Route::prefix('paquetes')->group(function() {
                Route::get('', 'API\v1\Admin\PaqueteController@index');
                Route::get('/all', 'API\v1\Admin\PaqueteController@all');
                Route::get('/{id}', 'API\v1\Admin\PaqueteController@view');
                Route::post('', 'API\v1\Admin\PaqueteController@create');
                Route::post('/{id}', 'API\v1\Admin\PaqueteController@update');
                Route::delete('/{id}', 'API\v1\Admin\PaqueteController@delete');
            });

            Route::prefix('empleados')->group(function (){
                Route::get('', 'API\v1\Admin\EmpleadoController@index');
                Route::get('{id}', 'API\v1\Admin\EmpleadoController@view');
                Route::post('', 'API\v1\Admin\EmpleadoController@create');
                Route::post('{id}', 'API\v1\Admin\EmpleadoController@update');
                Route::delete('{id}', 'API\v1\Admin\EmpleadoController@delete');
            });

            Route::prefix('lavado')->group(function () {
                Route::get('', 'API\v1\Admin\LavadoController@index');
                Route::get('{id}', 'API\v1\Admin\LavadoController@view');
                Route::post('', 'API\v1\Admin\LavadoController@create');
                Route::post('{id}', 'API\v1\Admin\LavadoController@update');
                Route::delete('{id}', 'API\v1\Admin\LavadoController@delete');
            });

            Route::prefix('articulo')->group(function () {
                Route::get('', 'API\v1\Admin\ArticuloController@index');
                Route::get('{id}', 'API\v1\Admin\ArticuloController@view');
                Route::post('', 'API\v1\Admin\ArticuloController@create');
                Route::post('{id}', 'API\v1\Admin\ArticuloController@update');
                Route::delete('{id}', 'API\v1\Admin\ArticuloController@delete');
            });

            Route::prefix('compra')->group(function () {
                Route::get('', 'API\v1\Admin\CompraController@index');
                Route::get('{id}', 'API\v1\Admin\CompraController@view');
                Route::post('', 'API\v1\Admin\CompraController@create');
                Route::post('{id}', 'API\v1\Admin\CompraController@update');
                Route::delete('{id}', 'API\v1\Admin\CompraController@delete');
            });

            Route::prefix('pdf')->group(function () {
                Route::get('','API\v1\Admin\PDFController@index');
                Route::get('form', function () {
                    return view('form');
                });
                Route::get('/downloadPDF/{id}','API\v1\Admin\PDFController@downloadPDF');
                Route::post('','API\v1\Admin\PDFController@store');
            });

        });
    });

    Route::prefix('landing')->group(function () {
        Route::prefix('paquetes')->group(function() {
            Route::get('', 'API\v1\Landing\PaqueteController@index');
        });
    });
});
