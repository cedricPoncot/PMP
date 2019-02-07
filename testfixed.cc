#include <iostream>
#include <iomanip>
#include <stdexcept>

#include "gtest/gtest.h"

#include "fixed.h"


TEST(FixedTest, constructeurFloat) {
	fp::fixed<4ul,4ul> f0(2.25f);
	EXPECT_EQ(f0.value, 36u);
	fp::fixed<2ul,2ul> f1(1.75f);
	EXPECT_EQ(f1.value, 7u);
	fp::fixed<2ul,2ul> f2(-2.0f);
	EXPECT_EQ(f2.value, -8);
}
TEST(FixedTest, lowest) {
	//std::cout<<fp::fixed<4ul,4ul>.fixed_traits.lowest().value;
}

TEST(FixedTest, constructeurFloatFailMax) {
	try {
		fp::fixed<2ul,2ul> f(1.76f);
	} catch (std::overflow_error& e) {
		EXPECT_STREQ("Debordement de bit", e.what());
	}
}

TEST(FixedTest, constructeurFloatFailMin) {
	try {
		fp::fixed<2ul,2ul> f(-2.01f);
	} catch (std::overflow_error& e) {
		EXPECT_STREQ("Debordement de bit", e.what());
	}
}
//Expect throw

TEST(FixedTest, constructeurFloatTropAlloc) {
	try {
		fp::fixed<33ul,33ul> f(2.25f);
	} catch (std::overflow_error& e) {
		EXPECT_STREQ("Allocation sur plus de 32bit", e.what());
	}
}


TEST(FixedTest, constructeurDouble) {
	fp::fixed<4ul,4ul> f(2.25d);
	EXPECT_EQ(f.value, 36u);
}

TEST(FixedTest, constructeurDoubleFail) {
	try {
		fp::fixed<1ul,4ul> f(2.0d);
	} catch (std::overflow_error& e) {
		EXPECT_STREQ("Debordement de bit", e.what());
	}
}

TEST(FixedTest, constructeurDoubleTropAlloc) {
	try {
		fp::fixed<33ul,33ul> f(2.0d);
	} catch (std::overflow_error& e) {
		EXPECT_STREQ("Allocation sur plus de 32bit", e.what());
	}
}


TEST(FixedTest, convertionDouble) {
	fp::fixed<4ul,4ul> f(2.25d);
	EXPECT_EQ((double)f, 2.25d);
}









int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
