#ifndef __BORROWER_RECORD_CONTAINER_H__
#define __BORROWER_RECORD_CONTAINER_H__

#include "../BorrowerRecord/BorrowerRecord.h"
#include <map>
#include <vector>
#include <string>

typedef std::string String;

class BorrowerRecordContainer
{
	public:
		BorrowerRecordContainer(String _borrowerRecordConfigPath);
		
		~BorrowerRecordContainer();
		
		bool 							Add(const BorrowerRecord* _borrRcd);
		
		bool 							Remove(const BorrowerRecord* _borrRcd);
		
		std::vector<BorrowerRecord*> 	SearchName(String _name) const; // O(n)
		
		BorrowerRecord* 				SearchID(String _ID) const; // O(log(n))
		
		bool 							Report(const BorrowerRecord* _borrRcd) const;
		
		void 							ReportAll() const;
	
	private:
		BorrowerRecordContainer(const BorrowerRecordContainer& _borrRcdCont);
		
		BorrowerRecordContainer& operator= (const BorrowerRecordContainer& _borrRcdCont);
		
		String							m_borrowerRecordConfigPath;
		
		map<string, BorrowerRecord*>	m_borrRecords;
};









#endif /* #ifndef __BORROWER_RECORD_CONTAINER_H__ */











































