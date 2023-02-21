#include <iostream>
#include "../tokens/utils.h"
#include "types.h"
#include "JsonData.h"

using namespace std;

//JSONObject

    JSONValues JSONObject::operator[](string key){
      JSONValues jv;
      jv.STR = getString(key);
      jv.INT = getInt(key);
      jv.BOO = getBool(key);
      jv.FLO = getFloat(key);
      if(dat->objects[getString(key)] != "") jv.OBJ = getObject(key);
      if(dat->arrays[getString(key)] != "") jv.ARR = getArray(key);
      return jv;
    }

    string JSONObject::getString(string key){
      return dat->values[dat->objects[id] + " " + key];
    }

    int JSONObject::getInt(string key){
      return toInt(getString(key));
    }

    float JSONObject::getFloat(string key){
      float res;
      try {
        res = std::stof(getString(key));
      } catch (const std::invalid_argument& e) {
        return 0.0;
      }
      return res;
    }

    bool JSONObject::getBool(string key){
      return getString(key) == "true";
    }
    
    JSONObject JSONObject::getObject(string key){
      string val = getString(key);
      JSONObject ob;
      ob.dat = dat;
      if(dat->objects[val] == "") {
        cout << "Error " << key << " no es un object!" << endl;
        exit(0);
      } else ob.id = val;
      return ob;
    }

    JSONArray JSONObject::getArray(string key){
      string val = getString(key);
      JSONArray arr;
      arr.dat = dat;
      if(dat->arrays[val] == "") {
        cout << "Error " << key << " no es un array!" << endl;
        exit(0);
      } else arr.id = val;
      return arr;
    }

    bool JSONObject::set(string key, string val){
      string elt = getString(key);
      if(dat->objects[elt] != "") {
        cout << "Error " << key << " es un object!" << endl;
        return false; //exit(0);
      } else if(dat->arrays[elt] != "") {
        cout << "Error " << key << " es un array!" << endl;
        return false; //exit(0);
      }
      dat->values[dat->objects[id] + " " + key] = val;
      return true;
    }

    bool JSONObject::set(string key, int val){
      return set(key, toStr(val));
    }

    bool JSONObject::set(string key, float val){
      return set(key, to_string(val));
    }

    bool JSONObject::set(string key, bool val){
      return set(key, val ? "true" : "false");
    }

    JSONObject::JSONObject(JsonData *data){
      this->dat = data;
      string identifier = dat->objects[
        data->defaultValue + "Object"
      ] == "" ? "Array" : "Object";
      
      if(identifier == "Array"){
        cout << "Error al asignar Array en Object!" << endl;
        exit(0);
      }

      this->id = data->defaultValue + identifier;
      //cout << identifier << endl;
    }
    JSONObject::JSONObject(){}

//JSONArray
    
    JSONValues JSONArray::operator[](int pos){
      JSONValues jv;
      jv.STR = getString(pos);
      jv.INT = getInt(pos);
      jv.BOO = getBool(pos);
      jv.FLO = getFloat(pos);
      if(dat->objects[getString(pos)] != "") jv.OBJ = getObject(pos);
      if(dat->arrays[getString(pos)] != "") jv.ARR = getArray(pos);
      return jv;
    }

    string JSONArray::getString(int pos){
      string val = dat->values[dat->arrays[id] + " " + toStr(pos)];
      int len = toInt(dat->values[dat->arrays[id] + " " + "len"]);
      if(pos > len-1 || pos < 0){
        cout << "Index invalido: " << pos << " length: " << len << endl;
      }
      return val;
    }

    int JSONArray::getInt(int pos){
      return toInt(getString(pos));
    }

    float JSONArray::getFloat(int pos){
      float res;
      try {
        res = std::stof(getString(pos));
      } catch (const std::invalid_argument& e) {
        return 0.0;
      }
      return res;
    }

    bool JSONArray::getBool(int pos){
      return getString(pos) == "true";
    }
    
    JSONObject JSONArray::getObject(int pos){
      string val = getString(pos);
      JSONObject ob;
      ob.dat = dat;
      if(dat->objects[val] == "") {
        cout << "Error array [" << pos << "] no es un object!" << endl;
        exit(0);
      } else ob.id = val;
      return ob;
    }

    JSONArray JSONArray::getArray(int pos){
      string val = getString(pos);
      JSONArray arr;
      arr.dat = dat;
      if(dat->arrays[val] == "") {
        cout << "Error array [" << pos << "] no es un array!" << endl;
        exit(0);
      } else arr.id = val;
      return arr;
    }

    bool JSONArray::set(int pos, string val){
      string elt = getString(pos);
      if(dat->objects[elt] != "") {
        cout << "Error " << pos << " es un object!" << endl;
        return false; //exit(0);
      } else if(dat->arrays[elt] != "") {
        cout << "Error " << pos << " es un array!" << endl;
        return false; //exit(0);
      }
      dat->values[dat->arrays[id] + " " + toStr(pos)] = val;
      return true;
    }

    bool JSONArray::set(int pos, int val){
      return set(pos, toStr(val));
    }

    bool JSONArray::set(int pos, float val){
      return set(pos, to_string(val));
    }

    bool JSONArray::set(int pos, bool val){
      return set(pos, val ? "true" : "false");
    }

    JSONArray::JSONArray(JsonData *data){
      this->dat = data;
      string identifier = dat->objects[
        data->defaultValue + "Object"
      ] == "" ? "Array" : "Object";
      
      if(identifier == "Object"){
        cout << "Error al asignar Object en Array!" << endl;
        exit(0);
      }

      this->id = data->defaultValue + identifier;
      //cout << identifier << endl;
    }
    JSONArray::JSONArray(){}

//