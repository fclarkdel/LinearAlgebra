#include <vector>

#include <gtest/gtest.h>

#include "LinearAlgebra.h"

class SubtractTest : public ::testing::Test {
protected:
	std::vector<std::vector<double>> const u {{-5, -4, -3},
											  {-2, -1, 0}};
	std::vector<std::vector<double>> const v {{1, 2, 3},
											  {4, 5, 6}};
	std::vector<std::vector<double>> const w {{7, 8, 9},
											  {10, 11, 12}};
	std::vector<std::vector<double>> const x {LinearAlgebra::identity(3, 3)};
};
TEST_F(SubtractTest, Associativity) {
	// Where all elements are not equal and non-zero:
	// u - (v - w) != (u - v) - w
	std::vector<std::vector<double>> const& l {LinearAlgebra::subtract(u, LinearAlgebra::subtract(v, w))};
	std::vector<std::vector<double>> const& r {LinearAlgebra::subtract(LinearAlgebra::subtract(u, v), w)};

	for(int i {0}; i < l.size(); ++i) {
		for(int j {0}; j < l[0].size(); ++j) {
			EXPECT_NE(l[i][j], r[i][j]);
		}
	}
}
TEST_F(SubtractTest, Commutativity) {
	// Where all elements are not equal and non-zero:
	// u - v != v - u
	std::vector<std::vector<double>> const& l {LinearAlgebra::subtract(u, v)};
	std::vector<std::vector<double>> const& r {LinearAlgebra::subtract(v, u)};

	for(int i {0}; i < l.size(); ++i) {
		for(int j {0}; j < l[0].size(); ++j) {
			EXPECT_NE(l[i][j], r[i][j]);
		}
	}
}
TEST_F(SubtractTest, IdentityElement) {
	// u - 0 = u
	std::vector<std::vector<double>> const& l {LinearAlgebra::subtract(u, LinearAlgebra::build(u.size(), u[0].size()))};
	std::vector<std::vector<double>> const& r {u};

	for(int i {0}; i < l.size(); ++i) {
		for(int j {0}; j < l[0].size(); ++j) {
			EXPECT_EQ(l[i][j], r[i][j]);
		}
	}
}
TEST_F(SubtractTest, InverseElement) {
	// u - u = 0
	std::vector<std::vector<double>> const& l {LinearAlgebra::subtract(u, u)};
	std::vector<std::vector<double>> const& r {LinearAlgebra::build(u.size(), u[0].size())};

	for(int i {0}; i < l.size(); ++i) {
		for(int j {0}; j < l[0].size(); ++j) {
			EXPECT_EQ(l[i][j], r[i][j]);
		}
	}
}
TEST_F(SubtractTest, InvalidDimensionsException) {
	EXPECT_THROW(
			LinearAlgebra::subtract(w, x),
			InvalidDimensionsException
	);
	EXPECT_THROW(
			LinearAlgebra::subtract(x, w),
			InvalidDimensionsException
	);
}