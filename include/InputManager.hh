#ifndef InputManager_h
#define InputManager_h 1

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <stdexcept>
#include <vector>

#include <TMath.h>

using namespace std;

class InputManager {

  public:
  InputManager();
 ~InputManager();
  void ReadFile(const char* afilename);
  template <class T>
  void GetVariable(string aname,T& value);

  private:
  const char* filename;
  std::map <string,string> config_var;
  std::map <string,string>::iterator it;

};

template <class T>
void InputManager::GetVariable(string name,T& value) {

  it = config_var.find(name);

  if (it==config_var.end()) {
    cerr << "Error in <InputManager::GetVariable>: Variable " << name << " is not in "<< filename << endl;
    exit(1);
  }

  stringstream sstr;
  sstr << it->second;

  sstr >> value;

}

#endif
