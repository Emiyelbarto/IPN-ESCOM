<?php

namespace App\Repositories\v1\Impl\Landing;

use App\Models\Autolavado\Paquete;

class PaqueteRepository implements \App\Repositories\v1\Interfaces\Landing\PaqueteRepositoryInterface
{
    public function index($page, $limit)
    {
        return Paquete::paginate($limit, ['*'], 'page', $page);
    }
}
