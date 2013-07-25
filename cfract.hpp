#include <iostream>
//#include "oldcompat_cfract.hpp"  #troubles with names!!!


class fract {
  
public:
  int numerator;
  int denominator;
  
  fract(int num, int den){
    this -> numerator = num;
    this -> denominator = den;
  }
  
  
//addition  
  fract operator+ (const fract &fr) {

    if(this -> denominator != fr.denominator) {  
      int res_num = this -> numerator * fr.denominator + fr.numerator * this -> denominator;
      int res_den = this -> denominator * fr.denominator;
      
      if (res_num == res_den) return fract(1, 1);
      
      else return fract(res_num,res_den);      
    }
    else { //if the same numerators 
      if(this-> numerator + fr.numerator != this -> denominator )
	return fract(this -> numerator + fr.numerator, this -> denominator);
      else return fract(1,1);
      
    }

  }
 
 
    /* IT WASNT GOOD IDEA*/
//     else if(this -> numerator == fr.numerator and this -> denominator != fr.denominator)
//     {
//       int res_num = this -> numerator * fr.denominator + fr.numerator * this -> denominator;
//       int res_den = denominator * fr.denominator;
//       
//       if (res_num == res_den && res_num > 0)
//       {
// 	return fract(1,1);
//       }
//       else return fract(res_num, res_den);
//     }



// under construction!!! whats with 0? in denominator or on sum of numerators?

// important: GCD() :)


fract operator+ (const int &fr) {

 
      int res_num = this -> numerator + fr * this -> denominator;
      int res_den = this -> denominator;
      
      if (res_num == res_den) return fract(1, 1);
      
      else return fract(res_num,res_den);      
  }


    
  
//subtraction

  fract operator- (const fract &fr) {
    if(this -> denominator != fr.denominator) {  
      int res_num =  (this -> numerator * fr.denominator)-(fr.numerator * this -> denominator);
      int res_den = this -> denominator * fr.denominator;
      
      if (res_num == res_den) return fract(1, 1);
      
      else return fract(res_num,res_den);      
    }
    else { //if the same numerators 
      if(this-> numerator - fr.numerator != this -> denominator )
	return fract(this -> numerator - fr.numerator, this -> denominator);
      else return fract(1,1);
      
    }        
  }
  

fract operator- (const int &fr) {

 
      int res_num = this -> numerator - fr * this -> denominator;
      int res_den = this -> denominator;
      
      if (res_num == res_den) return fract(1, 1);
      
      else return fract(res_num,res_den);      
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
