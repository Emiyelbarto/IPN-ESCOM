<?php
namespace App\Repositories\v1\Interfaces\Admin;

interface PDFRepositoryInterface
{
    /**
     * Get's PDFs
     *
     */
    public function index($page, $limit);

    public function store($request);

    public function download($id);
}
