#include <iostream>
#include "utils.h"

using namespace std;

class JsonString{
  public:
    string change(string jsonString, long int *pos, long int *len, long int *ln){
      long int i = *pos;
      string lexToken = "";
      for(i += 1; i < *len; i++){
        if(jsonString[i] == '\"') break;
        if(jsonString[i] == '\n') {
          cout << "Error \" in line: " << *ln << endl;
          exit(0);
        } else lexToken += jsonString[i];
      }
      *pos = i; // Add position
      return lexToken;
    }
};