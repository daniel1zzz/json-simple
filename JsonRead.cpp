#include <fstream>
#include <iostream>
#include <sstream>
#include "./tokens/utils.h"
#include "./type/JsonData.h"
#include "./tokens/JsonObject.h"
#include "./tokens/JsonWhiteSpace.h"

using namespace std;

class JsonRead {
  private:
    JsonData dat;
  public:
    JsonData load(string jsonString){
      //Values Globals
      long int len = jsonString.length();
      long int pos = 0;
      long int ln = 1;
      
      for(; pos < len; pos++){
        if(jsonString[pos] == '{') {
          //Json Object
          JsonObject().change(jsonString, &dat, &pos, &len, &ln);
        } else if(jsonString[pos] == '[') {
          //Json Array
          JsonObject().parseArray(jsonString, &dat, &pos, &len, &ln);
        } else if(isWhiteSpace(jsonString[pos])) {
          //White Space
          JsonWhiteSpace(jsonString, &pos, &len, &ln);
        } else {
          cout << "Error " << jsonString[pos] << " linea: " << ln << endl;
          exit(0);
        }
      }

      //cout<< "POS: " << pos << endl;
      //cout<< "LNS: " << ln << endl;

      return dat;

    }
    JsonData loadFile(string filename){
      string jsonString = "";

      ifstream inputFile(filename.c_str());
      ostringstream contents;

      if (inputFile.is_open()) {
        contents << inputFile.rdbuf();
        inputFile.close();
        jsonString = contents.str();
      } else {
        cout << "Failed, could not open file: " << filename << endl;
        exit(1);
      }
      
      //cout << "json-> " << jsonString << endl;
      return load(jsonString);
    }
};