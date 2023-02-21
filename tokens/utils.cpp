#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool isWhiteSpace(char c){
  switch(c){
    case ' ':
    case '\n':
    case '\r':
    case '\t': return true;
  }
  return false;
}

bool isNumber(char c){
  switch(c){
    case '0': 
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6': 
    case '7':
    case '8':
    case '9': 
    case '-': 
    case '+': 
    case 'e':
    case 'E': 
    case '.': return true;
  }
  return false;
}

bool isStrNumber(string str){
  for (int i = 0; i < str.length(); i++) {
    if (!isNumber(str[i])) return false;
  }
  return true;
}

//Convert to string hexadecimal
string toStringHex(long int i){
  ostringstream ss;
  ss << hex << i;
  string result = ss.str();  
  return result;
}

//Convert to string
string toStr(long int i){
  ostringstream ss;
  ss << i;
  string result = ss.str();  
  return result;
}

//Convert to int
int toInt(string str){
  return isStrNumber(str) ? stoi(str) : 0;
}
