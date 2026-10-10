#include "../common/LinkedList.h"
#include <iostream>
#include <stack>
using namespace std;

// Brute force! T.C -> O(2N); S.C -> O(N)
bool isPalindrome(Node *head)
{
  stack<int> s;
  Node *temp = head;
  while (temp != nullptr)
  {
    s.push(temp->data);
    temp = temp->next;
  }

  temp = head;
  while (temp != nullptr)
  {
    if (temp->data != s.top())
    {
      return false;
    }
    s.pop();
    temp = temp->next;
  }

  return true;
}

// optimal soln! T.C -> O(2N), S.C -> O(1)
Node *getReverseHead(Node *head)
{
  Node *prev;
  Node *temp;
  Node *front;
  prev = NULL;
  temp = head;
  while (temp != NULL)
  {
    front = temp->next;
    temp->next = prev;
    prev = temp;
    temp = front;
  }
  return prev;
}
bool isPalindromeOptimal(Node *head)
{
  Node *fast;
  Node *slow;
  fast = slow = head;
  while (fast->next != NULL && fast->next->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  Node *newHead = getReverseHead(slow->next);
  Node *first = head;
  Node *second = newHead;
  while (second != NULL)
  {
    if (first->data != second->data)
    {
      getReverseHead(newHead);
      return false;
    }
    first = first->next;
    second = second->next;
  }
  getReverseHead(newHead);
  return true;
}

int main()
{
  List myList;
  myList.push_back(10);
  myList.push_back(20);
  myList.push_back(30);
  myList.push_back(20);
  myList.push_back(10);

  cout << isPalindromeOptimal(myList.head) << endl;
  return 0;
}