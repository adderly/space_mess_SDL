#include"../lib/ParticleGenerator.h"
#include<iostream>

int main(int argc, char *argv[])
{

    float c[] = {210,50,0};
    c;
    ParticleGenerator* generator = new ParticleGenerator();
    generator->createParticles(150);
    generator->evolveParticles();


//	if(argc > 2)
//	{
//		for(int n = 0;n < sizeof(argv)/sizeof(char);n++)
//		{
//			std::cout<<*(argv);
//		}
//	}

	return 0;
}
