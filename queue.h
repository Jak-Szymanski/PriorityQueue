#pragma once

#include "node.h"
#define PACK_LENGTH 5

class Queue{

  private:
  
    Node *Head;

  public:

    Queue();

    void InsertSort(Package new_pack);

    void InsertFront(Package new_pack);

    Package RemoveMin();

    void Delete();

    bool IsEmpty() const {return !Head;};

    Node * const GetHead() const{return Head;};

    void SetHead(Node *new_head){Head = new_head;};
};

std::ostream &operator << (std::ostream &out, Queue const &queue);

