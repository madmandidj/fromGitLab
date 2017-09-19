#ifndef __TRANSMITTER_H__
#define __TRANSMITTER_H__
#include "../MsgQueue/MsgQ.h"
/** 
 *  @file Transmitter.h
 *
 *  @brief Transmitter is responsible for transmitting messages through the message queue
 *
 *  @author Eyal Alon  (eyal171@yahoo.com)
 * 
 *  @bug Blasphemy 
*/



typedef struct Transmitter Transmitter;



/** 
 * @brief Create new Transmitter instance and connect to message queue
 *
 * @param[in] _myPathToMsgQ - path and filename to directory entry of associated message queue
 *  
 * @return  pointer to allocated Transmitter instance
 *
 * @retval	NULL upon create fail
 *
 * @retval	!NULL upon create success
 */
Transmitter* TransmitterCreate(char* _myPathToMsgQ);



/** 
 * @brief Destroy Transmitter
 *
 * @param[in] _trans - Transmitter instance
 *  
 * @return  void
 */
void TransmitterDestroy(Transmitter* _trans);



/** 
 * @brief Destroy Transmitter and disconnect message queue
 *
 * @param[in] _trans - Transmitter instance
 *  
 * @return  void
 */
void TransmitterDestroyAndDisconnect(Transmitter* _trans);



/** 
 * @brief Transmit message into message queue
 *
 * @param[in] _trans - Transmitter instance
 *
 * @param[in] _msg - message to send
 *
 * @param[in] _msgSize - message size
 *
 * @param[in] _channel - channel to send message on
 *  
 * @return  Success ?
 *
 * @retval	0 if NULL==_trans
 *
 * @retval	1 if success
 */
int TransmitterSend(Transmitter* _trans, Msg* _msg, size_t _msgSize, int _channel);



#endif /* #ifndef __TRANSMITTER_H__ */





