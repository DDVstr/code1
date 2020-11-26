
#include <iomanip>
#include <iostream>
#include <algorithm>
#include "math.h"
#include <iomanip>




using namespace std;

double min(int *mass, int N)
{
	int min=0; 
	int i = 0; 
	min = mass[0]; 
	for (i = 0; i < N; i++)
	{
		
		 if (mass[i ] < min)
		 {

			 min = mass[i]; 
		 }


	}
	return min;
}

double max(int *mass, int N )
{  
	int max=0; 
	for (int i = 0; i < N; i++)
	{
		if (mass[i]> max)
		{
			max = mass[i];
		}
	}

	return max; 
}

double average(double  sum, double  count )

{
	float avr;
	

	avr = sum / count;


	return avr; 

}

double percentile(double  count,double sum)
{
	float  per;
	float j=90 ;
	//setting current  percentage 
	/*std::cout << "Enter percerntage j= ";
	std::cin >> j;*/

	per = (j / 100) * count;

	return per;
}

double median(int mass[10], const int N)
{
	// finding largest difference

	int max = -1;
	int min = mass[0];
	int left_sum = 0;
	int right_sum = 0;
	int med = 0;

	for (int i = 1; i < N; i++) // minimal difference 
	{
		left_sum = 0;
		right_sum = 0;
		for (int j = 0; j < i; j++)
		{
			left_sum += mass[j];

		}

		for (int k = i + 1; k < N; k++)
		{
			right_sum += mass[k];
			if (abs(left_sum - right_sum) >= max)
				max = abs(left_sum - right_sum);
		}
	}

	for (int i = 1; i < N - 1; i++)
	{
		left_sum = 0;
		right_sum = 0;
		for (int j = 0; j < i; j++)
		{
			left_sum += mass[j];

		}
		for (int k = i + 1; k < N; k++)
		{
			right_sum = mass[k];

		}
		if (abs(left_sum - right_sum) <= max)
		{
			max = abs(left_sum - right_sum);
		}

	}
	//std::cout << std::endl << "median of determined array has an index" << std::endl;

	for (int i = 1; i < N - 1; i++)
	{
		left_sum = 0;
		right_sum = 0;
		for (int j = 0; j < i; j++)
		{
			left_sum += mass[j];

		}
		for (int k = i + 1; k < N; k++)
		{

			right_sum += mass[k];
		}
		if (abs(left_sum - right_sum) == max)
		{

			std::cout << mass[i]<<endl;
			int med = mass[i];

		}
	}
	
	return med  ;
}

int main()
{

	const int N = 10;
	int mass[N] = { 5,8,0,0,1,5,5,5,10,6 };

	int i;
	double  sum=0 ;
	double   count = 0;

	for (i = 0; i < 10; i++)
	{
		//std::cout << std::setw(4) << mass[i] << endl;
		
		count = count+1;
		sum = sum + mass[i];
		
	}
	//std::cout <<sum << std::endl;
	//std::cout << count;
	int g = median(mass, N);
	std::cout << "median" << endl; 

	std::cout << std::setw(1) << g << std:: endl;

	std::cout << "percentile" << std::endl; 
	std::cout << percentile(sum, count)<<endl;

	std::cout << "average" << std::endl; 

	std::cout << average(sum, count) << endl; 

	std::cout << "maximum" << std::endl; 

	std::cout << max(mass, N) << endl; 

	std::cout << "minimun" << std::endl; 

	std::cout << min(mass, N) << std::endl;



}


