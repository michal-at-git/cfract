#ifndef CFRACT_H
#define CFRACT_H
#include <iostream>
#include "gcd.h" //gcd library required: https://github.com/michal-at-git/gcd/blob/master/gcd.h
/*Use this, copy and modify under GPLv3 :)
 * 
 */
int _FRACT[6] = {0,0,0,0,0};
int * _CFADR;

void _CFMEM(int num, int den)
{
int euk = 0;

	if (num > 1 && den > 1 && num != den) 
	{
	  //std::cout << "SC>in:"<< num << "|" << den << "\n";
	euk = gcd(num, den);	 
	//std::cout << "SC>out:"<< num << "|" << den << "\n";
	  num /= euk;
	  den /= euk;
	}
		
		
	if (_FRACT[0]==0 && _FRACT[1]==0 && _FRACT[2]==0 &&  _FRACT[3]==0 && _FRACT[4]==0 && _FRACT[5]==0)
	{
	_FRACT[0] = num;
	_FRACT[1] = den;
	  _CFADR =_FRACT; 
	}
	else if ( (_FRACT[0]!=0 && _FRACT[1]!=0) && _FRACT[2]==0 &&  _FRACT[3]==0 && _FRACT[4]==0 && _FRACT[5]==0 /*_FRACT[0]!=0 && _FRACT[2]==0 && _FRACT[4]==0*/ )
	{
			  
	_FRACT[2] =  num;
	_FRACT[3] = den;
	_CFADR = (_FRACT)+2; 
	}
	else if ((_FRACT[0]!=0 && _FRACT[1]!=0) && (_FRACT[2] != 0 &&  _FRACT[3] !=0) && _FRACT[4]==0 && _FRACT[5]==0 /*_FRACT[0]!=0 && _FRACT[2]!=0 && _FRACT[4]==0 */)
	{	  
	_FRACT[4] = num;
	_FRACT[5] = den;
	_CFADR = (_FRACT)+4; 
	}
	else if ((_FRACT[0]!=0 && _FRACT[1]!=0) && (_FRACT[2] != 0 &&  _FRACT[3] !=0) && (_FRACT[4]!=0 && _FRACT[5]!=0) /*_FRACT[0]!=0 && _FRACT[2]!=0 && _FRACT[4]!=0*/ )
	{
	_FRACT[0]=0;
	_FRACT[1]=0;
	_FRACT[2]=0;
	_FRACT[3]=0;
	_FRACT[4]=0;
	_FRACT[5]=0;
	_FRACT[0] = num;
	_FRACT[1] = den;
	_CFADR = _FRACT; 
	}
	else
	{
	std::cout << "memory error\n";
	} 
	/* new display method */
	if (num == den) 
	{
	std::cout << "1\n";
	}
	else 
	{
	std::cout << "\n" << num << "\n-\n" << den << "\n";
	}
}


int* fract(int numerator, int denominator)
{
  int singlfract[2];
	if (numerator != denominator)
	{
		std::cout << numerator << "/" << denominator << "\n"; 
		singlfract[0] = numerator;
		singlfract[1] = denominator;
	}
	
	else
	{
		std::cout << 1 << "\n";
		singlfract[0] = 1;
		singlfract[1] = 1;
	}
	
	_CFADR = singlfract;
  return _CFADR;
}

void fract(int* fraction)
{
  fract(*fraction, fraction[1]);
}

// ADDITION!!!

int* addfract(int numerator_1, int denominator_1, int numerator_2, int denominator_2)
{


  if (numerator_1 != numerator_2 and denominator_1 != denominator_2)
	{
		int addition_numerator = numerator_1 * denominator_2 + denominator_1 * numerator_2;
		int addition_denominator = denominator_1 * denominator_2;

		if (addition_numerator == addition_denominator)
		{	//fract = 1
			_CFMEM(1, 1);
		
		}	

		else 
		{
		    _CFMEM(addition_numerator, addition_denominator);			
		}
	}
	
	else if (numerator_1 == numerator_2 and denominator_1 != denominator_2)
	{
		int addition_numerator = numerator_1 * denominator_2 + denominator_1 * numerator_2;
		int addition_denominator = denominator_1 * denominator_2;

		if (addition_numerator == addition_denominator)
		{
			_CFMEM(1, 1);	
		}	

		else 
		{
			_CFMEM(addition_numerator, addition_denominator);
		}
	}
  
  
  
  
	//WSPÓLNE MIANOWNIKI
	else if (denominator_1 == denominator_2)
	{	if (numerator_1 + numerator_2 != denominator_1)
		{			
			_CFMEM(numerator_1 + numerator_2, denominator_1);
			
		}
		else
		{
			_CFMEM(1, 1);
		}
	}
	
return _CFADR;
}

