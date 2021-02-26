<?php

namespace App\Traits;

use Illuminate\Support\Facades\Storage;
use Illuminate\Support\Facades\Log;
use Illuminate\Support\Facades\Auth;
use Illuminate\Support\Facades\Input;

trait UsermgmtTrait
{

    public function getTokenScopes()
    {
        $scopes = ['user-guest'];
        // Log::channel('daily')->debug('getTokenScopes init');

        $user = Auth::user();

        if(empty($user)) return $scopes;

        array_push($scopes, "user-logged");

        if( $user->hasRole('Super Admin') ) return $scopes;

        if( $user->hasRole('Admin') ) {
            array_push($scopes, "admin-full");
            return $scopes;
        }

        return $scopes;
    }
}