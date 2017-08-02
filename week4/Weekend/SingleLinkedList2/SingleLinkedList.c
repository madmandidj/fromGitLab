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
	_p->m_next = _head;
	return _p;
}

Person* ListRemoveHead(Person* _head, Person** _item)
{
	_item = &_head;
	return _head->m_next;
}

Person* ListInsertByKey(Person* _head, int _key, Person* _p)
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
	/* Reached here if _p key is larger than _head key */
	else
	{
		prevP = _head;
		curP =_head->m_next;
		/* Iterate untill insert position found or reached end of list */
		while (NULL != curP->m_next)
		{
			if (_key == curP->m_id)
			{
				return _head;
			}
			else if (_key > curP->m_id)
			{
				prevP = prevP->m_next;
				curP = curP->m_next;
			}
			else
			{
				prevP->m_next = _p;
				_p->m_next = curP;
				return _head;
			}
		}
		/* Reached here if curP->m_next == NULL (end of single linked list) */
		if (_key == curP->m_id)
		{
			return _head;
		}
		else if (_key > curP->m_id)
		{
			curP->m_next = _p;
			_p->m_next = NULL;
		}
		else
		{
			prevP->m_next = _p;
			_p->m_next = curP;
		}
	}
	return _head;
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





