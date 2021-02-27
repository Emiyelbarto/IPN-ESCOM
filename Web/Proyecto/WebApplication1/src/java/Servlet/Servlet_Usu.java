
package Servlet;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import java.sql.*;
import Conexion.Conexion;
import Clase.*;
import javax.servlet.http.HttpSession;
/**
 *
 * @author Manuel CAOS ESCOM-IPN
 */
public class Servlet_Usu extends HttpServlet {

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            String accion = request.getParameter("accion");
            
            if(accion.equals("login")){
                Login(request, response); 
            }
            if(accion.equals("registrar")){
                RegistrarUsuario(request, response); 
            }
            if(accion.equals("modificarUsuario")){
                ModificarUsuario(request, response); 
            }
            if(accion.equals("modificarClave")){
                ModificarClaveUsuario(request, response); 
            }
            if(accion.equals("modificarEmail")){
                ModificarEmailUsuario(request, response); 
            }
            if(accion.equals("eliminar")){
                DarBajaUsuario(request, response); 
            }
            if(accion.equals("recuperar")){
                DarAltaUsuario(request, response); 
            }
            if(accion.equals("logout")){
                Logout(request, response); 
            }
        }
    }
    
    private void Login(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        PrintWriter out = response.getWriter();
        
        Connection cn;
        Conexion con = new Conexion();
        cn = con.conectar();
            
        String usuario = request.getParameter("txtUsuario");
        String clave = request.getParameter("txtClave");
            
        try{
            Usuario usu = Usuario_DB.VerificarUsuario(usuario);
            
            if(usuario.equals(usu.getIdUsuario())){
                if(clave.equals(usu.getClaveUsuario())){
                    if("HAB".equals(usu.getEstadoUsuario())){
                        request.getSession().setAttribute("parametroCodigo", usu.getCodigoUsuario());
                        response.sendRedirect("Catalogo.jsp");
                    }else{
                        response.sendRedirect("respuesta.jsp?mens='Usted ha sido inhabilitado del sistema"); 
                    }
                }else{
                    response.sendRedirect("respuesta.jsp?mens='Su clave es incorrecto'"); 
                }
            }else{
                response.sendRedirect("respuesta.jsp?mens='Su id de usuario es incorrecto'"); 
            }
            
        }catch(Exception ex){out.println(ex.toString());}
    }
    
    private void RegistrarUsuario(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String Nombre = request.getParameter("txtNombres");
        String Apellidos = request.getParameter("txtApellidos");
        String Dni = request.getParameter("txtDni");
        String Email = request.getParameter("txtEmail");
        String Departamento = request.getParameter("txtDepartamento");
        String Provincia = request.getParameter("txtProvincia");
        String Distrito = request.getParameter("txtDistrito");
        String Direccion1 = request.getParameter("txtDireccion1");
        String Direccion2 = request.getParameter("txtDireccion2");
        String Telefono = request.getParameter("txtTelefono");
        String Usuario = request.getParameter("txtUsuario");
        String Clave = request.getParameter("txtClave");
        
        Usuario usu = new Usuario();
        usu.setNombreUsuario(Nombre);
        usu.setApellidosUsuario(Apellidos);
        usu.setDniUsuario(Dni);
        usu.setEmailUsuario(Email);
        usu.setDepartamentoUsuario(Departamento);
        usu.setProvinciaUsuario(Provincia);
        usu.setDistritoUsuario(Distrito);
        usu.setDireccion1Usuario(Direccion1);
        usu.setDireccion2Usuario(Direccion2);
        usu.setTelefonoUsuario(Telefono);
        usu.setIdUsuario(Usuario);
        usu.setClaveUsuario(Clave);
         
        boolean resp = Usuario_DB.RegistrarUsuario(usu);
        if(resp){
            response.sendRedirect("respuesta.jsp?mens='Se ha registrado correctamente'");
        }else{
            response.sendRedirect("respuesta.jsp?mens='Error: Estamos solucionando un problema'"); 
        }
    }
    
    private void ModificarUsuario(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        Usuario usu = new Usuario();
        usu.setCodigoUsuario(request.getParameter("txtCodigo"));
        usu.setNombreUsuario(request.getParameter("txtNombre"));
        usu.setApellidosUsuario(request.getParameter("txtApellidos"));
        usu.setDniUsuario(request.getParameter("txtDni"));
        usu.setDepartamentoUsuario(request.getParameter("txtDepartamento"));
        usu.setProvinciaUsuario(request.getParameter("txtProvincia"));
        usu.setDistritoUsuario(request.getParameter("txtDistrito"));
        usu.setDireccion1Usuario(request.getParameter("txtDireccion1"));
        usu.setDireccion2Usuario(request.getParameter("txtDireccion2"));
        usu.setTelefonoUsuario(request.getParameter("txtTelefono"));
        
        boolean resp = Usuario_DB.ModificarUsuario(usu);
        if(resp){
            response.sendRedirect("mensaje2.jsp?mens='Sus datos se han modificado correctamente'");
        }else{
            response.sendRedirect("mensaje2.jsp?mens='Error al modificar uno de sus datos'");
        }
    }
    
    private void ModificarClaveUsuario(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String pass1 = request.getParameter("txtCaracter");
        String pass2 = request.getParameter("txtClaveActual");
        
        Usuario usu = new Usuario();
        usu.setCodigoUsuario(request.getParameter("txtCodigo"));
        usu.setClaveUsuario(request.getParameter("txtClave")); 
        
        if(pass1.equals(pass2)){
            boolean resp = Usuario_DB.ModificarClaveUsuario(usu);
            if(resp){
                response.sendRedirect("mensaje2.jsp?mens='Su password ha sido cambiado correctamente'");
            }else{
                response.sendRedirect("mensaje2.jsp?mens='Error al cambiar su contrase&ntildea'");
            }
        }else{
            response.sendRedirect("mensaje2.jsp?mens='Error el password actual no es correcta'");
        }
    }
    
    private void ModificarEmailUsuario(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException { 
        String pass1 = request.getParameter("txtCaracter");
        String pass2 = request.getParameter("txtPass");
        
        Usuario usu = new Usuario();
        usu.setCodigoUsuario(request.getParameter("txtCodigo"));
        usu.setEmailUsuario(request.getParameter("txtEmail")); 
        
        if(pass1.equals(pass2)){
            boolean resp = Usuario_DB.ModificarEmailUsuario(usu);
            if(resp){
                response.sendRedirect("mensaje2.jsp?mens='Su correo ha sido cambiado correctamente'");
            }else{
                response.sendRedirect("mensaje2.jsp?mens='Error al cambiar su correo electronico'");
            }
        }else{
            response.sendRedirect("mensaje2.jsp?mens='Error el password no es correcta'");
        }
    }
    
    private void DarBajaUsuario(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException { 
        Usuario usu = new Usuario();
        usu.setCodigoUsuario(request.getParameter("codigoU"));
        
        boolean resp = Usuario_DB.DarDeBajaUsuario(usu);
        if(resp){
            response.sendRedirect("mensaje.jsp?mens='El usuario "+usu.getCodigoUsuario()+" ha sido inhabilitado correctamente'");
        }else{
            response.sendRedirect("mensaje.jsp?mens='Error al eliminar el usuario'");
        }
    }
    
    private void DarAltaUsuario(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException { 
        Usuario usu = new Usuario();
        usu.setCodigoUsuario(request.getParameter("codigoU"));
        
        boolean resp = Usuario_DB.DarDeAltaUsuario(usu);
        if(resp){
            response.sendRedirect("mensaje.jsp?mens='El usuario "+usu.getCodigoUsuario()+" acaba de ser habilitado satisfactoriamente'");
        }else{
            response.sendRedirect("mensaje.jsp?mens='Error al recuperar el usuario'");
        }
    }
    
    
    private void Logout(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        HttpSession session = request.getSession();
        session.invalidate();
        response.sendRedirect("Catalogo.jsp");
    }
    
    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}
