
using System;
using System.IO;
using

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

      public void exercise2(){

        const string path = @"c:\temp\textfile.txt";

        if(File.Exists(path)){

          var text = File.ReadAllText(path);
          var words = text.split(' ');
          int wordSize = 0;
          string longestWord = "";

          foreach(string word in words){
            if(word.Length > wordSize){}
              longestWord = word;
              wordSize = word.Length;
            }
          }

          Console.WriteLine("Longest word is: " + longestWord);

        }else{

          Console.WriteLine("File does not exist");
        }



    }
  }
}
