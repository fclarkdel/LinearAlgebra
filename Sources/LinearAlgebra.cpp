#include "LinearAlgebra.h"

namespace LinearAlgebra {
	std::vector<std::vector<double>> build(unsigned int const& rows, unsigned int const& cols) {
		std::vector<std::vector<double>> a {};

		for(int i {0}; i < rows; ++i) {
			a.emplace_back();

			for(int j {0}; j < cols; ++j)
				a[i].push_back(0);
		}
		return a;
	}
	std::vector<std::vector<double>> identity(unsigned int const& rows, unsigned int const& cols) {
		std::vector<std::vector<double>> a {build(rows, cols)};

		for(int i {0}; i < a.size(); ++i)
			a[i][i] = 1;

		return a;
	}
	std::vector<std::vector<double>> row(unsigned int const& row, std::vector<std::vector<double>> const& a) {
		if(row >= a.size())
			throw InvalidDimensionsException();

		return std::vector<std::vector<double>> {a[row]};
	}
	std::vector<std::vector<double>> column(unsigned int const& column, std::vector<std::vector<double>> const& a) {
		if(column >= a[0].size())
			throw InvalidDimensionsException();

		return transpose(std::vector<std::vector<double>> {transpose(a)[column]});
	}
	std::vector<std::vector<double>> scalar(double const& c, std::vector<std::vector<double>> a) {
		for(int i {0}; i < a.size(); ++i) {
			for(int j {0}; j < a[0].size(); ++j)
				a[i][j] *= c;
		}
		return a;
	}
	std::vector<std::vector<double>> add(std::vector<std::vector<double>> a, std::vector<std::vector<double>> const& b) {
		if(a.size() != b.size() || a[0].size() != b[0].size())
			throw InvalidDimensionsException();

		for(int i {0}; i < a.size(); ++i) {
			for(int j {0}; j < a[0].size(); ++j)
				a[i][j] += b[i][j];
		}
		return a;
	}
	std::vector<std::vector<double>> subtract(std::vector<std::vector<double>> const& a, std::vector<std::vector<double>> const& b) {
		if(a.size() != b.size() || a[0].size() != b[0].size())
			throw InvalidDimensionsException();

		return add(a, scalar(-1, b));
	}
	std::vector<std::vector<double>> multiply(std::vector<std::vector<double>> const& a, std::vector<std::vector<double>> const& b) {
		if(a[0].size() != b.size())
			throw InvalidDimensionsException();

		std::vector<std::vector<double>> c {build(a.size(), b[0].size())};

		for(int i {0}; i < a.size(); ++i) {
			for(int j {0}; j < b[0].size(); ++j) {
				for(int k {0}; k < b.size(); ++k)
					c[i][j] += a[i][k] * b[k][j];
			}
		}
		return c;
	}
	std::vector<std::vector<double>> transpose(std::vector<std::vector<double>> const& a) {
		std::vector<std::vector<double>> b {build(a[0].size(), a.size())};

		for(int i {0}; i < a.size(); ++i) {
			for(int j {0}; j < a[0].size(); ++j)
				b[j][i] = a[i][j];
		}
		return b;
	}
	double determinant(std::vector<std::vector<double>> a) {
		if(a.size() != a[0].size())
			throw InvalidDimensionsException();

		double determinant {1};

		// Put the matrix into upper triangular form.
		for(int i {0}; i < a.size() - 1; ++i) {
			// Handle zero pivot.
			if(a[i][i] == 0) {
				// Find first row with non-zero value in pivot column.
				for(int j {i + 1}; j < a.size() && a[j][i] == 0; ++j)
					if(a[j][i] != 0) {
						// Swap rows.
						std::vector<double> temp {a[i]};

						a[i] = a[j];
						a[j] = temp;

						determinant *= -1;
					} else {
						// Zero column present in matrix.
						continue;
					}
			}
			// Subtract multiple of i_th row from j_th row.
			for(int j {i + 1}; j < a.size(); ++j) {
				double const l {a[j][i] / a[i][i]};

				a[j] = subtract(row(j, a), scalar(l, row(i, a)))[0];
			}
		}
		// Work back up.
		for(int i {static_cast<int>(a.size() - 1)}; i >= 0; --i) {
			// Subtract multiple of i_th row from j_th row.
			for(int j {i - 1}; j >= 0; --j) {
				double const l {a[j][i] / a[i][i]};

				a[j] = subtract(row(j, a), scalar(l, row(i, a)))[0];
			}
		}
		// Multiply pivots to get determinant.
		for(int i = 0; i < a.size(); ++i) {
			if(a[i][i] == 0)
				return 0;

			determinant *= a[i][i];
		}
		return determinant;
	}
	std::vector<std::vector<double>> inverse(std::vector<std::vector<double>> a) {
		if(determinant(a) == 0)
			throw SingularMatrixException();

		std::vector<std::vector<double>> b {identity(a.size(), a[0].size())};

		// Put the matrix into upper triangular form.
		for(int i {0}; i < a.size() - 1; ++i) {
			// Handle zero pivot.
			if(a[i][i] == 0) {
				// Find first row with non-zero value in pivot column.
				for(int j {i + 1}; j < a.size() && a[j][i] == 0; ++j)
					if(a[j][i] != 0) {
						// Swap rows.
						std::vector<double> temp {a[i]};

						a[i] = a[j];
						a[j] = temp;

						temp = b[i];

						b[i] = b[j];
						b[j] = temp;
					} else {
						// Zero column present in matrix.
						continue;
					}
			}
			// Subtract multiple of i_th row from j_th row.
			for(int j {i + 1}; j < a.size(); ++j) {
				double const l {a[j][i] / a[i][i]};

				a[j] = subtract(row(j, a), scalar(l, row(i, a)))[0];
				b[j] = subtract(row(j, b), scalar(l, row(i, b)))[0];
			}
		}
		// Work back up.
		for(int i {static_cast<int>(a.size() - 1)}; i >= 0; --i) {
			// Divide i_th row by i_th pivot.
			b[i] = scalar(1 / a[i][i], row(i, b))[0];
			a[i] = scalar(1 / a[i][i], row(i, a))[0];

			// Subtract multiple of i_th row from j_th row.
			for(int j {i - 1}; j >= 0; --j) {
				double const l {a[j][i]};

				a[j] = subtract(row(j, a), scalar(l, row(i, a)))[0];
				b[j] = subtract(row(j, b), scalar(l, row(i, b)))[0];
			}
		}
		return b;
	}
}