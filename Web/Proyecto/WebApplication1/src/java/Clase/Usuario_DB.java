
package Clase;
import java.sql.*;
import Conexion.Conexion;
import java.util.*;

/**
 *
 * @author Manuel CAOS ESCOM-IPN
 */
public class Usuario_DB {
    
    public static Usuario VerificarUsuario(String id_usuario){
        Usuario usu = new Usuario();
        
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL LOGEAR_USUARIO (?)");
            cs.setString(1, id_usuario);
            ResultSet rs = cs.executeQuery();
            
            while(rs.next()){
                usu.setCodigoUsuario(rs.getString("Codigo_U")); 
                usu.setIdUsuario(rs.getString("Id_U"));
                usu.setClaveUsuario(rs.getString("Clave_U"));
                usu.setEstadoUsuario(rs.getString("Estado_U")); 
            }
        }catch(Exception e){System.out.println(e);}
        return usu;
    }
    
    public static ArrayList<Usuario> MostrarUsuarioHabilitado(){
        ArrayList<Usuario> lista = new ArrayList<Usuario>();
        
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL MOSTRAR_USUARIOS_CLIENTES_HABILITADOS");
            ResultSet rs = cs.executeQuery();
            
            while(rs.next()){
                Usuario usu = new Usuario();
                usu.setCodigoUsuario(rs.getString("Codigo_U"));
                usu.setNombreUsuario(rs.getString("Nombres_U"));
                usu.setApellidosUsuario(rs.getString("Apellidos_U"));
                usu.setDniUsuario(rs.getString("Dni_U"));
                usu.setEmailUsuario(rs.getString("Email_U")); 
                usu.setTelefonoUsuario(rs.getString("Telefono_U"));
                usu.setIdUsuario(rs.getString("Id_U"));
                usu.setTipoUsuario(rs.getString("Tipo_U"));
                usu.setEstadoUsuario(rs.getString("Estado_U")); 
                lista.add(usu);
            }
        }catch(Exception e){System.out.println(e);}
        return lista;
    }
    
    public static ArrayList<Usuario> MostrarUsuarioInhabilitado(){
        ArrayList<Usuario> lista = new ArrayList<Usuario>();
        
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL MOSTRAR_USUARIOS_CLIENTES_INHABILITADOS");
            ResultSet rs = cs.executeQuery();
            
            while(rs.next()){
                Usuario usu = new Usuario();
                usu.setCodigoUsuario(rs.getString("Codigo_U"));
                usu.setNombreUsuario(rs.getString("Nombres_U"));
                usu.setApellidosUsuario(rs.getString("Apellidos_U"));
                usu.setDniUsuario(rs.getString("Dni_U"));
                usu.setEmailUsuario(rs.getString("Email_U")); 
                usu.setTelefonoUsuario(rs.getString("Telefono_U"));
                usu.setIdUsuario(rs.getString("Id_U"));
                usu.setTipoUsuario(rs.getString("Tipo_U"));
                usu.setEstadoUsuario(rs.getString("Estado_U")); 
                lista.add(usu);
            }
        }catch(Exception e){System.out.println(e);}
        return lista;
    }
    
    
    public static boolean RegistrarUsuario(Usuario usu){
        boolean resp = false;
        
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL REGISTRAR_USUARIO_CLIENTE (?,?,?,?,?,?,?,?,?,?,?,?)");
            cs.setString(1, usu.getNombreUsuario());
            cs.setString(2, usu.getApellidosUsuario());
            cs.setString(3, usu.getDniUsuario());
            cs.setString(4, usu.getEmailUsuario());
            cs.setString(5, usu.getDepartamentoUsuario());
            cs.setString(6, usu.getProvinciaUsuario());
            cs.setString(7, usu.getDistritoUsuario());
            cs.setString(8, usu.getDireccion1Usuario());
            cs.setString(9, usu.getDireccion2Usuario());
            cs.setString(10, usu.getTelefonoUsuario());
            cs.setString(11, usu.getIdUsuario());
            cs.setString(12, usu.getClaveUsuario());
            int i = cs.executeUpdate();
            
            if(i == 1){
                resp = true;
            }else{
                resp = false;
            }
        }catch(Exception e){System.out.println(e);}
        return resp;
    }
    
    public static boolean ModificarUsuario(Usuario usu){
        boolean resp = false;
        
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL MODIFICAR_USUARIO (?,?,?,?,?,?,?,?,?,?)");
            cs.setString(1, usu.getCodigoUsuario());
            cs.setString(2, usu.getNombreUsuario());
            cs.setString(3, usu.getApellidosUsuario());
            cs.setString(4, usu.getDniUsuario());
            cs.setString(5, usu.getDepartamentoUsuario());
            cs.setString(6, usu.getProvinciaUsuario());
            cs.setString(7, usu.getDistritoUsuario());
            cs.setString(8, usu.getDireccion1Usuario());
            cs.setString(9, usu.getDireccion2Usuario());
            cs.setString(10, usu.getTelefonoUsuario());
            int i = cs.executeUpdate();
            
            if(i == 1){
                resp = true;
            }else{
                resp = false;
            }
        }catch(Exception e){System.out.println(e);}
        return resp;
    }
    
    public static boolean ModificarClaveUsuario(Usuario usu){
        boolean resp = false;
        
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL MODIFICAR_CLAVE_USUARIO (?,?)");
            cs.setString(1, usu.getCodigoUsuario());
            cs.setString(2, usu.getClaveUsuario()); 
            int i = cs.executeUpdate();
            
            if(i == 1){
                resp = true;
            }else{
                resp = false;
            }
        }catch(Exception e){System.out.println(e);}
        return resp;
    }
    
    public static boolean ModificarEmailUsuario(Usuario usu){
        boolean resp = false;
        
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL MODIFICAR_EMAIL_USUARIO (?,?)");
            cs.setString(1, usu.getCodigoUsuario());
            cs.setString(2, usu.getEmailUsuario()); 
            int i = cs.executeUpdate();
            
            if(i == 1){
                resp = true;
            }else{
                resp = false;
            }
        }catch(Exception e){System.out.println(e);}
        return resp;
    }
    
    
    public static boolean DarDeBajaUsuario(Usuario usu){
        boolean resp = false;
        
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL ELIMINAR_USUARIO (?)");
            cs.setString(1, usu.getCodigoUsuario());
            int i = cs.executeUpdate();
            
            if(i == 1){
                resp = true;
            }else{
                resp = false;
            }
        }catch(Exception e){System.out.println(e);}
        return resp;
    }
    
    public static boolean DarDeAltaUsuario(Usuario usu){
        boolean resp = false;
        
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL RECUPERAR_USUARIO (?)");
            cs.setString(1, usu.getCodigoUsuario());
            int i = cs.executeUpdate();
            
            if(i == 1){
                resp = true;
            }else{
                resp = false;
            }
        }catch(Exception e){System.out.println(e);}
        return resp;
    }
    
    public static Usuario listarUsuarioPorCodigo(String codigo){
        Usuario usu = new Usuario();
        
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL MOSTRAR_USUARIO_POR_CODIGO (?)");
            cs.setString(1, codigo);
            ResultSet rs = cs.executeQuery();
            while(rs.next()){
                usu.setCodigoUsuario(rs.getString("Codigo_U"));
                usu.setNombreUsuario(rs.getString("Nombres_U"));
                usu.setApellidosUsuario(rs.getString("Apellidos_U"));
                usu.setDniUsuario(rs.getString("Dni_U"));
                usu.setEmailUsuario(rs.getString("Email_U"));
                usu.setDepartamentoUsuario(rs.getString("Departamento_U"));
                usu.setProvinciaUsuario(rs.getString("Provincia_U"));
                usu.setDistritoUsuario(rs.getString("Distrito_U"));
                usu.setDireccion1Usuario(rs.getString("Direccion1_U"));
                usu.setDireccion2Usuario(rs.getString("Direccion2_U"));
                usu.setTelefonoUsuario(rs.getString("Telefono_U")); 
                usu.setIdUsuario(rs.getString("Id_U"));
                usu.setClaveUsuario(rs.getString("Clave_U"));
                usu.setTipoUsuario(rs.getString("Tipo_U")); 
                usu.setEstadoUsuario(rs.getString("Estado_U")); 
            }
        }catch(Exception e){System.out.println(e);}
        return usu;
    }
    
}
