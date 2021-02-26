<?php
namespace App\Repositories\v1\Interfaces\Admin;

interface EmpleadoRepositoryInterface
{
    /**
     * Get's Empleados
     *
     */
    public function index($page, $limit);

    /**
     * Get's Empleados
     *
     */
    public function all();

    /**
     * Get a Empleado
     *
     */
    public function view($id);

    /**
     * Create a Empleado
     *
     */
    public function create($request);

    /**
     * Edit a Empleado
     *
     */
    public function update($id, $request);

    /**
     * Delete a Empleado
     *
     */
    public function delete($id, $request);
}
