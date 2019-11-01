/* ADT STATE dalam permainan, dan untuk push di stack untuk save state */

#ifndef STATE_H
#define STATE_H
#include "arraydin.h"
#include "player.h"

typedef struct {
    TabBangunan ArrayBangunan;
    Player Player1;
    Player Player2;    
} State;







#endif