#include <iostream>
#include "../json.h"

using namespace std;

int main(){
  
  string nameFile = "./resources/config.json";
  JsonData dat = JsonRead().loadFile(nameFile);
  JSONObject objMain(&dat);
  
  //Edit value object array position 0
  bool state = objMain["array"].ARR.set(0, 3); 
  //objMain["array"].ARR.set(1, (float) 2.6);

  cout << "State edit object: " << state << endl;
  cout << objMain["array"].ARR[0].INT << endl;
  
  return 0;
}