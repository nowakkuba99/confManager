/* --- Includes --- */
#include <gtest/gtest.h>
#include <iostream>
/* --- User includes --- */
#include "test.hpp"

/* --- Main function --- */
int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"Start of tests ...\n";
  return RUN_ALL_TESTS();
}

/* 
--------------------------------------------------------------
Sample class tests
--------------------------------------------------------------
*/
// Check reading one int
TEST(AddingTest, SimpleIntAdd)
{
  const int a = 2, b = 2;
  auto retVal = TestClass::add(a,b);
  EXPECT_EQ(retVal,4);  // 2+2 = 4
}