#ifndef __ADMINISTRATOR_H__
#define __ADMINISTRATOR_H__

#include "../Library/Library.h"
#include "../Members/Members.h"
#include "../BookRecordContainer/BookRecordContainer.h"
#include "../BorrowerRecordContainer/BorrowerRecordContainer.h"

typedef std::string String;

class Administrator
{
	public:
		Administrator(string m_adminID);
			
		virtual ~Administrator();
		
		bool 							AddBook(Library* _library, BookRecordContainer* _bookRcdCont, const Book* _book, size_t _numOfCopies) const;
		
		bool 							RemoveBook(Library* _library, BookRecordContainer* _bookRcdCont, const Book* _book,) const;
		
		bool 							AddBorrower(Members* _members, BorrowerRecordContainer* _borrRcdCont,  Borrower* _borrower) const;
		
		bool 							RemoveBorrower(Members* _members, BorrowerRecordContainer* _borrRcdCont, String _ID) const;
		
		bool							BorrowBook(BorrowerRecord* _borrRcd, BookRecord* _bookRcd) const;
		
		bool							ReturnBook(BorrowerRecord* _borrRcd, BookRecord* _bookRcd) const;
		
		std::vector<BookRecord*> 		SearchBookTitle(const BookRecordContainer* _bookRcdCont, String _title) const;
		
		std::vector<BookRecord*>		SearchBookAuthor(const BookRecordContainer* _bookRcdCont, String _author) const;
		
		BookRecord*						SearchBookISBN(const BookRecordContainer* _bookRcdCont, String _ISBN) const;
		
		std::vector<BorrowerRecord*>	SearchBorrowerName(const BorrowerRecordContainer* _borrRcdCont, String _name) const;
		
		BorrowerRecord*					SearchBorrowerID(const BorrowerRecordContainer* _borrRcdCont, String _name) const;
		
		void							BookReport(const BookRecord* _bookRcd) const;
		
		void							BookReportAll(const BookRecordContainer* _bookRcdCont) const;
		
		void							BorrowerReport(const BorrowerRecord* _borrRcd) const;
		
		void							BorrowerReportAll(const BorrowerRecordContainer* _borrRcdCont) const;
		
	private:
		String	m_adminID;
}




#endif /* #ifndef __ADMINISTRATOR_H__ */






