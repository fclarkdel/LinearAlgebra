#include <iostream>
#include <vector>

#include "LinearAlgebra.h"

using namespace std;

int main() {
	const vector<vector<double>> a = {{1, 2, 3},
									  {4, 4, 6},
									  {7, 8, 9}};
	const vector<vector<double>> b = LinearAlgebra::inverse(a);
	const vector<vector<double>> c = LinearAlgebra::multiply(a, b);
	const vector<vector<double>> d = LinearAlgebra::column(0, a);

	for(const vector<double> x : a) {
		for(const double y : x)
			cout << y << " ";

		cout << endl;
	}
	cout << endl;

	for(const vector<double> x : b) {
		for(const double y : x)
			cout << y << " ";

		cout << endl;
	}
	cout << endl;

	for(const vector<double> x : c) {
		for(const double y : x)
			cout << y << " ";

		cout << endl;
	}
	cout << endl;

	for(const vector<double> x : d) {
		for(const double y : x)
			cout << y << " ";

		cout << endl;
	}
	cout << endl;

	return 0;
}