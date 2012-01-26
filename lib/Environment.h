/*
*Here Will Be Place Variables that affects the environment
*
*  Gravity,PartclesDelay,Speed
*
*/



class Environment
{

    public:
    float gravity;
    float delay;
    Environment();
    float getGravity(){return gravity;}
    float getDelay(){return delay;}
    void setGravity(float g){gravity = g;}
    void setDelay(float d){ delay = d;}
    ~Environment();
};
