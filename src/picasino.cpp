/*
Estimate pi.
Run interactively.
Use a brute-force Monte Carlo method.
*/

/* TO DO
- don't use namespace std?
- pass dart by reference?
- inline functions?
- cleanup
*/

#include<iostream>
#include<vector>
#include<ctime>

using namespace std;

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

	vector<double> dart(2);
	unsigned long tosses = 0;
	unsigned long hits = 0;
	double pi_ish = 0;

	clock_t started;
	float elapsed;

	// Seed the random number generator
	srand(time(NULL));

	// Ask user for input
	cout << endl << "How many million darts? ";
	cin >> tosses;
	tosses *= 1000000;

	// Throw darts
	started = std::clock();
	cout << "Throwing darts..." << endl;
	for (int d = 0; d < tosses; d++){
		dart[0] = coord();
		dart[1] = coord();
		if (sqradius(dart) <= 1.0){
			hits ++;
		}
	}
	pi_ish = 4.0 * hits / tosses;
	elapsed = std::clock() - started;
	elapsed /= CLOCKS_PER_SEC;

	// Display results
	cout.precision(8);
	cout << endl;
	cout << "Estimate: " << pi_ish << endl;
	cout << "Error:    " << pi_ish - PI << endl;
	cout << "Tosses:   " << tosses << endl;
	cout << "Hits:     " << hits << endl;
	cout << "Time:     " << elapsed << " seconds" << endl;
	cout << endl;

	return 0;
}
