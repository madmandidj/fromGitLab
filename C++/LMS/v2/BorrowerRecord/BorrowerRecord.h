#ifndef __BORROWER_RECORD_H__
#define __BORROWER_RECORD_H__

#include <vector>
#include <set>

using namespace std;

class BorrowerRecord
{
	public:
		BorrowerRecord(string _firstName, string _lastName, string _phoneNum, string _ID);
		
		~BorrowerRecord();
		
		const string& GetFirstName() const;
		
		const string& GetLastName() const;
		
		const string& GetPhoneNum() const;
		
		const string& GetID() const;
		
		bool AddBorrowed(const string& _ISBN);
		
		bool RemoveBorrowed(const string& _ISBN);
		
		bool AddToWaitList(const string& _ISBN);
		
		bool RemoveFromWaitList(const string& _ISBN);
		
		void ReportAllBooksBorrowed() const;
	
	private:
		BorrowerRecord(const BorrowerRecord& _borrRcd);
		
		BorrowerRecord& operator= (const BorrowerRecord& _borrRcd);
		
		string 			m_firstName;
		
		string 			m_lastName;
		
		string 			m_phoneNum;
		
		string 			m_ID;
		
		set<string> 	m_myBorrowedBooks;
		
		vector<string>	m_myWaitingList;
};


#endif /* #ifndef __BORROWER_RECORD_H__ */











































