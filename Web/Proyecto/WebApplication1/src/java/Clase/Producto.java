
package Clase;

/**
 *
 * @author Manuel CAOS ESCOM-IPN
 */
public class Producto {
    private String CodigoP;
    private String ClaseProducto;
    private String MarcaProducto;
    private String Descripcion;
    private double PrecioP;
    private String ImagenP;
    private String EstadoP;

    public Producto() {
    }

    public Producto(String CodigoP, String ClaseProducto, String MarcaProducto, String Descripcion, double PrecioP, String ImagenP, String EstadoP) {
        this.CodigoP = CodigoP;
        this.ClaseProducto = ClaseProducto;
        this.MarcaProducto = MarcaProducto;
        this.Descripcion = Descripcion;
        this.PrecioP = PrecioP;
        this.ImagenP = ImagenP;
        this.EstadoP = EstadoP;
    }

    public String getCodigoP() {
        return CodigoP;
    }

    public void setCodigoP(String CodigoP) {
        this.CodigoP = CodigoP;
    }

    public String getClaseProducto() {
        return ClaseProducto;
    }

    public void setClaseProducto(String ClaseProducto) {
        this.ClaseProducto = ClaseProducto;
    }

    public String getMarcaProducto() {
        return MarcaProducto;
    }

    public void setMarcaProducto(String MarcaProducto) {
        this.MarcaProducto = MarcaProducto;
    }

    public String getDescripcion() {
        return Descripcion;
    }

    public void setDescripcion(String Descripcion) {
        this.Descripcion = Descripcion;
    }

    public double getPrecioP() {
        return PrecioP;
    }

    public void setPrecioP(double PrecioP) {
        this.PrecioP = PrecioP;
    }

    public String getImagenP() {
        return ImagenP;
    }

    public void setImagenP(String ImagenP) {
        this.ImagenP = ImagenP;
    }

    public String getEstadoP() {
        return EstadoP;
    }

    public void setEstadoP(String EstadoP) {
        this.EstadoP = EstadoP;
    }

    

}
