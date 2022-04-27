#pragma once

#include <iostream>

class Package{

    private:

        std::string Message;

        int Key;        

    public:

        Package();

        Package(std::string message, int key);

        int GetKey() const{return Key;};

        std::string GetMessage() const {return Message;};

        friend class Node;
};

std::ostream &operator << (std::ostream &out, Package const &pack);