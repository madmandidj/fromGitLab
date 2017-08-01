#include <stdio.h>
#include "SingleLinkedList.h"

void 	PrintList(Person * _head)
{
	Person* curP;
	curP = _head;
	while (curP->m_next != NULL)
	{
		printf("%d %s %d\n", curP->m_id, curP->m_name, curP->m_age);
		curP = curP->m_next;
	}
	printf("%d %s %d\n", curP->m_id, curP->m_name, curP->m_age);
	printf("End of List\n");
	return;
}

Person* ListInsertHead(Person* _head, Person* _p)
{
	/* Avoid inserting head that will point to itself */
	if (_head == _p)
	{
		return _head;
	}
	else
	{
		_p->m_next = _head;
		return _p;
	}
}

Person* ListRemoveHead(Person* _head, Person** _item)
{
	_item = &_head;
	return _head->m_next;
}

static Person* CheckKeyAndSetOneElement(Person* _head, int _key, Person* _p)
{
	Person* returnP = NULL;
	if (_key == _head->m_id )
	{
		returnP = _head;
	}
	else if (_key < _head->m_id)
	{
		returnP = ListInsertHead(_head, _p);
	}
	else if (_key > _head->m_id)
	{
		_p->m_next = NULL;
		_head->m_next = _p;
		returnP = _head;
	}
	return returnP;
}

static int CheckKeyMultiElement(Person* _curP, int _key)
{
	int keyState;
	if (NULL == _curP)
	{
		keyState = 0;
	}
	if (_key == _curP->m_id)
	{
		keyState = 1;
	}
	else if (_key < _curP->m_id)
	{
		keyState = 2;
	}
	else if (_key > _curP->m_id)
	{
		keyState = 3;
	}
	return keyState;
}


// Person* ListInsertByKey(Person* _head, int _key, Person* _p)
// {
// 	Person* prevP;
// 	Person* curP;
// 	int cont = 1;
// 	int keyState;
// 	/* Currently 0 elements in list */
// 	if (NULL == _head)
// 	{
// 		_head = ListInsertHead(_head, _p);
// 		return _head;
// 	}
// 	/* Currently 1 element in list */
// 	else if (NULL == _head->m_next)
// 	{
// 		_head = CheckKeyAndSetOneElement(_head, _key, _p);
// 		return _head;
// 	}
// 	/* Currently >1 element in list */
// 	else
// 	{
// 		prevP = _head;
// 		curP = _head->m_next;
// 		while (cont)
// 		{
// 			keyState = CheckKeyMultiElement(curP, _key);
// 			switch (keyState)
// 			{
// 				/* current person id == key */
// 				case 1:
// 					cont = 0;
// 					break;
// 				/* current person id > key */
// 				case 2:
// 					prevP->m_next = _p;
// 					_p->m_next = curP;
// 					cont = 0;
// 					break;
// 				/* current person id < key */
// 				case 3:
// 					/* If curP is last element, add p to end of list */
// 					if (NULL == curP->m_next)
// 					{
// 						_p->m_next = NULL;
// 						curP->m_next = _p;
// 						cont = 0;
// 					}
// 					else
// 					{
// 						prevP = prevP->m_next;
// 						curP = curP->m_next;
// 						cont = 1;
// 					}
// 					break;
// 			}
// 		}
// 		return _head;
// 	}
// }



Person* ListInsertByKey(Person* _head, int _key, Person* _p)
{
	Person* prevP;
	Person* curP;
	int cont = 1;
	int keyState;
	// /* Currently 0 elements in list */
	// if (NULL == _head)
	// {
	// 	_head = ListInsertHead(_head, _p);
	// 	return _head;
	// }
	// /* Currently 1 element in list */
	// else if (NULL == _head->m_next)
	// {
	// 	_head = CheckKeyAndSetOneElement(_head, _key, _p);
	// 	return _head;
	// }
	// /* Currently >1 element in list */
	// else
	// {
		prevP = NULL;
		curP = _head;
		while (cont)
		{
			keyState = CheckKeyMultiElement(curP, _key);
			switch (keyState)
			{
				/* current person id == key */
				case 0:
					_head = ListInsertHead(_head, _p);
					cont = 0;
					break;
				/* current person id == key */
				case 1:
					cont = 0;
					break;
				/* current person id > key */
				case 2:
					if (NULL == prevP)
					{
						_head = ListInsertHead(_head, _p);
						cont = 0;
					}
					else
					{
						prevP->m_next = _p;
						_p->m_next = curP;
						cont = 0;
					}
					break;
				/* current person id < key */
				case 3:
					/* If curP is last element, add p to end of list */
					if (NULL == curP->m_next)
					{
						_p->m_next = NULL;
						curP->m_next = _p;
						cont = 0;
					}
					else
					{
						prevP = curP;
						curP = curP->m_next;
						cont = 1;
					}
					break;
			}
		}
		return _head;
	// }
}




