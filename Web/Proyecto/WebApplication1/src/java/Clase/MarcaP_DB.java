
package Clase;

import java.sql.*;
import java.util.*;
import Conexion.Conexion;
/**
 *
 * @author Manuel CAOS ESCOM-IPN
 */
public class MarcaP_DB {
    
    public static ArrayList<MarcaP> obtenerMPHabilitados(){
        ArrayList<MarcaP> lista = new ArrayList<MarcaP>();
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL MOSTRAR_MARCA_PRODUCTO_HABILITADOS");
            ResultSet rs = cs.executeQuery();
            while(rs.next()){
                MarcaP MP = new MarcaP(rs.getString("Codigo_MP"), rs.getString("Nombre_MP"), rs.getString("Estado_MP"));
                lista.add(MP);
            }
            
        }catch(Exception e){
            System.out.println(e);
        }
        return lista;
    }
    
    public static ArrayList<MarcaP> obtenerMPInhabilitados(){
        ArrayList<MarcaP> lista = new ArrayList<MarcaP>();
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL MOSTRAR_MARCA_PRODUCTO_INHABILITADOS");
            ResultSet rs = cs.executeQuery();
            while(rs.next()){
                MarcaP MP = new MarcaP(rs.getString("Codigo_MP"), rs.getString("Nombre_MP"), rs.getString("Estado_MP"));
                lista.add(MP);
            }
            
        }catch(Exception e){
            System.out.println(e);
        }
        return lista;
    }
    
    public static boolean insertarMarcaProducto(MarcaP mp){
        boolean resp = false;
        
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL REGISTRAR_MARCA_PRODUCTO (?)");
            cs.setString(1, mp.getNombreMP());
            int i = cs.executeUpdate();
            
            if(i==1)
                resp = true;
            else
                resp = false;
            
        }catch(Exception e){System.out.println(e);}
        return resp;
    }
    
    public static boolean actualizarMarcaProducto(MarcaP mp){
        boolean resp = false;
        
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL MODIFICAR_MARCA_PRODUCTO (?,?)");
            cs.setString(1, mp.getCodigoMP());
            cs.setString(2, mp.getNombreMP()); 
            int i = cs.executeUpdate();
            
            if(i==1)
                resp = true;
            else
                resp = false;
            
        }catch(Exception e){System.out.println(e);}
        return resp;
    }
    
    public static boolean eliminarMarcaProducto(MarcaP mp){
        boolean resp = false;
        
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL ELIMINAR_MARCA_PRODUCTO (?)");
            cs.setString(1, mp.getCodigoMP());
            int i = cs.executeUpdate();
            
            if(i==1)
                resp = true;
            else
                resp = false;
            
        }catch(Exception e){System.out.println(e);}
        return resp;
    }
    
    public static boolean recuperarMarcaProducto(MarcaP mp){
        boolean resp = false;
        
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL RECUPERAR_MARCA_PRODUCTO (?)");
            cs.setString(1, mp.getCodigoMP());
            int i = cs.executeUpdate();
            
            if(i==1)
                resp = true;
            else
                resp = false;
            
        }catch(Exception e){System.out.println(e);}
        return resp;
    }

}
