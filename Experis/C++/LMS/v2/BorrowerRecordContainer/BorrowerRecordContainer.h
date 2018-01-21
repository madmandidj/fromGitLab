#ifndef __BORROWER_RECORD_CONTAINER_H__
#define __BORROWER_RECORD_CONTAINER_H__

#include <map>
#include <vector>
#include <string>

using namespace std;

class BorrowerRecord;

class BorrowerRecordContainer
{
	public:
		BorrowerRecordContainer();
		
		~BorrowerRecordContainer();
		
		bool Add(const BorrowerRecord* _borrRcd);
		
		bool Remove(const string& _ID);
		
		vector<BorrowerRecord*> SearchName(const string& _name) const; // O(n)
		
		const BorrowerRecord* SearchID(const string& _ID) const; // O(log(n))
		
		void Report(const BorrowerRecord* _borrRcd) const;
		
		void ReportAll() const;
	
	private:
		BorrowerRecordContainer(const BorrowerRecordContainer& _borrRcdCont);
		
		BorrowerRecordContainer& operator= (const BorrowerRecordContainer& _borrRcdCont);
		
		map<string, BorrowerRecord*> m_borrRecords;
};









#endif /* #ifndef __BORROWER_RECORD_CONTAINER_H__ */











































