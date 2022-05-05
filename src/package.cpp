#include "../inc/package.h"


Package::Package(){
    Key = 0;
    Message = "";
}


Package::Package(std::string message, int key){
    Message = message;
    Key = key;
}


std::ostream &operator << (std::ostream &out, Package const &pack){
  out << "Zawartosc: " << pack.GetMessage() << " Klucz: " << pack.GetKey() << std::endl;
  return out;
}
