#ifndef __UI_MANAGER_H__
#define __UI_MANAGER_H__

#include "../../Comms/Transmitter/Transmitter.h"

typedef struct UIManager UIManager;


UIManager* UIManagerCreate();

void UIManagerDestroy(UIManager* _uiMngr);

int UIManagerSendCommand(UIManager* _uiMngr, Data _data, int _channel);






















#endif /* #ifndef __UI_MANAGER_H__ */

