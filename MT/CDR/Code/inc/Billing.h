#ifndef __BILLING_H__
#define __BILLING_H__

#include "Record.h"
#include "Operator.h"
#include "Subscriber.h"

typedef struct Billing Billing;

/*
FOR Billing.c FILE:
--------------------
#include "Billing.h"
#include "Processor.h"
#include "Storage.h"
#include "TxLine.h
#include "Logger.h"


struct Billing
{
	unsigned int	m_magicNum;
	Processor* 		m_processor;
	Storage*		m_subscribers;
	Storage*		m_operators;
	TxLine*			m_txLine;
	Logger*			m_logger;
};
*/

Billing* BillingCreate(/*TODO: add parameters*/);

void BillingDestroy(/*TODO: add parameters*/);

/*TODO: Add return*/ BillingRun(/*TODO: add parameters*/);

/*TODO: Add return*/ BillingPause(/*TODO: add parameters*/);

/*TODO: Add return*/ BillingResume(/*TODO: add parameters*/);

/*TODO: Add return*/ BillingExport(/*TODO: add parameters*/);














#endif /* #ifndef __BILLING_H__ */



