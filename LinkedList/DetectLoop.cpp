#include "../common/LinkedList.h"
#include <iostream>
#include <unordered_set>
using namespace std;

// Brute Force. T.C-> O(N); S.C -> O(N)
bool isLoopDetedted(Node *head)
{
  unordered_set<Node *> s;
  Node *temp = head;
  while (temp != nullptr)
  {
    if (s.find(temp) != s.end())
    {
      return true;
    }
    s.insert(temp);
    temp = temp->next;
  }
  return false;
}

// Optimal. T.C -> O(N); S.C-> O(1)
bool hasCycle(Node *head)
{
  Node *slow;
  Node *fast;
  slow = fast = head;
  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      return true;
  }
  return false;
}

int main()
{
  List myList;
  myList.push_back(10);
  myList.push_back(20);
  myList.push_back(30);
  myList.push_back(20);
  myList.push_back(10);
  cout << isLoopDetedted(myList.head) << endl;
  return 0;
}