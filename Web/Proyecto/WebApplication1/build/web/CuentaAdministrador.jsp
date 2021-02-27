
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <link type="text/css" rel="stylesheet" href="css/css1.css" />
        <title>JSP Page</title>
    </head>
    <body>
        <form id="frmAdministrador">
            <table id="tablaAdministrador">
                <tr>
                	<th colspan="5"><div align="center"><img src="Imagen/log.jpg" width="178" height="178"></div>
                    </th>
                </tr>
                <tr>
                    <th colspan="5">
                        <h2> Control de Pedidos y Platillos</h2>
                    </th>
                </tr>
                <tr>
                    <th>
                        Registrar nuevo
                    </th>
                    <th width="103">
                        Registros habilitados
                    </th>
                    <th width="237">
                        Registros inhabilitados
                    </th>
                    <th width="197">
                        Pedidos realizados
                    </th>
                    <th width="100">
                        Menú
                    </th>
                </tr>
                <tr>
                    <td>
                        <a href="RegistrarClaseProducto.jsp" class="link">Clase platillo</a>
                    </td>
                    <td>
                        <a href="MostrarCP.jsp" class="link">Clase platillo</a>
                    </td>
                    <td>
                        <a href="MostrarCPEliminados.jsp" class="link">Clase platillo</a>
                    </td>
                    <td>
                        <a href="MostrarVenta.jsp" class="link">Ir a Ordenes del Día</a>
                    </td>
                    <td>
                        <a href="Catalogo.jsp" class="link">Ir a menú</a>
                    </td>
                </tr>
                <tr>
                    <td>
                        <a href="RegistrarMarcaProducto.jsp" class="link">Tipo de platillo</a>
                    </td>
                    <td>
                        <a href="MostrarMP.jsp" class="link">Tipo de platillo</a>
                    </td>
                    <td>
                        <a href="MostrarMPEliminados.jsp" class="link">Tipo de Platillo</a>
                    </td>
                    <td>
                        
                    </td>
                    <td>
                        
                    </td>
                </tr>
                <tr>
                    <td>
                        <a href="RegistrarProducto.jsp" class="link">Platillo</a>
                    </td>
                    <td>
                        <a href="MostrarProducto.jsp" class="link">Platillo</a>
                    </td>
                    <td>
                        <a href="MostrarProductosEliminados.jsp" class="link">Platillo</a>
                    </td>
                    <td>
                        
                    </td>
                    <td>
                        
                    </td>
                </tr>
                <tr>
                    <td>

                    </td>
                    <td>
                        <a href="MostrarUsuario.jsp" class="link">Cliente</a>
                    </td>
                    <td>
                        <a href="MostrarUsuarioEliminado.jsp" class="link">Cliente</a>
                    </td>
                    <td>
                        
                    </td>
                    <td>
                        
                    </td>
                </tr>
            </table>
        </form>
        
    </body>
</html>
