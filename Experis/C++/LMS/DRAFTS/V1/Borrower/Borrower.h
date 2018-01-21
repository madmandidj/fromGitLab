#ifndef __BORROWER_H__
#define __BORROWER_H__

#include <string>

class Borrower
{
	public:
		Borrower(std::string _firstName, std::string _lastName, std::string _phoneNum, std::string _ID);
		
		~Borrower();
		
		std::string 	GetFirstName() const;
		
		std::string 	GetLastName() const;
		
		std::string 	GetPhoneNum() const;
		
		std::string 	GetID() const;
		
		bool 			operator== (std::string _ID) const;
	
	private:
		Borrower(const Borrower& _borrower);
		
		Borrower& 		operator= (const Borrower& _borrower);
		
		std::string		m_firstName;
		
		std::string		m_lastName;
		
		std::string		m_phoneNum;
		
		std::string		m_ID;
};









#endif /* #ifndef __BORROWER_H__ */











































