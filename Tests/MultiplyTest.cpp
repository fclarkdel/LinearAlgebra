#include <vector>

#include <gtest/gtest.h>

#include "LinearAlgebra.h"

class MultiplyTest : public ::testing::Test {
protected:
	std::vector<std::vector<double>> const u {{1, 2},
											  {3, 4}};
	std::vector<std::vector<double>> const v {{-5, -4},
											  {-2, -1}};
	std::vector<std::vector<double>> const w {{7, 8},
											  {9, 10}};
	std::vector<std::vector<double>> const x {{1, 2, 3},
											  {4, 5, 6}};
};
TEST_F(MultiplyTest, Associativity) {
	// (u * v) * w = u * (v * w)
	std::vector<std::vector<double>> const& l {LinearAlgebra::multiply(LinearAlgebra::multiply(u, v), w)};
	std::vector<std::vector<double>> const& r {LinearAlgebra::multiply(u, LinearAlgebra::multiply(v, w))};

	for(int i {0}; i < l.size(); ++i) {
		for(int j {0}; j < l[0].size(); ++j) {
			EXPECT_EQ(l[i][j], r[i][j]);
		}
	}
}
TEST_F(MultiplyTest, Distributivity) {
	// u(v + w) = (u * v) + (u * w)
	std::vector<std::vector<double>> const& l {LinearAlgebra::multiply(u, LinearAlgebra::add(v, w))};
	std::vector<std::vector<double>> const& r {LinearAlgebra::add(LinearAlgebra::multiply(u, v), LinearAlgebra::multiply(u, w))};

	for(int i {0}; i < l.size(); ++i) {
		for(int j {0}; j < l[0].size(); ++j) {
			EXPECT_EQ(l[i][j], r[i][j]);
		}
	}
}
TEST_F(MultiplyTest, NonCommutativity) {
	// u * v != v * u
	std::vector<std::vector<double>> const& l {LinearAlgebra::multiply(u, v)};
	std::vector<std::vector<double>> const& r {LinearAlgebra::multiply(v, u)};

	for(int i {0}; i < l.size(); ++i) {
		for(int j {0}; j < l[0].size(); ++j) {
			EXPECT_NE(l[i][j], r[i][j]);
		}
	}
}
TEST_F(MultiplyTest, InvalidDimensionsException) {
	EXPECT_THROW(LinearAlgebra::multiply(x, v),
				 InvalidDimensionsException);
}