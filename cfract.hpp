#include <iostream>
#include "odlcompat_cfract.hpp"


class fract {
  
public:
  int numerator;
  int denominator;
  
  fract(int num, int den){
    this -> numerator = num;
    this -> denominator = den;
  }
  fract operator+ (const fract &fr) {
    return fract(this -> numerator + fr.numerator, this->denominator);
    
  }
  
  fract operator= (const fract &fr) {
    return fract(this -> numerator = fr.numerator, this->denominator = fr.denominator);
    
  }
};

//control for tests
// int main()
// {
//  fract first(1,10);
//  fract second(2,10); 
//  fract third(5,10);
//  
//  first = first + second + third;
//  std::cout << first.numerator << "|" << second.denominator << std::endl;
// }
