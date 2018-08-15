//Daniel Charua A01017419 - Code based on: https://www.thecrazyprogrammer.com/2016/11/caesar-cipher-c-c-encryption-decryption.html

#include <stdio.h>
#include <iostream>

using namespace std;

string encrypt(string msn, int key);
string decrypt(string msn, int key);

int main(){
  string msg, ecr, dec;
  int key;
  cout << "Write a message to encrypt: ";
  getline(cin, msg);
  cout << "Input the key: ";
  cin >> key;
  ecr = encrypt(msg, key);
  cout << "Encrypted message: " << ecr << endl;
  dec = decrypt(ecr, key);
  cout << "Decrypted message: " << dec << endl << "C++ program out!" << endl;
  return 0;
}


string encrypt(string msn, int key){
  unsigned char c;
  for(int i = 0; i < msn.size(); i++){
    if(msn[i] >= 'a' && msn[i] <= 'z'){
      c = msn[i] + key;
      if( c > 'z')
        c =   c - 'z' + 'a' - 1;
      msn[i] = c;
    }
    else if(msn[i] >= 'A' && msn[i] <= 'Z'){
      c = msn[i] + key;
      if(c > 'Z')
        c = c - 'Z' + 'A' - 1;
      msn[i] = c;
    }
  }
  return msn;
}

string decrypt(string msn, int key){
  unsigned char c;
  for(int i = 0; i < msn.size(); i++){
    if(msn[i] >= 'a' && msn[i] <= 'z'){
      c = msn[i] - key;
      if( c < 'a')
        c  =   c  + 'z' - 'a' + 1;
      msn[i] = c;
    }
    else if(msn[i] >= 'A' && msn[i] <= 'Z'){
      c = msn[i] - key;
      if(c > 'a')
        c = c + 'Z' - 'A' + 1;
      msn[i] = c;
    }
  }
  return msn;
}
