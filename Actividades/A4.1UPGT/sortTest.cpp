#include "gtest/gtest.h"
#include "sort.h"

template <class T>
class TypedFixture : public ::testing::TestWithParam<T>{
public:
  void SetUp(){parent = new T;}
  void TearDown(){delete parent;}
  T* parent;
};

typedef ::testing::Types<Child1, Child2, Child3> implementations;

TYPED_TEST_CASE(TypedFixture, implementations);

TYPED_TEST(TypedFixture, implementations){
  int numbers[] = {1,10,8,3,4,6,2,9,7,5};
  this->parent->sort(numbers, 10);
  this->parent->print(numbers, 10);
  int order[] = {1,2,3,4,5,6,7,8,9,10};
  for (int i=0; i<10;i++)
    ASSERT_EQ(numbers[i], order[i]);
}
