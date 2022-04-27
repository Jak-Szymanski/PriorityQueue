#include "queue.h"


Queue::Queue(){
  Head = NULL;  
}


void Queue::InsertSort(Package new_pack){

  Node *tmp = new Node(new_pack);

  if (!Head){
    tmp->Next = Head;
    Head = tmp;
    return;
  }

  Node *ptr = Head;

  if(ptr->GetKey() >= new_pack.GetKey()){
    tmp->Next = Head;
    Head = tmp;
    return;
  }

  while(ptr->Next != NULL){
    if(ptr->GetNext()->GetKey() >= new_pack.GetKey()){
      tmp->Next = ptr->Next;
      ptr->Next = tmp;
      return;
    }
    ptr = ptr->Next;
  }
  tmp->Next = ptr->Next;
  ptr->Next = tmp;
}

void Queue::InsertFront(Package new_pack){

  Node *tmp = new Node(new_pack);

  tmp->Next = Head;
  Head = tmp;
}


std::ostream &operator << (std::ostream &out, Queue const &queue){

  if(queue.IsEmpty()){
    out << "Kolejka jest pusta" << std::endl;
    return out;
  }

  Node *tmp = queue.GetHead();
  while(tmp->GetNext() != NULL){
    out << tmp->GetElem();
    tmp = tmp->GetNext();
  }
  out << tmp->GetElem(); 
  return out;
}

Package Queue::RemoveMin(){

  if(!Head){
    throw "Proba usuniecia elementu z pustej kolejki!";
  }

  Node *ptr = Head;
  Package min = ptr->Elem;
  Head = Head->Next;
  delete ptr;
  return min;
}

void Queue::Delete(){

  Node *ptr = Head;
  Node *next;
  Head = NULL;

  while(ptr != NULL){
    next = ptr->Next;
    free(ptr);
    ptr = next;
  }
}
