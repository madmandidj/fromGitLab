#include "../../inc/Vector.h"
#include "../../inc/ADTErr.h"
#include <stdlib.h>

struct Vector
{
    void** m_array;
    size_t m_initCapacity;
    size_t m_capacity;
    size_t m_blockSize;
    size_t m_numOfItems;
};

/****************
VectorCreate
****************/
static int AreCreateParamsValid(size_t _initCapacity)
{
    return _initCapacity == 0 ? 0 : 1;
}

static Vector* AllocateAndInit(size_t _initCapacity, size_t _blockSize)
{
    Vector* vector;
    if (!(vector = malloc(sizeof(Vector))))
    {
        return NULL;
    }
    vector->m_initCapacity = _initCapacity;
    vector->m_capacity = _initCapacity;
    vector->m_blockSize = _blockSize;
    vector->m_numOfItems = 0;
    if (!(vector->m_array = malloc(vector->m_initCapacity * sizeof(void*))))
    {
        free(vector);
        vector = NULL;
    }
    return vector;
}

Vector* VectorCreate(size_t _initCapacity, size_t _blockSize)
{
    Vector* vector;
    if (!AreCreateParamsValid(_initCapacity))
    {
        return NULL;
    }
    vector = AllocateAndInit(_initCapacity, _blockSize);
    return vector;
}

/****************
VectorDestroy
****************/
void VectorDestroy(Vector* _vector, ElementFunc _elemDestroyFunc)
{
    size_t index;
    void* removedElement;
    if (!_vector)
    {
        return;
    }
    if(_elemDestroyFunc)
    {
        for (index = 0; index < _vector->m_numOfItems; ++index)
        {
            VectorRemove(_vector, &removedElement);
            _elemDestroyFunc(removedElement);
        }
    }
    free(_vector->m_array);
    free(_vector);
    return;
}

/****************
VectorAppend
****************/
static ADTErr AreAppendParamsValid(Vector* _vector, void* _element)
{
    if (NULL == _vector || NULL == _element)
    {
        return ERR_INVARG;
    }
    return ERR_OK;
}

static ADTErr ResizeMoreIfNeeded(Vector* _vector)
{
    void** tempArr;
    if (_vector->m_numOfItems == _vector->m_capacity)
    {
        if (0 == _vector->m_blockSize)
        {
            return ERR_VEC_ZEROBLOCKSIZE;
        }
        if (!(tempArr = realloc(_vector->m_array, sizeof(void*) * (_vector->m_capacity + _vector->m_blockSize))))
        {
            return ERR_NOMEM;
        }
        _vector->m_capacity = _vector->m_capacity + _vector->m_blockSize;
        _vector->m_array = tempArr;
    }
    return ERR_OK;
}

static void DoAppend(Vector* _vector, void* _element)
{
    _vector->m_array[_vector->m_numOfItems] = _element;
    ++_vector->m_numOfItems;
    return;
}

ADTErr VectorAppend(Vector* _vector, void* _element)
{
    ADTErr err = ERR_OK;
    if (ERR_OK != (err = AreAppendParamsValid(_vector, _element)))
    {
        return err;
    }
    if (ERR_OK != (err = ResizeMoreIfNeeded(_vector)))
    {
        return err;
    }
    DoAppend(_vector, _element);
    return err;
}

/****************
VectorRemove
****************/
static ADTErr AreRemoveParamsValid(Vector* _vector, void** _removedElement)
{
    if (NULL == _vector || NULL == _removedElement || 0 == _vector->m_numOfItems)
    {
        return ERR_INVARG;
    }
    return ERR_OK;
}

static void DoRemove(Vector* _vector, void** _removedElement)
{
    *_removedElement = _vector->m_array[_vector->m_numOfItems - 1];
    --_vector->m_numOfItems;
}

static ADTErr ResizeLessIfNeeded(Vector* _vector)
{
    void** tempArr;
    if (0 == _vector->m_blockSize)
    {
        return ERR_VEC_ZEROBLOCKSIZE;
    }
    if ((_vector->m_numOfItems <= _vector->m_capacity - _vector->m_blockSize)
        && _vector->m_initCapacity <= _vector->m_capacity - _vector->m_blockSize)
    {
        if (!(tempArr = realloc(_vector->m_array, sizeof(void*) * (_vector->m_capacity - _vector->m_blockSize))))
        {
            return ERR_NOMEM;
        }
        _vector->m_capacity = _vector->m_capacity - _vector->m_blockSize;
        _vector->m_array = tempArr;
    }
    return ERR_OK;
}

ADTErr VectorRemove(Vector* _vector, void** _removedElement)
{
    ADTErr err = ERR_OK;
    if (ERR_OK != (err = AreRemoveParamsValid(_vector, _removedElement)))
    {
        return err;
    }
    DoRemove(_vector, _removedElement);
    ResizeLessIfNeeded(_vector);
    return err;
}

/****************
VectorSet
****************/
static ADTErr AreSetGetParamsValid(Vector* _vector, size_t _index, void* _element)
{
    if (!_vector || _vector->m_numOfItems <= _index || !_element)
    {
        return ERR_INVARG;
    }
    return ERR_OK;
}

ADTErr VectorSet(Vector* _vector, size_t _index, void* _element)
{
    ADTErr err = ERR_OK;
    if (ERR_OK == (err = AreSetGetParamsValid(_vector, _index, _element)))
    {
        _vector->m_array[_index] = _element;
    }
    return err;
}

/****************
VectorGet
****************/
ADTErr VectorGet(Vector* _vector, size_t _index, void** _gotElement)
{
    ADTErr err = ERR_OK;
    if (ERR_OK == (err = AreSetGetParamsValid(_vector, _index, _gotElement)))
    {
        *_gotElement = _vector->m_array[_index];
    }
    return err;
}

/****************
VectorItemsNum
****************/
size_t VectorItemsNum(Vector* _vector)
{
    return NULL == _vector ? 0 : _vector->m_numOfItems;
}

/****************
VectorPrint
****************/
void VectorPrint(Vector* _vector, ElementFunc _elemPrintfunc)
{
    size_t index;
    if (_vector)
    {
        for (index = 0; index < _vector->m_numOfItems; ++index)
        {
            _elemPrintfunc(_vector->m_array[index]);
        }
    }
}




