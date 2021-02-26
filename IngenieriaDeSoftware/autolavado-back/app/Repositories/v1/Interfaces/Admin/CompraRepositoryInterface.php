<?php
namespace App\Repositories\v1\Interfaces\Admin;

interface CompraRepositoryInterface
{
    /**
     * Get's Compras
     *
     */
    public function index($page, $limit);

    /**
     * Get's Compras
     *
     */
    public function all();

    /**
     * Get a Compra
     *
     */
    public function view($id);

    /**
     * Create a Compra
     *
     */
    public function create($request);

    /**
     * Edit a Compra
     *
     */
    public function update($id, $request);

    /**
     * Delete a Compra
     *
     */
    public function delete($id, $request);
}
