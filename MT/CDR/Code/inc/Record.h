#ifndef __RECORD_H__
#define __RECORD_H__


typedef struct Record Record;

struct Record
{
	unsigned int	m_magicNum;
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
	char			m_callType[7];
	char			m_callDate[11];
	char			m_callTime[9];
	unsigned int	m_duration;
	unsigned int	m_downloadMB;
	unsigned int	m_uploadMB;
	
	/*
	Party identifiers
	*/
	char			m_partyMsisdn[16];
	char			m_partyMCCMNC[7];
};




#endif /* #ifndef __RECORD_H__ */








