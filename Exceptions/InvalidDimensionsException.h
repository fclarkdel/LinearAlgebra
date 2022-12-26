#ifndef LINEARALGEBRA_INVALIDDIMENSIONSEXCEPTION_H
#define LINEARALGEBRA_INVALIDDIMENSIONSEXCEPTION_H

#include <exception>
#include <iostream>
#include <string>

class InvalidDimensionsException : public std::exception {
private:
	std::string message {};

public:
	InvalidDimensionsException(std::string_view message);

	const char* what() const noexcept override;
};
#endif //LINEARALGEBRA_INVALIDDIMENSIONSEXCEPTION_H