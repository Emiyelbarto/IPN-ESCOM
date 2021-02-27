public class Contacto 
{
    private String nombre;
    private int telefono;
	private String email;

    public Contacto()
    {
		this.nombre=null;
		this.email=null;
		this.telefono=0;
    }
    
	public Contacto(String nombre, int telefono, String email) 
	{
        this.nombre = nombre;
		this.email = email;
        this.telefono = telefono;
    }
    
	public void set_nombre(String nomb)
	{        
        this.nombre=nomb.toUpperCase();
    }
	
    public void set_telefono(int telf)
	{
        this.telefono=telf;
    }
	
	public void set_email(String eml)
	{
		this.email=eml;
	}

    public String getNombre() 
	{
        return this.nombre;
    }

    public int getTelefono() 
	{
        return telefono;
    }
	
	public String getEmail()
	{
		return email;
	}
    
    
    
}