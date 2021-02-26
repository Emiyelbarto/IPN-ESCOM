<?php

namespace App\Models\Autolavado;

use Illuminate\Database\Eloquent\Model;

class PDF extends Model
{
    protected $fillable = ['full_name','street_address','zip_code','city'];
}
