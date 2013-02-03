#ifndef CFRACT_H
#define CFRACT_H
#include <iostream>
#include "gcd.h" //gcd library required: https://github.com/michal-at-git/gcd/blob/master/gcd.h
/*Use this, copy and modify under GPLv3 :)
 * 
 */
int _FRACT[6] = {0,0,0,0,0,0};
int * _CFADR;

void _CFMEM(int num, int den)
{
int euk = 0;
	  euk = gcd(num, den);	 
	 if (euk > 1)
	 {
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
	_FRACT[0]= 0;
	_FRACT[1]= 0;
	_FRACT[2]= 0;
	_FRACT[3]= 0;
	_FRACT[4]= 0;
	_FRACT[5]= 0;
	_FRACT[0]= num;
	_FRACT[1]= den;
	_CFADR = _FRACT; 
	}
	else
	{
	std::cout << "memory error\n";
	} 
	/* new display method */
	if (num == den && num > 0) 
	{
	std::cout << "1\n";
	}
	else 
	{
	std::cout << "\n" << num << "\n-\n" << den << "\n";
	}
// 	std::cout << "fract " << "[0: " << _FRACT[0] << "]" << "[1: " << _FRACT[1] << "]" << "[2: " << _FRACT[2] << "]"
// 	<< "[3: " << _FRACT[3] << "]" << "[4: " << _FRACT[4] << "]" << "[5: " << _FRACT[5] << "]" << "\n";
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

int* addfract(int num1, int den1, int num2, int den2)
{


  if (num1 != num2 and den1 != den2)
	{
		int add_num = num1 * den2 + den1 * num2;
		int add_den = den1 * den2;

		if (add_num == add_den && add_num > 0)
		{	//fract = 1
			_CFMEM(1, 1);
		
		}	

		else 
		{
		    _CFMEM(add_num, add_den);			
		}
	}
	
	else if (num1 == num2 and den1 != den2)
	{
		int add_num = num1 * den2 + den1 * num2;
		int add_den = den1 * den2;

		if (add_num == add_den && add_num > 0)
		{
			_CFMEM(1, 1);	
		}	

		else 
		{
			_CFMEM(add_num, add_den);
		}
	}
  
  
  
  
	//WSPÓLNE MIANOWNIKI
	else if (den1 == den2)
	{	if (num1 + num2 != den1)
		{			
			_CFMEM(num1 + num2, den1);
			
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
  if (fract[1] > 0 && fract2[1] >0) addfract(*fract, fract[1], *fract2, fract2[1]);
}





int* subfract(int num1, int den1, int num2, int den2)
{
	if (den1 != den2)
	{
		
		int subfract_num =  num1 * den2 - num2 * den1;
		int subfract_den = den1 * den2;
		
			_CFMEM(subfract_num, subfract_den);
		
	}

	
	else if (den1 == den2)
	{
		if (num1 != num2 and num1 - num2 != den1)
		{
			_CFMEM(num1-num2, den1);
			
		}
	
		else if (num1 - num2 == den1 and den1 > 0)
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
 if (fract[1] > 0 && fract2[1] >0) subfract(*fract, fract[1], *fract2, fract2[2]);
}




//multiplication of fractions 
int* multifract(int num1, int den1, int num2, int den2)
{
	if (num1 == den1 and num2 != den2)
	{
		  _CFMEM(num2, den2);
	}


	else if (num1 != den1 and num2 == den2)
	{
		_CFMEM(num1, den1);
	}


	else if (num1 == num1 and num2 == den2)
	{
	      _CFMEM(1, 1);
	}

	else if ((num1 * num2) == 0 || (den1 * den2) == 0 )
	{
	  _CFMEM(1, 1);
	}
	else
	{
	int multi_num = num1 * num2;
	int multi_den = den1 * den2;
	_CFMEM(multi_num, multi_den);
	}

	
return _CFADR;
	
}



void multifract(int* fract, int* fract2)
{
 if (fract[1] > 0 && fract2[1] >0) multifract(*fract, fract[1], *fract2, fract2[1] );
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
 if (fract[1] > 0 && fract2[1] >0) divfract(*fract, fract[1], *fract2, fract2[1]);
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
 int num = 0;
  int den, i = 1, resgcd;
  double partden = decimal; //temporary... 
  
  while (i < 100000) // maximal precision 0.0000x
  {partden *= 10;
   den = i;
  i *= 10;
  }
 num = (int) partden;
 den = i;
 
 resgcd = gcd(num, den);
 if (resgcd >1)
 {
 num = num / resgcd;
 den = den / resgcd;
 }
fract(num, den);
}
#endif