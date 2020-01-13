/*
Monte Carlo estimate of pi.
Can only be runs interactively.
*/

#include<iostream>
#include<vector>
#include<ctime>

using namespace std;

#define MILLION 1000000
#define PI 3.14159265358979323846264338327950288419716939937510

double sqradius( vector<double>& point ){
	// Return squared radius because we don't have time for square roots.
	double x = point[0];
	double y = point[1];

	return x*x + y*y;
}

double coord(){
	// Random sample from uniform distribution on [-1, 1).

	return 2.0 * rand() / RAND_MAX - 1.0;
}

int main(){
	// Ask user number of samples. Print estimated pi and error.
	vector<double> point(2);
	unsigned long tosses = 0;
	unsigned long hits = 0;
	double pi_ish = 0;

	cout << endl << "How many million darts should we throw? ";
	cin >> tosses;
	tosses *= MILLION;

	// Seed the pseudorandom number generator
	srand(time(NULL));

	cout << "Throwing darts..." << endl;
	for ( int d = 0; d < tosses; d++ ){
		point[0] = coord();
		point[1] = coord();
		if ( sqradius(point) <= 1.0 ){
			hits ++;
		}
	}
	pi_ish = (4.0 * hits) / tosses;

	cout.precision(10);
	cout << hits << " hits out of " << tosses << " tosses. " << endl;
	cout << "Estimated value of pi is " << pi_ish << endl;
	cout << "Error is " << pi_ish - PI << endl;

	return 0;
}
