#ifndef __UI_MANAGER_H__
#define __UI_MANAGER_H__
#include "../../Comms/Transmitter/Transmitter.h"
/** 
 *  @file UIManager.h
 *
 *  @brief UI Manager receives commands from user and transmits to processor or feeder accordingly
 *
 *  @author Eyal Alon  (eyal171@yahoo.com)
 * 
 *  @bug Blasphemy 
*/


typedef struct UIManager UIManager;



/** 
 * @brief Create new UIManager
 *  
 * @return  pointer to allocated UIManager instance
 *
 * @retval	NULL upon create fail
 *
 * @retval	!NULL upon create success
 */
UIManager* UIManagerCreate();



/** 
 * @brief Destroy UIManager
 *
 * @param[in] _uiMngr - UIManager instance to destroy
 * 
 * @return  void
 */
void UIManagerDestroy(UIManager* _uiMngr);



/** 
 * @brief Send command to feeder or processor
 *
 * @param[in] _uiMngr - UIManager instance that contains trnasmitter instance
 * 
 * @param[in] _data - Data of message to send
 * 
 * @param[in] _channel - Channel to send message on
 *  
 * @return  Transmit success?
 *
 * @retval	0 upon NULL == _uiMngr
 *
 * @retval	1 upon success
 */
int UIManagerSendCommand(UIManager* _uiMngr, Data _data, int _channel);





#endif /* #ifndef __UI_MANAGER_H__ */

