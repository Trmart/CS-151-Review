//Taylor Martin 
//CS-151 REview
//Gaddis Ch.17 Linked Lists
//9/30/21
#include "list.h"

void LinkedList::printListForward(LinkedList *head_ref)
{   //1.check if head_ref is null
    if(head_ref == nullptr)
    {
        cerr << "Your Linked List is Empty. There is nothing to print"; 
        return; 
    }
    //while head_ref is not null
    while(head_ref != nullptr)
    {
        //output the node data
        cout << head_ref->m_data << "\n";
        // assign head_ref to head_ref->next
        head_ref = head_ref->next; 
    }
}

void LinkedList::printListBackward(LinkedList *last_node)
{
    //check if last_node is null
    if(last_node == nullptr)
    {
        cerr << "Your Linked List is Empty. There is nothing to print"; 
        return; 
    }
    //if last_node is not null
    else
    {
        //while last_node is not null
       while(last_node != nullptr)
       {
           //output node data 
           cout << last_node->m_data << endl; 
           //assign last_node to last_node->prev
           last_node = last_node->prev; 
       } 
    }
}

/* Function to delete a node in a Doubly Linked List.
head_ref --> pointer to head node pointer.
del --> pointer to node to be deleted. */
  void LinkedList::removeNode(LinkedList *head_ref, LinkedList *node_to_delete)
  {
    //   1.check if head_ref is nullptr
    if(head_ref == nullptr)
    {
        cerr << "Your Linked List is empty. Nothing to delete. Process terminated." << endl;
        return; 
    }
    //   2.if node to be deleted is head node, assign head_ref to node_to_delete->prev
    if(node_to_delete == m_head)
    {
        head_ref = node_to_delete->prev; 
    }
    //   3. change node_to_delete->next->prev = node_to_delete->prev only if node to be deleted is not the last node
    if(node_to_delete->next != nullptr)
    {
        node_to_delete->next->prev = node_to_delete->prev; 
    }
    //   4.change node_to_delete->prev->next to node_to_delete->next only if node to be deleted is not the first node 
      if(node_to_delete->prev != nullptr)
    {
        node_to_delete->prev->next = node_to_delete->next; 
    }
    //   5. finally, free the memory occupied by node_to_delete
    delete node_to_delete; 
    node_to_delete = nullptr;
  }


void LinkedList::putBeforeNode(LinkedList *head_ref, LinkedList *next_node, int new_data)
{
    // 1.Check if the next_node is NULL or not. If it’s NULL, return from the function because any new node can not be added before a NULL
   if(next_node == nullptr)
   {
       cerr<< "Your linked list is empty. Process terminated" <<endl; 
       return;
   }
    // 2.Allocate memory for the new node, let it be called new_node
   LinkedList *new_node = new LinkedList();
    // 3.Set new_node->data = new_data
   new_node->m_data = new_data;
    // 4.Set the previous pointer of this new_node as the previous node of the next_node, new_node->prev = next_node->prev
   new_node->prev = next_node->prev; 
    // 5.Set the previous pointer of the next_node as the new_node, next_node->prev = new_node
   next_node->prev = new_node; 
    // 6.Set the next pointer of this new_node as the next_node, new_node->next = next_node;
   new_node->next = next_node; 
    // 7.If the previous node of the new_node is not NULL, then set the next pointer of this previous node as new_node, new_node->prev->next = new_node
   if(new_node->prev != nullptr)
   {
       new_node->prev->next = new_node; 
   }
    // 8.Else, if the prev of new_node is NULL, it will be the new head node. So, make (*head_ref) = new_node.
  else
  {
      head_ref = new_node; 
  }
  
}

/* Given a reference (pointer to pointer)
to the head of a list
and an int, inserts a new node on the
front of the list. */
  void LinkedList::pushNode(LinkedList *head_ref, int newData)
  {
    //1.Allocate memory for new node 
    LinkedList *new_node = new LinkedList(); 
    //2. Put in the data
    new_node->m_data = newData; 
    //3. Make next of the new node as head and prev as nullptr
    new_node->next = m_head; 
    new_node->prev = nullptr; 
    //4. change prev of head node to new node
    if(m_head != nullptr)
    {
        m_head->prev = new_node; 
    }
    //5. move the head to point to the new node 
    m_head = new_node; 
  }


/* Given a node as prev_node, insert
a new node after the given node */
  void LinkedList::putAfterNode(LinkedList *prev_node, int data)
  {
      //1. check if the given node if nullptr
      if(prev_node == nullptr)
      {
        cerr<< "The previous node of the linked list cannot be NULL. Process terminated."; 
        exit(1); 
      }
      //2. allocate the memory for new node
      LinkedList *new_node = new LinkedList(); 
      //3.put data in node 
      new_node->m_data = data; 
      //4. make the next of new node as next of prev node
      new_node->next = prev_node->next; 
      //5. make the next of the prev node as new node
      prev_node->next = new_node; 
      //6. make new_node prev node as previous node
      new_node->prev = prev_node; 
      //7. if new_node->next not nullptr, change previous of new node to next node 
      if(prev_node != nullptr)
      {
          new_node->prev = new_node->next; 
      }
  }


  void LinkedList::appendNode(LinkedList *ptr, int data)
  {
    //   1.allocate memory for addNode
    LinkedList *new_node = new LinkedList(); 
    LinkedList *last = m_head; //used in step 5
    //   2.put data in new_node
    new_node->m_data = data; 
    //   3. The new_node is going to be the last node in the list, so make new_node->next nullptr
    new_node->next = nullptr; 
    //   4.If the linked list is empty, then make the new_node->prev null and m_head set to new_node
    if(m_head == nullptr)
    {
        new_node->prev = nullptr; 
        m_head = new_node; 
    }
    //   5. else travel till the last addNode
    else
    {
        while(ptr->next != nullptr)
        {
            last = last->next; 
        }
    }
    //   6.change the next of last node to new_node
    last->next = new_node; 
    //   7.make new_node->prev as last
    new_node->prev = last; 

    return; 
  }