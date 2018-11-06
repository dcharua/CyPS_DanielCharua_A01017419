//Daniel Charua - A01017419 -7/09/18
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "gtest/gtest.h"
using namespace std;

class AsciiArt{
public:
  AsciiArt (string filename){file = filename;}
  string image, file, compressed;
  int compressedInt[1000];

  void read(){
    ifstream f(file);
      stringstream buf;
      buf << f.rdbuf();
      image = buf.str();
     cout << image;
  };

  void compress(){
    int counter = 1, j = 0;
    for (int i = 0; i < image.length(); i++){
      if (image[i] == image[i+1]){
        counter++;
      }else{
        compressed+=image[i];
        compressedInt[j++]=counter;
        counter = 1;
      }
    }

  };

  string decompress(){
    string imageBack;
    for(int i=0; i<compressed.length(); i++){
      for (int k=0; k<compressedInt[i]; k++){
        imageBack += compressed[i];
      }
    }
    return imageBack;
  };
};

TEST (TestName, rabit){
  AsciiArt a("rabit.art");
  a.read();
  a.compress();
  ASSERT_STREQ (a.image.c_str(), a.decompress().c_str());
}

TEST (TestName, arch){
  AsciiArt a("arch.art");
  a.read();
  a.compress();
  ASSERT_STREQ (a.image.c_str(), a.decompress().c_str());
}

TEST (TestName, bart){
  AsciiArt a("bart.art");
  a.read();
  a.compress();
  ASSERT_STREQ (a.image.c_str(), a.decompress().c_str());
}

TEST (TestName, beer){
  AsciiArt a("beer.art");
  a.read();
  a.compress();
  ASSERT_STREQ (a.image.c_str(), a.decompress().c_str());
}

TEST (TestName, dog){
  AsciiArt a("dog.art");
  a.read();
  a.compress();
  ASSERT_STREQ (a.image.c_str(), a.decompress().c_str());
}

TEST (TestName, football){
  AsciiArt a("football.art");
  a.read();
  a.compress();
  ASSERT_STREQ (a.image.c_str(), a.decompress().c_str());
}

TEST (TestName, hommer){
  AsciiArt a("hommer.art");
  a.read();
  a.compress();
  ASSERT_STREQ (a.image.c_str(), a.decompress().c_str());
}

TEST (TestName, max){
  AsciiArt a("max.art");
  a.read();
  a.compress();
  ASSERT_STREQ (a.image.c_str(), a.decompress().c_str());
}

TEST (TestName, mickt){
  AsciiArt a("mickt.art");
  a.read();
  a.compress();
  ASSERT_STREQ (a.image.c_str(), a.decompress().c_str());
}

TEST (TestName, soccer){
  AsciiArt a("soccer.art");
  a.read();
  a.compress();
  ASSERT_STREQ (a.image.c_str(), a.decompress().c_str());
}
