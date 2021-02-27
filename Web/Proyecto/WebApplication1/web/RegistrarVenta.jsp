

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="java.util.*" %>
<%@page import="Clase.*" %>
<%@page import="java.text.*" %>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <script type="text/javascript" src="js/jquery-1.4.2.min.js"></script>
        <script type="text/javascript" src="js/RegistrarVenta.js"></script>
        <link type="text/css" rel="stylesheet" href="css/css1.css" />
        <title>JSP Page</title>
    </head>
    <body>
        
        <%
            String codigoVenta = ObtenerCodigo.CodigoVenta();
            String cliente = (String)session.getAttribute("parametroCliente");
        %>
        
        <form action="Servlet_Venta" method="post" id="frmRegistrarVenta">
            <br>
            <table id="tablaRegistrarVenta">
                <tr>
                    <th colspan="7" class="TituloDV">
                        <h3><img src="Imagen/log.jpg" width="123" height="112"></h3>
                        <h3>ORDEN DE MESA</h3>
                        <input type="hidden" name="txtCodigoV" value="<%=codigoVenta %>">
                    </th>
                </tr>
                <tr>
                    <th colspan="2" class="TituloDV">
                        CLIENTE :  
                    </th>
                    <td colspan="5" class="Contenido">
                        <%=cliente %>
                        <input type="hidden" name="txtCliente" value="<%=cliente %>" size="50" readonly>
                    </td>
                </tr>
                <tr>
                    <td colspan="7" class="FilaEnBlanco">
                        <br>
                    </td>
                </tr>
                <tr>
                    <th class="TituloDV">
                        N°
                    </th>
                    <th class="TituloDV">
                        PLATILLO 
                    </th>
                    <th class="TituloDV">
                        P/U ($)
                    </th>
                    <th class="TituloDV">
                        CANTIDAD 
                    </th>
                    <th class="TituloDV">
                        DESC ($)
                    </th>
                    <th class="TituloDV">
                        SUBTOTAL ($)
                    </th>
                    <th class="TituloDV">
                        OPCION
                    </th>
                </tr>
                
                <%
                    DecimalFormat df = new DecimalFormat("0.00");
                    DecimalFormatSymbols dfs = df.getDecimalFormatSymbols();
                    dfs.setDecimalSeparator('.');
                    df.setDecimalFormatSymbols(dfs);
                    
                    double total = 0;
                    ArrayList<DetalleVenta> lista = (ArrayList<DetalleVenta>)session.getAttribute("carrito");
                    
                    if(lista != null){
                        for(DetalleVenta dv:lista){
                            %>
                            
                            <tr>
                                <td class="Contenido">
                                    <%=dv.getNumero() %>
                                </td>
                                <td class="Contenido">
                                    <%=dv.getNombreProducto() %>
                                    <input type="hidden" name="nombreProd" value="<%=dv.getNombreProducto() %>">
                                </td>
                                <td class="Contenido">
                                    <%=df.format(dv.getPrecio())%>
                                    <input type="hidden" name="precioProd" value="<%=dv.getPrecio()%>">
                                </td>
                                <td class="Contenido">
                                    <%=dv.getCantidad()%>
                                    <input type="hidden" name="cantidadProd" value="<%=dv.getCantidad()%>">
                                </td>
                                <td class="Contenido">
                                    <%=df.format(dv.getDescuento())%>
                                    <input type="hidden" name="descuentoProd" value="<%=dv.getDescuento()%>">
                                </td>
                                <td class="Contenido">
                                    <div> <%=df.format(dv.getSubTotal()) %> </div>
                                    <input type="hidden" name="subTotalProd" value="<%=dv.getSubTotal()%>">
                                </td> 
                                <td whidh="100" class="Opcion">
                                    <input type="button" name="btnEliminar" id="btnEliminar" class="button" value="Eliminar" onclick="location.href='Servlet_Venta?numero=<%=dv.getNumero() %>&&accion=quitar'">
                                </td>
                            </tr>
                            <%
                            total = total + dv.getSubTotal();
                        }
                    }
                %>
                <tr>
                    <th colspan="5" class="TituloDV">
                        <div> TOTAL ($.)  </div>
                    </th>
                    <th class="Contenido">
                        <div> <%=String.valueOf(df.format(total)) %> </div>
                        <input type="hidden" name="txtTotal" value="<%=String.valueOf(df.format(total)) %>" readonly>
                    </th>
                    <th class="FilaEnBlanco">
                    </th>
                </tr>
                <tr>
                    <td colspan="7" class="FilaEnBlanco">
                        <br>
                    </td>
                </tr>
            </table>
            
            <table id="tablaRegresar">
                <tr>
                    <td>
                        <br>
                    </td>
                </tr>
                <tr>
                    <td>
                        <input type="button" name="btnRegistrar" id="btnRegistrarVenta" class="button" value="Enviar Pedido">
                    </td>
                </tr>
                <tr>
                    <td>
                        <br>
                    </td>
                </tr>
            </table>        
                    <p align="center">
                      <input type="hidden" name="accion" value="RegistrarVenta">
                      <img src="Imagen/Pan_Vino_Bienvenida.jpg" width="627" height="363"><br>
                    </p>
                    
        </form>
                    <h3 align="center">
                        <a href="Catalogo.jsp" class="link">No se olvide del Postre, pida algo más...</a>
                    </h3>
    </body>
</html>
