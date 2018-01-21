#ifndef __GENERICDLL_H__
#define __GENERICDLL_H__

typedef struct DLL DLL;
typedef struct Node Node;
typedef Node* Itr;
typedef int (*UserActionFunc)(void* _element, void* _context);

enum ListErr
{
	LISTERR_OK,
	LISTERR_INVARG,
	LISTERR_BADALLOC
}ListErr;

DLL* DLLCreate();
void DLLDestroy(DLL* _dll, UserActionFunc _destroyFunc);
void DLLPushHead(DLL* _dll, void* _element);
void DLLPopHead(DLL* _dll, void** _poppedElement);
void DLLPushTail(DLL* _dll, void* _element);
void DLLPopTail(DLL* _dll, void** _poppedElement);
size_t DLLCount(DLL* _dll);
void DLLForEach(DLL* _dll, UserActionFunc _forEachFunc);


















#endif /*#ifndef __GENERICDLL_H__*/
