
package Clase;

/**
 *
 * @author Manuel CAOS ESCOM-IPN
 */
public class DetalleVenta {
    private String numero;
    private String CodigoVenta;
    private String codigoProducto;
    private String NombreProducto;
    private double Precio;
    private double Cantidad;
    private double Descuento;
    private double SubTotal;
    private Producto Producto;
    private Venta Venta;

    public DetalleVenta() {
    }

    public DetalleVenta(String numero, String CodigoVenta, String codigoProducto, String NombreProducto, double Precio, double Cantidad, double Descuento, double SubTotal, Producto Producto, Venta Venta) {
        this.numero = numero;
        this.CodigoVenta = CodigoVenta;
        this.codigoProducto = codigoProducto;
        this.NombreProducto = NombreProducto;
        this.Precio = Precio;
        this.Cantidad = Cantidad;
        this.Descuento = Descuento;
        this.SubTotal = SubTotal;
        this.Producto = Producto;
        this.Venta = Venta;
    }

    public String getNumero() {
        return numero;
    }

    public void setNumero(String numero) {
        this.numero = numero;
    }

    public String getCodigoVenta() {
        return CodigoVenta;
    }

    public void setCodigoVenta(String CodigoVenta) {
        this.CodigoVenta = CodigoVenta;
    }

    public String getCodigoProducto() {
        return codigoProducto;
    }

    public void setCodigoProducto(String codigoProducto) {
        this.codigoProducto = codigoProducto;
    }

    public String getNombreProducto() {
        return NombreProducto;
    }

    public void setNombreProducto(String NombreProducto) {
        this.NombreProducto = NombreProducto;
    }

    public double getPrecio() {
        return Precio;
    }

    public void setPrecio(double Precio) {
        this.Precio = Precio;
    }

    public double getCantidad() {
        return Cantidad;
    }

    public void setCantidad(double Cantidad) {
        this.Cantidad = Cantidad;
    }

    public double getDescuento() {
        return Descuento;
    }

    public void setDescuento(double Descuento) {
        this.Descuento = Descuento;
    }

    public double getSubTotal() {
        return SubTotal;
    }

    public void setSubTotal(double SubTotal) {
        this.SubTotal = SubTotal;
    }

    public Producto getProducto() {
        return Producto;
    }

    public void setProducto(Producto Producto) {
        this.Producto = Producto;
    }

    public Venta getVenta() {
        return Venta;
    }

    public void setVenta(Venta Venta) {
        this.Venta = Venta;
    }

    
    
}
