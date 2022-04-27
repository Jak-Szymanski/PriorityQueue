#include "node.h"

Node::Node(){
  Elem = Package();
  Next = NULL;
}

Node::Node(Package new_elem){
  Elem = new_elem;
  Next = NULL;
}