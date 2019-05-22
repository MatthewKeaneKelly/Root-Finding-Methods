#include <iostream>
#include <string>
#include <stdio.h>
// #include <unistd.h>
#include <math.h>
#include <stdarg.h>
#include <assert.h>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <random>
#include <vector>
// #include "gnuplot.cxx"

using namespace std;

//Goal: FInd the root of a given potentially non-linear function. 

using namespace std;

float Bisection(float a, float b, float TOL, int N);
float * GenerateFunction();
float ComputeFunction(int N, float X, float *p);
void DisplayFunction(float *p, int N);

int main()
{
	float root, TOL = 0.000005, a, b;
	int N; 
	cout << "Please input the left endpoint of the function: ";
	cin >> a;
	cout << "Please input the right endpoint of the function: ";
	cin >> b;
	cout << "Please input the number of iterations you want to run: ";
	cin >> N;
	
	root = Bisection(a, b, TOL, N);

	cout << "The root is: " << root;
	cin.get();
	cin.get();
	return EXIT_SUCCESS;
}

float Bisection(float a, float b, float TOL, int N)
{
	float *p, root, FP, FA; 
	int deg;
	cout << "Please input the degree of the function you wish to compute (N < 100): ";
	cin >> deg;
	p = GenerateFunction();
	DisplayFunction(p,deg);
	FA = ComputeFunction(deg, a, p); 
	
	for (int i = 1; i < N; i++) {
		root = a + ((b - a) / (2 + 1.0)); 
		FP = ComputeFunction(deg, root, p); 
		if (FP = 0) 
		{
		return root;
			}
		else if (((b - a) / (2 + 1.0))<TOL)
       {
		return root;
			}
			if ((FA * FP) > 0) {
				a = root;
				FA = FP;
			}
			else
				b = root;
	}
	cout << "The method has failed after " << N << " iterations."; 
		return EXIT_FAILURE; 


}

float * GenerateFunction()
{
	//Generates an array with 100 random numbers to use with the compute function.
	static float f[100];
	random_device rd; // obtain a random number from hardware
	mt19937 eng(rd()); // seed the generator
	uniform_int_distribution<> distr(-50, 50); // define the range
	float A, B;

	for (int i = 0; i < 100; ++i) {
		A = distr(eng);
		B = (distr(eng)* 1.0) / (100);
		f[i] = A + B;

	}
	return f;

}

float ComputeFunction(int N, float X, float *p)
{
	//Uses the array of random numbers as a funcion and computes it's value.
	int j;
	float total = p[0], temp;
	for (j = 1; j < N; j++) {
		total = total + p[j] * pow(X, j);
	}
	total = total + p[j] * pow(X, j);
	return total;
}

void DisplayFunction(float *p, int N)
{
	int n;
	cout << "Your generated function is: \n";
	cout << p[0] << " + ";
	for (n = 1; n < N; n++) {
		cout << p[n] << "X^" << n<< " + ";
	}
	cout << p[n] << "X^" << n << "\n \n \n \n";
}