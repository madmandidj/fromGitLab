#ifndef __RECORD_H__
#define __RECORD_H__


typedef struct Record Record;

typedef enum CallType
{
	MOC = 0, 	/* Outgoing voice */
	MTC,		/* Incoming voice */
	SMS_MO,		/* Outgoing SMS */
	SMS_MT,		/* Incoming SMS */
	GPRS		/* Internet */
}CallType;

struct Record
{
	/*
	Subscriber identifiers
	*/
	char			m_imsi[16];
	char			m_msisdn[16];
	char			m_imei[16];
	
	/*
	Operator identifiers
	*/
	char			m_operatorBrand[65];
	char			m_operatorMCCMNC[7];
	
	/*
	Record type attributes
	*/
	CallType		m_callType;
	char			m_callDate[11];
	char			m_callTime[9];
	unsigned int	m_duration;
	float			m_downloadMB;
	float			m_uploadMB;
	
	/*
	Party identifiers
	*/
	char			m_partyMsisdn[16];
	char			m_partyMCCMNC[7];
};




#endif /* #ifndef __RECORD_H__ */








