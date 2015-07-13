/*
MonteCarloPi is a simple Monte Carlo estimate of pi.
Draw a unit circle. Now draw a square that just barely contains the circle.
Choose random points uniformly distributed on the square.
The probability of each point being inside the circle is pi / 4.

Copyright 2012 Sam Kennerly.
MonteCarloPi is free software: you can redistribute it and/or modify it under the terms
of the GNU General Public License as published by the Free Software Foundation, either
version 3 of the License, or (at your option) any later version.

MonteCarloPi is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU General Public License for more details.
For a copy of the GNU General Public License, see <http://www.gnu.org/licenses/>.
*/

#include<iostream>
#include<vector>		// Darts are represented as vectors
#include<ctime>			// Used to seed the pseudo-random number generator

using namespace std;

#define PI_50_DIGITS 3.14159265358979323846264338327950288419716939937510

// Returns square magnitude of a 2D vector. Taking the square root would slow us down!
// Pass by reference for speed. (I tested it - it really is significantly faster.)
double sqradius( vector<double>& input_vector ){
	double x = input_vector[0];
	double y = input_vector[1];
	return x*x + y*y;
}

// ------------ MAIN PROGRAM -------------------
int main(){

	unsigned long tosses = 0;				// How many darts should we throw?
	unsigned long hits = 0;					// Counts darts that landed inside unit circle
	double estimated_pi = 0;				// Estimated value of pi
	vector<double> dart(2);					// Position of a dart
	
	cout << endl << "How many million darts should we throw? ";
	cin >> tosses;
	tosses *= 1000000;

	srand(time(NULL));						// Seed the pseudo-RNG

	cout << "Throwing darts..." << endl;
	for ( int d = 0; d < tosses; d++ ){
		dart[0] = 2.0 * rand( ) / RAND_MAX - 1.0;	// Random x-component for this dart
		dart[1] = 2.0 * rand( ) / RAND_MAX - 1.0;	// Random y-component for this dart
		if ( sqradius(dart) <= 1.0 ){
			hits ++;								// If this dart hits circle, count it.
		}
	}
	
	estimated_pi = ( 4.0 * hits ) / tosses;		// Square has area 4, circle has area pi.
	cout.precision(10);							// Show 10 significant figures
	cout << hits << " hits out of " << tosses << " tosses. " << endl;
	cout << "Estimated value of pi is " << estimated_pi << endl;
	cout << "Error is " << estimated_pi - PI_50_DIGITS << endl << endl;

return 0;
}
