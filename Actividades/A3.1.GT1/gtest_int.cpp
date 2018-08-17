#include <iostream>
#include "gtest/gtest.h"

using namespace std;


TEST (TestName, incrementa_5){
  int valor = 10, incremento = 5;

  valor += incremento;
  ASSERT_EQ(15, valor);
}

int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
