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
	char			m_operatorMCCMNC[7];
	
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
	float			m_downloadMB;
	float			m_uploadMB;
};





#endif /* #ifndef __OPERATOR_H__ */








