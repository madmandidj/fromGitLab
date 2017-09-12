#ifndef __SUBSCRIBER_H__
#define __SUBSCRIBER_H__


typedef struct Subscriber Subscriber;

struct Subscriber
{
//	unsigned int	m_magicNum;
	/*
	Subscriber identifiers
	*/
	char			m_imsi[16]; 			/* subscriber is identified by this according to 5.1 */
	char			m_msisdn[16];			/* Should imsi or msisdn be used as key to hash function? */
	
	/*
	Voice call durations
	*/
	unsigned int	m_outVoiceWithinOp;
	unsigned int	m_inVoiceWithinOp;
	unsigned int	m_outVoiceOutsideOp;
	unsigned int	m_inVoiceOutsideOp;	
	
	/*
	Number of SMS
	*/
	unsigned int	m_outSmsWithinOp;
	unsigned int	m_inSmsWithinOp;
	unsigned int	m_outSmsOutsideOp;
	unsigned int	m_inSmsOutsideOp;	
	
	/*
	Data download/upload
	*/
	unsigned int	m_downloadMB;
	unsigned int	m_uploadMB;
};




#endif /* #ifndef __SUBSCRIBER_H__ */








