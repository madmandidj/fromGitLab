#ifndef __OPERATOR_H__
#define __OPERATOR_H__


typedef struct Operator Operator;

struct Operator
{
	/*unsigned int	m_magicNum;*/
	/*
	Operator identifiers
	*/
	char			m_operatorBrand[65];
	int				m_operatorMCCMNC;
	
	/*
	Voice call durations
	*/
	unsigned int	m_outVoice;
	unsigned int	m_inVoice;
	
	/*
	Number of SMS
	*/
	unsigned int	m_outSms;	
	unsigned int	m_inSms;
	
	
	/*
	Data download/upload
	*/
	unsigned int	m_downloadMB;
	unsigned int	m_uploadMB;
};





#endif /* #ifndef __OPERATOR_H__ */








