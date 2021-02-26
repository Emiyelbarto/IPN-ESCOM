<?php

namespace App\Http\Controllers\API\v1\Admin;

use Illuminate\Http\Request;
use App\Http\Requests\API\v1\LavadoRequest;
use App\Http\Controllers\Controller;
use Illuminate\Support\Facades\Auth;
use Illuminate\Support\Facades\Log;
use App\Repositories\v1\Interfaces\Admin\LavadoRepositoryInterface;

class LavadoController extends Controller
{

    private $lavadoRepository;
    /**
     * Create a new controller instance.
     *
     * @return void
     */
    public function __construct(LavadoRepositoryInterface $lavadoRepository)
    {
        $this->lavadoRepository = $lavadoRepository;
    }

    public function index(Request $request)
    {
        $page       = !empty($request->query('page')) ? $request->query('page') : 1;
        $limit      = !empty($request->query('limit')) ? $request->query('limit') : 10;
        return $this->lavadoRepository->index($page, $limit);
    }

    public function all()
    {
        return $this->lavadoRepository->all();
    }

    public function view($id, Request $request)
    {
        return $this->lavadoRepository->view($id);
    }

    public function create(LavadoRequest $request)
    {
        $result = $this->lavadoRepository->create($request);

        if(!$result['error']) {
            return response()->json($result['data'], 201);
        } else {
            return response()->json($result, 500);
        }
    }

    public function update($id, LavadoRequest $request)
    {
        if(!$id)
            return response()->json(['message' => 'error'], 500);

        $result = $this->lavadoRepository->update($id, $request);

        if(!$result['error']) {
            return response()->json($result['data'], 200);
        } else {
            return response()->json(['message' => 'error'], 500);
        }
    }

    public function delete($id, Request $request)
    {
        return $this->lavadoRepository->delete($id, $request);
    }

    public function getLatest(Request $request)
    {
        return $this->lavadoRepository->getLatest($request);
    }

}
