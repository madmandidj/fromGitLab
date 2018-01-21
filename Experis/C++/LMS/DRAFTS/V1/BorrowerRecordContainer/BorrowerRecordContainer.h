#ifndef __BORROWER_RECORD_CONTAINER_H__
#define __BORROWER_RECORD_CONTAINER_H__

#include "../BorrowerRecord/BorrowerRecord.h"
#include <map>
#include <vector>
#include <string>

/* TODO: Is an overriding Compare() / Less function required for map ?*/

class BorrowerRecordContainer
{
	public:
		BorrowerRecordContainer(std::string _borrowerRecordsPath);
		
		~BorrowerRecordContainer();
		
		bool 		Add(const BorrowerRecord* _borrRcd); /* If BorrowerID exists, will not be added */
		
		bool 		Remove(std::string _ISBN);
		
		std::vector<BorrowerRecord*> SearchName(std::string _name) const; // O(n)
		
		BorrowerRecord* SearchID(std::string _ID) const; // O(log(n))
		
		bool 		Report(std::string _ID) const;
		
		void 		ReportAll() const;
	
	private:
		BorrowerRecordContainer(const BorrowerRecordContainer& _borrRcdCont);
		
		BorrowerRecordContainer& operator= (const BorrowerRecordContainer& _borrRcdCont);
		
		map<string, BorrowerRecord*>	m_borrRecords;
};









#endif /* #ifndef __BORROWER_RECORD_CONTAINER_H__ */











































