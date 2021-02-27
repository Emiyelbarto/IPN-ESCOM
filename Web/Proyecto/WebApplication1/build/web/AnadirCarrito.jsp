

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="java.util.*" %>
<%@page import="Clase.*" %>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <script type="text/javascript" src="js/jquery-1.4.2.min.js"></script>
        <script type="text/javascript" src="js/RegistrarCliente.js"></script>
        <link type="text/css" rel="stylesheet" href="css/css1.css" />
        <title>JSP Page</title>
        
    </head>
    <%
        String cliente = request.getParameter("cliente");
        Producto p = Producto_DB.listarProductoPorCodigo(request.getParameter("codigoP"));
    %>
    
    <body>
        <form name="frm" action="Servlet_Prod" method="post" id="frmAnadirCarrito">
            <div align="center">
              <input type="hidden" name="txtCliente" value="<%=cliente %>">
              <img src="Imagen/log.jpg" alt="logo" width="178" height="178" align="middle">
            </div>
            <table id="tablaAnadirCarrito">
                <tr>
                    <th colspan="2">
                        <h1>Añadir Platillo a Orden</h1>
                    </th>
                </tr>
                <tr>
                    <td colspan="2">
                        <dd> <input type="hidden" name="txtCodigo" value="<%=p.getCodigoP() %>" size="20" maxlength="30"> </dd>
                    </td>
                </tr>
                <tr>
                    <td class="primeraColumna">
                        Nombre producto :
                    </td>
                    <td>
                        <dd> <input type="text" name="txtNombreP" class="campoNoEditable" value="<%=p.getClaseProducto() %> <%=p.getMarcaProducto() %> - <%=p.getDescripcion() %>" 
                               size="60" readonly> </dd>
                    </td>
                </tr>
                <tr>
                    <td class="primeraColumna">
                        Precio producto :
                    </td>
                    <td>
                        <dd> <input type="text" name="txtPrecio" class="campoNoEditable" value="<%=p.getPrecioP() %>" size="20" maxlength="30" readonly> </dd>
                    </td>
                </tr>
                <tr>
                    <td class="primeraColumna">
                        Cantidad :
                    </td>
                    <td>
                        <dd> <input type="number" name="txtCantidad" value="1" min="1"> </dd>
                    </td>
                </tr>
                <tr>
                    <td colspan="2" class="Botones">
                        <br>
                        <input type="button" name="btnCancelar" id="btnCancelar" class="button" value="Cancelar">
                        <input type="submit" name="btnGuardar" id="btnGuardar" class="button" value="ADD a Pedido">
                    </td>
                </tr>
                <tr>
                    <td>
                        <br>
                    </td>
                </tr>
            </table>
                    <p align="center"><img src="Imagen/Pan_Vino_Bienvenida.jpg" width="627" height="363"></p>
                    <p>
                      <input type="hidden" name="accion" value="anadirCarrito">
                      <em>
                      </em></p>
                    <em>
                    <p align="center">&quot;Disfruta una nueva experiencia de comer&quot;.</p>
                    </em>
        </form>
    </body>
</html>
