EXEC= BOXHead
GAME= main.o camera.o world.o
ENTITIES= entity.o enemy.o player.o projectile.o tower.o
DEPS= includes.h

SFML= -lsfml-graphics -lsfml-window -lsfml-system
CC=gcc
CFLAGS=-I. $(SFML)

%.o: %.cpp %.h $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

boxhead: $(ENTITIES) $(GAME)
		$(CC) -o $(EXEC) $^ $(CFLAGS)

clean:
	rm -rf $(ENTITIES) $(GAME) $(EXEC)
