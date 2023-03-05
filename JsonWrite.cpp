#include <iostream>
#include <fstream>
#include <string>
#include "./tokens/utils.h"

using namespace std;

#ifndef WRITE_TYPES
#define WRITE_TYPES

class JSObject;
class JSArray;

class JSObject{
  private:
    void addValue(string key, string value);
    string elements;
  public:
    void add(string key, string value);
    void add(string key, int value);
    void add(string key, float value);
    void add(string key, bool value);
    void add(string key, JSObject value);
    void add(string key, JSArray value);
    string toString();
    JSObject();
    JSObject(string key, string value);
    JSObject(string key, int value);
    JSObject(string key, float value);
    JSObject(string key, bool value);
    JSObject(string key, JSObject value);
    JSObject(string key, JSArray value);
};

class JSArray{
  private:
    void addValue(string value);
    string elements;
  public:
    void add(string value);
    void add(int value);
    void add(float value);
    void add(bool value);
    void add(JSObject value);
    void add(JSArray value);
    string toString();
    JSArray();
    JSArray(string value);
    JSArray(int value);
    JSArray(float value);
    JSArray(bool value);
    JSArray(JSObject value);
};

#endif

//JSObject
  
  void JSObject::addValue(string key, string value){
    if(elements != "") elements += ",";
    elements += "\"";
    elements += key;
    elements += "\"";
    elements += ": ";
    elements += value;
  }
  void JSObject::add(string key, string value){
    addValue(key, "\"" + value + "\"");
  }
  void JSObject::add(string key, int value){
    addValue(key, toStr(value));
  }
  void JSObject::add(string key, float value){
    addValue(key, to_string(value));
  }
  void JSObject::add(string key, bool value){
    addValue(key, value ? "true" : "false");
  }
  void JSObject::add(string key, JSObject value){
    addValue(key, value.toString());
  }
  void JSObject::add(string key, JSArray value){
    addValue(key, value.toString());
  }
  
  string JSObject::toString(){
    return "{" + elements + "}";
  }
  
  JSObject::JSObject(){
    elements = "";
  }
  JSObject::JSObject(string key, string value){
    JSObject();
    add(key, value);
  }
  JSObject::JSObject(string key, int value){
    JSObject();
    add(key, value);
  }
  JSObject::JSObject(string key, float value){
    JSObject();
    add(key, value);
  }
  JSObject::JSObject(string key, bool value){
    JSObject();
    add(key, value);
  }
  JSObject::JSObject(string key, JSObject value){
    JSObject();
    add(key, value);
  }
  JSObject::JSObject(string key, JSArray value){
    JSObject();
    add(key, value);
  }

//JSArray

    void JSArray::addValue(string value){
      if(elements != "") elements += ", ";
      elements += value;
    }

    void JSArray::add(string value){
      addValue("\"" + value + "\"");
    }
    void JSArray::add(int value){
      addValue(toStr(value));
    }
    void JSArray::add(float value){
      addValue(to_string(value));
    }
    void JSArray::add(bool value){
      addValue(value ? "true" : "false");
    }
    void JSArray::add(JSObject value){
      addValue(value.toString());
    }
    void JSArray::add(JSArray value){
      addValue(value.toString());
    }
    
    string JSArray::toString(){
      return "[" + elements + "]";
    }
    
    JSArray::JSArray(){
      elements = "";
    }
    JSArray::JSArray(string value){
      JSArray();
      add(value);
    }
    JSArray::JSArray(int value){
      JSArray();
      add(value);
    }
    JSArray::JSArray(float value){
      JSArray();
      add(value);
    }
    JSArray::JSArray(bool value){
      JSArray();
      add(value);
    }
    JSArray::JSArray(JSObject value){
      JSArray();
      add(value);
    }

//

//Write on file json text

class JsonWrite{
  private:
    void writeFile(string jsonText, string nameFile){
      
      ofstream file(nameFile, ios::out);

      if (!file.is_open()) {
        cout << "Failed, could not open file: " << nameFile << endl;
        exit(1);
      }

      file << jsonText;
      file.close();

    }
  public:
    void write(JSObject ob, string nameFile){
      writeFile(ob.toString(), nameFile);
    }
    void write(JSArray ar, string nameFile){
      writeFile(ar.toString(), nameFile);
    }
};

