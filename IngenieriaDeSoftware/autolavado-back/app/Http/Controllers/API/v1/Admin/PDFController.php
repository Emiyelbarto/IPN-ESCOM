<?php

namespace App\Http\Controllers\API\v1\Admin;

use Illuminate\Http\Request;
use App\Http\Requests\API\v1\PDFRequest;
use App\PDF;
use App\Http\Controllers\Controller;
use Illuminate\Support\Facades\Auth;
use Illuminate\Support\Facades\Log;
use App\Repositories\v1\Interfaces\Admin\PDFRepositoryInterface;

class PDFController extends Controller
{

    private $pdfRepository;
    /**
     * Create a new controller instance.
     *
     * @return void
     */
    public function __construct(PDFRepositoryInterface $pdfRepository)
    {
        $this->pdfRepository = $pdfRepository;
    }

    public function index(Request $request)
    {
        $page       = !empty($request->query('page')) ? $request->query('page') : 1;
        $limit      = !empty($request->query('limit')) ? $request->query('limit') : 10;
        return $this->pdfRepository->index($page, $limit);
    }

    public function store(PaqueteRequest $request)
    {
        $result = $this->pdfRepository->create($request);

        if(!$result['error']) {
            return response()->json($result['data'], 201);
        } else {
            return response()->json($result, 500);
        }
    }

    public function download($id)
    {
        return $this->pdfRepository->download($id);
    }

}
