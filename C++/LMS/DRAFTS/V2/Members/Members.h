#ifndef __MEMBERS_H__
#define __MEMBERS_H__


#include "..Borrower/Borrower.h"
#include <map>
#include <string>

typedef std::string String;

class Members
{
	public:
		Members(String _membersConfigPath);
		
		~Members();
		
		bool		AddMember(const Borrower* _borrower);
		
		bool		RemoveMember(const Borrower* _borrower);
		
		Borrower* 	SearchID(String _ID) const;
		
		size_t		NumOfMembers() const;

	private:
		Members(const Members& _members);
		
		Members& operator= (const Members& _members);
		
		String					m_membersConfigPath;
		
		map<String, Borrower*>	m_members;
		
};








#endif /* #ifndef __MEMBERS_H__ */





