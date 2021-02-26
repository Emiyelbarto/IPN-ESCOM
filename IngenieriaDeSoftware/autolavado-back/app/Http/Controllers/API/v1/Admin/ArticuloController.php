<?php

namespace App\Http\Controllers\API\v1\Admin;

use Illuminate\Http\Request;
use App\Http\Requests\API\v1\ArticuloRequest;
use App\Http\Controllers\Controller;
use Illuminate\Support\Facades\Auth;
use Illuminate\Support\Facades\Log;
use App\Repositories\v1\Interfaces\Admin\ArticuloRepositoryInterface;

class ArticuloController extends Controller
{

    private $articuloRepository;
    /**
     * Create a new controller instance.
     *
     * @return void
     */
    public function __construct(ArticuloRepositoryInterface $articuloRepository)
    {
        $this->articuloRepository = $articuloRepository;
    }

    public function index(Request $request)
    {
        $page       = !empty($request->query('page')) ? $request->query('page') : 1;
        $limit      = !empty($request->query('limit')) ? $request->query('limit') : 10;
        return $this->articuloRepository->index($page, $limit);
    }

    public function all()
    {
        return $this->articuloRepository->all();
    }

    public function view($id, Request $request)
    {
        return $this->articuloRepository->view($id);
    }

    public function create(ArticuloRequest $request)
    {
        $result = $this->articuloRepository->create($request);

        if(!$result['error']) {
            return response()->json($result['data'], 201);
        } else {
            return response()->json($result, 500);
        }
    }

    public function update($id, ArticuloRequest $request)
    {
        if(!$id)
            return response()->json(['message' => 'error'], 500);

        $result = $this->articuloRepository->update($id, $request);

        if(!$result['error']) {
            return response()->json($result['data'], 200);
        } else {
            return response()->json(['message' => 'error'], 500);
        }
    }

    public function delete($id, Request $request)
    {
        return $this->articuloRepository->delete($id, $request);
    }

    public function getLatest(Request $request)
    {
        return $this->articuloRepository->getLatest($request);
    }

}
