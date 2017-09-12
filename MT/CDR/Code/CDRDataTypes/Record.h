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
//	unsigned int	m_magicNum;
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
	unsigned int	m_operatorMCCMNC;
	
	/*
	Record type attributes
	*/
	CallType		m_callType;
	char			m_callDate[11];
	unsigned int	m_callTime;
	unsigned int	m_duration;
	unsigned int	m_downloadMB;
	unsigned int	m_uploadMB;
	
	/*
	Party identifiers
	*/
	char			m_partyMsisdn[16];
	unsigned int	m_partyMCCMNC;
};




#endif /* #ifndef __RECORD_H__ */








