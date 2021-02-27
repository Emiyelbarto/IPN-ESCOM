
package Clase;
import Conexion.Conexion;
import java.sql.*;
import java.util.*;
/**
 *
 * @author Manuel CAOS ESCOM-IPN
 */
public class DetalleVenta_DB {
    public static ArrayList<DetalleVenta> obtenerDetalleVenta(String CodigoVenta){
        ArrayList<DetalleVenta> lista = new ArrayList<DetalleVenta>();
        
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
        try{
            CallableStatement cs = cn.prepareCall("CALL MOSTRAR_DETALLE_VENTA_POR_CODIGO (?)");
            cs.setString(1, CodigoVenta);
            ResultSet rs = cs.executeQuery();
            
            while(rs.next()){
                DetalleVenta dv = new DetalleVenta();
                dv.setCodigoVenta(rs.getString("Codigo_V"));
                dv.setNombreProducto(rs.getString("Producto"));
                dv.setPrecio(rs.getDouble("Precio"));
                dv.setCantidad(rs.getDouble("Cantidad"));
                dv.setDescuento(rs.getDouble("Descuento"));
                dv.setSubTotal(rs.getDouble("SubTotal")); 
                lista.add(dv);
            }
        }catch(Exception e){System.out.println(e);}
        return lista;
    }
}
