#include <iostream>
#include "utils.h"

using namespace std;

class JsonNumber{
  public:
    string change(string jsonString, long int *pos, long int *len){
      long int i = *pos;
      string lexToken = "";
      for(; i < *len; i++){
        if(!isNumber(jsonString[i])) break;
        else lexToken += jsonString[i];
      }
      *pos = i; // Add position
      return lexToken;
    }
};