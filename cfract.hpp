#include <iostream>
#include <cmath>
#include "gcd.h"

class fract {
  
public:
  int numerator;
  int denominator;
  
  fract(int num, int den){
    this -> numerator = num;
    this -> denominator = den;
  }
  fract (double n) {
    int temp = (int) (n*1000);
    int i = 3;
    while(temp%10 == 0 && i >0) 
    {	
      temp /= 10;
       --i;
    }
    int num = temp;
    int den = pow(10,i);
    this->numerator = num/gcd(num, den);
    this->denominator = den/gcd(num, den);
  }
  
  fract(int n) {
   this->numerator = n;
   this->denominator = 1;
  }
//addition  
  fract operator+ (const fract &fr) {

    if(this -> denominator != fr.denominator) {  
      int res_num = this -> numerator * fr.denominator + fr.numerator * this -> denominator;
      int res_den = this -> denominator * fr.denominator;
      
      if (res_num == res_den) return fract(1, 1);
      
      else {	
	return fract(res_num/gcd(res_num, res_den),
	res_den/gcd(res_num, res_den));
      }
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
      
      else return fract(res_num/gcd(res_num, res_den),
		     res_den/gcd(res_num, res_den));   
      
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
    
  
  else {int res_num = this->numerator*fr.numerator;
      int res_den = this->denominator*fr.denominator;
    return fract(res_num/gcd(res_num, res_den),
		 res_den/gcd(res_num, res_den));
    
    }
  } 
  
fract operator* (const int &fr)  {
  return fract(this->numerator*fr, this -> denominator);
}
  
  fract operator= (const fract &fr) {
    return fract(this -> numerator = fr.numerator, this->denominator = fr.denominator);
    
  }

fract operator/ (const fract &fr) {
  //THERE'S NO PRECISION HERE:
  if(this->numerator != fr.numerator and this->denominator == fr.denominator
    and (this->numerator != 0 or fr.numerator != 0 or this->denominator != 0 or fr.denominator != 0)) {
    return fract(this -> numerator / fr.numerator,this->denominator);
  }
  
  
  else if (this->numerator == fr.numerator and this->denominator==fr.denominator 
    and (this->numerator != 0 or fr.numerator != 0 or this->denominator != 0 or fr.denominator != 0)) 
    return fract(1,1);
  
  
  else if(this->numerator == 0 or fr.numerator == 0 or this->denominator== 0 or fr.denominator == 0) {
    std::cerr << "[cfract] ERROR: Division by zero!\n";
    return fract(0,1);
  }
  
  
  else{
    int res_num = this->numerator * fr.denominator;
    int res_den = this->denominator * fr.numerator;
    
    return fract(res_num/gcd(res_num, res_den),
		 res_den/gcd(res_num, res_den)
		);
  }
}

fract operator/ (const int &fr) {
    int res_num = 0, res_den = this->denominator;
    
    if(fr > 0 && (this -> numerator % fr) == 0 ) res_num = this->numerator / fr;
    else if (fr > 0 && (this-> numerator % fr) > 0) {
      res_num = this->numerator;
      res_den = fr * this->denominator;
    }
    else { 
      std::cerr << "[cfract] ERROR: Division by zero!\n";
      //numerator defined as before
    }
      return fract(res_num/gcd(res_num, res_den),
		 res_den/gcd(res_num, res_den)
		);
  }

  
};