#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;
using ::testing::InSequence;
class Tortuga {
public:
  virtual ~Tortuga() {}
  virtual void PenUp() {}
  virtual void PenDown() {cout << "PenDown";}
  virtual int GetX() {return 1;}
  virtual int GetY() {return 1;}
  virtual void Forward(int distancia) {cout << distancia << endl;}
  virtual void Turn(int grados){cout << grados << endl;}
  virtual void GoTo(int x, int y) {cout << x << y << endl;}
};

class MockTortuga : public Tortuga {
 public:
  MOCK_METHOD0(PenUp, void());
  MOCK_METHOD0(PenDown, void());
  MOCK_METHOD0(GetX, int());
  MOCK_METHOD0(GetY, int());
  MOCK_METHOD1(Forward, void(int distancia));
  MOCK_METHOD1(Turn, void(int grados));
  MOCK_METHOD2(GoTo, void(int x, int y));
};

class Pintor {
	Tortuga &t;
public:
  Pintor (Tortuga &_t): t(_t) {}
  void pinta(){ t.PenDown();
    t.Forward(1);
    t.Turn(45);
    t.Forward(1);
    t.Turn(45);
    t.Forward(1);
    t.Turn(45);
    t.Forward(1);
    t.PenUp();
  }
};

TEST(PruebaDibujo, DibujaAlgo) {
	// Arrange
  MockTortuga turtle;
  Pintor t(turtle);
  {InSequence algo;
    EXPECT_CALL(turtle, PenDown()).Times(1);
    EXPECT_CALL(turtle, Forward(1)).Times(1);
    EXPECT_CALL(turtle, Turn(45)).Times(1);
    EXPECT_CALL(turtle, Forward(1)).Times(1);
    EXPECT_CALL(turtle, Turn(45)).Times(1);
    EXPECT_CALL(turtle, Forward(1)).Times(1);
    EXPECT_CALL(turtle, Turn(45)).Times(1);
    EXPECT_CALL(turtle, Forward(1)).Times(1);
    EXPECT_CALL(turtle, PenUp()).Times(1);
  }
	// Act
  t.pinta();
	// Assert
	//
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
