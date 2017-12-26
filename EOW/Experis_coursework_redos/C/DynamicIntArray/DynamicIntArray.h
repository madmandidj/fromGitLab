#ifndef __DYNAMICINTARR_H__
#define __DYNAMICINTARR_H__

typedef int* IntPtr;

typedef struct DynArr{
    IntPtr* m_arr;
    int 	m_cap;
    int 	m_noe;
    int		m_blockSize;
}DynArr;

DynArr* CreateDA(int _capacity, int _blockSize);	
void 	Destroy(DynArr* _da1);
int 	Insert(DynArr* _da1, int* _num);
int 	InsertByIndex(DynArr* _da1, int* _num, int _index);
int*	Find(DynArr* _da1, int _numtofind);
int		RemoveNum(DynArr* _da1, int _numtoremove);
void	PrintDA(DynArr* _da1);	


#endif /*#ifndef __DYNAMICINTARR_H__*/


