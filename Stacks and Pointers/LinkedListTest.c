typedef struct tListElement
{
	tListElement *next;
	int value;
	bool tail;
	bool head;
} tListElement;

const int kNumbOfListItems = 10;
tListElement listElements[kNumbOfListItems];

void initList(tListElement *list, int nListSize)
{
	tListElement *pCurr;
	tListElement *pNext;

	memset(list, 99, sizeof(tListElement) * nListSize);
	memset(list, 0, sizeof(tListElement) * nListSize);
	pCurr = list;
	pCurr->tail = true;
	pCurr->head = false;

	pNext = pCurr;
	for (int index = 0; index < nListSize; ++index)
	{
		pCurr = pNext;
		pNext += sizeof(tListElement);  // Kludge until compiler fixed.
		pCurr->value = index;
		pCurr->next = pNext;
	}
}

task main ()
{
	tListElement *head = &listElements[0];
	initList(&listElements[0], kNumbOfListItems);
}
