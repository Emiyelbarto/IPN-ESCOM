<?php

namespace App\Http\Controllers\API\v1\Admin;

use Illuminate\Http\Request;
use App\Http\Requests\API\v1\CompraRequest;
use App\Http\Controllers\Controller;
use Illuminate\Support\Facades\Auth;
use Illuminate\Support\Facades\Log;
use App\Repositories\v1\Interfaces\Admin\CompraRepositoryInterface;

class CompraController extends Controller
{

    private $compraRepository;
    /**
     * Create a new controller instance.
     *
     * @return void
     */
    public function __construct(CompraRepositoryInterface $compraRepository)
    {
        $this->compraRepository = $compraRepository;
    }

    public function index(Request $request)
    {
        $page       = !empty($request->query('page')) ? $request->query('page') : 1;
        $limit      = !empty($request->query('limit')) ? $request->query('limit') : 10;
        return $this->compraRepository->index($page, $limit);
    }

    public function all()
    {
        return $this->compraRepository->all();
    }

    public function view($id, Request $request)
    {
        return $this->compraRepository->view($id);
    }

    public function create(CompraRequest $request)
    {
        $result = $this->compraRepository->create($request);

        if(!$result['error']) {
            return response()->json($result['data'], 201);
        } else {
            return response()->json($result, 500);
        }
    }

    public function update($id, CompraRequest $request)
    {
        if(!$id)
            return response()->json(['message' => 'error'], 500);

        $result = $this->compraRepository->update($id, $request);

        if(!$result['error']) {
            return response()->json($result['data'], 200);
        } else {
            return response()->json(['message' => 'error'], 500);
        }
    }

    public function delete($id, Request $request)
    {
        return $this->compraRepository->delete($id, $request);
    }

    public function getLatest(Request $request)
    {
        return $this->compraRepository->getLatest($request);
    }

}
