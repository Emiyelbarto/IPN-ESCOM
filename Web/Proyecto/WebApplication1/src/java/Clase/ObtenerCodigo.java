
package Clase;
import java.sql.*;
import Conexion.Conexion;
/**
 *
 * @author Manuel CAOS ESCOM-IPN
 */
public class ObtenerCodigo {
    public static String CodigoProducto(){
        String Codigo = "";
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL MOSTRAR_CODIGO_PRODUCTO");
            ResultSet rs = cs.executeQuery();
            while(rs.next()){
                Codigo = rs.getString("Codigo_P");
            }
        }catch(Exception e){
           System.out.println(e);
        }
        return Codigo;
    }
    
    public static String CodigoMarcaProducto(){
        String Codigo = "";
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL MOSTRAR_CODIGO_MARCA_PRODUCTO");
            ResultSet rs = cs.executeQuery();
            while(rs.next()){
                Codigo = rs.getString("Codigo_MP");
            }
        }catch(Exception e){
           System.out.println(e);
        }
        return Codigo;
    }
    
    public static String CodigoClaseProducto(){
        String Codigo = "";
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL MOSTRAR_CODIGO_CLASE_PRODUCTO");
            ResultSet rs = cs.executeQuery();
            while(rs.next()){
                Codigo = rs.getString("Codigo_CP");
            }
        }catch(Exception e){
           System.out.println(e);
        }
        return Codigo;
    }
    
    public static String CodigoVenta(){
        String Codigo = "";
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL MOSTRAR_CODIGO_VENTA");
            ResultSet rs = cs.executeQuery();
            while(rs.next()){
                Codigo = rs.getString("Codigo_V");
            }
        }catch(Exception e){
           System.out.println(e);
        }
        return Codigo;
    }
}
