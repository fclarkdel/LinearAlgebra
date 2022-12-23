#include "../Headers/LinearAlgebra.h"

namespace LinearAlgebra {
	std::vector<std::vector<double>> build(int const& rows, int const& cols) {
		std::vector<std::vector<double>> a;

		for(int i = 0; i < rows; ++i) {
			std::vector<double> row;
			a.push_back(row);

			for(int j = 0; j < cols; ++j)
				a[i].push_back(0);
		}
		return a;
	}
	std::vector<std::vector<double>> identity(int const& rows, int const& cols) {
		std::vector<std::vector<double>> a = build(rows, cols);

		for(int i = 0; i < a.size(); ++i)
			a[i][i] = 1;

		return a;
	}
	std::vector<std::vector<double>> scalar(double const& c, std::vector<std::vector<double>> a) {
		for(int i = 0; i < a.size(); ++i) {
			for(int j = 0; j < a[0].size(); ++j)
				a[i][j] *= c;
		}
		return a;
	}
	std::vector<std::vector<double>> add(std::vector<std::vector<double>> a, std::vector<std::vector<double>> const& b) {
		for(int i = 0; i < a.size(); ++i) {
			for(int j = 0; j < a[0].size(); ++j)
				a[i][j] += b[i][j];
		}
		return a;
	}
	std::vector<std::vector<double>> subtract(std::vector<std::vector<double>> a, std::vector<std::vector<double>> const& b) {
		return add(a, scalar(-1, b));
	}
	std::vector<std::vector<double>> multiply(std::vector<std::vector<double>> const& a, std::vector<std::vector<double>> const& b) {
		std::vector<std::vector<double>> c = build(a.size(), b[0].size());

		for(int i = 0; i < a.size(); ++i) {
			for(int j = 0; j < b[0].size(); ++j) {
				for(int k = 0; k < b.size(); ++k)
					c[i][j] += a[i][k] * b[k][j];
			}
		}
		return c;
	}
	std::vector<std::vector<double>> transpose(std::vector<std::vector<double>> const& a) {
		std::vector<std::vector<double>> b = build(a[0].size(), a.size());

		for(int i = 0; i < a.size(); ++i) {
			for(int j = 0; j < a[0].size(); ++j)
				b[j][i] = a[i][j];
		}
		return b;
	}
	std::vector<std::vector<double>> inverse(std::vector<std::vector<double>> const& a) {
		std::vector<std::vector<double>> b = identity(a.size(), a[0].size());

		// Put matrix "a" into upper triangular form.
		// (i - 1)_th pivot
		for(int i = 1; i < a.size(); ++i) {
			// Handle zero pivot.
			if(a[i - 1][i - 1] == 0) {

			}
			// j_th row
			for(int j = i; j < a.size(); ++j) {
				int const& l = a[j][i - 1] / a[i - 1][i - 1];

				// k_th column
				for(int k = 0; k < a[0].size(); ++k) {

				}
			}
		}
	}
}