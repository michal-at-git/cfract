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


// under construction!!! whats with 0? in denominator or on sum of numerators?
//[^answ] with zero currently I don't see any problems ;P
//...but later i'll check it better 

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

fract operator* (const fract &fr) {
  
  
  if (this->numerator == this->denominator and fr.numerator != fr.denominator)
	{
		
		  return fract(fr.numerator, fr.denominator);
	}
	
  else if (this->numerator != this->denominator and fr.numerator == fr.denominator) 
  {
		  return fract(this->numerator, this->denominator);
  }
  
  else if (this->numerator == this->denominator and fr.numerator == fr.denominator) 
    return fract(1,1);
    
  
  else {
    return fract(this->numerator*fr.numerator, 
		 this->denominator*fr.denominator);
    
    }
  } 
  
fract operator* (const int &fr)  {
  return fract(this->numerator*fr, this -> denominator);
}
  
  fract operator= (const fract &fr) {
    return fract(this -> numerator = fr.numerator, this->denominator = fr.denominator);
    
  }
};