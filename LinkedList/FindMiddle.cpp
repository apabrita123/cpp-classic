#include "../common/LinkedList.h"
#include <iostream>

using namespace std;
// Brute force approach. T.C-> O(n+n/2), S.C -> 0(1)
Node *getMiddle(Node *head)
{
  Node *temp = head;
  int count = 0;
  while (temp != NULL)
  {
    count++;
    temp = temp->next;
  }
  int midIdx = (count / 2) + 1;
  temp = head;
  while (temp != NULL)
  {
    midIdx--;
    if (midIdx == 0)
    {
      break;
    }
    temp = temp->next;
  }
  return temp;
};

// Optimal Approach. T.C -> O(n/2), S.C-> O(1)
Node *getMiddleOptimal(Node *head)
{
  Node *slow;
  Node *fast;
  slow = fast = head;
  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
};

int main()
{
  List myList;

  myList.push_back(10);
  myList.push_back(20);
  myList.push_back(30);
  myList.push_back(40);
  myList.push_back(50);

  cout << getMiddle(myList.head)->data << endl;
  cout << getMiddleOptimal(myList.head)->data << endl;

  return 0;
}