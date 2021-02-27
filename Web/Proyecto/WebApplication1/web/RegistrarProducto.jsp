

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="Clase.*" %>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <script type="text/javascript" src="js/jquery-1.4.2.min.js"></script>
        <script type="text/javascript" src="js/RegistrarProd.js"></script>
        <link type="text/css" rel="stylesheet" href="css/css1.css" />
        <title>JSP Page</title>
    </head>
    
    <%
        String Codigo_P = ObtenerCodigo.CodigoProducto();
    %>
    
    <body onload="cargar()">
        <form name="frm" action="Servlet_Prod" method="post" id="frmRegistrarProd">
            <table id="tablaRegistrarProd">
                <tr>
                    <th colspan="2">
                        <h1><img src="Imagen/log.jpg" width="178" height="178"> </h1>
                        <h1>Registrar platillo</h1>
                    </th>
                </tr>
                <tr>
                    <td class="primeraColumna">
                        Codigo :
                    </td>
                    <td>
                        <dd> <input type="text" name="txtCodigo" value="<%=Codigo_P %>" readonly> </dd>
                    </td>
                </tr>
                <tr>
                    <td class="primeraColumna">
                        Clase platillo :
                    </td>
                    <td>
                        <dd> <input type="text" name="txtClase" id="txtClase" class="textBox"> </dd>
                    </td>
                </tr>
                <tr>
                    <td class="primeraColumna">
                        Tipo Platillo:
                    </td>
                    <td>
                        <dd> <input type="text" name="txtMarca" id="txtMarca" class="textBox"> </dd>
                    </td>
                </tr>
                <tr>
                    <td class="primeraColumna">
                        Descripcion :
                    </td>
                    <td>
                        <dd> <input type="text" name="txtDescripcion" id="txtDescripcion" class="textBox"> </dd>
                    </td>
                </tr>
                <tr>
                    <td class="primeraColumna">
                        Precio :
                    </td>
                    <td>
                        <dd> <input type="text" name="txtPrecio" id="txtPrecio" class="textBox"> </dd>
                    </td>
                </tr>
                <tr>
                    <td class="primeraColumna">
                        Imagen :
                    </td>
                    <td>
                        <dd> <input type="file" name="txtImagen" size="30" id="txtImagen" class="textBox"> </dd>
                    </td>
                </tr>
                <tr>
                    <td colspan="2" class="Botones">
                        <br>
                        <input type="button" name="btnCancelar" id="btnCancelar" class="button" value="Cancelar">
                        <input type="button" name="btnRegistrar" id="btnRegistrar" class="button" value="Registrar">
                    </td>
                </tr>
                <tr>
                    <td>
                        <br>
                    </td>
                </tr>
            </table>
                    <input type="hidden" name="accion" value="insertar">
        </form>
    </body>
</html>
