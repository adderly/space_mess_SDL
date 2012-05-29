#include<SDL/SDL.h>

#ifndef KEYS
#define KEYS
/*
    This file constains keys for handling
    constantly pressend keys
    *******
    MOUSE AND KEYBOARD
    *******
*/
// Game STATES

static bool Running =  true;
static bool Paused = true;
static bool Mainmenu= false;
static bool GRABBED =  false;

/*    KEYBOARD      */
static SDL_Event event;
//static SDL_Surface *screen;
static bool p_left = false;
static bool p_right = false;
static bool p_up = false;
static bool p_down = false;
static bool SPACE = false;
static bool ENTER = false;
static bool A = false;
static bool S = false;
static bool D = false;
static bool W = false;
static bool BACKSPACE = false;
static bool E = false;
static bool R = false;
static bool Q = false;
static bool F = false;
static bool Z = false;
static bool X = false;
static bool C = false;
static bool V = false;
static bool TAB = false;

/*      MOUSE       */
static bool MOUSE_LCLICK = false;
static bool MOUSE_RCLICK = false;
static bool MOUSE_MCLICK = false;


#endif
