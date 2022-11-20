#include "MonsterWorld.h"
#include "Human.h"
#include "VariousMonsters.h"
#include <time.h>

int main(void) {
	srand((unsigned int)time(NULL));
	int width = 16, height = 8;

	MonsterWorld game(width, height);
	game.add(new Human("ㅇ1ㄴ간", '&', rand() % width, rand() % height));
	game.add(new Zombie("좀ㅂ1", '!', rand() % width, rand() % height));
	game.add(new Vampire("뱀ㅍr이어1", '@', rand() % width, rand() % height));
	game.add(new Vampire("뱀pㅏ이어2", '*', rand() % width, rand() % height));
	game.play(30, 1000);
	return 0;
}