#include <iostream>
#include "utils.h"

using namespace std;

class JsonWhiteSpace{
  public:
    JsonWhiteSpace(string jsonString, long int *pos, long int *len, long int *ln){
      long int i = *pos;
      for(; i < *len; i++){
        if (jsonString[i] == '\n') {
          *ln += 1;
          //if(i == *pos) i++;
          //break;
        } else if(!isWhiteSpace(jsonString[i])) break;
      }
      *pos = i; // Add position
    }
};