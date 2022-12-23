#include "../Headers/LinearAlgebra.h"

namespace LinearAlgebra {
	std::vector<std::vector<double>> build(int const& rows, int const& cols) {
		std::vector<std::vector<double>> a;

		for(int i = 0; i < rows; ++i) {
			std::vector<double> row;
			a.push_back(row);

			for(int j = 0; j < cols; ++j) {
				a[i].push_back(0);
			}
		}
		return a;
	}
	std::vector<std::vector<double>> add(std::vector<std::vector<double>> a, std::vector<std::vector<double>> const& b) {
		for(int i = 0; i < a.size(); ++i) {
			for(int j = 0; j < a[0].size(); ++j) {
				a[i][j] += b[i][j];
			}
		}
		return a;
	}
	std::vector<std::vector<double>> subtract(std::vector<std::vector<double>> a, std::vector<std::vector<double>> const& b) {
		return add(a, scalar(-1, b));
	}
	std::vector<std::vector<double>> scalar(double const& c, std::vector<std::vector<double>> a) {
		for(int i = 0; i < a.size(); ++i) {
			for(int j = 0; j < a[0].size(); ++j) {
				a[i][j] *= c;
			}
		}
		return a;
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
			for(int j = 0; j < a[0].size(); ++j) {
				b[j][i] = a[i][j];
			}
		}
		return b;
	}
	std::vector<std::vector<double>> inverse(std::vector<std::vector<double>> a, std::vector<std::vector<double>> b);
}