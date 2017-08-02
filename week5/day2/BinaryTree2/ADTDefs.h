/*
Filename: 		ADTDefs.h 
Description:	Abstract Data Type errors
Created: 		08/07/17
Created by:		Eyal Alon
Last modified: 	17/07/17
Modified by:	Eyal Alon
*/

#ifndef __ADTDEFS_H__
#define __ADTDEFS_H__



typedef enum
{
    /* General ADT Errors */
    ERR_OK       =0,
    ERR_GENERAL,
    ERR_NOT_INITIALIZED,
    ERR_ALLOCATION_FAILED,
    ERR_REALLOCATION_FAILED,
    ERR_UNDERFLOW,
    ERR_OVERFLOW,
    ERR_WRONG_INDEX,
    /* Queue Errors */
    ERR_FULL,
    ERR_EMPTY,
    /* Vector Errors */
    
    /* Stack  Errors */

    ERR_STACK_BBBBB = 30,

    /* LinkedList  Errors */
	ERR_EMPTY_LIST,
	ERR_MAGIC_NUM,
    /* Bit Vector*/
    
    /* Binary Tree */
	ERR_VALUE_EXISTS
} ADTErr;

#endif/*#ifndef __ADTDEFS_H__*/
