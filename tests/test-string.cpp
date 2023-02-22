#include <iostream>
#include "../json.h"

using namespace std;

int main(){
  
  JsonRead jread;
  
  //jread.load("{\n}");
  //jread.load("[\n\n]");
  //jread.load("[1]");
  //jread.load("[\"HELLO!\",\"Hello!\"]");
  //jread.load("[{\"hi\":\"World\"},{\"name\":\"Daniel\"}]");
  //jread.load("{\"name\": \"Daniel\",\n\"age\": {\n} }");
  //jread.load("{\"name\": [\"HI!\" ]}");
  
  JsonData dat = jread.load("{\n"
  "  \"name\": \"Daniel\", \n"
  "  \"age\": 18 \n"
  "}");

  JSONObject objMain(&dat);
  cout << objMain["name"].STR << endl;
  
  return 0;
}