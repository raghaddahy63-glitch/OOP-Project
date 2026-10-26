  package pkgfinal.project;
import javax.swing.JFrame;
public class Art extends JFrame {
    public Art(String name)
    {
        super(name);
        super.setSize(300, 300);
        super.setResizable(false);
        super.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        super.setVisible(true);
    } 
}
 package pkgfinal.project;

public class Circle extends Shape {

    private double radius;

    public Circle(double radius) 
    {
        this.radius = radius;
    }

    public Circle(String color ,double radius)
    {
        super(color);
        this.radius = radius;
    }

    public double getRadius()
    {
        return radius;
    }

    public void setRadius(double radius)
    {
        if(radius>0)
        this.radius = radius;
    }

    @Override
    public String toString()
    {
        return "Circle{" + "radius=" + radius + '}';
    }
    
    @Override
    public double getArea() 
    {
        return radius*radius*Math.PI;
    }

    @Override
    public double getPermiter()
    {
        return 2*radius*Math.PI;
    }

    @Override
    public String howToDraw() 
    {
       return "Draw circle with raduis :"+radius;
    }  
}
 package pkgfinal.project;

public class Cupe extends ThreeDShape{

    private double side;

    public Cupe(double side)
    {
        this.side = side;
    }

    public Cupe( String color,double side) 
    {
        super(color);
        this.side = side;
    }

    public double getSide()
    {
        return side;
    }

    public void setSide(double side)
    {
        if(side>0)
        this.side = side;
    }
    
    @Override
    public double getVolume()
    {
      return side*side *side;   
    }

    @Override
    public double getArea() 
    {
       return 6*side *side;  
    }

    @Override
    public double getPermiter()
    {
        return 12*side *side;  
    }

    @Override
    public String howToDraw()
    {
      return "draw cupe with side : "+side;
    }

    @Override
    public String toString() 
    {
        return "Cupe{" + "side=" + side + '}';
    }    
}
 package pkgfinal.project;
public interface Drawable {
  public String howToDraw(); 
}
[10/26, 11:42 PM] ساره ابو الحسن: package pkgfinal.project;
import java.awt.Graphics;
import java.awt.Color;
import javax.swing.JPanel;
public class Drawer extends JPanel {
    public Shape obj;
    public Drawer(Shape obj) {
        this.obj = obj;
    }
    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        if (obj instanceof Cupe) {
            int side = (int)((Cupe) obj).getSide();
            int offset = side / 3;
            int x1 = 100;
            int y1 = 50;
            int x2 = x1 + offset;
            int y2 = y1 - offset;
            g.setColor(new Color(180, 180, 255));
            g.fillRect(x2, y2, side, side);
            g.setColor(new Color(100, 100, 255));
            g.fillRect(x1, y1, side, side);
            g.setColor(Color.BLACK);
            g.drawRect(x1, y1, side, side);
            g.drawRect(x2, y2, side, side);
            g.drawLine(x1, y1, x2, y2);
            g.drawLine(x1 + side, y1, x2 + side, y2);
            g.drawLine(x1, y1 + side, x2, y2 + side);
            g.drawLine(x1 + side, y1 + side, x2 + side, y2 + side);
        }
        else if (obj instanceof Circle) {
            int radius = (int) ((Circle) obj).getRadius();
            g.setColor(Color.PINK);
            g.fillOval(100, 50, radius, radius);
            g.setColor(Color.BLACK);
            g.drawOval(100, 50, radius, radius);
        }
    }
}
 package pkgfinal.project;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
import javax.swing.JFrame;
public class FinalProject {
    static int count=0;
    public static void main(String[] args) {
        try 
        {
        File output=new File("sumAreas.txt");
        File input =new File("input.txt"); 
        Scanner scan=new Scanner(input);
        int n = scan.nextInt();
        Shape[] array=new Shape[n];
        
            for (int i = 0; i < n; i++) {
               String name =scan.next();
               double size=scan.nextDouble();
               if(name.equals("circle"))
               {
                   array[i]=new Circle(size);
               }
               else if(name.equals("cube"))
               {
                   array[i]=new Cupe(size);
               }
            }
            scan.close();   
              PrintWriter p=new PrintWriter(output);
            for (int i = 0; i < n; i++)
            {
              p.println(array[i].getArea());
            }
            p.close();
            for (int i = 0; i < n; i++)
            {
              Art art=new Art("frame"+i);
              art.add(new Drawer(array[i]));
            }          
        }catch(FileNotFoundException ex)
        {
            System.err.println(ex.getMessage());
        }
    }  
}
 package pkgfinal.project;

import java.util.Date;

public abstract class Shape implements Drawable{
    private Date dateCreated; 
    private String color;

    public Shape() 
    {
        dateCreated = new Date();   
    }

    public Shape(String color) {
        this();
        this.color = color;
    }
     
    public Date GetDateCreated()
    {
        return dateCreated;
    }
    public abstract double getArea();
    public abstract double getPermiter();
    void m()
    {
        System.out.println("s");
       }
}
 package pkgfinal.project;
public abstract class ThreeDShape extends Shape{

    public ThreeDShape()
    {
        
    }

    public ThreeDShape(String color) 
    {
        super(color);
    }
    public abstract double getVolume();
}