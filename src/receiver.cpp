#include "../inc/receiver.h"

std::string Receiver::RestoreMessage(){
    std::string message = "";

    if(SortedMessage.IsEmpty()){
        throw std::runtime_error("Kolejka jest pusta");
    }

    while(!SortedMessage.IsEmpty()){
        message.append(SortedMessage.RemoveMin().GetMessage());
    }

    return message;

}

std::ostream &operator << (std::ostream &out, Receiver const &receiver){

    out << receiver.GetSortedMessages(); 
    return out;
}
