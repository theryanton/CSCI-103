#include "delist.h"
#include <cstddef>

DEList::DEList()
{
  head = NULL;
  tail = NULL;
}

DEList::~DEList()
{
  while (head != NULL)
  {
    pop_front(); // use delete on single element
  }
}

bool DEList::empty() 
{
  if (head == NULL && tail == NULL)
  {
    return true;
  }
  return false;
}

int DEList::size()
{
  if (head == NULL) 
  {
    return -1;
  }
  else 
  {
    int counter = 0;
    DEItem* temp;
    temp = head;
    while (temp != NULL)
    {
      counter++;
      temp = temp->next;
    }
    return counter;
  }
}

int DEList::front()
{
  if (head == NULL)
  {
    return -1;
  }
  else
  {
    return head->val;
  }
}

int DEList::back()
{
  if (tail == NULL)
  {
    return -1;
  }
  else
  {
    return tail->val;
  }
}

void DEList::push_front(int new_val)
{
  if (empty())
  {
    DEItem* temp = new DEItem();
    temp->val = new_val;
    head = temp;
    tail = temp;
  }
  else
  {
    DEItem* temp = new DEItem();
    temp->val = new_val; 
    temp->next = head;
    temp->prev = NULL;
    head->prev = temp;
    head = temp;
  }
}

void DEList::push_back(int new_val)
{
  if (empty())
  {
    DEItem* temp = new DEItem();
    temp->val = new_val;
    head = temp;
    tail = temp;
  }
  else
  {
    DEItem* temp = new DEItem();
    temp->val = new_val; 
    temp->prev = tail;
    temp->next = NULL;
    tail->next = temp;
    tail = temp;
  }
}

void DEList::pop_front()
{
  if (head == tail)
  {
    delete head;
    head = NULL;
    tail = NULL;
  }
  else if (head != NULL)
  {
    DEItem* temp;
    temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
  }
}

void DEList::pop_back()
{
  if (head == tail)
  {
    delete tail;
    head = NULL;
    tail = NULL;
  }
  else if (tail != NULL)
  {
    DEItem* temp;
    temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete temp;
  }
}