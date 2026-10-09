#include "../common/LinkedList.h"
#include <iostream>
#include <unordered_set>
using namespace std;

// Brute force approach, T.C-> O(N1+N2) ; S.C -> O(N1||N2)
Node *getIntersectionNodeBruteForce(Node *head1, Node *head2)
{
  unordered_set<Node *> visited;
  Node *temp = head1;
  while (temp != nullptr)
  {
    visited.insert(temp);
    temp = temp->next;
  }
  temp = head2;
  while (temp != nullptr)
  {
    if (visited.find(temp) != visited.end())
    {
      return temp;
    }
    temp = temp->next;
  }
  return nullptr;
};

// Better approach
// T.C -> O(N1) + O(N2) + O(d) + O(N1); S.C-> O(1)
Node *getIntersectPoint(Node *t1, Node *t2, int d)
{
  while (d)
  {
    t2 = t2->next;
    d--;
  }
  while (t1 != nullptr && t2 != nullptr)
  {
    if (t1 == t2)
    {
      return t1;
    }
    t1 = t1->next;
    t2 = t2->next;
  }
  return nullptr;
}
Node *getIntersectionNodeBetter(Node *head1, Node *head2)
{
  // length of first LL
  Node *temp1 = head1;
  int N1 = 0;
  while (temp1 != nullptr)
  {
    N1++;
    temp1 = temp1->next;
  }
  // length of second LL
  Node *temp2 = head2;
  int N2 = 0;
  while (temp2 != nullptr)
  {
    N2++;
    temp2 = temp2->next;
  };
  Node *intersectPoint;
  if (N1 < N2)
  {
    intersectPoint = getIntersectPoint(head1, head2, N2 - N1);
  }
  else
  {
    intersectPoint = getIntersectPoint(head2, head1, N1 - N2);
  }
  return intersectPoint;
}

// optimal Approach
// T.C -> O(N1+N2); S.C-> O(1);
Node *getIntersectionNodeOptimal(Node *head1, Node *head2)
{
  Node *t1 = head1;
  Node *t2 = head2;
  while (t1 != t2)
  {
    t1 = t1->next;
    t2 = t2->next;
    if (t1 == t2)
    {
      return t1;
    }
    if (t1 == nullptr)
      t1 = head2;
    if (t2 == nullptr)
      t2 = nullptr;
  }
  return t1;
};

int main()
{
  List listA;
  List listB;

  // Create the shared portion: 8 -> 10 -> NULL
  Node *shared = new Node(8);
  shared->next = new Node(10);

  // List A: 3 -> 7 -> 8 -> 10 -> NULL
  listA.push_back(3);
  listA.push_back(7);
  listA.tail->next = shared;
  listA.tail = shared->next;

  // List B: 1 -> 2 -> 8 -> 10 -> NULL
  listB.push_back(1);
  listB.push_back(2);
  listB.tail->next = shared;
  listB.tail = shared->next;

  Node *intersection = getIntersectionNodeOptimal(
      listA.head,
      listB.head);
  if (intersection)
  {
    cout << intersection->data << endl;
  }
  else
  {
    cout << "No intersection point is found." << endl;
  }

  return 0;
}