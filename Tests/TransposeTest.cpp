#include <vector>

#include <gtest/gtest.h>

#include "LinearAlgebra.h"

class TransposeTest : public ::testing::Test {
protected:
	double const c {2};

	std::vector<std::vector<double>> const u {{1, 2, 7},
											  {3, 2, 8},
											  {5, 6, 9}};
	std::vector<std::vector<double>> const v {{-5, -4, 2},
											  {-2, -2, 3},
											  {0, 1, 4}};
};
TEST_F(TransposeTest, Add) {
	// (u + v)^T = u^T + v^T
	std::vector<std::vector<double>> const& l {LinearAlgebra::transpose(LinearAlgebra::add(u, v))};
	std::vector<std::vector<double>> const& r {LinearAlgebra::add(LinearAlgebra::transpose(u), LinearAlgebra::transpose(v))};

	for(int i {0}; i < l.size(); ++i) {
		for(int j {0}; j < l[0].size(); ++j) {
			EXPECT_EQ(l[i][j], r[i][j]);
		}
	}
}
TEST_F(TransposeTest, Involution) {
	// (u^T)^T = u
	std::vector<std::vector<double>> const& l {LinearAlgebra::transpose(LinearAlgebra::transpose(u))};
	std::vector<std::vector<double>> const& r {u};

	for(int i {0}; i < l.size(); ++i) {
		for(int j {0}; j < l[0].size(); ++j) {
			EXPECT_EQ(l[i][j], r[i][j]);
		}
	}
}
TEST_F(TransposeTest, Multiply) {
	// (u * v)^T = v^T * u^T
	std::vector<std::vector<double>> const& l {LinearAlgebra::transpose(LinearAlgebra::multiply(u, v))};
	std::vector<std::vector<double>> const& r {LinearAlgebra::multiply(LinearAlgebra::transpose(v), LinearAlgebra::transpose(u))};

	for(int i {0}; i < l.size(); ++i) {
		for(int j {0}; j < l[0].size(); ++j) {
			EXPECT_EQ(l[i][j], r[i][j]);
		}
	}
}
TEST_F(TransposeTest, Scalar) {
	// (c * u)^T = c * u^T
	std::vector<std::vector<double>> const& l {LinearAlgebra::transpose(LinearAlgebra::scalar(c, u))};
	std::vector<std::vector<double>> const& r {LinearAlgebra::scalar(c, LinearAlgebra::transpose(u))};

	for(int i {0}; i < l.size(); ++i) {
		for(int j {0}; j < l[0].size(); ++j) {
			EXPECT_EQ(l[i][j], r[i][j]);
		}
	}
}