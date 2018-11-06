#include "gtest/gtest.h"
#include "impresora.h"

class Fix : public ::testing::TestWithParam<int>{};
class Chars :public ::testing::TestWithParam<char>{};
class Bools :public ::testing::TestWithParam<bool>{};

class Comb :public ::testing::TestWithParam< ::testing::tuple<int, int>>{
public:
  int num1 = ::testing::get<0>(GetParam());
  int num2 = ::testing::get<1>(GetParam());
};

TEST_P(Fix, test1){
  print_value(GetParam());
}

TEST_P(Chars, test2){
  print_value(GetParam());
}

TEST_P(Bools, test3){
  print_value(GetParam());
}

TEST_P(Comb, test4){
  print_tuple(num1, num2);
}

INSTANTIATE_TEST_CASE_P(local1, Fix, ::testing::Values(1,2,3,4,5,6,7));
char arr[] = {'a','b','c','d'};
INSTANTIATE_TEST_CASE_P(local2, Chars, ::testing::ValuesIn(arr));
INSTANTIATE_TEST_CASE_P(local3, Bools, ::testing::Values(true, false, true));
INSTANTIATE_TEST_CASE_P(local4, Comb, ::testing::Combine(::testing::Range(1,10,1), ::testing::Range(1,10,1)));
