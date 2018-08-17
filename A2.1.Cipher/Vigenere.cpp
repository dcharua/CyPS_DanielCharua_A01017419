//Daniel Charua A0101719 - Code based on https://www.thecrazyprogrammer.com/2017/08/vigenere-cipher-c-c.html

#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
  string msg, key, ecr, dec, newKey;
  cout << "Write a message to encrypt: ";
  getline(cin, msg);
  cout << "Input the key: ";
  getline(cin, key);

  //generating new key
  for(int i = 0, j = 0; i < msg.length(); ++i, ++j){
      if(j == key.length())
          j = 0;
      newKey += key[j];
  }


  //encryption
  for(int i = 0; i < msg.length(); ++i)
      ecr += ((msg[i] + newKey[i]) % 26) + 'A';
      
  //decryption
  for(int i = 0; i <  msg.length(); ++i)
      dec += (((ecr[i] - newKey[i]) + 26) % 26) + 'A';

  cout<<"Original Message: "<< msg <endl;
  cout<<"Key: "<<key << endl;
  cout<<"New Generated Key: "<< newKeyz << endl;
  cout<<"Encrypted Message: "<< ecr << endl;
  cout<<"Decrypted Message: "<< dec << endl;

  return 0;
}
