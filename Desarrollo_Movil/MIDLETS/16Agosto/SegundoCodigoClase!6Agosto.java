//SegundoCodigoClase16Agosto

class Lienzo extends Canvas{
    public void paint(Graphics g){
        g.setColor(255,255,255);
        g.fillRect(0,0,getWidth(),getHeight());
        g.setColor(255,0,0);
        g.drawLine(20,30,80,120);
        g.fillRect(40,40,25,25);
        //g.drawRect(x,y,x,y);
        //g.drawArc(x,y,r1,r2,O1,O2);
    }
}