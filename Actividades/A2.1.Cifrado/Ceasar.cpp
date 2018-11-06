//Daniel Charua A01017419 - Code based on: https://www.thecrazyprogrammer.com/2016/11/caesar-cipher-c-c-encryption-decryption.html

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

string encrypt(string msn, int key);
string decrypt(string msn, int key);
void readFile(string file);
void readConsole();
void printResult(string msg, string ecr, string dec);

int main(){
  int opt;
  cout << "1.- Read form file"<<endl;
  cout << "2.- Read form console"<<endl;
  cin >> opt;
  cin.ignore();
  if (opt == 1)
    readFile("diccionario.txt");
  else if (opt == 2)
    readConsole();
  else
    cout << "Invalid Option Progarm terminated"<<endl;
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
      if(c < 'A')
        c = c + 'Z' - 'A' + 1;
      msn[i] = c;
    }
  }
  return msn;
}

void readFile(string file){
  string msg, ecr, dec;
  ifstream infile(file);
  string line;
  while (std::getline(infile, line)){
    msg = line;
    ecr = encrypt(msg, 15);
    dec = decrypt(ecr, 15);
    printResult(msg, ecr, dec);
  }
}

void readConsole(){
  string msg, ecr, dec;
  int key;
  cout << "Write a message to encrypt: ";
  getline(cin, msg);
  cout << "Input the key: ";
  cin >> key;
  ecr = encrypt(msg, key);
  dec = decrypt(ecr, key);
  printResult(msg, ecr, dec);
}

void printResult(string msg, string ecr, string dec){
    cout << "Original message: " << msg << endl;
    cout << "Encrypted message: " << ecr << endl;
    cout << "Decrypted message: " << dec << endl << "C++ program out!" << endl;
}
