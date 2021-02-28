using System;

namepace CSharpFundamentals{

public class exercises{

  public void ex1()
    {

        var num = Console.ReadLine();
        var convertNum = Convert.ToInt32(num);

        if(num > 1 && num < 10){
          Console.Write("Valid");
        }else{
          Console.Write("Invalid");
        }
    }

    public void ex2(){

      Console.Write("Enter first number: ");
      var num1 = Convert.ToInt32(Console.ReadLine());
      Console.Write("Enter second number: ");
      var num2 = Convert.ToInt32(Console.ReadLine());

      var maxNum = (num1 > num2) ? num1 : num2;
      Console.Write("Max number is "+ maxNum);

    }

    public void ex3(){

      Console.Write("Enter width image");
      var width = Convert.ToInt32(Console.ReadLine());
      Console.Write("Enter height image");
      var height = Convert.ToInt32(Console.ReadLine());

      var perspective = (heigh > width) ? ImagePerspective.Portrait : ImagePerspective.Landscape;
      Console.Write("The image is a " + perspective);
    }

    public enum ImagePerspective{
      Landscape,
      Portrait
    }

    public void ex4(){

      Console.Write("Enter the speed limit: ");
      var speedLimit = Convert.ToInt32(Console.Read());

      Console.Write("Enter speed of the car: ");
      var speedCar = Convert.ToInt32(Console.Read());

      if(speedCar < speedLimit)
        Console.Write("OK");
      else{
        const int demeritPointKM = 5;
        int demeritPoints = (speedCar - speedLimit) / demeritPointKM;

        if(demeritPoints < 12)
          Console.Write("Total demerit points: " + demeritPoints);
        else
          Console.Write("License suspended");
    }
  }

}
