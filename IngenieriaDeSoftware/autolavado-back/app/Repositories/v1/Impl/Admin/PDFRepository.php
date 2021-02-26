<?php

namespace App\Repositories\v1\Impl\Admin;

use Kreait\Firebase;
use Kreait\Firebase\Factory;
use Kreait\Firebase\ServiceAccount;
use App\Models\Autolavado\PDF;
use Illuminate\Support\Carbon;
use Illuminate\Support\Facades\Auth;
use Illuminate\Support\Facades\DB;
use Illuminate\Support\Facades\Log;
use Illuminate\Support\Facades\URL;

class PDFRepository implements \App\Repositories\v1\Interfaces\Admin\PDFRepositoryInterface
{
    public function index($page, $limit)
    {
        return PDF::paginate($limit, ['*'], 'page', $page);
    }

    public function store($request){

      $user = new PDF([
        'full_name' => $request->get('full_name'),
        'street_address' => $request->get('street_address'),
        'city' => $request->get('city'),
        'zip_code' => $request->get('zip_code')
      ]);

      $user->save();
      return redirect('/index');
    }

    public function download($id){
      $user = UserDetail::find($id);

      $pdf = PDF::loadView('pdf', compact('user'));
      return $pdf->download('invoice.pdf');

    }
}
