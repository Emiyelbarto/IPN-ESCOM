<?php

namespace App\Models\Autolavado;

use Illuminate\Database\Eloquent\SoftDeletes;
use Illuminate\Database\Eloquent\Model;
use Illuminate\Support\Facades\Storage;

class Empleado extends Model
{

    protected $table = 'empleados';

    use SoftDeletes;

    /**
     * Get the usuario associated with the Empleado.
     */
    public function usuario()
    {
        return $this->belongsTo('App\Models\Usuario', 'idUsuario');
    }

    /**
     * The attributes that are mass assignable.
     *
     * @var array
     */
    protected $fillable = [
        'idUsuario',
        'Nombre',
        'CURP',
        'fecha_nacimiento',
        'usuario',
        'password',
        'correo',
        'NFC_data'
    ];

    /**
     * The model's default values for attributes.
     *
     * @var array
     */
    protected $attributes = [
        'activo' => 1
    ];

}