void addfract(int* fract, int* fract2)
{
addfract(*fract, fract[1], *fract2, fract2[1]);
}





int* subfract(int numerator_1, int denominator_1, int numerator_2, int denominator_2)
{
	if (denominator_1 != denominator_2)
	{
		
		int subtraction_numerator =  numerator_1 * denominator_2 - numerator_2 * denominator_1;
		int subtraction_denominator = denominator_1 * denominator_2;
		
			_CFMEM(subtraction_numerator, subtraction_denominator);
		
	}

	
	else if (denominator_1 == denominator_2)
	{
		if (numerator_1 != numerator_2 and numerator_1 - numerator_2 != denominator_1)
		{
			_CFMEM(numerator_1-numerator_2, denominator_1);
			
		}
	
		else if (numerator_1 - numerator_2 == denominator_1 and denominator_1 > 0)
		{
			_CFMEM(1, 1);
		}

		else
		{	
			_CFMEM(0, 1);
		}

	}

return _CFADR;

}

void subfract(int* fract, int* fract2)
{
  subfract(*fract, fract[1], *fract2, fract2[2]);
}




//multiplication of fractions 
int* multifract(int numerator_1, int denominator_1, int numerator_2, int denominator_2)
{
	if (numerator_1 == denominator_1 and numerator_2 != denominator_2)
	{
		  _CFMEM(numerator_2, denominator_2);
	}


	else if (numerator_1 != denominator_1 and numerator_2 == denominator_2)
	{
		_CFMEM(numerator_1, denominator_1);
	}


	else if (numerator_1 == numerator_1 and numerator_2 == denominator_2)
	{
	      _CFMEM(1, 1);
	}

	else if ((numerator_1 * numerator_2) == 0 || (denominator_1 * denominator_2) == 0 )
	{
	  _CFMEM(1, 1);
	}
	else
	{
	int multiplication_numerator = numerator_1 * numerator_2;
	int multiplication_denominator = denominator_1 * denominator_2;
	_CFMEM(multiplication_numerator, multiplication_denominator);
	}

	
return _CFADR;
	
}



void multifract(int* fract, int* fract2)
{
  multifract(*fract, fract[1], *fract2, fract2[1] );
}


//division of fractions

int* divfract(int num1, int den1, int num2, int den2)
{
	int div_num;
	int div_den;
	
	if (num1 != num2 && den1 == den2)
	{
	 div_num = num1/num2;
	 div_den = den1;
	 _CFMEM(div_num, div_den);
	}
	else if (num1 == num2 && den1 == den2) 
	{
	  _CFMEM(1,1);
	}
	else if (num1 == 0 || num2 == 0 || den1 == 0 || den2 == 0) 
	{
	  std::cout << "[WARNING!]: Division by zero!!!\n";
	  _CFMEM(0,1);
	}
	else
	{
	  div_num = (num1 * den2) / (num2 * den1);
	  div_den = den1 * den2;
	  _CFMEM(div_num, div_den);
	}
	return _CFADR;
}

void divfract(int* fract, int* fract2)
{
  divfract(*fract, fract[1], *fract2, fract2[1]);
}
//TEMPORARY FUNCTION NAME!!!
double frtodec(int numerator, int denominator) 
{
  double num = (double) numerator;
  double den = (double) denominator;
  double dec = num / den;
  std::cout << dec << "\n";
 
  
  return dec;
}
//TEMPORARY FUNCTION NAME!!!
void dectofr(double decimal)
{
  
  int num = 0, den, i = 1, resgcd;
  double partden = decimal; //temporary... 
  
  while (i < 1000)
  {
    
    partden *= 10;


    den = i;
    
        std::cout << "Decimal: " << decimal << "\n";
	
   
  i *= 10;
  }
  num = (int) partden;
  den = i;
  resgcd = gcd(num, den);
 num = num / resgcd;
 den = den / resgcd;
std::cout << num << "|" << den << "\n";
  
//   int tofract = (int) decimal;
//   double tonumerator = (decimal - (double) tofract);
//   int denominator = (int) 1.0 / tonumerator;
//  std::cout << decimal;
//   
//   int numerator = 1 + denominator * tofract;
//   fract( numerator, denominator);
}
#endif