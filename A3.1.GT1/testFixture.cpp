#include "gtest/gtest.h"
#include <iostream>
using namespace std;

class Foo{
public:
  void salute(){cout<<"hola"<<endl;}
};

class myFixture : public ::testing::Test{
public:
  static void SetUpTestCase(){f = new Foo;}
  static void TearDownTestCase(){delete f;}
  virtual void SetUp() {cout << "SetUp"<<endl;}
  virtual void TearDown() {cout << "TearDown"<<endl;}
protected:
  static Foo* f;
};

Foo* myFixture::f = 0;


class myEnvironment : public ::testing::Environment{
public:
  void SetUp(){cout << "EnvSetUp"<<endl; foo = new Foo;}
  void TearDown(){cout << "EnvTearD"<<endl; delete foo;}
  static Foo* foo;
};

Foo* myEnvironment::foo = 0;

testing::Environment* const foo_en = testing::AddGlobalTestEnvironment(new myEnvironment);

TEST_F(myFixture, prueba1){
  f->salute();
  ASSERT_TRUE(true);
}

TEST_F(myFixture, prueba2){
  f->salute();
  ASSERT_TRUE(true);
}

TEST(otro, prueba3){
  ASSERT_TRUE(true);
}
