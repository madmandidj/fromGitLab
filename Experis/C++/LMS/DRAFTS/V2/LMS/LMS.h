#ifndef __LMS_H__
#define __LMS_H__

#include "../Library/Library.h"
#include "../Members/Members.h"
#include "../BookRecordContainer/BookRecordContainer.h"
#include "../BorrowerRecordContainer/BorrowerRecordContainer.h"
#include "../Administrator/Administrator.h"

typedef std::string String;

class LMS
{
	public:
		LMS(String _libraryConfigPath,
			String _membersConfigPath, 
			String _bookRecordConfigPath,  
			String _borrowerRecordConfigPath);
			
		~LMS();
		
		Run();
		
		Quit();
	
	private:
		LMS(const LMS& _lms);
		
		LMS& 	operator= (const LMS& _lms);
		
		Library*					m_library;
		
		Members*					m_members;
		
		BookRecordContainer* 		m_bookRcdCont;
		
		BorrowerRecordContainer* 	m_borrRcdCont;
		
		Admininstrator*				m_admin;
};




#endif /* #ifndef __LMS_H__ */



