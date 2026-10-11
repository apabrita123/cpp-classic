#include "../common/LinkedList.h"
#include <iostream>

// Brute Force. T.C -> O(2N); S.C -> O(1)
Node *removeNthFromEnd(Node *head, int n)
{
  Node *temp = head;
  int length = 0;
  while (temp != NULL)
  {
    length++;
    temp = temp->next;
  }
  int count = length - n;
  if (count == 0)
  {
    Node *temp = head->next;
    head->next = NULL;
    delete head;
    head = temp;
    return head;
  }
  else
  {
    temp = head;
    while (temp != NULL)
    {
      if (count == 1)
      {
        break;
      }
      count--;
      temp = temp->next;
    }
    Node *toDelNode = temp->next;
    temp->next = temp->next->next;
    toDelNode->next = NULL;
    delete toDelNode;
  }
  return head;
}

// Optimal. T.C-> O(N); S.C-> O(1)
Node *removeNthFromEndOptilmal(Node *head, int n)
{
  Node *temp = head;
  int count = 0;
  while (count < n)
  {
    count++;
    temp = temp->next;
  }
  if (temp == NULL)
  {
    Node *oldHead = head;
    head = head->next;
    oldHead->next = nullptr;
    delete oldHead;
    return head;
  }
  Node *slow = head;
  Node *fast = temp;
  while (fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next;
  }
  Node *deletedNode = slow->next;
  slow->next = slow->next->next;
  deletedNode->next = nullptr;
  delete deletedNode;
  return head;
}

int main()
{
  List myList;
  myList.push_back(1);
  myList.push_back(2);
  // myList.push_back(3);
  // myList.push_back(4);
  // myList.push_back(5);

  myList.head = removeNthFromEndOptilmal(myList.head, 2);
  Node *temp = myList.head;
  while (temp != NULL)
  {
    std::cout << temp->data << " -> ";
    temp = temp->next;
  }
  std::cout << "NULL" << std::endl;
  return 0;
}