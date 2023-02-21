#ifndef TYPES_H
#define TYPES_H

#include <iostream>
#include "JsonData.h"
using namespace std;

class JSONArray;
class JSONObject;
class JSONValues;

class JSONObject{
  public:
    string id;
    JsonData *dat;
    
    //Read values
    JSONValues operator[](string key);
    string getString(string key);
    int getInt(string key);
    bool getBool(string key);
    JSONObject getObject(string key);
    JSONArray getArray(string key);

    //Edit values, todo bien true
    bool setString(string key, string val);
    bool setInt(string key, int val);
    bool setBool(string key, bool val);

    JSONObject(JsonData *data);
    JSONObject();

};

class JSONArray{
  public:
    string id;
    JsonData *dat;

    //Read values
    JSONValues operator[](int pos);
    string getString(int pos);
    int getInt(int pos);
    bool getBool(int pos);
    JSONObject getObject(int pos);
    JSONArray getArray(int pos);

    //Edit values, todo bien true
    bool setString(int pos, string val);
    bool setInt(int pos, int val);
    bool setBool(int pos, bool val);
  
    JSONArray(JsonData *data);
    JSONArray();

};

class JSONValues{
  public:
    string STR;
    int INT;
    //float FLO;
    bool BOO;
    JSONObject OBJ;
    JSONArray ARR;
};

#include "types.cpp"

#endif