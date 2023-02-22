#include <iostream>
#include <map>
#include <string>
#include "../tokens/utils.h"

using namespace std;

class JsonData{
  private:
    long int position;
    string tokenID(string type){
      string result = "0x";
      result += toStr(++position);
      result += "x";
      result += type;
      return result;
    }
  public:
    map<string, string> values;
    map<string, string> objects;
    map<string, string> arrays;
    string defaultValue;
    JsonData(){
      defaultValue = "";
      defaultValue = tokenID("");
      position -= 1;
    }
    void setValue(string key, string value){
      values.insert(pair<string, string>(key, value));
    }
    string setObject(){
      string key = tokenID("Object");
      string value = tokenID("ID");
      objects.insert(pair<string, string>(key, value));
      return key;
    }
    string setArray(){
      string key = tokenID("Array");
      string value = tokenID("ID");
      arrays.insert(pair<string, string>(key, value));
      return key;
    }
    
};
