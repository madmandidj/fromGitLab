#ifndef __RECEIVER_H__
#define __RECEIVER_H__
#include "../MsgQueue/MsgQ.h"
/** 
 *  @file Receiver.h
 *
 *  @brief Receiver is responsible for receiving messages through the message queue
 *
 *  @author Eyal Alon  (eyal171@yahoo.com)
 * 
 *  @bug Blasphemy 
*/



typedef struct Receiver Receiver;



/** 
 * @brief Create new Receiver instance and connect to message queue
 *
 * @param[in] _myPathToMsgQ - path and filename to directory entry of associated message queue
 *  
 * @return  pointer to allocated Receiver instance
 *
 * @retval	NULL upon create fail
 *
 * @retval	!NULL upon create success
 */
Receiver* ReceiverCreate(char* _myPathToMsgQ);



/** 
 * @brief Destroy receiver
 *
 * @param[in] _rcvr - receiver instance
 *  
 * @return  void
 */
void ReceiverDestroy(Receiver* _rcvr);



/** 
 * @brief Destroy receiver and disconnect message queue
 *
 * @param[in] _rcvr - receiver instance
 *  
 * @return  void
 */
void ReceiverDestroyAndDisconnect(Receiver* _rcvr);



/** 
 * @brief Receive message from message queue
 *
 * @param[in] _rcvr - Receiver instance
 *
 * @param[in] _msg - message to receive
 *
 * @param[in] _msgSize - message size
 *
 * @param[in] _channel - channel to receive message on
 *
 * @param[in] _flag - Receive flag (e.g. IPC_NOWAIT)
 *  
 * @return  number of bytes received or  -1 upon error
 */
ssize_t ReceiverReceive(Receiver* _rcvr, Msg* _msg, size_t _msgSize, int _channel, int _flag);



#endif /* #ifndef __RECEIVER_H__ */


