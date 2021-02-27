<%-- 
    Document   : MiPerfil
    Created on : 13-dic-2016, 22:22:04
    Author     : Manuel
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="Clase.*"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <script type="text/javascript" src="js/jquery-1.4.2.min.js"></script>
        <script type="text/javascript" src="js/MiPerfil.js"></script>
        <link type="text/css" rel="stylesheet" href="css/css1.css" />
        <title>JSP Page</title>
    </head>
    
    <%
        Usuario usu = Usuario_DB.listarUsuarioPorCodigo(request.getParameter("codigoU"));
    %>
    
    <body>
        <form action="Servlet_Usu" method="post" id="frmModificarUsuario">
            <p align="center"><img src="Imagen/log.jpg" width="178" height="178"></p>
            <table bgcolor="#CCCCCC" id="tablaModificarUsuario">
                <tr>
                    <th colspan="3">
                        <h1>Perfil de Cliente</h1>
                    </th>
                </tr>
                <tr>
                    <td colspan="3">
                        <input type="hidden" name="txtCodigo" value="<%=usu.getCodigoUsuario() %>"> 
                    </td>
                </tr>
                <tr>
                    <td class="primeraColumna">
                        Nombre : 
                    </td>
                    <td>
                        <dd class="soloTexto"> <%=usu.getNombreUsuario() %> </dd>
                        <dd> <input type="text" name="txtNombre" id="txtNombre" class="campoOculto" value="<%=usu.getNombreUsuario() %>" size="30" maxlength="50"> </dd>
                        
                    </td>
                    <td></td>
                </tr>
                <tr>
                    <td class="primeraColumna">
                        Apellidos : 
                    </td>
                    <td>
                        <dd class="soloTexto"> <%=usu.getApellidosUsuario()%> </dd>
                        <dd> <input type="text" name="txtApellidos" id="txtApellido" class="campoOculto" value="<%=usu.getApellidosUsuario() %>" size="30" maxlength="50"> </dd>
                    </td>
                    <td></td>
                </tr>
                <tr>
                    <td class="primeraColumna">
                        Edad :
                    </td>
                    <td>
                        <dd class="soloTexto"> <%=usu.getDniUsuario()%> </dd>
                        <dd> <input type="text" name="txtDni" id="txtDni" class="campoOculto" value="<%=usu.getDniUsuario() %>" size="30" maxlength="8"> </dd>
                    </td>
                    <td></td>
                </tr>
                <tr>
                    <td class="primeraColumna">
                        Email :
                    </td>
                    <td>
                        <dd> <%=usu.getEmailUsuario()%> </dd>
                    </td>
                    <td>
                        <dd> <a href="ModificarEmail.jsp?codigoU=<%=usu.getCodigoUsuario() %>" class="Enlace">Cambiar email</a> </dd>
                    </td>
                </tr>
                <tr>
                    <td class="primeraColumna">
                        Contraseña :
                    </td>
                    <td>
                        <dd> ********** </dd>
                    </td>
                    <td>
                        <dd> <a href="ModificarContraseña.jsp?codigoU=<%=usu.getCodigoUsuario() %>" class="Enlace">Cambiar contraseña</a> </dd>
                    </td>
                </tr>
                <tr>
                    <td class="primeraColumna">
                        Casado/Soltero:
                    </td>
                    <td>
                        <dd class="soloTexto"> <%=usu.getDepartamentoUsuario()%> </dd>
                        <dd> <input type="text" name="txtDepartamento" id="txtDepartamento" class="campoOculto" value="<%=usu.getDepartamentoUsuario() %>" size="30" maxlength="20"> </dd>
                    </td>
                    <td></td>
                </tr>
                <tr>
                    <td class="primeraColumna">
                        Pais :
                    </td>
                    <td>
                        <dd class="soloTexto"> <%=usu.getProvinciaUsuario()%> </dd>
                        <dd> <input type="text" name="txtProvincia" id="txtProvincia" class="campoOculto" value="<%=usu.getProvinciaUsuario() %>" size="30" maxlength="20"> </dd>
                    </td>
                    <td></td>
                </tr>
                <tr>
                    <td class="primeraColumna">
                        Estado :
                    </td>
                    <td>
                        <dd class="soloTexto"> <%=usu.getDistritoUsuario()%> </dd>
                        <dd> <input type="text" name="txtDistrito" id="txtDistrito" class="campoOculto" value="<%=usu.getDistritoUsuario() %>" size="30" maxlength="20"> </dd>
                    </td>
                    <td></td>
                </tr>
                <tr>
                    <td class="primeraColumna">
                        Direccion 1 :
                    </td>
                    <td>
                        <dd class="soloTexto"> <%=usu.getDireccion1Usuario()%> </dd>
                        <dd> <input type="text" name="txtDireccion1" id="txtDireccion1" class="campoOculto" value="<%=usu.getDireccion1Usuario() %>" size="30" maxlength="50"> </dd>
                    </td>
                    <td></td>
                </tr>
                <tr>
                    <td class="primeraColumna">
                        Direccion 2 :
                    </td>
                    <td>
                        <dd class="soloTexto"> <%=usu.getDireccion2Usuario()%> </dd>
                        <dd> <input type="text" name="txtDireccion2" id="txtDireccion2" class="campoOculto" value="<%=usu.getDireccion2Usuario() %>" size="30" maxlength="50"> </dd>
                    </td>
                    <td></td>
                </tr>
                <tr>
                    <td class="primeraColumna">
                        Telefono :
                    </td>
                    <td>
                        <dd class="soloTexto"> <%=usu.getTelefonoUsuario()%> </dd>
                        <dd> <input type="text" name="txtTelefono" id="txtTelefono" class="campoOculto" value="<%=usu.getTelefonoUsuario() %>" size="30" maxlength="9"> </dd>
                    </td>
                    <td></td>
                </tr>
                <tr>
                    
                </tr>
                <tr>
                    <td colspan="3" class="Botones">
                        <br>
                        <input type="button" name="btnCancelar" id="btnCancelar" class="button" value="Cancelar">
                        <input type="button" name="btnModificar" id="btnModificar" class="button" value="Modificar">
                        <input type="button" name="btnGuardar" id="btnGuardar" class="campoOculto" value="Guardar">
                    </td>
                </tr>
                <tr>
                    <td>
                        <br>
                    </td>
                </tr>
            </table>
                    <input type="hidden" name="accion" value="modificarUsuario">
        </form>
    </body>
</html>
