#ifndef __BORROWER_RECORD_H__
#define __BORROWER_RECORD_H__

#include "../Borrower/Borrower.h"
#include "../Book/Book.h"

class BorrowerRecord
{
	public:
		BorrowerRecord(const Borrower* _borrower, std::vector<Book*> _borrowedBooks);
		
		~BorrowerRecord();
		
		Borrower* 			GetBorrower() const;
		
		bool 				AddBorrowedBook(const Book* m_bookRcd);
		
		bool 				RemoveBorrowedBook(const Book* m_bookRcd);
		
		void 				ReportAllBooksBorrowed() const;
	
	private:
		BorrowerRecord(const BorrowerRecord& _borrRcd);
		
		BorrowerRecord& 	operator= (const BorrowerRecord& _borrRcd);
		
		Borrower*			m_borrower;
		
		std::vector<Book*> 	m_borrowedBooks;
};









#endif /* #ifndef __BORROWER_RECORD_H__ */











































