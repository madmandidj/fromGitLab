#include <stdio.h>
#include "SingleLinkedList.h"


Person* ListInsertHead(Person* _head, Person* _p)
{
	_p->m_next = _head;
	return _p;
}

Person* ListRemoveHead(Person* _head, Person** _item)
{
	*_item = _head;
	return _head->m_next;
}

Person* ListInsertByKey(Person* _head, int _key, Person* _p)
{
	Person* tempP;
	Person* prevP;
	Person* curP;
	/* Check if no elements in linked list */
	if (NULL == _head)
	{
		_head = ListInsertHead(_head, _p);
		return _head;
	}
	/* Check if _p should be placed as new head */
	else if (_key < _head->m_id)
	{
		_head = ListInsertHead(_head, _p);
		return _head;
	}
	else if (_key == _head->m_id)
	{
		return _head;
	}
	else
	{
		prevP = _head;
		curP =_head->m_next;
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
			}
		}
		/* Reached here if curP->m_next == NULL */
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







