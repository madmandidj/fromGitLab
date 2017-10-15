#include "../virtIO_t/virtIO_t.h"
#include <string>

using namespace std;

class asciiIO_t : public virtIO_t
{
	public:
		/******** Inhertied from virtIO_t
		*********

		const string& GetFileName() const;
		
		const string& GetMode() const;
		
		FileStatus GetStatus() const;
		
		size_t GetFileLength();
		
		*********
		********/
		asciiIO_t();
		
		asciiIO_t(const string& _fileName, const string& _mode);
		
		virtual ~asciiIO_t();
		
		virtual asciiIO_t& operator>> (char& _char);
		
		virtual asciiIO_t& operator<< (char& _char);		
		
	protected:
		/******** Inhertied from virtIO_t
		*********
		
		void SetStatus(FileStatus _status);
		
		*********
		********/
		
	private:
	
	
};





































