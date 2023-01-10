#include <vector>

#include <gtest/gtest.h>

#include "LinearAlgebra.h"

class ColumnTest : public ::testing::Test {
protected:
	std::vector<std::vector<double>> const u {{1, 2, 3},
											  {4, 5 ,6},
											  {7, 8, 9}};
};
TEST_F(ColumnTest, Column) {
	for(int j {0}; j < u[0].size(); ++j) {
		std::vector<std::vector<double>> const& v {LinearAlgebra::column(j, u)};

		for(int i {0}; i < u.size(); ++i) {
			EXPECT_EQ(u[i][j], v[i][0]);
		}
	}
}
TEST_F(ColumnTest, InvalidDimensionsException) {
	EXPECT_THROW(
		std::vector<std::vector<double>> const& v {LinearAlgebra::column(-1, u)},
		InvalidDimensionsException
	);
}