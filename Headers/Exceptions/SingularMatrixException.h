#ifndef LINEARALGEBRA_SINGULARMATRIXEXCEPTION_H
#define LINEARALGEBRA_SINGULARMATRIXEXCEPTION_H

#include <exception>
#include <string>

class SingularMatrixException : public std::exception {
private:
	std::string message {};

public:
	SingularMatrixException(std::string_view message = "Singular matrix.");

	const char* what() const noexcept override;
};
#endif //LINEARALGEBRA_SINGULARMATRIXEXCEPTION_H