#include "Exceptions/InvalidDimensionsException.h"

InvalidDimensionsException::InvalidDimensionsException(std::string_view message) : message(message) {}

const char* InvalidDimensionsException::what() const noexcept {
	return message.c_str();
}