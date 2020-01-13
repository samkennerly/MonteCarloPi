/*
Monte Carlo estimate of pi.
Can only be runs interactively.
*/

#include<iostream>
#include<vector>
#include<ctime>

using namespace std;

#define PI_50_DIGITS 3.14159265358979323846264338327950288419716939937510

double sqradius( vector<double>& input_vector ){
	// Returns squared radius because we don't have time for square roots.

	double x = input_vector[0];
	double y = input_vector[1];

	return x*x + y*y;
}

int main(){
	// Ask user number of samples. Print estimated pi and error.

	unsigned long tosses = 0;
	unsigned long hits = 0;
	double pi_ish = 0;
	vector<double> dart(2);

	cout << endl << "How many million darts should we throw? ";
	cin >> tosses;
	tosses *= 1000000;

	// Seed the pseudorandom number generator
	srand(time(NULL));

	cout << "Throwing darts..." << endl;
	for ( int d = 0; d < tosses; d++ ){
		dart[0] = 2.0 * rand( ) / RAND_MAX - 1.0;
		dart[1] = 2.0 * rand( ) / RAND_MAX - 1.0;
		if ( sqradius(dart) <= 1.0 ){
			hits ++;
		}
	}
	pi_ish = ( 4.0 * hits ) / tosses;

	cout.precision(10);
	cout << hits << " hits out of " << tosses << " tosses. " << endl;
	cout << "Estimated value of pi is " << pi_ish << endl;
	cout << "Error is " << pi_ish - PI_50_DIGITS << endl;

	return 0;
}
