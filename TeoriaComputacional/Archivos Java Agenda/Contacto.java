
public class Contacto {
    private String direc;
    private String nombre;
    private String email;
    private int telefono;
    
    public Contacto(){
        direc=nombre=email="";
        telefono=0;
    }
    public Contacto(String d,String n,String e,int t){
        direc=d;
        nombre=n;
        email=e;
        telefono=t;
    }
    public String getDirec(){return direc;};
    public void setDirec(String d){direc=d;};
    
    public String getNombre(){return nombre;};
    public void setNombre(String n){nombre=n;};
    
    public String getEmail(){return email;};
    public void setEmail(String e){email=e;};

    public int getTelefono(){return telefono;};
    public void setTelefono(int t){telefono=t;};
}
