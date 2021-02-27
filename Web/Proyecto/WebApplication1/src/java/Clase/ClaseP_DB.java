
package Clase;

import java.sql.*;
import java.util.*;
import Conexion.Conexion;
/**
 *
 * @author Manuel CAOS ESCOM-IPN
 */
public class ClaseP_DB {
    
    public static ArrayList<ClaseP> ObtenerCPHabilitados(){
        ArrayList<ClaseP> lista = new ArrayList<ClaseP>();
        Connection cn;
        Conexion con = new Conexion();
        cn=con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL MOSTRAR_CLASE_PRODUCTO_HABILITADOS");
            ResultSet rs = cs.executeQuery();
            while(rs.next()){
                ClaseP cp = new ClaseP(rs.getString("Codigo_CP"), rs.getString("Nombre_CP"), rs.getString("Estado_CP"));
                lista.add(cp);
            }
        }catch(Exception e){ 
            System.out.println(e);
        }
        return lista;
    }
    
    public static ArrayList<ClaseP> obtenerCPInhabilitados(){
        ArrayList<ClaseP> lista = new ArrayList<ClaseP>();
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL MOSTRAR_CLASE_PRODUCTO_INHABILITADOS");
            ResultSet rs = cs.executeQuery();
            while(rs.next()){
                ClaseP CP = new ClaseP(rs.getString("Codigo_CP"), rs.getString("Nombre_CP"), rs.getString("Estado_CP"));
                lista.add(CP);
            }
        }catch(Exception e){
            System.out.println(e);
        }
        return lista;
    } 
    
    public static boolean insertarClaseProducto(ClaseP cp){
        boolean resp = false;
        
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL REGISTRAR_CLASE_PRODUCTO (?)");
            cs.setString(1, cp.getNombreCP());
            int i = cs.executeUpdate();
            
            if(i==1)
                resp = true;
            else
                resp = false;
            
        }catch(Exception e){System.out.println(e);}
        return resp;
    }
    
    public static boolean actualizarClaseProducto(ClaseP cp){
        boolean resp = false;
        
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL MODIFICAR_CLASE_PRODUCTO (?,?)");
            cs.setString(1, cp.getCodigoCP());
            cs.setString(2, cp.getNombreCP()); 
            int i = cs.executeUpdate();
            
            if(i==1)
                resp = true;
            else
                resp = false;
            
        }catch(Exception e){System.out.println(e);}
        return resp;
    }
    
    public static boolean darBajaClaseProducto(ClaseP cp){
        boolean resp = false;
        
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL ELIMINAR_CLASE_PRODUCTO (?)");
            cs.setString(1, cp.getCodigoCP()); 
            int i = cs.executeUpdate();
            
            if(i==1)
                resp = true;
            else
                resp = false;
            
        }catch(Exception e){System.out.println(e);}
        return resp;
    }
    
    public static boolean darAltaClaseProducto(ClaseP cp){
        boolean resp = false;
        
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL RECUPERAR_CLASE_PRODUCTO (?)");
            cs.setString(1, cp.getCodigoCP()); 
            int i = cs.executeUpdate();
            
            if(i==1)
                resp = true;
            else
                resp = false;
            
        }catch(Exception e){System.out.println(e);}
        return resp;
    }
}
