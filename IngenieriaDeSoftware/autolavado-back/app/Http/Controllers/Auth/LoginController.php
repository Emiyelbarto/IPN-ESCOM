<?php

namespace App\Http\Controllers\Auth;

use App\Http\Controllers\Controller;
use Illuminate\Foundation\Auth\AuthenticatesUsers;
use Illuminate\Support\Facades\Auth;
use App\Traits\UsermgmtTrait;
use Illuminate\Support\Facades\Log;

class LoginController extends Controller
{
    /*
    |--------------------------------------------------------------------------
    | Login Controller
    |--------------------------------------------------------------------------
    |
    | This controller handles authenticating users for the application and
    | redirecting them to your home screen. The controller uses a trait
    | to conveniently provide its functionality to your applications.
    |
    */

    use AuthenticatesUsers, UsermgmtTrait;

    /**
     * Where to redirect users after login.
     *
     * @var string
     */
    protected $redirectTo = '/home';

    /**
     * Create a new controller instance.
     *
     * @return void
     */
    public function __construct()
    {
        $this->middleware('guest')->except('logout');
    }

    /**
     * Override de Login en AuthenticatesUsers
     *
     * @return \Illuminate\Http\Response
     */
    public function login()
    {
        $credentials = ['email' => request('email'), 'password' => request('password')];

        if (Auth::attempt($credentials)) {
            $user = Auth::user();
            //dd($user);
            $scopes = $this->getTokenScopes();
            Log::channel('daily')->debug($scopes);

            $token = $user->createToken('AutolavadoCORE', $scopes)->accessToken;

            return response()->json(['token' => $token], 200);
        } else {
            $response['status'] = 'error';
            $response['message'] = 'User / password do not match.';

            return response()->json(['token' => $response], 401);
        }
    }
}
