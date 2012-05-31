/*
*Here Will Be Place Variables that affects the environment
*
*  Gravity,PartclesDelay,Speed
*
*/

#ifndef ENV
#define ENV

class Environment
{
public:
    float gravity;
    float delay;
    float wind;
    Environment();
    float getGravity()
    {
        return gravity;
    }
    float getDelay()
    {
        return delay;
    }
    void setGravity(float g)
    {
        gravity = g;
    }
    void setDelay(float d)
    {
        delay = d;
    }
    ~Environment();
};
#endif
