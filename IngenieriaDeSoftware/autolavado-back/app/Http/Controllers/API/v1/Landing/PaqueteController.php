<?php

namespace App\Http\Controllers\API\v1\Landing;

use Illuminate\Http\Request;
use App\Http\Controllers\Controller;
use App\Repositories\v1\Interfaces\Landing\PaqueteRepositoryInterface;

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
}
