<?php

namespace App\Models\Autolavado;

use Illuminate\Database\Eloquent\SoftDeletes;
use Illuminate\Database\Eloquent\Model;
use Illuminate\Support\Facades\Storage;

class Articulo extends Model
{

    protected $table = 'articulos';

    use SoftDeletes;

    public $appends = ['nombre', 'descripcion', 'precio', 'cantidad', 'foto'];

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
        'descripcion',
        'precio',
        'cantidad',
        'foto'
    ];

    public function getBannerUrlAttribute()
    {
        if(empty($this->foto)) return '';
        return Storage::disk('foto')->url($this->foto);
    }

    /**
     * The model's default values for attributes.
     *
     * @var array
     */
    protected $attributes = [
        'activo' => 1
    ];

}
