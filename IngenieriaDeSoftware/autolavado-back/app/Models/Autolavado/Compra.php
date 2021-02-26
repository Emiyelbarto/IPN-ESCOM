<?php

namespace App\Models\Autolavado;

use Illuminate\Database\Eloquent\SoftDeletes;
use Illuminate\Database\Eloquent\Model;
use Illuminate\Support\Facades\Storage;

class Compra extends Model
{

    protected $table = 'compras';

    use SoftDeletes;

    public $appends = ['nombre', 'direccion', 'descripcion', 'cantidad'];

    /**
     * Get the usuario associated with the faq.
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
        'nombre',
        'direccion',
        'descripcion',
        'cantidad',
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
