
package Clase;

/**
 *
 * @author Manuel CAOS ESCOM-IPN
 */
public class Provincia {
    private int CodigoDepart;
    private int CodigoProv;
    private String NombreProv;

    public Provincia() {
    }

    public Provincia(int CodigoDepart, int CodigoProv, String NombreProv) {
        this.CodigoDepart = CodigoDepart;
        this.CodigoProv = CodigoProv;
        this.NombreProv = NombreProv;
    }

    public int getCodigoDepart() {
        return CodigoDepart;
    }

    public void setCodigoDepart(int CodigoDepart) {
        this.CodigoDepart = CodigoDepart;
    }

    public int getCodigoProv() {
        return CodigoProv;
    }

    public void setCodigoProv(int CodigoProv) {
        this.CodigoProv = CodigoProv;
    }

    public String getNombreProv() {
        return NombreProv;
    }

    public void setNombreProv(String NombreProv) {
        this.NombreProv = NombreProv;
    }


}
