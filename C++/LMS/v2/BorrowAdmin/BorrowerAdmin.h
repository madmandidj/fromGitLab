#ifndef __BORROWERADMIN_H__
#define __BORROWERADMIN_H__

#include <string>
#include <vector>

class BorrowerRecord;
class BorrowerRecordContainer;

using namespace std;

class BorrowerAdmin
{
	public:
		BorrowerAdmin(BorrowerRecordContainer* _borrRcdCont);
		
		~BorrowerAdmin();
	
		bool AddBorrower(const BorrowerRecord* _borrRcd) const;
		
		bool RemoveBorrower(const string& _ID) const;
		
		vector<BorrowerRecord*>	SearchBorrowerName(const string& _name) const;
		
		BorrowerRecord*	SearchBorrowerID(const string& _ID) const;
		
		void BorrowerReport(const BorrowerRecord* _borrRcd) const;
		
		void BorrowerReportAll() const;
	
	private:
		string 						m_adminID;
		
		BorrowerRecordContainer*	m_borrRcdCont;
};









#endif /* #ifndef __BORROWERADMIN_H__ */




