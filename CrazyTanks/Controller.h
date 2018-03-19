// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#ifndef CONTROLLER_H
#define CONTROLLER_H

class Tank;

class Controller
{
public:

    Controller();
    virtual ~Controller();

    virtual void tick(float deltaTime) = 0;

    void setPawn(Tank& pawn);
    const Tank& getPawn() const;

protected:

    Tank* pawn_;

};

#endif // !CONTROLLER_H