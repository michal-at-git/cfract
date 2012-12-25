/*Use this, copy and modify under GPLv3 :)
 * 
 */
#include <iostream> 

int fraction(double numerator, double denominator)
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


int addition_fractions(double numerator_1, double denominator_1, double numerator_2, double denominator_2)
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
		}
	}
	//WSPÓLNE MIANOWNIKI
	else if (denominator_1 == denominator_2)
	{	if (numerator_1 + numerator_2 != denominator_1)
		{
			std::cout << numerator_1 + numerator_2 << "/" << denominator_1;
		}
		else
		{
			std::cout << 1;

		}
	}
	
return 0;

}

int subtraction_fractions(double numerator_1, double denominator_1, double numerator_2, double denominator_2)
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
int multiplication_fractions(double numerator_1, double denominator_1, double numerator_2, double denominator_2)
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

int division_fractions(double numerator_1, double denominator_1, double numerator_2, double denominator_2)
{
	double division_numerator = numerator_1 * denominator_2;
	double division_denominator = denominator_1 * numerator_2;
	std::cout << division_numerator << "/" << division_denominator;
  return 0;

}


