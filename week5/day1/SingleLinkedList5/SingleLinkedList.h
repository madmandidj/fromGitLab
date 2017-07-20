/*
Filename: 		SingleLinkedList.h 
Description:	Contains SLL (Single Linked List) API given by Izik.
Created: 		13/07/17
Created by:		Eyal Alon
Last modified: 	16/07/17
Modified by:	Eyal Alon
*/
#ifndef __LINKED_H__
#define __LINKED_H__

#define NAME_SIZE 32

typedef struct Person Person;

struct Person
{
	int 	m_id; /* Primary Key */
	char 	m_name[NAME_SIZE];
	int 	m_age;
	Person* m_next;
};

/*
Desc: Insert-head to single linked list
In:	Person* _head points to current head, Person* _p points to new head
Out: Person* points to new head
Err: No errors. If _head == _p, _head is returned to avoid cyclic list. If _p == NULL, head returned.
*/
Person* ListInsertHead(Person* _head, Person* _p);

/*
Desc: Remove-head from single linked list
In:	Person* _head points to current head, Person** _item points to removed person
Out: Person* points to new head
Err: No errors. If _head == NULL, NULL is returned.
***Izik suggests: if item is NULL dont remove head.
*/
Person* ListRemoveHead(Person* _head, Person** _item);

/*
Desc: Insert-by-key to single linked list
In:	Person* _head points to current head, int _key value of new person, Person* _p points to new person
Out: Person* points to head
Err: No errors. If _head == _p, _head is returned to avoid cyclic list. If _p == NULL, NULL returned.
*/
Person* ListInsertByKey(Person* _head, int _key, Person* _p);

/*
Desc: Insert-by-key-recursive to single linked list
In:	Person* _head points to current head, int _key value of new person, Person* _p points to new person
Out: Person* points to head
Err: No errors. If _head == _p, _head is returned to avoid cyclic list. If _p == NULL, NULL returned.
*/
Person* ListInsertByKeyRec(Person* _head, int _key, Person* _p);

/*
Desc: Remove-by-key from single linked list
In:	Person* _head points to current head, Person** _item points to removed person
Out: Person* points to head
Err: No errors. If _head == NULL, NULL is returned.
*/
Person* ListRemoveByKey(Person* _head, int _key, Person** _p);

/*
Desc: Remove-by-key from single linked list
In:	Person* _head points to current head, Person** _item points to removed person
Out: Person* points to head
Err: No errors. If _head == NULL, NULL is returned.
*/
Person* ListRemoveByKeyRec(Person* _head, int _key, Person** _p);

/*
Desc: Print single linked list
In:	Person* _head points to head of list
Out: void
Err: No errors. If _head == NULL, NULL is returned.
*/
void 	PrintList(Person * _head);

#endif /* endif __LINKED_H__ */
