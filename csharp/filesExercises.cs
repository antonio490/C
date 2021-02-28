
using System;
using System.IO;

namespace CSharpFundamentals{

  public class exercises{

    public void exercise1(){

      const string path = @"c:\temp\textfile.txt";

      if(File.Exists(path)){

        var text = File.ReadAllText(path);
        var words = text.split(' ');
        var count = 0;

        foreach(var word in words)
          count++;
        Console.WriteLine("Total words: " + count);

      }else{

        Console.WriteLine("File does not exist");
      }



    }
  }
}
