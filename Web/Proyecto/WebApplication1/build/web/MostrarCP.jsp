
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="Clase.*" %>
<%@page import="java.util.ArrayList" %>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <link type="text/css" rel="stylesheet" href="css/css1.css" />
        <title>JSP Page</title>
    </head>
    
    <body>
        <form id="frmMostrarCabeceraCP">
        <table id="tablaMostrarCabeceraCP">
            <tr>
                    <th>
                        <h1><img src="Imagen/log.jpg" width="178" height="178"> </h1>
                        <h1>Clase platillos habilitados </h1>
                    </th>
                </tr>
                <tr>
                    <td>
                        <a href="CuentaAdministrador.jsp" class="link"><h4> Pagina principal </h4></a>
                    </td>
                </tr>
            </table>
        </form>
        
        <hr>
        
        <form id="frmMostrarCuerpoCP">
            <table id="tablaMostrarCuerpoCP">
                <tr>
                    <th class="Titulo">
                        CODIGO
                    </th>
                    <th class="Titulo">
                        NOMBRE
                    </th>
                    <th class="Titulo">
                        ESTADO
                    </th>
                    <th colspan="2" class="Titulo">
                        OPCION
                    </th>
                </tr>    
                
                <%
                    ArrayList<ClaseP> lista = ClaseP_DB.ObtenerCPHabilitados();
                    for(int i=0; i<lista.size(); i++){
                        ClaseP CP = lista.get(i);
                        %>
                        
                <tr>
                    <td>
                        <%=CP.getCodigoCP() %>
                    </td>
                    <td>
                        <%=CP.getNombreCP() %>
                    </td>
                    <td>
                        <%=CP.getEstadoCP() %>
                    </td>
                    <td class="Opcion">
                        <input type="button" name="btnModificar" value="Modificar" id="btnModificar" class="button" onclick="location.href='ModificarCP.jsp?codigoCP=<%=CP.getCodigoCP() %>&&nombreCP=<%=CP.getNombreCP() %>&&estadoCP=<%=CP.getEstadoCP() %>'">
                    </td>
                    <td class="Opcion">
                        <input type="button" name="btnEliminar" value="Eliminar" id="btnEliminar" class="button" onclick="location.href='Servlet_CP?codigoCP=<%=CP.getCodigoCP() %>&&accion=eliminar'">
                    </td>
                </tr>
                
                <%
                    }
                %>

            </table>
        </form>
    </body>
    
    
</html>
