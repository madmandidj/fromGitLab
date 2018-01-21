#ifndef __BOOK_RECORD_H__
#define __BOOK_RECORD_H__

#include "../Book/Book.h"
#include "../BorrowerRecord/BorrowerRecord.h"
#include <string>

class BookRecord
{
	public:
		BookRecord(const Book* _book, size_t _numOfCopies, std::vector<BorrowerRecord*> _borrowers);
		
		~BookRecord();
		
		Book* 			GetBook() const;
		
		bool 			GetStatus() const;
		
		bool 			Borrow(BorrowerRecord* _borrRcd);
		
		bool 			Return(BorrowerRecord* _borrRcd);
		
		void 			ReportAllBorrowers();
	
	private:
		BookRecord(const BookRecord& _bookRcd);
		
		BookRecord& 	operator= (const BookRecord& _bookRcd);
		
		Book*			m_book;
		
		size_t			m_numAvailable;;
		
		size_t			m_numOfCopies;
		
		std::vector<BorrowerRecord*> 	m_borrowers;
};









#endif /* #ifndef __BOOK_RECORD_H__ */











































