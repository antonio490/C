
using System;
using System.IO;
using System.Collections.Generic;

namespace CSharpFundamentals
{
    class exercises
    {
        public void exercise1(){
            System.Console.WriteLine("Enter a few numbers separated by a hyphen");
            var input = System.Console.ReadLine();

            var listNums = new List<int>();
            foreach(var num in input.Split("-"))
                listNums.Add(Convert.ToInt32(num));

            var isConsecutive = true;
            for (int i = 1; i < listNums.Count; i++)
            {
                if(listNums[i] != listNums[i-1] + 1){
                    isConsecutive = false;
                    break;
                }
            }

            var message = isConsecutive ? "consecutive" : "not consecutive";
            Console.WriteLine("List of numbers given is " + message);

        }

        public void exercise2(){
            System.Console.WriteLine("Enter a few numbers separated by a hyphen");
            var input = System.Console.ReadLine();

            if(String.IsNullOrWhiteSpace(input))
                return;

            var listNums = new List<int>();
            foreach(var num in input.Split("-"))
                listNums.Add(Convert.ToInt32(num));

            var isDuplicate = false;
            var listDuplicates = new List<int>();


            foreach (var num in listNums)
            {
                if(!duplicates.Contains(num))
                    listDuplicates.Add(num);
                else{
                    isDuplicate = true;
                    break;
                }
            }

            var message = isDuplicate ? "duplicates" : "not duplicates";
            Console.WriteLine("List of numbers given has " + message);

        }

        public void exercise3(){
            System.Console.WriteLine("Enter a time value in the 24-hour time format (e.g. 19:00)");
            var input = System.Console.ReadLine();

            if(String.IsNullOrWhiteSpace(input)){
                Console.WriteLine("Invalid Time");
                return;
            }
            

            var values = input.Split(":");

            if(values.Length != 0){
                Console.WriteLine("Invalid Time");
                return;
            }

            try{
                var hour = Convert.ToInt32(values[0]);
                var minutes = Convert.ToInt32(values[1]);

                if(hour >= 0 && hour <= 23 && minutes >= 0 && minutes <=59)
                    Console.WriteLine("Ok");
                else
                    Console.WriteLine("Invalid Time");
            }
            catch (Exception){
                Console.WriteLine("Invalid Time");
            }


        }

        public void exercise5(){

            Console.WriteLine("Enter a word in english");
            var input = Console.ReadLine().ToLower();

            var vocals = new List<char>(new char[] {'a', 'e', 'i', 'o', 'u'});
            var counter = 0;

            foreach(var character in input){
                if(vocals.Contains(character))
                    counter++;
            }

            Console.WriteLine("The word has " + counter + " vocals");
        }
        
    }
    
}
