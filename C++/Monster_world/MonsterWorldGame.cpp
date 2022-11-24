#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include "RankBoard.h"
#include "Human.h"
#include <time.h>

#define RANK_FILENAME "MonsterWorld.txt"

int main(void) {
  RankingBoard rankboard;
  rankboard.load(RANK_FILENAME);
	srand((unsigned int)time(NULL));
	int width = 16, height = 8;
	MonsterWorld game(width, height);
	Human* human = new Human("ㅇ1ㄴ간", '&', rand() % width, rand() % height);
	game.add(new Zombie("좀ㅂ1", '!', rand() % width, rand() % height));
	game.add(new Vampire("뱀ㅍr이어1", '@', rand() % width, rand() % height));
	game.add(new Vampire("뱀pㅏ이어2", '*', rand() % width, rand() % height));
  game.add(human);
  game.play(30, 100);

  rankboard.add(human->getnItem());
  rankboard.print("[game rank] : end");
  rankboard.save(RANK_FILENAME);
	return 0;
}
