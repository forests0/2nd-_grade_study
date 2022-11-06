#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include <time.h>

int main(void) {
	srand((unsigned int)time(NULL));
	int width = 16, height = 8;

	MonsterWorld game(width, height);
	game.add(new Zombie("좀비1", '!', rand() % width, rand() % height));
	game.add(new Vampire("뱀파이어1", '@', rand() % width, rand() % height));
	game.add(new Jiangshi("강시1", '^', rand() % width, rand() % height));
  game.add(new Human("인간1", '~' , rand() % width, rand() % height ));
	game.play(5, 1);
	return 0;
}