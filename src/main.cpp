

#include "../inc/sender.h"
#include "../inc/receiver.h"



int main(){
  srand (time (NULL));

  Sender jan;
  Receiver anna;
  std::string message = "abcd-efgh-ijkl-mnop-qrs";
  Package tmp_pack;

  std::cout << "Wiadomosc: " << message << std::endl << std::endl;

  std::cout << "Wiadomosc podzielona na pakiety:" << std::endl;

  jan.DivideMessage(message);
  std::cout << jan;

  std::cout << std::endl << "Wiadomosc wyslana w losowej kolejnosci:" << std::endl;
  if(!jan.SendMessage(&anna)){
    std::cout << "Blad w wysylaniu wiadomosci" << std::endl;
    return 0;
  }

  std::cout << std::endl << "Wiadomosc otrzymana i posortowana:" << std::endl;
  std::cout << anna; 

  std::cout << std::endl << "Wiadomosc zlozona spowrotem: " << anna.RestoreMessage() << std::endl;

  return 0;
}
