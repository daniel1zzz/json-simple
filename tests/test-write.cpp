#include <iostream>
#include "../json.h"

using namespace std;

int main(){

  JSObject ob("name", "Daniel");
  ob.add("age", 18);
  ob.add("pie", (float) 2.35);
  ob.add("men", true);
  ob.add("dev", JSArray((string)"smartphone"));
  ob.add("ot", JSObject("key", (string)"1"));

  cout << ob.toString() << endl;
  JsonWrite(ob, "./resources/file.json");

  return 0;
}