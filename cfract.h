#ifndef CFRACT_H
#define CFRACT_H
/*Use this, copy and modify under GPLv3 :)
 * 
 */
#include <iostream> 

int _FRACT[4] = {0,0,0,0};
int * _CFADR;

void _CFMEM(int num, int den)
{			
			 _FRACT[0]=_FRACT[1]=_FRACT[2]=_FRACT[3] = 0;

			if (_FRACT[0]==0 && _FRACT[2]==0)
			{
			_FRACT[0] = num;
			_FRACT[1] = den;
			  _CFADR =_FRACT; 
			}
			else if (_FRACT[0]!=0 && _FRACT[2]==0)
			{
			  
			  _FRACT[2] =  num;
			_FRACT[3] = den;
			  _CFADR = (_FRACT)+2; 
			}
			else if (_FRACT[0]!=0 && _FRACT[2]!=0)
			{
			 _FRACT[0]=_FRACT[1]=_FRACT[2]=_FRACT[3] = 0;
			_FRACT[0] = num;
			_FRACT[1] = den;
			_CFADR = _FRACT; 
			}
			else
			{
			  std::cout << "memory error\n";
			}
			
}


int fract(double numerator, double denominator)
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
		double addition_numerator = numerator_1 * denominator_2 + denominator_1 * numerator_2;
		double addition_denominator = denominator_1 * denominator_2;

		if (addition_numerator == addition_denominator)
		{	
			std::cout << 1 << "\n";
			
			_CFMEM(1, 1);
			return _CFADR;
			
		}	

		else 
		{
			std::cout << addition_numerator << "/" << addition_denominator << "\n";
			
			_CFMEM(addition_numerator, addition_denominator);
			return _CFADR;
			
		}
	}
	
	
	else if (numerator_1 == numerator_2 and denominator_1 != denominator_2)
	{
		double addition_numerator = numerator_1 * denominator_2 + denominator_1 * numerator_2;
		double addition_denominator = denominator_1 * denominator_2;

		if (addition_numerator == addition_denominator)
		{	
			std::cout << 1 << "\n";
		
			_CFMEM(1, 1);
			return _CFADR;
			
		}	

		else 
		{
			std::cout << addition_numerator << "/" << addition_denominator << "\n";
			
			_CFMEM(addition_numerator, addition_denominator);
			return _CFADR;
		}
	}
  
  
  
  
	//WSPÓLNE MIANOWNIKI
	else if (denominator_1 == denominator_2)
	{	if (numerator_1 + numerator_2 != denominator_1)
		{
			std::cout << numerator_1 + numerator_2 << "/" << denominator_1 << "\n";
			
			_CFMEM(numerator_1 + numerator_2, denominator_1);
			return _CFADR;
			
		}
		else
		{
			std::cout << 1 << "\n";
			_CFMEM(1, 1);
			return _CFADR;
			

		}
	}
	

}

void addfract(int* fract, int* fract2)
{
std::cout << *fract << fract[1] << " }{ " << *fract2 << fract2[1] << "\n";
addfract(*fract, fract[1], *fract2, fract2[1]);
//return 0; 
}





int* subfract(double numerator_1, double denominator_1, double numerator_2, double denominator_2)
{
	if (denominator_1 != denominator_2)
	{
		
		double subtraction_numerator =  numerator_1 * denominator_2 - numerator_2 * denominator_1;
		double subtraction_denominator = denominator_1 * denominator_2;
		std::cout << subtraction_numerator << "/" << subtraction_denominator << "\n";
		
			_CFMEM(subtraction_numerator, subtraction_denominator);
			return _CFADR;
		

	}

	
	else if (denominator_1 == denominator_2)
	{
		if (numerator_1 != numerator_2 and numerator_1 - numerator_2 != denominator_1)
		{
			std::cout << numerator_1-numerator_2 << "/" << denominator_1 << "\n";
			
			_CFMEM(numerator_1-numerator_2, denominator_1);
			return _CFADR;
			
			
		}
	
		else if (numerator_1 - numerator_2 == denominator_1 and denominator_1 > 0)
		{
			std::cout << 1 << "\n";
			_CFMEM(1, 1);
			return _CFADR;
		}

		else
		{	// do something with this... ;/ hmmm... maybe _CFMEM(0, denominator_1) and update _CFMEM? 
			std::cout << 0 << "\n";
		}

	}
return 0;	
}

void subfract(int* fract, int* fract2)
{
  subfract(*fract, fract[1], *fract2, fract[2]);
}




//multiplication of fractions 
int multiplfract(double numerator_1, double denominator_1, double numerator_2, double denominator_2)
{
	if (numerator_1 == denominator_1 and numerator_2 != denominator_2)
	{
		std::cout << numerator_2 << "/" << denominator_2;
	}


	else if (numerator_1 != denominator_1 and numerator_2 == denominator_2)
	{
		std::cout << numerator_1 << "/" << denominator_1;	
	}


	else if (numerator_1 == numerator_1 and numerator_2 == denominator_2)
	{
		std::cout << "1";
	}


	else
	{
	double multiplication_numerator = numerator_1 * numerator_2;
	double multiplication_denominator = denominator_1 * denominator_2;
	std::cout << multiplication_numerator << "/" << multiplication_denominator;
	}

}




//division of fractions

int divfract(double numerator_1, double denominator_1, double numerator_2, double denominator_2)
{
	double division_numerator = numerator_1 * denominator_2;
	double division_denominator = denominator_1 * numerator_2;
	std::cout << division_numerator << "/" << division_denominator;
  return 0;

}

#endif
