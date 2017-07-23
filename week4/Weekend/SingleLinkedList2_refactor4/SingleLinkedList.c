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

// static void LRBKR(Person* _curP, Person* _prevP, int _key, Person** _p)
// {

// }

// Person* ListRemoveByKeyRec(Person* _head, int _key, Person** _p)
// {
// 	Person* prevP;
// 	Person* curP;
// 	int keyState;
// 	if (NULL == _head)
// 	{
// 		return NULL;
// 	}
// 	prevP = NULL;
// 	curP = _head;
// 	keyState = CheckKey(curP, _key);
// 	switch (keyState)
// 	{
// 	case 0:
// 	/* Empty list*/
// 		return _head;
// 		break;
// 	case 1:
// 		/* current person id == key */
// 		if (NULL == prevP)
// 		{
// 			/* current person is head */
// 			_p = &curP;
// 			_head = curP->m_next;
// 		}
// 		else
// 		{
// 			/* current person is not head */
// 			_p = &curP;
// 			prevP->m_next = curP->m_next;
// 		}
// 		return _head;
// 		break;
// 	default:
		
// 		break;
// 	}
// }





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





// Person* ListRemoveByKeyRec(Person* _head, int _key, Person** _p)
// {
//     Person* prevP;
//     Person* curP;
//     if (_key == _head->m_id)
//     {
//         _p = &_head;
//         _head = _head->m_next;
//         return _head;
//     }
//     else if(NULL == _head->m_next)
//     {
//         return _head;
//     }
//     else
//     {
//         prevP = _head;
//         curP = _head->m_next;
//         LRBKR(curP, prevP, _key, _p);
//     }
//     return _head;
// }



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





