EXEC= BOXHead
GAME= main.o world.o texturemanager.o
ENTITIES= entity.o enemy.o player.o projectile.o tower.o spawn.o
DEPS= includes.h

SFML= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
CC=g++
CFLAGS=-I. $(SFML)

%.o: %.cpp %.h $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

boxhead: $(ENTITIES) $(GAME)
		$(CC) -o $(EXEC) $^ $(CFLAGS)

clean:
	rm -rf $(ENTITIES) $(GAME) $(EXEC)
