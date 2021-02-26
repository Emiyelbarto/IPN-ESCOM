<?php
namespace App\Repositories\v1\Interfaces\Landing;

interface PaqueteRepositoryInterface
{
    /**
     * Get's Paquetes
     *
     */
    public function index($page, $limit);
}
