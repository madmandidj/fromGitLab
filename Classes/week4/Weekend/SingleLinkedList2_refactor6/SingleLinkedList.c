#include <stdio.h>
#include "SingleLinkedList.h"

void 	PrintList(Person * _head)
{
	Person* curP;
	if (NULL == _head)
	{
		return;
	}
	curP = _head;
	while (curP->m_next != NULL)
	{
		printf("Key: %d\tName: %s\n", curP->m_id, curP->m_name);
		curP = curP->m_next;
	}
	printf("Key: %d\tName: %s\n", curP->m_id, curP->m_name);
	printf("***End of List***\n");
	return;
}

Person* ListInsertHead(Person* _head, Person* _p)
{
	if (_head == _p)
	{
		/* Avoid inserting head that will point to itself */
		return _head;
	}
	else if (_p == NULL)
	{
		/* NULL new person so return head */
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
	if (NULL == _head)
	{
		return NULL;
	}
	else
	{
		// _item = &_head;
		*_item = _head;
		return _head->m_next;
	}
}

static int CheckKey(Person* _curP, int _key)
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

Person* ListInsertByKey(Person* _head, int _key, Person* _p)
{
	Person* prevP;
	Person* curP;
	int cont = 1;
	int keyState;

	if (_head == _p)
	{
		/* Avoid inserting head that will point to itself */
		return _head;
	}
	else if (_p == NULL)
	{
		/* NULL new person so return head */
		return _head;
	}
	prevP = NULL;
	curP = _head;
	while (cont)
	{
		keyState = CheckKey(curP, _key);
		switch (keyState)
		{
		case 0:
			/* Empty list */
			_head = ListInsertHead(_head, _p);
			cont = 0;
			break;
		case 1:
			/* current person id == key */
			cont = 0;
			break;
		case 2:
			/* current person id > key */
			if (NULL == prevP)
			{
				/* current person is head */
				_head = ListInsertHead(_head, _p);
				cont = 0;
			}
			else
			{
				/* current person is not head */
				prevP->m_next = _p;
				_p->m_next = curP;
				cont = 0;
			}
			break;
		case 3:
			/* current person id < key */
			if (NULL == curP->m_next)
			{
				/* current person is last in list */
				_p->m_next = NULL;
				curP->m_next = _p;
				cont = 0;
			}
			else
			{
				/* current person is last in list */
				prevP = curP;
				curP = curP->m_next;
				cont = 1;
			}
			break;
		}
	}
	return _head;
}

static void LIBKR(Person* _curP, Person* _prevP, int _key, Person* _p)
{
    if (_key == _curP->m_id)
    {
		/* ID already exists so exit without changing list */
        return;
    }
    else if(_key > _curP->m_id && NULL == _curP->m_next)
    {
		/* Place new person at the end of list */
        _curP->m_next = _p;
        _p->m_next = NULL;
        return;
    }
    else if(_key < _curP->m_id)
    {
		/* Place new person in the middle of list */
        _prevP->m_next = _p;
        _p->m_next = _curP;
        return;
    }
    else if (_key > _curP->m_id)
    {
		/* Set pointers to next person in list and recurse */
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
	
	if (_head == _p)
	{
		/* Avoid inserting head that will point to itself */
		return _head;
	}
	else if (_p == NULL)
	{
		/* NULL new person so return head */
		return _head;
	}
	else if (NULL == _head)
	{
		/* Empty list */
		_head = ListInsertHead(_head, _p);
		return _head;
	}
	else if (_key < _head->m_id)
	{
		/* new key is smaller than head ID so insert as head */
		_head = ListInsertHead(_head, _p);
		return _head;
	}
	else if (_key == _head->m_id)
	{
		/* new key is head ID so exit without changing list */
		return _head;
	}
	else if (NULL == _head->m_next)
	{
		/* Insert new key after head which is the only element in list */
		_head = ListInsertByKey(_head, _key, _p);
		return _head;
	}
    else
    {
		/* Multiple element list and head ID is smaller than new key so increment pointers and call recursive function */
        prevP = _head;
        curP = _head->m_next;
        LIBKR(curP, prevP, _key, _p);
    }
    return _head;
}

Person* ListRemoveByKey(Person* _head, int _key, Person** _p)
{
	Person* prevP;
	Person* curP;
	int cont = 1;
	int keyState;

	if (NULL == _head)
	{
		return NULL;
	}
	prevP = NULL;
	curP = _head;
	while (cont)
	{
		keyState = CheckKey(curP, _key);
		switch (keyState)
		{
		case 0:
		/* Empty list*/
			cont = 0;
			break;
		case 1:
			/* current person id == key */
			if (NULL == prevP)
			{
				/* current person is head */
				_p = &curP;
				_head = curP->m_next;
				cont = 0;
			}
			else
			{
				/* current person is not head */
				_p = &curP;
				prevP->m_next = curP->m_next;
				cont = 0;
			}
			break;
		case 2:
			/* current person id > key */
			cont = 0;
			break;
		case 3:
			/* current person id < key */
			if (NULL == curP->m_next)
			{
				/* current person is last in list */
				cont = 0;
			}
			else
			{
				/* current person is not last in list */
				prevP = curP;
				curP = curP->m_next;
				cont = 1;
			}
			break;
		}
	}
	return _head;
}

static void LRBKR(Person* _curP, Person* _prevP, int _key, Person** _p)
{
    if (_curP->m_id != _key && _curP->m_next == NULL)
    {
		/* person id has not been found in list */
        return;
    }
    else if (_key == _curP->m_id)
    {
		/* person has been found */
        _p = &_curP;
        _prevP->m_next = _curP->m_next;
        return;
    }
    else
    {
		/* person has not been found so perform recursive call */
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

	if (NULL == _head)
	{
		/* Empty List */
		return _head;
	}
    else if (_key == _head->m_id)
    {
		/* Key is head */
        _p = &_head;
        _head = _head->m_next;
        return _head;
    }
    else if(NULL == _head->m_next)
    {
		/* Key not found in single element list */
        return _head;
    }
    else
    {
		/* Key not found in multiple element list so call recursive function */
        prevP = _head;
        curP = _head->m_next;
        LRBKR(curP, prevP, _key, _p);
    }
    return _head;
}







