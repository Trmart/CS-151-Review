#ifndef LIST_H
#define LIST_H
//Taylor Martin 
//CS-151 REview
//Gaddis Ch.17 Linked Lists
//9/30/21
#include <iostream>
#include <cstdio> 
using namespace std; 

class LinkedList
{
public:
  LinkedList(); //Default class constuctor
  ~LinkedList(); // Defualt class destructor
  void removeNode(LinkedList *head_ref, LinkedList *node_to_delete); 
  void putBeforeNode(LinkedList *head_ref, LinkedList *next_node, int new_data); 
  void printListForward(LinkedList *head_ref); 
  void printListBackward(LinkedList *last_node); 
  void pushNode(LinkedList *ptr, int data); 
  void putAfterNode(LinkedList *ptr, int data); 
  void appendNode(LinkedList *ptr, int data); 
  

protected:
    LinkedList *m_head; //pointer to head of the linked list 
    LinkedList *next; 
    LinkedList *prev; 
    int m_size; //size of the linked list 
    int m_data; 

};

#endif 