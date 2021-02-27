

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="java.util.ArrayList" %>
<%@page import="Clase.*"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <script type="text/javascript" src="js/jquery-1.4.2.min.js"></script>
        <script type="text/javascript" src="js/Catalogo.js"></script>
        <link type="text/css" rel="stylesheet" href="css/css1.css" />
        
        <title>JSP Page</title>
        
    </head>
    
    <body onload="cargar()">
        
        <%
            String codigo = (String)session.getAttribute("parametroCodigo");
            
            Usuario usu = Usuario_DB.listarUsuarioPorCodigo(codigo);
            String cliente =   usu.getNombreUsuario() + ", " + usu.getApellidosUsuario();
            
       
        %>
        
        <form action="Servlet_Usu" method="post" id="frmCabecera">
            <div align="center" bgcolor="#FFBF00">
              <input type="hidden" value="<%=usu.getTipoUsuario() %>" name="txtTipo" id="txtTipo">
              <img src="Imagen/log.jpg" alt="" width="118" height="115" align="right">
              <img src="Imagen/log.jpg" alt="" width="118" height="115" align="left">
            </div>
            <div align="left" bgcolor="#FFBF00"></div>
            <table bgcolor="#33CC99" id="tablaCabecera">
                <tr>
                    <td colspan="5">
                     
                        <h1> Bienvenido:  <%=cliente%></h1>
                    </td>
                </tr>
                <tr>
                    <td>
                        <a href="RegistrarVenta.jsp" class="link" id="lnkCompra"><h4>Mi compra</h4></a>
                    </td>
                    <td>
                        <a href="MiPerfil.jsp?codigoU=<%=usu.getCodigoUsuario() %>" class="link" id="lnkPerfil">Mi cuenta</a>  
                    </td>
                    <td>
                        <a href="CuentaAdministrador.jsp" class="link" id="lnkAdm">Administrar</a>
                    </td>
                    <td>
                        <a href="Login.jsp" class="link" id="lnkLogin">Login</a>
                    </td>
                    <td>
                        <a href="CatalogoPrincipal.jsp" class="link" id="lnkLogout">Salir</a>
                    </td>
                </tr>
            </table>
            <input type="hidden" name="accion" value="logout">
        </form>
        <hr>

        <form id="frmCatalogo">
            
            <table width="800" bgcolor="#FFBF00" id="tablaCatalogo">
                <tr>
                    <th colspan="3">
                        <h1> <em>Elección de Platillos de Nuestro Menú</em></h1>
                    </th>
                </tr>
                
                <tbody>
                <%
                    ArrayList<Producto> lista = Producto_DB.obtenerProductosHabilitados();
                    int salto = 0;
                    for(int i=0; i<lista.size(); i++){
                        Producto p = lista.get(i);
                %>
                        
                            <th><p><img src="Imagen/<%=p.getImagenP() %>" width="100" height="100"><br>
                                <%=p.getClaseProducto()%> <%=p.getMarcaProducto()%> <br>
                                <%=p.getDescripcion()%><br>
                                S/ <%=p.getPrecioP() %><br>
                            <input type="button" class="BotonModificar" name="btnModificar" value="Modificar" onclick="location.href='ModificarProducto.jsp?codigoP=<%=p.getCodigoP() %>'">
                            <input type="button" class="BotonADD" name="btnADD" value="ADD a Pedido" onclick="location.href='AnadirCarrito.jsp?codigoP=<%=p.getCodigoP()%>&&cliente=<%=cliente %>'">
                            </p></th>
                <%
                        salto++;
                        if(salto == 3){
                            %>
                            
                            <tr>
                                
                            <%
                            salto = 0;
                        } 
                    }
                %>
                </tbody>
            </table>
            <p align="center">&quot;Disfruta una nueva experiencia de comer&quot;.</p>
        </form>  
    </body>
</html>
