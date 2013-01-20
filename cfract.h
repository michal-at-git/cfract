#ifndef CFRACT_H
#define CFRACT_H
#include <iostream>
#include "gcd.h" //gcd library required: https://github.com/michal-at-git/gcd/blob/master/gcd.h
/*Use this, copy and modify under GPLv3 :)
 * 
 */
int _FRACT[6] = {0,0,0,0};
int * _CFADR;

extern void _CFMEM(int num, int den)
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


int fract(int numerator, int denominator)
{
	if (numerator != denominator)
	{
		std::cout << numerator << "/" << denominator << "\n"; 
	}
	
	else
	{
		std::cout << 1 << "\n";
	}
  return 0;
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
			std::cout << 1 << "\n";
			_CFMEM(1, 1);
		}
	}
	
return _CFADR;
}

void addfract(int* fract, int* fract2)
{
//std::cout << *fract << fract[1] << " }{ " << *fract2 << fract2[1] << "\n";
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
  subfract(*fract, fract[1], *fract2, fract[2]);
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
		std::cout << "1";
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

int* divfract(int numerator_1, int denominator_1, int numerator_2, int denominator_2)
{
	if (numerator_1 == 0 || numerator_2 == 0 || denominator_1 == 0 || denominator_2 == 0) std::cout << "[WARNING!]: Division by zero!!!\n";
	int division_numerator = numerator_1 * denominator_2;
	int division_denominator = denominator_1 * numerator_2;
	_CFMEM(division_numerator, division_denominator);
	return _CFADR;

}

void divfract (int* fract, int* fract2)
{
  divfract (*fract, fract[1], *fract2, fract[1]);
}

#endif