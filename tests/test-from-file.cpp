#include <iostream>
#include "../json.h"

using namespace std;

int main(){
  
  string nameFile = "./resources/config.json";
  JsonData dat = JsonRead().loadFile(nameFile);
  JSONObject objMain(&dat);
  
  cout << objMain["array"].ARR[0].INT << endl;
  
  return 0;
}