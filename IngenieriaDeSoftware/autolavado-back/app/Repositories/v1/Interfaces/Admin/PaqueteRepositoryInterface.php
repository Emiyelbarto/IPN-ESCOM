<?php
namespace App\Repositories\v1\Interfaces\Admin;

interface PaqueteRepositoryInterface
{
    /**
     * Get's Paquetes
     *
     */
    public function index($page, $limit);

    /**
     * Get's Paquetes
     *
     */
    public function all();

    /**
     * Get a Paquete
     *
     */
    public function view($id);

    /**
     * Create a Paquete
     *
     */
    public function create($request);

    /**
     * Edit a Paquete
     *
     */
    public function update($id, $request);

    /**
     * Delete a Paquete
     *
     */
    public function delete($id, $request);
}
