
package Clase;

import java.sql.*;
import java.util.*;
import Conexion.Conexion;
/**
 *
 * @author Manuel CAOS ESCOM-IPN
 */
public class Producto_DB {
    // Traer todo los productos
    public static ArrayList<Producto> obtenerProductosHabilitados(){
        ArrayList<Producto> lista = new ArrayList<Producto>();
            Connection cn;
            Conexion con = new Conexion();
            cn = con.conectar();
            
            CallableStatement cs = null;
            ResultSet rs = null;
            
            try{
                cs=cn.prepareCall("CALL MOSTRAR_PRODUCTOS_HABILITADOS");
                rs=cs.executeQuery();
                while(rs.next()){
                    Producto p = new Producto(rs.getString("Codigo_P"), rs.getString("Clase_P"), rs.getString("Marca_P"), rs.getString("Descripcion_P"), rs.getDouble("Precio_P"), rs.getString("Imagen_P"), rs.getString("Estado_P"));
                    lista.add(p);
                }
                
            }catch(Exception e){
                System.out.println(e);
            }
            
        return lista;
    }
    
    public static ArrayList<Producto> obtenerProductosInhabilitados(){
        ArrayList<Producto> lista = new ArrayList<Producto>();
            Connection cn;
            Conexion con = new Conexion();
            cn = con.conectar();
            
            CallableStatement cs = null;
            ResultSet rs = null;
            
            try{
                cs=cn.prepareCall("CALL MOSTRAR_PRODUCTOS_ELIMINADOS");
                rs=cs.executeQuery();
                while(rs.next()){
                    Producto p = new Producto(rs.getString("Codigo_P"), rs.getString("Clase_P") , rs.getString("Marca_P"), rs.getString("Descripcion_P"), rs.getDouble("Precio_P"), rs.getString("Imagen_P"), rs.getString("Estado_P"));
                    lista.add(p);
                }
                
            }catch(Exception e){
                System.out.println(e);
            }
            
        return lista;
    }
    
    public static boolean insertarProducto(Producto p){
        boolean resp = false;
        
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL REGISTRAR_PRODUCTO (?,?,?,?,?)");
            cs.setString(1, p.getClaseProducto());
            cs.setString(2, p.getMarcaProducto());
            cs.setString(3, p.getDescripcion());
            cs.setDouble(4, p.getPrecioP());
            cs.setString(5, p.getImagenP());
            int i = cs.executeUpdate();
            
            if(i==1)
                resp = true;
            else
                resp = false;
            
        }catch(Exception e){System.out.println(e);}
        return resp;
    }
    
    public static boolean actualizarProducto(Producto p){
        boolean resp = false;
        
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL MODIFICAR_PRODUCTO (?,?,?,?,?,?)");
            cs.setString(1, p.getCodigoP());
            cs.setString(2, p.getClaseProducto());
            cs.setString(3, p.getMarcaProducto());
            cs.setString(4, p.getDescripcion());
            cs.setDouble(5, p.getPrecioP());
            cs.setString(6, p.getImagenP());
            cs.executeUpdate();
            
            int i = cs.executeUpdate();
            
            if(i==1)
                resp = true;
            else
                resp = false;
            
        }catch(Exception e){System.out.println(e);}
        return resp;
    }
    
    public static boolean eliminarProducto(Producto p){
        boolean resp = false;
        
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL ELIMINAR_PRODUCTO (?)");
            cs.setString(1, p.getCodigoP());

            int i = cs.executeUpdate();
            
            if(i==1)
                resp = true;
            else
                resp = false;
            
        }catch(Exception e){System.out.println(e);}
        return resp;
    }
    
    public static boolean recuperarProducto(Producto p){
        boolean resp = false;
        
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL RECUPERAR_PRODUCTO (?)");
            cs.setString(1, p.getCodigoP());
            
            int i = cs.executeUpdate();
            
            if(i==1)
                resp = true;
            else
                resp = false;
            
        }catch(Exception e){System.out.println(e);}
        return resp;
    }
    
    public static Producto listarProductoPorCodigo(String Codigo){
        Producto p = new Producto();
        
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL BUSCAR_PRODUCTO_CODIGO (?)");
            cs.setString(1, Codigo);
            ResultSet rs = cs.executeQuery();
            while(rs.next()){
                p.setCodigoP(rs.getString("Codigo_P"));
                p.setClaseProducto(rs.getString("Nombre_CP"));
                p.setMarcaProducto(rs.getString("Nombre_MP"));
                p.setDescripcion(rs.getString("Descripcion_P"));
                p.setPrecioP(rs.getDouble("Precio_P"));
                p.setImagenP(rs.getString("Imagen_P")); 
            }
        }catch(Exception e){System.out.println(e);}
        return p;
    }
}
