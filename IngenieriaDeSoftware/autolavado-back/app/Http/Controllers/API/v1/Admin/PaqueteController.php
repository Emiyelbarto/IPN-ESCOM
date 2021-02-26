<?php

namespace App\Http\Controllers\API\v1\Admin;

use Illuminate\Http\Request;
use App\Http\Requests\API\v1\PaqueteRequest;
use App\Http\Controllers\Controller;
use Illuminate\Support\Facades\Auth;
use Illuminate\Support\Facades\Log;
use App\Repositories\v1\Interfaces\Admin\PaqueteRepositoryInterface;

class PaqueteController extends Controller
{

    private $paqueteRepository;
    /**
     * Create a new controller instance.
     *
     * @return void
     */
    public function __construct(PaqueteRepositoryInterface $paqueteRepository)
    {
        $this->paqueteRepository = $paqueteRepository;
    }

    public function index(Request $request)
    {
        $page       = !empty($request->query('page')) ? $request->query('page') : 1;
        $limit      = !empty($request->query('limit')) ? $request->query('limit') : 10;
        return $this->paqueteRepository->index($page, $limit);
    }

    public function all()
    {
        return $this->paqueteRepository->all();
    }

    public function view($id, Request $request)
    {
        return $this->paqueteRepository->view($id);
    }

    public function create(PaqueteRequest $request)
    {
        $result = $this->paqueteRepository->create($request);

        if(!$result['error']) {
            return response()->json($result['data'], 201);
        } else {
            return response()->json($result, 500);
        }
    }

    public function update($id, PaqueteRequest $request)
    {
        if(!$id)
            return response()->json(['message' => 'error'], 500);

        $result = $this->paqueteRepository->update($id, $request);

        if(!$result['error']) {
            return response()->json($result['data'], 200);
        } else {
            return response()->json(['message' => 'error'], 500);
        }
    }

    public function delete($id, Request $request)
    {
        return $this->paqueteRepository->delete($id, $request);
    }

    public function getLatest(Request $request)
    {
        return $this->paqueteRepository->getLatest($request);
    }

}
