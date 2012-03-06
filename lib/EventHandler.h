#include<SDL/SDL.h>
#include"../utils/keys.h"

class Game;
class Player;
class EventHandler
	{

       SDL_Event event;
     friend class Game;
		public:
		EventHandler();
		EventHandler(Game* gm);
		EventHandler(Game* gm,Player* player);
		void checkEvents();
		void addFuncToKey(void(*callback));
		~EventHandler();

	};
