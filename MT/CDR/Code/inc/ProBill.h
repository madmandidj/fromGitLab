#ifndef __PRO_BILL_H__
#define __PRO_BILL_H__


typedef struct ProBill ProBill;


/*
FOR ProBill.c FILE:
--------------------
#include "Billing.h"
#include "Feeder.h"
#include "UI.h"
#include "Logger.h"


struct ProBill
{
	unsigned int	m_magicNum;
	Billing*		m_billing;
	Feeder*			m_feeder;
	UI*				m_ui;
};
*/



ProBill* 	ProBillCreate(/*TODO: add parameters*/);

void		ProBillDestroy(ProBill* _proBill);

/*TODO: Add return*/ ProBillRun(/*TODO: add parameters*/);

/*TODO: Add return*/ ProBillShutDown(/*TODO: add parameters*/);



























#endif /* #ifndef __PRO_BILL_H__ */



