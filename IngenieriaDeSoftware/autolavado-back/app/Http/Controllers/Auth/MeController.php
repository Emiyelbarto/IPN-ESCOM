<?php

namespace App\Http\Controllers\Auth;

use App\Http\Controllers\Controller;
use Illuminate\Support\Facades\Auth;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\DB;
use App\Traits\UsermgmtTrait;
use Illuminate\Support\Facades\Log;

class MeController extends Controller
{
    use UsermgmtTrait;

    public $successStatus = 200;

    public function me() {
        $user = Auth::user();
        $user['scopes'] = $this->getTokenScopes();

        return response()->json(['user' => $user], $this->successStatus);
    }


    public function logout() {
        Auth::user()->token()->revoke();

        return response()->json(['message' => 'ok'], $this-> successStatus);
    }
}
