<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title></title>
  </head>
  <body>
    <table class="table table-bordered">
      <tr>
        <td>
          {{$user->full_name}}
        </td>
        <td>
          {{$user->street_address}}
        </td>
      </tr>
      <tr>
        <td>
          {{$user->city}}
        </td>
        <td>
          {{$user->zip_code}}
        </td>
      </tr>
    </table>
  </body>
</html>
