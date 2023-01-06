#include <vector>

#include <gtest/gtest.h>

#include "LinearAlgebra.h"

class AddTest : public ::testing::Test {
protected:
	std::vector<std::vector<double>> const u {{-5, -4, -3},
											  {-2, -1, 0}};
	std::vector<std::vector<double>> const v {{1, 2, 3},
											  {4, 5, 6}};
	std::vector<std::vector<double>> const w {{7, 8, 9},
											  {10, 11, 12}};
	std::vector<std::vector<double>> const x {LinearAlgebra::identity(3, 3)};
};
TEST_F(AddTest, Associativity) {
	// u + (v + w) = (u + v) + w
	std::vector<std::vector<double>> const& l {LinearAlgebra::add(u, LinearAlgebra::add(v, w))};
	std::vector<std::vector<double>> const& r {LinearAlgebra::add(LinearAlgebra::add(u, v), w)};

	for(int i {0}; i < l.size(); ++i) {
		for(int j {0}; j < l[0].size(); ++j) {
			EXPECT_EQ(l[i][j], r[i][j]);
		}
	}
}
TEST_F(AddTest, Commutativity) {
	// u + v = v + u
	std::vector<std::vector<double>> const& l {LinearAlgebra::add(u, v)};
	std::vector<std::vector<double>> const& r {LinearAlgebra::add(v, u)};

	for(int i {0}; i < l.size(); ++i) {
		for(int j {0}; j < l[0].size(); ++j) {
			EXPECT_EQ(l[i][j], r[i][j]);
		}
	}
}
TEST_F(AddTest, IdentityElement) {
	// 0 + u = u
	std::vector<std::vector<double>> const& l {LinearAlgebra::add(LinearAlgebra::build(u.size(), u[0].size()), u)};
	std::vector<std::vector<double>> const& r {u};

	for(int i {0}; i < l.size(); ++i) {
		for(int j {0}; j < l[0].size(); ++j) {
			EXPECT_EQ(l[i][j], r[i][j]);
		}
	}
}
TEST_F(AddTest, InverseElement) {
	// u + (-u) = 0
	std::vector<std::vector<double>> const& l {LinearAlgebra::add(u, LinearAlgebra::scalar(-1, u))};
	std::vector<std::vector<double>> const& r {LinearAlgebra::build(u.size(), u[0].size())};

	for(int i {0}; i < l.size(); ++i) {
		for(int j {0}; j < l[0].size(); ++j) {
			EXPECT_EQ(l[i][j], r[i][j]);
		}
	}
}
TEST_F(AddTest, InvalidDimensionsException) {
	EXPECT_THROW(
			LinearAlgebra::add(w, x),
			InvalidDimensionsException
	);
	EXPECT_THROW(
			LinearAlgebra::add(x, w),
			InvalidDimensionsException
	);
}