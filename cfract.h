/*Use this, copy and modify under GPLv3 :)
 * 
 */
#include <iostream> 

int _FRACT[4] = {0,0,0,0};


int fract(double numerator, double denominator)
{
	if (numerator != denominator)
	{
		std::cout << numerator << "/" << denominator; 
	}
	
	else
	{
		std::cout << 1;
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
			std::cout << 1;
		}	

		else 
		{
			std::cout << addition_numerator << "/" << addition_denominator;
			
			if (_FRACT[0]==0)
			{
			_FRACT[0] = addition_numerator;
			_FRACT[1] = addition_denominator;
			return  _FRACT; //I'm sure < - it's good! :)
			}
			else
			{
			  _FRACT[2] =  addition_numerator;
			_FRACT[3] = addition_denominator;
			  return  (_FRACT)+2; //I'm sure < - it's good! :)
			}
			
		}
	}
	
	
	else if (numerator_1 == numerator_2 and denominator_1 != denominator_2)
	{
		double addition_numerator = numerator_1 * denominator_2 + denominator_1 * numerator_2;
		double addition_denominator = denominator_1 * denominator_2;

		if (addition_numerator == addition_denominator)
		{	
			std::cout << 1;
		}	

		else 
		{
			std::cout << addition_numerator << "/" << addition_denominator;
			
			if (_FRACT[0]==0)
			{
			_FRACT[0] = addition_numerator;
			_FRACT[1] = addition_denominator;
			return  _FRACT; //I'm sure < - it's good! :)
			}
			else
			{
			  _FRACT[2] =  addition_numerator;
			_FRACT[3] = addition_denominator;
			  return  (_FRACT)+2; //I'm sure < - it's good! :)
			}
		}
	}
  
  
  
  
	//WSPÓLNE MIANOWNIKI
	else if (denominator_1 == denominator_2)
	{	if (numerator_1 + numerator_2 != denominator_1)
		{
			std::cout << numerator_1 + numerator_2 << "/" << denominator_1;
			
			if (_FRACT[0]==0)
			{
			_FRACT[0] = numerator_1 + numerator_2 ;
			_FRACT[1] = denominator_1;
			return  _FRACT; //I'm sure < - it's good! :)
			}
			else
			{
			  _FRACT[2] = numerator_1 + numerator_2 ;
			_FRACT[3] = denominator_1;
			  return  (_FRACT)+2; //I'm sure < - it's good! :)
			}
		}
		else
		{
			std::cout << 1;
			//return 1;

		}
	}
	

}

int addfract(int* fract, int* fract2)
{
addfract(*fract, fract[1], *fract2, fract2[1]);
//return 0; 
}





int subtrfract(double numerator_1, double denominator_1, double numerator_2, double denominator_2)
{
	if (denominator_1 != denominator_2)
	{
		
		double subtraction_numerator =  numerator_1 * denominator_2 - numerator_2 * denominator_1;
		double subtraction_denominator = denominator_1 * denominator_2;
		std::cout << subtraction_numerator << "/" << subtraction_denominator;

	}

	
	else if (denominator_1 == denominator_2)
	{
		if (numerator_1 != numerator_2 and numerator_1 - numerator_2 != denominator_1)
		{
			std::cout << numerator_1-numerator_2 << "/" << denominator_1;
		}
	
		else if (numerator_1 - numerator_2 == denominator_1 and denominator_1 > 0)
		{
			std::cout << 1;
		}

		else
		{
			std::cout << 0;
		}

	}
  return 0;
	
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
  return 0;

}




//division of fractions

int divfract(double numerator_1, double denominator_1, double numerator_2, double denominator_2)
{
	double division_numerator = numerator_1 * denominator_2;
	double division_denominator = denominator_1 * numerator_2;
	std::cout << division_numerator << "/" << division_denominator;
  return 0;

}

