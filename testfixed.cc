#include <iostream>
#include <iomanip>
#include <stdexcept>

#include "gtest/gtest.h"

#include "fixed.cc"



//***************Test Contructeur OK*********************
TEST(FixedTest, constructeurFloat) {
	fp::fixed<4ul,4ul> f0(2.25f);
	EXPECT_EQ(f0.value, 36u);
	fp::fixed<2ul,2ul> f1(1.75f);
	EXPECT_EQ(f1.value, 7u);
	fp::fixed<2ul,2ul> f2(-2.0f);
	EXPECT_EQ(f2.value, -8);
}
TEST(FixedTest, constructeurDouble) {
	fp::fixed<4ul,4ul> f0(2.25d);
	EXPECT_EQ(f0.value, 36u);
	fp::fixed<2ul,2ul> f1(1.75d);
	EXPECT_EQ(f1.value, 7u);
	fp::fixed<2ul,2ul> f2(-2.0d);
	EXPECT_EQ(f2.value, -8);
}

//***************Test Contructeur FAIL*********************
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
TEST(FixedTest, constructeurDoubleFailMax) {
	try {
		fp::fixed<2ul,2ul> f(1.76d);
	} catch (std::overflow_error& e) {
		EXPECT_STREQ("Debordement de bit", e.what());
	}
}

TEST(FixedTest, constructeurDoubleFailMin) {
	try {
		fp::fixed<2ul,2ul> f(-2.01d);
	} catch (std::overflow_error& e) {
		EXPECT_STREQ("Debordement de bit", e.what());
	}
}


//*********************Test Convertion réel*******************************
TEST(FixedTest, convertionDouble) {
	fp::fixed<4ul,4ul> f(2.25d);
	EXPECT_EQ((double)f, 2.25d);
}

TEST(FixedTest, convertionFloat) {
	fp::fixed<4ul,4ul> f(2.25f);
	EXPECT_EQ((float)f, 2.25f);
}

//***************Test Copy Constructor*********************
TEST(FixedTest, CopyConstructorMemeType) {
	fp::fixed<4ul,4ul> f0(2.25f);
	fp::fixed<4ul,4ul> f1(f0);
	EXPECT_EQ(f1.value, 36u);
}
TEST(FixedTest, CopyConstructorTypeDifferent) {
	fp::fixed<4ul,4ul> f0(2.25f);
	fp::fixed<4ul,3ul> f1(f0);
	EXPECT_EQ(f1.value, 18u);
	fp::fixed<4ul,2ul> f2(f0);
	EXPECT_EQ(f2.value, 9u);
	fp::fixed<4ul,1ul> f3(f0);
	EXPECT_EQ(f3.value, 4u);
	fp::fixed<4ul,5ul> f4(f0);
	EXPECT_EQ(f4.value, 72u);
	fp::fixed<5ul,5ul> f5(f0);
	EXPECT_EQ(f5.value, 72u);
}

//*****************Test CopyAssignement *************************
TEST(FixedTest, CopyAssignementMemeType) {
	fp::fixed<4ul,4ul> f0(2.25f);
	fp::fixed<4ul,4ul> f1(1.75f);
	f1=f0;
	EXPECT_EQ(f1.value, 36u);
}
TEST(FixedTest, CopyAssignementTypeDifferent) {
	fp::fixed<4ul,4ul> f0(2.25f);
	fp::fixed<4ul,4ul> f1(1.);
	fp::fixed<4ul,4ul> f2(1.1f);
	fp::fixed<4ul,4ul> f3(-4.);
	fp::fixed<4ul,4ul> f4(2.25f);
	fp::fixed<4ul,4ul> f5(4.44f);
	f1=f0;
	f2=f1;
	f3=f2;
	f4=f3;
	f5=f4;
	EXPECT_EQ(f1.value, 36u);
	EXPECT_EQ(f2.value, 36u);
	EXPECT_EQ(f3.value, 36u);
	EXPECT_EQ(f4.value, 36u);
	EXPECT_EQ(f5.value, 36u);
}
//*****************Test FixedTraits *************************

TEST(FixedTest,min){
	fp::fixed<2,2> f=fp::fixed_traits<fp::fixed<2,2>>::min();
	EXPECT_EQ(f.value,-8);
}

TEST(FixedTest,max){
	fp::fixed<2,2> f=fp::fixed_traits<fp::fixed<2,2>>::max();
	EXPECT_EQ(f.value,7u);
}

TEST(FixedTest,lowest){
	fp::fixed<2,2> f=fp::fixed_traits<fp::fixed<2,2>>::lowest();
	EXPECT_EQ((double)f,0.25d);
}
//*******************Test Operateur + (TODO)********************
TEST(FixedTest, operateurPlus) {
	fp::fixed<4ul,4ul> f(2.25d);
	fp::fixed<4ul,4ul> h(2.25d);
	EXPECT_EQ(f+h,72);
}

TEST(FixedTest, operateurPlusTypeDifferent) {
	fp::fixed<3ul,4ul> f(2.25d);
	fp::fixed<4ul,4ul> h(2.25d);
	EXPECT_EQ(f+h,72);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
