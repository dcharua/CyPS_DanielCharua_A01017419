#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;
using ::testing::Mock;

class DataBaseConnect{
public:
  virtual bool login(string username, string password){return true;}
  virtual bool logout(string username){return true;}
  virtual int fetchRecord(){return 1;}
};

class MyDatabase{
  DataBaseConnect & dbConnect;
public:
  MyDatabase(DataBaseConnect & _dbC) : dbConnect(_dbC) {}
  int Init(string uname, string passwd){
    if(dbConnect.login(uname, passwd)!= true){
      cout << "Falued to connect" << endl;
      return -1;
    } else {
      cout << "Connected" <<endl;
      return 1;
    }
  }
  int Out(string uname){
    if(dbConnect.logout(uname)!= true){
      cout << "Falued to logout" << endl;
      return -1;
    } else {
      cout << "Logged out" <<endl;
      return 1;
    }
  }
  int Fetched(){
    if (dbConnect.fetchRecord()!=true){
      cout << "Failed to Fetched" << endl;
      return -1;
    }else{
      cout << "Fecthed" <<endl;
      return 1;
    }
  }
};

class MockDB : public DataBaseConnect{
public:
  MOCK_METHOD0(fetchRecord, int());
  MOCK_METHOD1(logout, bool(string uname));
  MOCK_METHOD2(login, bool(string uname, string passwd));
};

TEST(MyDBTest, LoginTest){
  MockDB mdb;
  MyDatabase db(mdb);
  EXPECT_CALL(mdb, login("username", "password"))
  .Times(1)
  .WillOnce(Return(true));
  // ACT
  int retValue = db.Init("username", "password");
  //Assert
  EXPECT_EQ(1, retValue);
}

TEST(MyDBTest, LogoutTest){
  MockDB mdb;
  MyDatabase db(mdb);
  EXPECT_CALL(mdb, logout("username"))
  .Times(1)
  .WillOnce(Return(true));
  // ACT
  int retValue = db.Out("username");
  //Assert
  EXPECT_EQ(1, retValue);
}

TEST(MyDBTest, FetchTest){
  MockDB mdb;
  MyDatabase db(mdb);
  EXPECT_CALL(mdb, fetchRecord())
  .Times(1)
  .WillOnce(Return(true));
  // ACT
  int retValue = db.Fetched();
  //Assert
  EXPECT_EQ(1, retValue);
}


int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
