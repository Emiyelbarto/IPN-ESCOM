
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <script type="text/javascript" src="js/jquery-1.4.2.min.js"></script>
        <script type="text/javascript" src="js/Login.js"></script>
        <link type="text/css" rel="stylesheet" href="css/css1.css" />
        <title>JSP Page</title>
    </head>
    
    <body>
        <div>
            <form method="post" action="Servlet_Usu" id="frmLogin">
                <div align="center"><img src="Imagen/log.jpg" width="178" height="178">
                </div>
                <table bgcolor="#F7D358" id="tablaLogin">
                    <tr>
                        <th>
                            <h1>Acceso de Clientes</h1>
                        </th>
                    </tr>
                    <tr>
                        <td>
                            <div align="center">
                              <input type="text" name="txtUsuario" placeholder="Ingrese usuario" id="txtUsuario" class="textBox">
                            </div>
                        </td>
                    </tr>
                    <tr>
                        <td>
                            <div align="center">
                              <input type="password" name="txtClave" placeholder="Ingrese contraseña" id="txtClave" class="textBox">
                            </div>
                        </td>
                    </tr>
                    <tr>
                        <td>
                            <div align="center">
                              <input type="button" name="btnIngresar" value="Ingresar" id="btnIngresar" >
                            </div>
                        </td>
                    </tr>
                    <tr>
                        <td class="centrarBoton">
                            <a href="RegistrarCliente.jsp" id="lnkRegistrarUsuario"><h4 align="center">Registrate aqui</h4></a>
                        </td>
                    </tr>
                </table>
                    <p align="center">
                      <input type="hidden" name="accion" value="login">
            </form>
        </div>
    </body>
</html>
