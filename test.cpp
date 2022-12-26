#include <iostream>
#include <vector>

#include "LinearAlgebra.h"

using namespace std;

vector<vector<double>> leastSquares(vector<vector<double>> data);

int main() {
	vector<vector<double>> data = {{0, 2},
								   {1, 4},
								   {2, 6}};
	vector<vector<double>> a;
	vector<vector<double>> b;

	for(vector<double> x : data) {
		a.push_back({1, x[0]});
		b.push_back({x[1]});
	}
	vector<vector<double>> c = LinearAlgebra::multiply(LinearAlgebra::transpose(a), a);
	vector<vector<double>> d = LinearAlgebra::inverse(c);
	vector<vector<double>> e = LinearAlgebra::multiply(c, d);

	for(vector<double> x : a) {
		cout << endl;

		for(double y : x)
			cout << y << " ";
	}
	for(vector<double> x : b) {
		cout << endl;

		for(double y : x)
			cout << y << " ";
	}
	for(vector<double> x : c) {
		cout << endl;

		for(double y : x)
			cout << y << " ";
	}
	for(vector<double> x : d) {
		cout << endl;

		for(double y : x)
			cout << y << " ";
	}
	for(vector<double> x : e) {
		cout << endl;

		for(double y : x)
			cout << y << " ";
	}
	return 0;
}
vector<vector<double>> leastSquares(vector<vector<double>> data) {
	vector<vector<double>> a;
	vector<vector<double>> b;

	for(vector<double> x : data) {
		a.push_back({1, x[0]});
		b.push_back({x[1]});
	}
	return LinearAlgebra::multiply(LinearAlgebra::inverse(LinearAlgebra::multiply(LinearAlgebra::transpose(a), a)),
								   LinearAlgebra::multiply(LinearAlgebra::transpose(a), b));
}