#include <iostream>
#include "../json.h"

using namespace std;

int main(){
  
  string nameFile = "./resources/config.json";
  JsonData dat = JsonRead().loadFile(nameFile);
  JSONObject objMain(&dat);

  objMain["array"].ARR.set(0, 3); //Edit value object array position 0
  //objMain["array"].ARR.set(1, (float) 2.6);

  cout << objMain["array"].ARR[0].INT << endl;
  
  return 0;
}