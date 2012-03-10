#include"../utils/keys.h"

class Game;
class Player;
class EventHandler
	{
         SDL_Event *event;
		public:
		friend class Game;
		EventHandler(SDL_Event *event);
		EventHandler(Game* gm);
		EventHandler(Game* gm,Player* player);
		void check();
		void addFuncToKey(void(*callback));
		~EventHandler();

	};



