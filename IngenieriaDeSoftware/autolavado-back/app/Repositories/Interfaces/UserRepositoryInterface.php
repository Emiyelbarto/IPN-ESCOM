<?php
namespace App\Repositories\Interfaces;

interface UserRepositoryInterface
{
    /**
     * Get's all Users
     *
     */
    public function all();

    /**
     * Create a User
     *
     * @param App\User
     * @param mixed
     */
    public function create($user, $role);
}