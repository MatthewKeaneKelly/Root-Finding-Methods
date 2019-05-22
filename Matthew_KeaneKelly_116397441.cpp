
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
// #include "gnuplot.cxx"

using namespace std;

float NewtonRaphson(float Po, int QN, float P);

int main()
{
	//This section simply takes in the info needed for the Newton Raphson method and uses the function to output the final root. 
	float G, P = 0, temp; 
	int Q; 
	cout << "Please enter your initial guess: "; 
	cin >> G; 
	cout << "Please enter the number of the question (1-3): "; 
	cin >> Q; 
	P = NewtonRaphson(G, Q, P);
	cout << "The root of Question " << Q << ". is " << P << "\n";
	cout << "Press Enter to Continue"; 
	cin.get();
	cin.get();
	return EXIT_SUCCESS; 
}
// This funtion Impliments the Newton Raphson method, QN is the number of the questions and decides which function to apply the method to. 
float NewtonRaphson(float Po, int QN, float P)
{
	float tol, No, T1, T2;
	int i; 
	tol = pow(10, -10);
	No = pow(10, 1); 
	i = 1; 
	/*
	Code I used for bugtesting.
	T2 = (3 * pow(Po, 2) + 8 * (Po)*1.0);
	T1 = (pow(Po, 3) + 4 * pow(Po, 2) - 10);
	cout << (T1*1.0) / (T2) << "\n";
	cout << "T1: " << T1 << "\n T2: " << T2 << "\n";
	cout << No << "\n";
	cout << tol << "\n";
	cout << P << "\n";
	cout << Po << "\n";
	cout << abs(P - Po) << "\n";
	cout << i << "\n"; */
	while (i < No) {
		if (QN == 1) {
			P = Po - ((pow(Po, 3) + 4 * pow(Po, 2) - 10) / (3 * pow(Po, 2) + 8*(Po)*1.0)); 
			if (abs(P - Po) < tol) {
				
				return P; 
			}
			else {
				Po = P; 
			}
			i = i + 1; 
			

		}
		else if (QN == 2) {
			P = Po - (((1.0 / Po) + log(Po+1) -5) / ((1.0/(Po+1)) - (1.0/(pow(Po, 2)))));
			
			if (abs(P - Po) < tol) {
				
				return P;
			}
			else {
				Po = P;
			}
			i = i + 1;

		}

		else if (QN == 3) {
			P = Po - ((log(Po) + exp(Po)) / ((1/Po) + exp(Po)));
			if (abs(P - Po) < tol) {
				
				return P;
			}
			else {
				Po = P;
			}
			i = i + 1;

		}
		else {
			//This is just to that if the wrong question number is entered the code stops. 
			cin.get();
			EXIT_FAILURE; 
		}

	}



}

