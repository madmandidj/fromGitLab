#ifndef __ADTERR_H__
#define __ADTERR_H__
/*
--------------------
Eyals Abstract Data Type Errors
--------------------
*/


typedef enum ADTErr
{
    ERR_OK,
    ERR_NOMEM,
    ERR_INVARG,
    ERR_VEC_ZEROBLOCKSIZE,
    ERR_QUEUE_FULL,
    ERR_QUEUE_EMPTY
}ADTErr;

#endif/*#ifndef __ADTERR_H__*/
