#include <vector>

#include <gtest/gtest.h>

#include "LinearAlgebra.h"

class InverseTest : public ::testing::Test {
protected:
	double const c {2};

	std::vector<std::vector<double>> const u {{1, 2, 7},
											  {3, 2, 8},
											  {5, 6, 9}};
	std::vector<std::vector<double>> const v {{-5, -4, 2},
											  {-2, -2, 3},
											  {0, 1, 4}};
	std::vector<std::vector<double>> const w {{1, 2, 3},
											  {4, 5, 6}};
	std::vector<std::vector<double>> const x {{1, 2, 3},
											  {4, 5, 6},
											  {7, 8, 9}};
};
TEST_F(InverseTest, Involution) {
	// (u^-1)^-1 = u
	std::vector<std::vector<double>> const& l {LinearAlgebra::inverse(LinearAlgebra::inverse(u))};
	std::vector<std::vector<double>> const& r {u};

	for(int i {0}; i < l.size(); ++i) {
		for(int j {0}; j < l[0].size(); ++j) {
			// Temporary work around - truncate to 5 decimal places.
			double lv {l[i][j]};
			lv *= 100000;
			lv = static_cast<int>(lv);
			lv /= 100000;
			lv = static_cast<double>(lv);

			double rv {r[i][j]};
			rv *= 100000;
			rv = static_cast<int>(rv);
			rv /= 100000;
			rv = static_cast<double>(rv);

			EXPECT_EQ(lv, rv);
		}
	}
}
TEST_F(InverseTest, Scalar) {
	// (c * u)^-1 = (c^-1) * (u^-1)
	std::vector<std::vector<double>> const& l {LinearAlgebra::inverse(LinearAlgebra::scalar(c, u))};
	std::vector<std::vector<double>> const& r {LinearAlgebra::scalar(1 / c, LinearAlgebra::inverse(u))};

	for(int i {0}; i < l.size(); ++i) {
		for(int j {0}; j < l[0].size(); ++j) {
			// Temporary work around - truncate to 5 decimal places.
			double lv {l[i][j]};
			lv *= 100000;
			lv = static_cast<int>(lv);
			lv /= 100000;
			lv = static_cast<double>(lv);

			double rv {r[i][j]};
			rv *= 100000;
			rv = static_cast<int>(rv);
			rv /= 100000;
			rv = static_cast<double>(rv);

			EXPECT_EQ(lv, rv);
		}
	}
}
TEST_F(InverseTest, Multiply) {
	// (u * v)^-1 = (v^-1) * (u^-1)
	std::vector<std::vector<double>> const& l {LinearAlgebra::inverse(LinearAlgebra::multiply(u, v))};
	std::vector<std::vector<double>> const& r {LinearAlgebra::multiply(LinearAlgebra::inverse(v), LinearAlgebra::inverse(u))};

	for(int i {0}; i < l.size(); ++i) {
		for(int j {0}; j < l[0].size(); ++j) {
			// Temporary work around - truncate to 5 decimal places.
			double lv {l[i][j]};
			lv *= 100000;
			lv = static_cast<int>(lv);
			lv /= 100000;
			lv = static_cast<double>(lv);

			double rv {r[i][j]};
			rv *= 100000;
			rv = static_cast<int>(rv);
			rv /= 100000;
			rv = static_cast<double>(rv);

			EXPECT_EQ(lv, rv);
		}
	}
}
TEST_F(InverseTest, Transpose) {
	// (u^T)^-1 = (u^-1)^T
	std::vector<std::vector<double>> const& l {LinearAlgebra::inverse(LinearAlgebra::transpose(u))};
	std::vector<std::vector<double>> const& r {LinearAlgebra::transpose(LinearAlgebra::inverse(u))};

	for(int i {0}; i < l.size(); ++i) {
		for(int j {0}; j < l[0].size(); ++j) {
			// Temporary work around - truncate to 5 decimal places.
			double lv {l[i][j]};
			lv *= 100000;
			lv = static_cast<int>(lv);
			lv /= 100000;
			lv = static_cast<double>(lv);

			double rv {r[i][j]};
			rv *= 100000;
			rv = static_cast<int>(rv);
			rv /= 100000;
			rv = static_cast<double>(rv);

			EXPECT_EQ(lv, rv);
		}
	}
}
TEST_F(InverseTest, Determinant) {
	// det(u^-1) = det(u)^-1
	double const& l {LinearAlgebra::determinant(LinearAlgebra::inverse(u))};
	double const& r {1 / LinearAlgebra::determinant(u)};

	EXPECT_EQ(l, r);
}
TEST_F(InverseTest, InvalidDimensionsException) {
	EXPECT_THROW(LinearAlgebra::inverse(w),
				 InvalidDimensionsException);
}
TEST_F(InverseTest, SingularMatrixException) {
	EXPECT_THROW(LinearAlgebra::inverse(x),
				 SingularMatrixException);
}