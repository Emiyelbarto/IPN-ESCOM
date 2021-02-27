
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="java.util.*" %>
<%@page import="Clase.*" %>

<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <script type="text/javascript" src="js/jquery-1.4.2.min.js"></script>
        <script type="text/javascript" src="js/ModificarProd.js"></script>
        <link type="text/css" rel="stylesheet" href="css/css1.css" />
        <title>JSP Page</title>
    </head>
    
    <%
        Producto p = Producto_DB.listarProductoPorCodigo(request.getParameter("codigoP"));
    %>
    
    <body onload="cargar()">
        <form name="frm" action="Servlet_Prod" method="post" id="frmModificarProd">
            <table id="tablaModificarProd">
                <tr>
                    <th colspan="2">
                        <h1><img src="Imagen/log.jpg" width="178" height="178"></h1>
                        <h1>Modificar platillo</h1>
                    </th>
                </tr>
                <tr>
                    <td colspan="2">
                        <input type="hidden" name="txtCodigo" value="<%=p.getCodigoP() %>">
                    </td>
                </tr>
                <tr>
                    <td class="primeraColumna">
                        Codigo platillo :
                    </td>
                    <td>
                        <dd> <%=p.getCodigoP() %> </dd>
                    </td>
                </tr>
                <tr>
                    <td class="primeraColumna">
                        Nombre CP :
                    </td>
                    <td>
                        <dd> <input type="text" name="txtNombreCP" id="txtNombreCP" value="<%=p.getClaseProducto() %>" size="30" maxlength="30"> </dd>
                    </td>
                </tr>
                <tr>
                    <td class="primeraColumna">
                        Nombre TP :
                    </td>
                    <td>
                        <dd> <input type="text" name="txtNombreMP" id="txtNombreMP" value="<%=p.getMarcaProducto() %>" size="30" maxlength="30"> </dd>
                    </td>
                </tr>
                <tr>
                    <td class="primeraColumna">
                        Descripcion platillo :
                    </td>
                    <td>
                        <dd> <input type="text" name="txtDescripcionP" id="txtDescripcionP" value="<%=p.getDescripcion() %>" size="30" maxlength="30"> </dd>
                    </td>
                </tr>
                <tr>
                    <td class="primeraColumna">
                        Precio platillo :
                    </td>
                    <td>
                        <dd> <input type="text" name="txtPrecioP" id="txtPrecioP" value="<%=p.getPrecioP() %>" size="30" maxlength="30"> </dd>
                    </td>
                </tr>
                <tr>
                    <td class="primeraColumna">
                        Imagen actual : 
                    </td>
                    <td>
                            <dd> <input type="radio" name="selected" value="SelectImagenActual" id="SelectImagenActual" checked="checked"> 
                            <input type="text" name="txtImagen" id="txtImagen" value="<%=p.getImagenP() %>" size="30" maxlength="30"> </dd>
                    </td>
                </tr>
                <tr>
                    <td class="primeraColumna">
                        Modificar imagen : 
                    </td>
                    <td>
                            <dd> <input type="radio" name="selected" value="SelectModificarImagen" id="SelectModificarImagen"> 
                            <input type="file" name="txtModificarImagen" id="txtModificarImagen" size="30"> </dd>
                    </td>
                </tr>
                <tr>
                    <td colspan="2" class="Botones">
                        <br>
                        <input type="button" name="btnCancelar" id="btnCancelar" class="button" value="Cancelar">
                        <input type="button" name="btnGuardar" id="btnGuardar" class="button" value="Guardar">
                    </td>
                </tr>
                <tr>
                    <td>
                        <br>
                    </td>
                </tr>
            </table>
                    <input type="hidden" name="accion" value="actualizar">
        </form>
    </body>
</html>
