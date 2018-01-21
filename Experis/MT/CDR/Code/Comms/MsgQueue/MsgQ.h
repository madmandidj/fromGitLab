#ifndef __MSGQ_H__
#define __MSGQ_H__
#define _GNU_SOURCE
#include "MsgType.h"
#include <sys/types.h>		/* msgrcv, msgsnd, msgget, msgctl */
#include <sys/ipc.h>		/* msgrcv, msgsnd, msgget, msgctl */
/** 
 *  @file MsgQ.h
 *
 *  @brief MsgQ is the commuincation line between processes in the CDR program
 *
 *  @author Eyal Alon  (eyal171@yahoo.com)
 * 
 *  @bug Blasphemy 
*/



typedef struct msqid_ds msqid_ds;



/** 
 * @brief Create or join message queue
 *
 * @param[in] _mqKey - msg queue key
 *
 * @param[in] _mqID - msg queue ID
 *
 * @param[in] _myPathToMsgQ - path to message queue directory entry
 *  
 * @return  void
 */
void MsgQCreate(key_t* _mqKey, int* _mqID, char* _myPathToMsgQ);



/** 
 * @brief Destroy message queue
 *
 * @param[in] _mqID - msg queue ID
 *
 * @param[in-out] _msqDs - pointer to retrieve data on message queue
 *  
 * @return  void
 */
void MsgQDestroy(int _mqID, msqid_ds* _msqDs);



/** 
 * @brief Transmit message into message queue
 *
 * @param[in] _mqID - message queue ID
 *
 * @param[in] _txMsg - message to send
 *
 * @param[in] _msgSize - message size
 *
 * @param[in] _channel - channel to send message on
 *  
 * @return  Success ?
 *
 * @retval	TODO update this
 */
int MsgQTransmit(int _mqID, Msg* _txMsg, size_t _msgSize, int _channel);



/** 
 * @brief Receive message from message queue
 *
 * @param[in] _mqID -  message queue ID
 *
 * @param[in] _rxMsg - message to receive
 *
 * @param[in] _msgSize - message size
 *
 * @param[in] _channel - channel to receive message on
 *
 * @param[in] _flag - Receive flag (e.g. IPC_NOWAIT)
 *  
 * @return  TODO update this
 */
ssize_t MsgQReceive(int _mqID, Msg* _rxMsg, size_t _msgSize, int _channel, int _flag);




#endif /* #ifndef __MSGQ_H__ */



