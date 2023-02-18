namespace MethodOverriding
{
    class Program
    {
        static void Main(string[] args)
        {
            //var shapes = new List<Shape>();

            var circle = new Circle();
            var rectangle = new Rectangle();

            circle.Draw();
            rectangle.Draw();
            
            //shapes.Add(new Cricle());
            //shapes.Add(new Rectangle());

            //var canvas = new Canvas();
            //canvas.DrawShapes();

        }
    }
}