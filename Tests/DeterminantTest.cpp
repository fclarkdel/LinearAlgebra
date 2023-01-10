#include <vector>

#include <gtest/gtest.h>

#include "LinearAlgebra.h"

class DeterminantTest : public ::testing::Test {
protected:
	double const c {2};

	std::vector<std::vector<double>> const u {{1, 2, 7},
											  {3, 2, 8},
											  {5, 6, 9}};
	std::vector<std::vector<double>> const v {{1, 2, 3},
											  {4, 5, 6}};
	std::vector<std::vector<double>> const w {{1, 2, 3},
											  {4, 5, 6},
											  {7, 8, 9}};
};
TEST_F(DeterminantTest, Identity) {
	// det(I) = 1
	std::vector<std::vector<double>> const& v {LinearAlgebra::identity(3, 3)};

	double const& l {LinearAlgebra::determinant(v)};
	double const& r {1};

	EXPECT_EQ(l, r);
}
TEST_F(DeterminantTest, RowExchange) {
	// det(u) = -1 * det(u'), where u' is u with a row exchanged.
	double const& l {LinearAlgebra::determinant(u)};

	std::vector<std::vector<double>> uPrime {u};

	std::vector<double> const temp {uPrime[0]};
	uPrime[0] = uPrime[1];
	uPrime[1] = temp;

	double const& r {-1 * LinearAlgebra::determinant(uPrime)};

	EXPECT_EQ(l, r);
}
TEST_F(DeterminantTest, Linearity) {
	// c * det(u) = det(u'), where u' is u with one row multiplied by a constant c.
	double const& l {c * LinearAlgebra::determinant(u)};

	std::vector<std::vector<double>> uPrime {u};

	uPrime[0] = LinearAlgebra::scalar(c, LinearAlgebra::row(0, uPrime))[0];

	double const& r {LinearAlgebra::determinant(uPrime)};

	EXPECT_EQ(l, r);
}
TEST_F(DeterminantTest, EqualRows) {
	// det(u') = 0, where u' is u with two equal rows.
	std::vector<std::vector<double>> uPrime {u};

	uPrime[0] = uPrime[1];

	double const& l {LinearAlgebra::determinant(uPrime)};
	double const& r {0};

	EXPECT_EQ(l, r);
}
TEST_F(DeterminantTest, Transpose) {
	// det(u^T) = det(u)
	double const& l {LinearAlgebra::determinant(LinearAlgebra::transpose(u))};
	double const& r {LinearAlgebra::determinant(u)};

	EXPECT_EQ(l, r);
}
TEST_F(DeterminantTest, SingularMatrix) {
	// det(w) = 0, where w is a singular matrix.
	EXPECT_EQ(LinearAlgebra::determinant(w), 0);
}
TEST_F(DeterminantTest, InvalidDimensionsException) {
	EXPECT_THROW(LinearAlgebra::determinant(v),
				 InvalidDimensionsException);
}