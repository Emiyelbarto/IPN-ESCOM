<?php

namespace App\Http\Controllers\API\v1\Admin;

use Illuminate\Http\Request;
use App\Http\Requests\API\v1\EmpleadoRequest;
use App\Http\Controllers\Controller;
use Illuminate\Support\Facades\Auth;
use Illuminate\Support\Facades\Log;
use App\Repositories\v1\Interfaces\Admin\EmpleadoRepositoryInterface;

class EmpleadoController extends Controller
{
    private $empleadoRepository;
    /**
     * Create a new controller instance.
     *
     * @return void
     */
    public function __construct(EmpleadoRepositoryInterface $empleadoRepository)
    {
        $this->empleadoRepository = $empleadoRepository;
    }

    public function index(Request $request)
    {
        $page       = !empty($request->query('page')) ? $request->query('page') : 1;
        $limit      = !empty($request->query('limit')) ? $request->query('limit') : 10;
        return $this->empleadoRepository->index($page, $limit);
    }

    public function all()
    {
        return $this->empleadoRepository->all();
    }

    public function view($id, Request $request)
    {
        return $this->empleadoRepository->view($id);
    }

    public function create(EmpleadoRequest $request)
    {
        $result = $this->empleadoRepository->create($request);

        if(!$result['error']) {
            return response()->json($result['data'], 201);
        } else {
            return response()->json($result, 500);
        }
    }

    public function update($id, EmpleadoRequest $request)
    {
        if(!$id)
            return response()->json(['message' => 'error'], 500);

        $result = $this->empleadoRepository->update($id, $request);

        if(!$result['error']) {
            return response()->json($result['data'], 200);
        } else {
            return response()->json(['message' => 'error'], 500);
        }
    }

    public function delete($id, Request $request)
    {
        return $this->empleadoRepository->delete($id, $request);
    }

    public function getLatest(Request $request)
    {
        return $this->empleadoRepository->getLatest($request);
    }

}
