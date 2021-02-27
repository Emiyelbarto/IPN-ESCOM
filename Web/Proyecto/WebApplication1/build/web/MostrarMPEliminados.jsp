

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="java.util.ArrayList" %>
<%@page import="Clase.*" %>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <link type="text/css" rel="stylesheet" href="css/css1.css" />
        <title>JSP Page</title>
    </head>

    <body>
        <form id="frmMostrarCabeceraMPEliminados">
        <table id="tablaMostrarCabeceraMPEliminados">
            <tr>
                    <th>
                        <h1><img src="Imagen/log.jpg" width="178" height="178"> </h1>
                        <h1>Tipo de platillos eliminados </h1>
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
        
        <form id="frmMostrarCuerpoMPEliminados">
            <table id="tablaMostrarCuerpoMPEliminados">
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
                    <th class="Titulo">
                        OPCION
                    </th>
                </tr>
                
                <%
                    ArrayList<MarcaP> lista = MarcaP_DB.obtenerMPInhabilitados();
                    for(int i=0; i<lista.size(); i++){
                        MarcaP MP = lista.get(i);
                %>
  
                <tr>
                    <td>
                        <%=MP.getCodigoMP() %>
                    </td>
                    <td>
                        <%=MP.getNombreMP() %>
                    </td>
                    <td>
                        <%=MP.getEstadoMP() %>
                    </td>
                    <td class="Opcion">
                        <input type="button" name="btnRecuperar" id="btnRecuperar" class="button" value="Recuperar" onclick="location.href='Servlet_MP?codigoMP=<%=MP.getCodigoMP() %>&&accion=recuperar'">
                    </td>
                </tr>
                
                <%
                    }
                %>
    
            </table>
        </form>
    </body>
    
</html>
