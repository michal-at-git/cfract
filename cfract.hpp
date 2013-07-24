#include <iostream>

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

int main()
{
 fract pierwszy(3,4);
 fract drugi(1,4); 

 pierwszy = pierwszy + drugi;
 std::cout << pierwszy.numerator << "|" << pierwszy.denominator << std::endl;
}
