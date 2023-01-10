#include <vector>

#include <gtest/gtest.h>

#include "LinearAlgebra.h"

class ScalarTest : public ::testing::Test {
protected:
	double const c {2};
	double const d {3};

	std::vector<std::vector<double>> const u {{1, 2, 3},
											  {4, 5, 6}};
	std::vector<std::vector<double>> const v {{7, 8, 9},
											  {10, 11, 12}};
};
TEST_F(ScalarTest, Associativity) {
	// (c * d) * u = c * (d * u)
	std::vector<std::vector<double>> const& l {LinearAlgebra::scalar(c * d, u)};
	std::vector<std::vector<double>> const& r {LinearAlgebra::scalar(c, LinearAlgebra::scalar(d, u))};

	for(int i {0}; i < l.size(); ++i) {
		for(int j {0}; j < l[0].size(); ++j) {
			EXPECT_EQ(l[i][j], r[i][j]);
		}
	}
}
TEST_F(ScalarTest, Distributivity) {
	// (c + d) * u = (c * u) + (d * u)
	std::vector<std::vector<double>> l {LinearAlgebra::scalar(c + d, u)};
	std::vector<std::vector<double>> r {LinearAlgebra::add(LinearAlgebra::scalar(c, u), LinearAlgebra::scalar(d, u))};

	for(int i {0}; i < l.size(); ++i) {
		for(int j {0}; j < l[0].size(); ++j) {
			EXPECT_EQ(l[i][j], r[i][j]);
		}
	}
	// c * (u + v) = (c * u) + (c * v)
	l = LinearAlgebra::scalar(c, LinearAlgebra::add(u, v));
	r = LinearAlgebra::add(LinearAlgebra::scalar(c, u), LinearAlgebra::scalar(c, v));

	for(int i {0}; i < l.size(); ++i) {
		for(int j {0}; j < l[0].size(); ++j) {
			EXPECT_EQ(l[i][j], r[i][j]);
		}
	}
}
TEST_F(ScalarTest, IdentityElement) {
	// 1 * u = u
	std::vector<std::vector<double>> const& l {LinearAlgebra::scalar(1, u)};
	std::vector<std::vector<double>> const& r {u};

	for(int i {0}; i < l.size(); ++i) {
		for(int j {0}; j < l[0].size(); ++j) {
			EXPECT_EQ(l[i][j], r[i][j]);
		}
	}
}
TEST_F(ScalarTest, InverseElement) {
	// (1 / c) * (c * u) = u
	std::vector<std::vector<double>> const& l {LinearAlgebra::scalar(1.0 / c, LinearAlgebra::scalar(c, u))};
	std::vector<std::vector<double>> const& r {u};

	for(int i {0}; i < l.size(); ++i) {
		for(int j {0}; j < l[0].size(); ++j) {
			EXPECT_EQ(l[i][j], r[i][j]);
		}
	}
}
TEST_F(ScalarTest, AbsorbingElement) {
	// 0 * u = 0
	std::vector<std::vector<double>> l {LinearAlgebra::scalar(0, u)};
	std::vector<std::vector<double>> r {LinearAlgebra::build(static_cast<int>(u.size()), static_cast<int>(u[0].size()))};

	for(int i {0}; i < l.size(); ++i) {
		for(int j {0}; j < l[0].size(); ++j) {
			EXPECT_EQ(l[i][j], r[i][j]);
		}
	}
	// c * 0 = 0
	l = LinearAlgebra::scalar(c, LinearAlgebra::build(static_cast<int>(u.size()), static_cast<int>(u[0].size())));
	r = LinearAlgebra::build(static_cast<int>(u.size()), static_cast<int>(u[0].size()));

	for(int i {0}; i < l.size(); ++i) {
		for(int j {0}; j < l[0].size(); ++j) {
			EXPECT_EQ(l[i][j], r[i][j]);
		}
	}
}