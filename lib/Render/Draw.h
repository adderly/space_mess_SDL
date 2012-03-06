
/*
Here To solve the problem in drawing some objects,
they could actually inherit draw mechanisms.
The idea in here is like for animations, explisions.
This could help, in writing more flexible code.

Ex.: If we could have like an instance of an animation,
 it would be easier that it draw itself. Rather than
 passing it around in the render.
 Good practice? I don't know.

*/

#ifndef DRAW
#define DRAW

class Draw
{
    public:
    virtual void draw()=0;
};

#endif


