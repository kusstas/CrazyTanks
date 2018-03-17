#ifndef GAME_INSTANCE_H
#define GAME_INSTANCE_H

class GameInstance
{
public:

	GameInstance();
	virtual ~GameInstance() = 0;

	// Execute on initialize game
	virtual void initialize();

	// Execute even draw-tick (deltaTime - time previos tick in sec)
	virtual void tick(float deltaTime);

};

#endif // !GAME_INSTANCE_H