
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
    
    <body >
        

        
        <form action="Servlet_Usu" method="post" id="frmCabecera">
           
            <div align="center" bgcolor="#FF0055"><img src="Imagen/log.jpg" width="131" height="119" align="right"></div>
            <img src="Imagen/log.jpg" width="123" height="120" align="left">
            <table bgcolor="#FFBF00" frame="box" rules="none" id="tablaCabecera">
                <tr>
                    <td colspan="5">
                            <h1 align="center">COCINA VIRTUAL</h1>
                    </td>
              </tr>
                <tr>
                    <td>
                        <a href="RegistrarVenta.jsp" class="link" id="lnkCompra"><h4>Mi compra</h4></a>
                    </td>
                   
                    <td>
                        <a href="CuentaAdministrador.jsp" class="link" id="lnkAdm">Administrar</a>
                    </td>
                    <td>
                        <a href="Login.jsp" class="link" id="lnkLogin">Login</a>
                    </td>
                    <td>
                        <a href="Servlet_Usu?accion=logout" class="link" id="lnkLogout">Salir</a>
                    </td>
                </tr>
          </table>
          <div align="center">
            <input type="hidden" name="accion" value="logout">
            <span id="frmCabecera">Elija los platillos que desea pedir: </span></div>
        </form>
        <hr>

        <form id="frmCatalogo">
            
            <table width="800" bgcolor="#FF8000" id="tablaCatalogo">
                <tr>
                    <th colspan="3">
                        <h1> <em>Menú</em></h1>
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
                            <input type="button" class="BotonModificar" name="btnModificar" value="Modificar" >
                            <input type="button" class="BotonADD" name="btnADD" value="ADD a Pedido" >
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
            <p align="center"><strong>&quot;<em>Disfruta la calidad de comer</em>&quot;</strong></p>
        </form>  
    </body>
</html>
