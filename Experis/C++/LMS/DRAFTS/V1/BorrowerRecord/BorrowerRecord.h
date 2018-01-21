#ifndef __BORROWER_RECORD_H__
#define __BORROWER_RECORD_H__

#include "../Borrower/Borrower.h"
#include "../BookRecord/BookRecord.h"
#include <string>

class BorrowerRecord
{
	public:
		BorrowerRecord(const Borrower* _borrower, std::vector<BookRecord*> _borrowedBooks);
		
		~BorrowerRecord();
		
		Borrower* 			GetBorrower() const;
		
		bool 				AddBorrowedBook(const BookRecord* m_bookRcd);
		
		bool 				ReturnBorrowedBook(const BookRecord* m_bookRcd);
		
		void 				ReportAllBorrowers();
	
	private:
		BorrowerRecord(const BorrowerRecord& _borrRcd);
		
		BorrowerRecord& 	operator= (const BorrowerRecord& _borrRcd);
		
		Borrower*			m_borrower;
		
		std::vector<BookRecord*> 	m_borrowedBooks;
};









#endif /* #ifndef __BORROWER_RECORD_H__ */











































