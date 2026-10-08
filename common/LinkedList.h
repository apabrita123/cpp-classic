#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class Node
{
public:
  int data;
  Node *next;

  Node(int data)
  {
    this->data = data;
    this->next = nullptr;
  }
};

class List
{
public:
  Node *head;
  Node *tail;

  List()
  {
    head = nullptr;
    tail = nullptr;
  }

  void push_back(int data)
  {
    Node *newNode = new Node(data);

    // If list is empty
    if (head == nullptr)
    {
      head = tail = newNode;
      return;
    }

    // Add node at the end
    tail->next = newNode;
    tail = newNode;
  }
};

#endif