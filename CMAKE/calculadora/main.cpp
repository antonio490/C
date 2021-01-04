
#include <iostream>

#include "suma.h"
#include "division.h"
#include "resultado.h"

main (){

  float num1, num2, rsuma, rdiv;

  std::cout<< "Enter first number\t";
  std::cin>> num1;
  std::cout<< "Enter second number\t";
  std::cin>> num2;

  rsuma = suma(num1, num2);
  rdiv = division(num1, num2);

  resultado("Suma", rsuma);
  resultado("Division", rdiv);
}
