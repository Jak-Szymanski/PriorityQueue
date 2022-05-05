#include "../inc/sender.h"

#include <string>
#include <fstream> 
#include <iostream>


void Sender::DivideMessage(std::string Message){

    int length = Message.length();
    std::string tmp_string = "";
    Package tmp_pack;

    for(int i=0; i<length; i+=PACK_LENGTH){
        for(int j=i; j<i+PACK_LENGTH && j<length; j++){
            tmp_string += Message[j];
        }
    tmp_pack = Package(tmp_string, i/PACK_LENGTH);
    Messages.InsertFront(tmp_pack);
    Size++;
    tmp_string = "";
    }
}


Sender::Sender(){
    Messages = Queue();
    Size = 0;
}


Package Sender::TakeRandomPackage(){

    if(Size == 0){
        throw std::runtime_error("Kolejka jest pusta");
    }

    Node *ptr = Messages.GetHead();

    int n = rand() % Size;
    if (n==0){
        Size--;
        return Messages.RemoveMin();
    }
    for(int i=0; i<n-1; i++){
        ptr = ptr->GetNext();
    }

    Package tmp = ptr->GetNext()->GetElem();
    ptr->SetNext(ptr->GetNext()->GetNext());
    Size--;
    return tmp;

}


bool Sender::SendMessage(Receiver *receiver){

    Package tmp_pack;
    if (IsEmpty()) return 0;
    while(!IsEmpty()){
        tmp_pack = TakeRandomPackage();
        std::cout << tmp_pack;
        receiver->SortNewPackage(tmp_pack);
    }
    return 1;
}


std::ostream &operator << (std::ostream &out, Sender const &sender){

    out << sender.GetMessages(); 
    return out;
}
