#ifndef __RECORD_H__
#define __RECORD_H__


typedef struct Record Record;

struct Record
{
	unsigned int	m_magicNum;
	/*
	Subscriber identifiers
	*/
	char			m_imsi[15];
	char			m_msisdn[15];
	char			m_imei[15];
	
	/*
	Operator identifiers
	*/
	char			m_operatorBrand[64];
	char			m_operatorMCCMNC[6];
	
	/*
	Record type attributes
	*/
	char			m_callType[6];
	char			m_callDate[10];
	char			m_callTime[8];
	unsigned int	m_duration;
	unsigned int	m_downloadMB;
	unsigned int	m_uploadMB;
	
	/*
	Party identifiers
	*/
	char			m_partyMsisdn[15];
	char			m_partyMCCMNC[6];
};




#endif /* #ifndef __RECORD_H__ */








