
package Servlet;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import Clase.*;

/**
 *
 * @author Manuel CAOS ESCOM-IPN
 */
public class Servlet_CP extends HttpServlet {

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
            if(accion.equals("insertar")){
                this.RegistrarClaseProducto(request, response);
            }
            if(accion.equals("actualizar")){
                this.ActualizarClaseProducto(request, response); 
            }
            if(accion.equals("eliminar")){
                this.EliminarClaseProducto(request, response); 
            }
            if(accion.equals("recuperar")){
                this.RecuperarClaseProducto(request, response); 
            }
            
        }
    }
    
    private void RegistrarClaseProducto(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException{
        ClaseP cp = new ClaseP();
        cp.setNombreCP(request.getParameter("txtNombre")); 
        
        boolean resp = ClaseP_DB.insertarClaseProducto(cp);
        if(resp){
            response.sendRedirect("mensaje.jsp?mens='Se ha registrado una clase de producto correctamente'");
        }else{
            response.sendRedirect("mensaje.jsp?mens='Error al registrar en la clase producto'"); 
        }
    }
    
    private void ActualizarClaseProducto(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException{
        ClaseP cp = new ClaseP();
        cp.setCodigoCP(request.getParameter("txtCodigo"));
        cp.setNombreCP(request.getParameter("txtNombre")); 
        
        boolean resp = ClaseP_DB.actualizarClaseProducto(cp);
        if(resp){
            response.sendRedirect("mensaje.jsp?mens='Se ha modificado la clase producto "+cp.getCodigoCP()+"'");
        }else{
            response.sendRedirect("mensaje.jsp?mens='Error al actualizar la clase producto'");
        }
    }
    
    private void EliminarClaseProducto(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException{
        ClaseP cp = new ClaseP();
        cp.setCodigoCP(request.getParameter("codigoCP"));
        
        boolean resp = ClaseP_DB.darBajaClaseProducto(cp);
        if(resp){
            response.sendRedirect("mensaje.jsp?mens='Se ha eliminado la clase producto "+cp.getCodigoCP()+"'");
        }else{
            response.sendRedirect("mensaje.jsp?mens='Error al eliminar la clase producto'");
        }
    }
    
    private void RecuperarClaseProducto(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException{
        ClaseP cp = new ClaseP();
        cp.setCodigoCP(request.getParameter("codigoCP"));
        
        boolean resp = ClaseP_DB.darAltaClaseProducto(cp);
        if(resp){
            response.sendRedirect("mensaje.jsp?mens='Se ha recuperado la clase producto "+cp.getCodigoCP()+"'");
        }else{
            response.sendRedirect("mensaje.jsp?mens='Error al recuperar la clase producto'");
        }
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
