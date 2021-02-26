<?php
namespace App\Repositories\v1\Interfaces\Admin;

interface LavadoRepositoryInterface
{
    /**
     * Get's Lavados
     *
     */
    public function index($page, $limit);

    /**
     * Get's Lavados
     *
     */
    public function all();

    /**
     * Get a Lavado
     *
     */
    public function view($id);

    /**
     * Create a Lavado
     *
     */
    public function create($request);

    /**
     * Edit a Lavado
     *
     */
    public function update($id, $request);

    /**
     * Delete a Lavado
     *
     */
    public function delete($id, $request);
}
