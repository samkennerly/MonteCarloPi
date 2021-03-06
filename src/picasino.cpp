/*
Estimate pi. Run interactively.
Use a brute-force Monte Carlo method.
*/

#include<iostream>
#include<cmath>
#include<ctime>

using namespace std;

double sample(){
	// Random sample from uniform distribution on [-1, 1).
	return 2.0 * rand() / RAND_MAX - 1.0;
}

double sqradius(double (&point)[2]){
	// Return squared radius. We don't have time for square roots.
	return point[0] * point[0] + point[1] * point[1];
}

double hits(unsigned long &tosses){
	// Throw many darts. How many landed inside the circle?

	unsigned long hits = 0;
	double dart[2] = {0, 0};

	for (int d = 0; d < tosses; d++){
		dart[0] = sample();
		dart[1] = sample();
		if (sqradius(dart) <= 1.0) {
			hits++;
		}
	}

	return hits;
}

int main(){

	clock_t started;
	unsigned long tosses = 0;
	double roughpi = 0;
	double elapsed;

	// Seed the random number generator
	srand(time(NULL));

	// Ask user for input
	cout << endl << "How many million darts? ";
	cin >> tosses;
	tosses *= 1000000;

	// Throw darts
	cout << "Throwing darts..." << endl;
	started = clock();
	roughpi = 4.0 * hits(tosses) / tosses;
	elapsed = clock() - started;

	// Display results
	cout.precision(8);
	cout << endl;
	cout << "Estimate: " << roughpi << endl;
	cout << "Error:    " << roughpi - M_PI << endl;
	cout << "Tosses:   " << tosses << endl;
	cout << "Time:     " << elapsed / CLOCKS_PER_SEC << " seconds" << endl;
	cout << endl;

	return 0;
}
