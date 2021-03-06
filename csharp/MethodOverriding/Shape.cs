
namespace MethodOverriding{

    public class Cirlce : Shape
    {
        public override void Draw()
        {
            //Codigo especifico a la clase Circle
            System.Console.WriteLine("Draw a circle");
        }

    }

    public class Rectangle: Shape
    {
        public override void Draw()
        {
            //Codigo especifico a la clase Rectangle
            System.Console.WriteLine("Draw a rectangle");
        }
    }

    public class Triangle: Shape
    {
        public override void Draw()
        {
            //Codigo especifico a la clase Triangle
            System.Console.WriteLine("Draw a triangle");
        }
    }

    public abstract class Shape{
        public int Width { get; set; }
        public int Height { get; set; }
        public Position Position { get; set; }
        //public ShapeType Type { get; set;}

        public abstract void Draw();
    
    }
}