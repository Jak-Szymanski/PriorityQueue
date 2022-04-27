#pragma once

#include "queue.h"

class Receiver{

    private:

        Queue SortedMessage;

    public:

        Receiver(){SortedMessage = Queue();};

        ~Receiver(){SortedMessage.Delete();};

        void SortNewPackage(Package new_pack){SortedMessage.InsertSort(new_pack);};

        std::string RestoreMessage();

        Queue GetSortedMessages() const{return SortedMessage;};
};

std::ostream &operator << (std::ostream &out, Receiver const &receiver);