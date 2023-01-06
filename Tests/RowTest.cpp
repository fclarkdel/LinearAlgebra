#include <vector>

#include <gtest/gtest.h>

#include "LinearAlgebra.h"

class RowTest : public ::testing::Test {
protected:
	std::vector<std::vector<double>> const u {{1, 2, 3},
											  {4, 5 ,6},
											  {7, 8, 9}};
};
TEST_F(RowTest, Row) {
	for(int i {0}; i < u.size(); ++i) {
		std::vector<std::vector<double>> v {LinearAlgebra::row(i, u)};

		for(int j {0}; j < u[0].size(); ++j) {
			EXPECT_EQ(u[i][j], v[0][j]);
		}
	}
}
TEST_F(RowTest, InvalidDimensionsException) {
	EXPECT_THROW(
		std::vector<std::vector<double>> v {LinearAlgebra::row(-1, u)},
		InvalidDimensionsException
	);
}