#include <vector>

#include <gtest/gtest.h>

#include "LinearAlgebra.h"

class BuildTest : public ::testing::Test {
protected:
	int const m {2};
	int const n {3};
};
TEST_F(BuildTest, Build) {
	std::vector<std::vector<double>> const& u {LinearAlgebra::build(m, n)};

	ASSERT_EQ(u.size(), m);
	ASSERT_EQ(u[0].size(), n);

	for(int i {0}; i < m; ++i) {
		for(int j {0}; j < n; ++j) {
			EXPECT_EQ(u[i][j], 0);
		}
	}
}
TEST_F(BuildTest, InvalidDimensionsException) {
	EXPECT_THROW(
		std::vector<std::vector<double>> const& u {LinearAlgebra::build(-m, n)},
		InvalidDimensionsException
	);
	EXPECT_THROW(
			std::vector<std::vector<double>> const& u {LinearAlgebra::build(m, -n)},
			InvalidDimensionsException
	);
	EXPECT_THROW(
			std::vector<std::vector<double>> const& u {LinearAlgebra::build(-m, -n)},
			InvalidDimensionsException
	);
}