#include "Exceptions/SingularMatrixException.h"

SingularMatrixException::SingularMatrixException(std::string_view message) : message(message) {}

const char* SingularMatrixException::what() const noexcept {
	return message.c_str();
}