#pragma debuggerWindows(debugStream)

struct tListElement;  // KLudge because of forward declaration bug

struct
{
  tListElement *next;
  int nDebugField;
} tListElement;

const int kListSize = 10;

struct tList
{
  tListElement *head;
  tListElement *tail;
  int nListSize;
  tListElement elements[kListSize];
} tList;

tList theList;

void appendNode(tList &list, tListElement *pElement)
{
	if (pElement == NULL)
	{
		VERIFY(false);
		return;
	}

	pElement->next = NULL;
	pElement->nDebugField = list.nListSize;

	if (list.tail == NULL)
		list.head = pElement;
	else
		list.tail->next = pElement;

	list.tail = pElement;
	++list.nListSize;
	return;
}

void initList(tList &list)
{
  list.head = &list.elements[0];
	list.tail = &list.elements[0];
	list.nListSize = 0;
	for (int nIndex = 0; nIndex < kListSize; ++nIndex)
	{
		tListElement *pElementToAdd;
		pElementToAdd = &list.elements[nIndex];
		appendNode(list, &list.elements[nIndex]);
	}
}

task main ()
{
	clearDebugStream();
	writeDebugStreamLine("Starting Linked List Test ...");
	initList(theList);
	for (int i = 0; i < kListSize; ++i)
	{
		VERIFY(theList.elements[i].nDebugField == i);
	}
	VERIFY(theList.nListSize == kListSize);
	VERIFY(theList.head == &theList.elements[0]);
	VERIFY(theList.tail == &theList.elements[kListSize - 1]);
	writeDebugStreamLine("...Linked List Test PASSED");
}
