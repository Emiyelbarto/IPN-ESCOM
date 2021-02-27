
package Clase;

/**
 *
 * @author Manuel CAOS ESCOM-IPN
 */
public class Departamento {
    private int CodigoDep;
    private String NombreDep;

    public Departamento() {
    }

    public Departamento(int CodigoDep, String NombreDep) {
        this.CodigoDep = CodigoDep;
        this.NombreDep = NombreDep;
    }

    public int getCodigoDep() {
        return CodigoDep;
    }

    public void setCodigoDep(int CodigoDep) {
        this.CodigoDep = CodigoDep;
    }

    public String getNombreDep() {
        return NombreDep;
    }

    public void setNombreDep(String NombreDep) {
        this.NombreDep = NombreDep;
    }


}
