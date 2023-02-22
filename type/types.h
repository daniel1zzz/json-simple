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
    float getFloat(string key);
    bool getBool(string key);
    JSONObject getObject(string key);
    JSONArray getArray(string key);

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
    float getFloat(int pos);
    bool getBool(int pos);
    JSONObject getObject(int pos);
    JSONArray getArray(int pos);

    JSONArray(JsonData *data);
    JSONArray();

};

class JSONValues{
  public:
    string STR;
    int INT;
    float FLO;
    bool BOO;
    JSONObject OBJ;
    JSONArray ARR;
};

#include "types.cpp"

#endif