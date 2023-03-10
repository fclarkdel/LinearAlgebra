#ifndef LINEARALGEBRA_LINEARALGEBRA_H
#define LINEARALGEBRA_LINEARALGEBRA_H

#include <vector>

#include "Exceptions/InvalidDimensionsException.h"
#include "Exceptions/SingularMatrixException.h"

namespace LinearAlgebra {
	std::vector<std::vector<double>> build(int const& rows, int const& cols);

	std::vector<std::vector<double>> identity(int const& rows, int const& cols);

	std::vector<std::vector<double>> row(int const& row, std::vector<std::vector<double>> const& a);

	std::vector<std::vector<double>> column(int const& column, std::vector<std::vector<double>> const& a);

	std::vector<std::vector<double>> scalar(double const& c, std::vector<std::vector<double>> a);

	std::vector<std::vector<double>> add(std::vector<std::vector<double>> a, std::vector<std::vector<double>> const& b);

	std::vector<std::vector<double>> subtract(std::vector<std::vector<double>> const& a, std::vector<std::vector<double>> const& b);

	std::vector<std::vector<double>> multiply(std::vector<std::vector<double>> const& a, std::vector<std::vector<double>> const& b);

	std::vector<std::vector<double>> transpose(std::vector<std::vector<double>> const& a);

	double determinant(std::vector<std::vector<double>> a);

	std::vector<std::vector<double>> inverse(std::vector<std::vector<double>> a);
}
#endif //LINEARALGEBRA_LINEARALGEBRA_H