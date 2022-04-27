#pragma once

#include "queue.h"
#include "receiver.h"


class Sender{

    private:

        Queue Messages;

        int Size;

    public:

        void DivideMessage(std::string Message);

        Sender();

        ~Sender(){Messages.Delete();};

        Package TakeRandomPackage();

        bool IsEmpty() const {return Messages.IsEmpty();};

        Queue GetMessages() const {return Messages;};

        bool SendMessage(Receiver *receiver);

};

std::ostream &operator << (std::ostream &out, Sender const &sender);