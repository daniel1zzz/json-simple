#include <iostream>
#include "utils.h"
#include "../type/JsonData.h"
#include "JsonWhiteSpace.h"
#include "JsonString.h"
#include "JsonNumber.h"

using namespace std;

class JsonObject{
  public:
    string parseArray(string jsonString, JsonData *dat, long int *pos, long int *len, long int *ln){
            
      long int i = *pos;
      string arrayToken = dat->setArray();
      string val = "";
      long int arrPos = 0;

      for(i += 1; i < *len; i++){
        
        if(isWhiteSpace(jsonString[i])) {
          JsonWhiteSpace(jsonString, &i, len, ln);
          //cout << "CWS: " << jsonString[i+1] << endl;
          if(
            jsonString[i] != ']' &&
            !isWhiteSpace(jsonString[i])
          ) i--;
          else if(jsonString[i] == ']') i--;
          else if(!isWhiteSpace(jsonString[i])) {
            cout << "Error " << jsonString[i] << " ws en linea " <<
            *ln << ":" << i << endl;
            exit(0);
          }
        } else if(jsonString[i] == ']') break;
        else {
          val = JsonObject().parseValue(jsonString, dat, &i, len, ln);
          i += 1;
          //cout << "ARRAY: " << jsonString[i] << " " << i << endl;
          if(isWhiteSpace(jsonString[i])) JsonWhiteSpace(jsonString, &i, len, ln);
          //cout << "ARRAY1: " << jsonString[i] << " " << i << endl;
          if(jsonString[i] == ',' || jsonString[i] == ']') {
            dat->setValue(dat->arrays[arrayToken] + " " + toStr(arrPos++), val);
            //cout << "R: " << dat->arrays[arrayToken] + " " + toStr(arrPos) << " " << val << endl;
            if(jsonString[i] == ']') i--;
          }
        }
        
      }

      //Array length
      dat->setValue(dat->arrays[arrayToken] + " " + "len", toStr(arrPos));

      *pos = i; // Add position
      return arrayToken;

    }
    string parseValue(string jsonString, JsonData *dat, long int *pos, long int *len, long int *ln){
      long int i = *pos;
      string value = "";
      for(; i < *len; i++){
        if (isWhiteSpace(jsonString[i])) { //white space
          JsonWhiteSpace(jsonString, pos, len, ln);
        } else if(jsonString[i] == '\"') { //string
          value = JsonString().change(jsonString, &i, len, ln);
          break;
        } else if( //false 
          jsonString[i] == 'f' && jsonString[i+1] == 'a' &&
          jsonString[i+2] == 'l' && jsonString[i+3] == 's' &&
          jsonString[i+4] == 'e') {
            value = "false";
            i += 4;
            break;
        } else if( //true
          jsonString[i] == 't' && jsonString[i+1] == 'r' &&
          jsonString[i+2] == 'u' && jsonString[i+3] == 'e') {
            value = "true";
            i += 3;
            break;
        } else if( //null
          jsonString[i] == 'n' && jsonString[i+1] == 'u' &&
          jsonString[i+2] == 'l' && jsonString[i+3] == 'l') {
            value = "null";
            i += 3;
            break;
        } else if(isNumber(jsonString[i])) { //Number
          value = JsonNumber().change(jsonString, &i, len);
          i--;
          break;
        } else if(jsonString[i] == '{') { //Object
          value = JsonObject().change(jsonString, dat, &i, len, ln);
          i--;
          break;
        } else if(jsonString[i] == '[') { //Array
          value = JsonObject().parseArray(jsonString, dat, &i, len, ln);
          //cout << "arr " << jsonString[i] << endl;
          //i--;
          break;
        } else {
          cout << "Error value linea: " << *ln << endl;
          exit(0);
        }
      }
      *pos = i; // Add position
      return value;
    }
    string change(string jsonString, JsonData *dat, long int *pos, long int *len, long int *ln){
      
      long int i = *pos;
      string objToken = dat->setObject();

      for(i += 1; i < *len; i++){
        
        if(isWhiteSpace(jsonString[i])) {
          JsonWhiteSpace(jsonString, &i, len, ln);
          if(
            jsonString[i] != '\"' &&
            jsonString[i] != '}' &&
            !isWhiteSpace(jsonString[i])
          ) {
            cout << "Error " << jsonString[i] << " ws en linea " <<
            *ln << ":" << i << endl;
            exit(0);
          } else if(jsonString[i] == '\"') i--;
          else if(jsonString[i] == '}') i--;
        }
        else if(jsonString[i] == '\"') {
          
          string key = JsonString().change(jsonString, &i, len, ln); 
          i++;
          if(isWhiteSpace(jsonString[i])) JsonWhiteSpace(jsonString, &i, len, ln);
          if (jsonString[i] == ':') {
            i++;
            string val = parseValue(jsonString, dat, &i, len, ln);
            i++;
            if(isWhiteSpace(jsonString[i])) JsonWhiteSpace(jsonString, &i, len, ln);
            //cout << "CS: " << jsonString[i-1] << endl;
            if (jsonString[i] == ',' || jsonString[i] == '}') {
              //objToken = dat->setObject();
              dat->setValue(dat->objects[objToken] + " " + key, val);
              //cout << "R: " << key << " " << val << endl;
              if(jsonString[i] == '}') i--;
            }
            else {
              cout << "Error , linea: " << *ln << endl;
              exit(0);
            }
          } else {
            cout << "Error : linea " << *ln << endl;
            exit(0);
          }
        
        } else if(jsonString[i] == '}') break;
        else {
          cout << "Error " << jsonString[i] << " en linea " <<
          *ln << endl;
          exit(0);
        }
        
      }

      *pos = i + 1; // Add position
      return objToken;

    }
};