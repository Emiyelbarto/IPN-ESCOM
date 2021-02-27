
package Clase;
/**
 *
 * @author Manuel CAOS ESCOM-IPN
 */
public class Venta {
    private String CodigoVenta;
    private String CodigoCliente;
    private String Cliente;
    private double Total;
    private String Fecha;

    public Venta() {
    }

    public Venta(String CodigoVenta, String CodigoCliente, String Cliente, double Total, String Fecha) {
        this.CodigoVenta = CodigoVenta;
        this.CodigoCliente = CodigoCliente;
        this.Cliente = Cliente;
        this.Total = Total;
        this.Fecha = Fecha;
    }

    public String getCodigoVenta() {
        return CodigoVenta;
    }

    public void setCodigoVenta(String CodigoVenta) {
        this.CodigoVenta = CodigoVenta;
    }

    public String getCodigoCliente() {
        return CodigoCliente;
    }

    public void setCodigoCliente(String CodigoCliente) {
        this.CodigoCliente = CodigoCliente;
    }

    public String getCliente() {
        return Cliente;
    }

    public void setCliente(String Cliente) {
        this.Cliente = Cliente;
    }

    public double getTotal() {
        return Total;
    }

    public void setTotal(double Total) {
        this.Total = Total;
    }

    public String getFecha() {
        return Fecha;
    }

    public void setFecha(String Fecha) {
        this.Fecha = Fecha;
    }

    
}
