#ifndef __BUFFER_H__
#define __BUFFER_H__



template <class T> class Buffer
{
	public:
		~Buffer();
		Buffer();
		Buffer(size_t _capacity);
	protected:
		static SetDefaultCapacity(size_t);
	private:
		char*	m_buf;
		size_t 	m_length;
		size_t 	m_capacity;
};






























#endif //#ifndef __BUFFER_H__


