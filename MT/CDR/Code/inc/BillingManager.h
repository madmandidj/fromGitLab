#ifndef __PRO_BILL_H__
#define __PRO_BILL_H__


typedef struct BillingManager BillingManager;


/*
FOR ProBill.c FILE:
--------------------
#include "Biller.h"
#include "Feeder.h"
#include "UI.h"
#include "Logger.h"


struct ProBill
{
	unsigned int	m_magicNum;
	Biller*			m_biller;
	Feeder*			m_feeder;
	UI*				m_ui;
};
*/



BillingManager* 		BillingManagerCreate(/*TODO: add parameters*/);

void					BillingManagerDestroy(ProBill* _proBill);

/*TODO: Add return*/ 	BillingManagerRun(/*TODO: add parameters*/);

/*TODO: Add return*/ 	BillingManagerShutDown(/*TODO: add parameters*/);



























#endif /* #ifndef __PRO_BILL_H__ */



