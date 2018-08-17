#include <iostream>
#include "gtest/gtest.h"

using namespace std;


TEST (TestName, SubTest_1){
  ASSERT_TRUE (1 == 1);
  cout << "Despues de asercion" <<endl;
  ASSERT_TRUE (1 == 1);
}

TEST (TestName, SubTest_2){
  ASSERT_TRUE (1 == 2);
}

int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
