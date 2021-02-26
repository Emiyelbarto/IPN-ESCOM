<?php

namespace App\Models\Autolavado;

use Illuminate\Database\Eloquent\SoftDeletes;
use Illuminate\Database\Eloquent\Model;
use Illuminate\Support\Facades\Storage;

class Lavado extends Model
{

    protected $table = 'lavado';

    use SoftDeletes;

    public $appends = ['placas', 'fecha', 'hora_inicio', 'hora_fin', 'lote'];

    /**
     * Get the usuario associated with the faq.
     */
    public function usuario()
    {
        return $this->belongsTo('App\Models\Usuario', 'idUsuario');
    }

    public function supervisor()
    {
        return $this->belongsTo('App\Models\Supervisor', 'idSupervisor');
    }

    public function encargado()
    {
        return $this->belongsTo('App\Models\Encargado', 'idEncargado');
    }

    public function paquete()
    {
        return $this->belongsTo('App\Models\Paquete', 'idPaquete');
    }


    /**
     * The attributes that are mass assignable.
     *
     * @var array
     */
    protected $fillable = [
        'idUsuario',
        'idSupervisor',
        'idEncargado',
        'idPaquete',
        'placas',
        'fecha',
        'hora_inicio',
        'hora_fin',
        'lote'
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
