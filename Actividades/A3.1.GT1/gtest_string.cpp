#include <iostream>
#include "gtest/gtest.h"

using namespace std;

class MiClase{
  string id;
public:
  MiClase(string _id) : id(_id){} //Constructor
  string getID(){return id;}
};

TEST (TestName, testString){
  MiClase mc("prueba");
  string valor = mc.getID();
  ASSERT_STREQ ("prueba", valor.c_str());
}

int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