Person* ListRemoveByKey(Person* _head, int _key, Person** _p)
{
	Person* prevP;
	Person* curP;
	/* If no elements in linked list or _p key is smaller than head key, return head unchanged */
	if (NULL == _head || _key < _head->m_id)
	{
		return _head;
	}
	/* If _p key is equal to head key, remove head */
	else if (_key == _head->m_id)
	{
		_head = ListRemoveHead(_head, _p);
		return _head;
	}
	/* Reached here if _p key is larger than _head key */
	else
	{
		prevP = _head;
		curP =_head->m_next;
		/* Iterate untill key found or reach end of list */
		while (NULL != curP->m_next)
		{
			if (_key == curP->m_id)
			{
				_p = &curP;
				prevP->m_next = curP->m_next;
				return _head;
			}
			else if(_key < curP->m_id)
			{
				return _head;
			}
			else
			{
				prevP = prevP->m_next;
				curP = curP->m_next;
			}
		}
		/* Check if _p key is equal to key of last list element */
		if (_key == curP->m_id)
		{
			_p = &curP;
			prevP->m_next = NULL;
		}
	}
	return _head;
}

static void LRBKR(Person* _curP, Person* _prevP, int _key, Person** _p)
{
    if (_curP->m_id != _key && _curP->m_next == NULL)
    {
        return;
    }
    else if (_key == _curP->m_id)
    {
        _p = &_curP;
        _prevP->m_next = _curP->m_next;
        return;
    }
    else
    {
        _prevP = _prevP->m_next;
        _curP = _curP->m_next;
        LRBKR(_curP, _prevP, _key, _p);
    }
    return;
}


Person* ListRemoveByKeyRec(Person* _head, int _key, Person** _p)
{
    Person* prevP;
    Person* curP;
    if (_key == _head->m_id)
    {
        _p = &_head;
        _head = _head->m_next;
        return _head;
    }
    else if(NULL == _head->m_next)
    {
        return _head;
    }
    else
    {
        prevP = _head;
        curP = _head->m_next;
        LRBKR(curP, prevP, _key, _p);
    }
    return _head;
}



static void LIBKR(Person* _curP, Person* _prevP, int _key, Person* _p)
{
    if (_key == _curP->m_id)
    {
        return;
    }
    else if(_key > _curP->m_id && NULL == _curP->m_next)
    {
        _curP->m_next = _p;
        _p->m_next = NULL;
        return;
    }
    else if(_key < _curP->m_id)
    {
        _prevP->m_next = _p;
        _p->m_next = _curP;
        return;
    }
    else if (_key > _curP->m_id)
    {
        _prevP = _prevP->m_next;
        _curP = _curP->m_next;
        LIBKR(_curP, _prevP, _key, _p);
    }
    return;
}


Person* ListInsertByKeyRec(Person* _head, int _key, Person* _p)
{
    Person* prevP;
    Person* curP;

    /* If no elements in linked list, create head */
	if (NULL == _head)
	{
		_head = ListInsertHead(_head, _p);
		return _head;
	}
	/* If _p key is smaller than head key, set p as head */
	else if (_key < _head->m_id)
	{
		_head = ListInsertHead(_head, _p);
		return _head;
	}
	/* If _p key is equal to head key, return original head */
	else if (_key == _head->m_id)
	{
		return _head;
	}
    else
    {
        prevP = _head;
        curP = _head->m_next;
        LIBKR(curP, prevP, _key, _p);
    }
    return _head;
}





