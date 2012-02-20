#include"Actors/Gun.h"
#include"ParticleGenerator.h"


class Player
{
        Gun *gun;
        ParticleGenerator* gen;
		public:
		friend class ParticleGenerator;
        int movx;
        int movy;
        int movz;
		int x;
		int y;
		int width;
		int height;
		bool alive;
		void shoot();

		Player(ParticleGenerator* gen);
		~Player();
};


