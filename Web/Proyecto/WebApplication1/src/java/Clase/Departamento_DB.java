
package Clase;
import java.sql.*;
import java.util.*;
import Conexion.Conexion;
/**
 *
 * @author Manuel CAOS ESCOM-IPN
 */
public class Departamento_DB {
    public static List<Departamento> ObtenerDepartamentos(){
        List<Departamento> lista = new ArrayList<Departamento>();
        Connection cn;
        Conexion con = new Conexion();
        cn=con.conectar();
        
        try{
            CallableStatement cs = cn.prepareCall("CALL MOSTRAR_DEPARTAMENTOS");
            ResultSet rs = cs.executeQuery();
            while(rs.next()){
                Departamento dep = new Departamento(rs.getInt("IdDepartamento"), rs.getString("Departamento"));
                lista.add(dep);
            }
        }catch(Exception e){ 
            System.out.println(e);
        }
        return lista;
    }
    
}
