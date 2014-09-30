#define MAX_LIST_SIZE 10

struct tListElement
{
  int next;
  int value;
  int pos;
  bool free;
} tListElement;

struct tList
{
  int head;
  int tail;
  tListElement elements[MAX_LIST_SIZE];
  int size;
} tList;


int findFreeNode(tList &list)
{
  for (int i = 0; i < MAX_LIST_SIZE; i++)
  {
    if (list.elements[i].free == true)
    {
      return i;
    }
  }
  return -1;
}


void initList(tList &list)
{
  list.head = 0;
  list.tail = 0;
  list.size = 0;
  for (int i = 0; i < MAX_LIST_SIZE; i++)
  {
    list.elements[i].next = -1;
    list.elements[i].pos = i;
    list.elements[i].free = true;
  }
}

int appendNode(tList &list, int value)
{
  int position = -1;
  // The list is still empty
  if (list.size == 0)
  {
    list.elements[0].value = value;
    list.elements[0].free = false;
    list.size++;
    list.head = 0;
    list.tail = 0;
    return list.tail;
  }
  // The list is full!
  else if (list.size < MAX_LIST_SIZE)
  {
    // find a free node
    position = findFreeNode(list);
    // No free nodes available, shouldn't happen
    if (position == -1)
    {
      return -1;
    }
    list.elements[position].value = value;
    list.elements[position].free = false;
    list.elements[list.tail].next = position;
    list.tail = position;
    list.size++;
    return list.tail;
  }
  return -1;
}

void deleteNode(tList &list, int position)
{
  int tmpNodeNr;
  // Does the list have any elements?
  if (list.size == 0)
  {
    return;
  }
  // is the node used?
  else if (list.elements[tmpNodeNr].free == true)
	{
	  return;
	}
	// Check if the node to be deleted is the head
	else if (list.head == position)
	{
	  list.elements[position].free = true;
	  if (list.size > 1)
	  {
      list.head = list.elements[position].next;
    }
  }
  else
  {
	  // find the node which has this position as its
	  // next node
		for (int tmpNodeNr = 0; tmpNodeNr < MAX_LIST_SIZE; tmpNodeNr++)
	  {
	    if (list.elements[tmpNodeNr].next == position)
	    {
	      break;
	    }
	  }
	  if (list.head == position)
	  {
	    list.head = tmpNodeNr;
	  }
	  list.elements[tmpNodeNr].next = list.elements[position].next;
	  list.elements[position].free = true;
	  // If this was the old tail position, update.
	  if (list.tail == position)
	  {
	    list.tail = tmpNodeNr;
	  }
  }
  list.size--;
}

int getNextNode(tList &list, int nodeNr)
{
  if (list.elements[nodeNr].free == true)
  {
    return -1;
  }
  else if (list.elements[list.elements[nodeNr].next].free == true)
  {
    return -1;
  }
  else
  {
    return list.elements[nodeNr].next;
  }
}

void printList(tList &list)
{
  int currNode = list.head;

  if (list.size == 0)
  {
    //writeDebugStreamLine("list empty");
    return;
  }

  //writeDebugStreamLine("v: %d", list.elements[currNode].value);
  while(currNode != -1)
  {
    currNode = getNextNode(list, currNode);
    //writeDebugStreamLine("v: %d", list.elements[currNode].value);
  }
}
task main ()
{
  tList myList;
  initList(myList);
  appendNode(myList, 14);
  printList(myList);
}
