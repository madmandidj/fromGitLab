#ifndef __MSG_TYPE_H__
#define __MSG_TYPE_H__


#include "../ChannelDefs/ChannelDefs.h"
#include "../../CDRDataTypes/Record.h"

typedef struct Msg Msg;

typedef struct Data Data;

typedef struct UIcommand UIcommand;

/*
struct Msg
{
    long 	m_channel;
    Record 	m_data; 
};
*/

struct UIcommand
{
	unsigned int m_command;
	char m_searchKey[32];
};

struct Data
{
	Record 		m_rec;
	UIcommand 	m_uiCommand;
};


struct Msg
{
    long 	m_channel;
    Data 	m_data; 
};





#endif /*#ifndef __MSG_TYPE_H__*/






