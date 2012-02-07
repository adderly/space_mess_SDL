#include<SDL/SDL.h>

class EventHandler
	{
     protected: SDL_Event event;
     friend class Game;
		public:


		//EventHandler(Game& gm);
		EventHandler();
		void checkEvents();
		~EventHandler();

	};
