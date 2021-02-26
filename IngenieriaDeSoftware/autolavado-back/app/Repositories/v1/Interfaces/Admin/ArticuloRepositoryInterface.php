<?php
namespace App\Repositories\v1\Interfaces\Admin;

interface ArticuloRepositoryInterface
{
    /**
     * Get's Articulos
     *
     */
    public function index($page, $limit);

    /**
     * Get's Articulos
     *
     */
    public function all();

    /**
     * Get a Articulo
     *
     */
    public function view($id);

    /**
     * Create a Articulo
     *
     */
    public function create($request);

    /**
     * Edit a Articulo
     *
     */
    public function update($id, $request);

    /**
     * Delete a Articulo
     *
     */
    public function delete($id, $request);
}
