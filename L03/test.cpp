#include "pch.h"
#include "../timus_1730/functions.cpp"

TEST(CheckTests, RightAnswer) {
	EXPECT_TRUE(Check(512));
}

TEST(CheckTests, underflowValue) {
	EXPECT_THROW(Check(0), std::out_of_range);
}

TEST(CheckTests, overflowValue) {
	EXPECT_THROW(Check(1501), std::out_of_range);
}

TEST(GCDTests, ArgsNotInRange) {
	EXPECT_THROW(GCD(0,2), std::out_of_range);
	EXPECT_THROW(GCD(2, 0), std::out_of_range);
	EXPECT_THROW(GCD(1501, 2), std::out_of_range);
	EXPECT_THROW(GCD(2, 1501), std::out_of_range);
}

TEST(GCDTests, RightAnswer) {
	EXPECT_EQ(5, GCD(5,10));
	EXPECT_EQ(4, GCD(64, 20));
	EXPECT_EQ(20, GCD(60, 20));
	EXPECT_EQ(7, GCD(21, 56));
}

TEST(GetLevelTests, RightAnswer) {
	EXPECT_EQ(GetLevel(8), 3);
	EXPECT_EQ(GetLevel(7), 3);
	EXPECT_EQ(GetLevel(4), 2);
}

TEST(GetLevelTests, underflowValue) {
	EXPECT_THROW(GetLevel(0), std::out_of_range);
}

TEST(GetLevelTests, overflowValue) {
	EXPECT_THROW(GetLevel(10000), std::out_of_range);
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

}