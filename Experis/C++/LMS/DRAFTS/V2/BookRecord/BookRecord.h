#ifndef __BOOK_RECORD_H__
#define __BOOK_RECORD_H__

#include "../Book/Book.h"
#include "../Borrower/Borrower.h"

class BookRecord
{
	public:
		BookRecord(const Book* _book, size_t _numOfCopies, std::vector<Borrower*> _borrowers);
		
		~BookRecord();
		
		Book* GetBook() const;
		
		bool GetStatus() const;
		
		bool AddBorrower(const Borrower* _borrower);
		
		bool RemoveBorrower(const Borrower* _borrower);
		
		void ReportAllBorrowers() const;
	
	private:
		BookRecord(const BookRecord& _bookRcd);
		
		BookRecord& operator= (const BookRecord& _bookRcd);
		
		Book*						m_book;
		
		size_t						m_numAvailable;;
		
		size_t						m_numOfCopies;
		
		std::vector<Borrower*> 		m_borrowers;
};


#endif /* #ifndef __BOOK_RECORD_H__ */











































