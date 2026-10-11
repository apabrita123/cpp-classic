#include "../common/LinkedList.h"
#include <iostream>
#include <unordered_set>
using namespace std;

// Brute force. T.C-> O(N); S.C -> O(N)
Node *detectCycleIdx(Node *head)
{
  unordered_set<Node *> s;
  Node *temp = head;
  while (temp != nullptr)
  {
    if (s.find(temp) != s.end())
    {
      return temp;
    }
    s.insert(temp);
    temp = temp->next;
  }
  return NULL;
};
// optimal
Node *detectCycleIdxOptimal(Node *head)
{
  Node *fast;
  Node *slow;
  slow = fast = head;
  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (fast == slow)
    {
      slow = head;
      while (slow != fast)
      {
        slow = slow->next;
        fast = fast->next;
      }
      return slow;
    }
  }
  return nullptr;
};

int main()
{
  List myList;
  myList.push_back(1);
  myList.push_back(2);
  myList.push_back(3);
  myList.push_back(4);
  myList.push_back(5);

  cout << detectCycleIdx(myList.head)->data << endl;
  cout << detectCycleIdxOptimal(myList.head)->data << endl;
  return 0;
}