#include <exception>
#include <iostream>
#include <vector>

#include "LinearAlgebra.h"

using namespace std;

vector<vector<double>> leastSquares(vector<vector<double>> data);

int main() {
	try {
		vector<vector<double>> a {{1, 1},
								  {2, 3},
								  {3, 7}};
		for(vector<double> x : leastSquares(a)) {
			for(double y : x)
				cout << y << " ";

			cout << endl;
		}
	} catch(std::exception const& e) {
		 cerr << e.what() << endl;
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
	// X = (((A^T)(A))^-1)(A^T)(B)
	return LinearAlgebra::multiply(LinearAlgebra::inverse(LinearAlgebra::multiply(LinearAlgebra::transpose(a), a)),
								   LinearAlgebra::multiply(LinearAlgebra::transpose(a), b));
}