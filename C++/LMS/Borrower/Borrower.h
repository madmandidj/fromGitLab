#ifndef __BORROWER_H__
#define __BORROWER_H__

#include <string>

typedef std::string String;

class Borrower
{
	public:
		Borrower(String _firstName, String _lastName, String _phoneNum, String _ID);
		
		~Borrower();
		
		String 	GetFirstName() const;
		
		String 	GetLastName() const;
		
		String 	GetPhoneNum() const;
		
		String 	GetID() const;
		
		bool operator== (String _ID) const;
	
	private:
		Borrower(const Borrower& _borrower);
		
		Borrower& operator= (const Borrower& _borrower);
		
		String m_firstName;
		
		String m_lastName;
		
		String m_phoneNum;
		
		String m_ID;
};









#endif /* #ifndef __BORROWER_H__ */











































