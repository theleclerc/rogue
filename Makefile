all: rogue

rogue: main.o personnage.o labyrinthe.o 
	g++ $^ -lncurses -o $@ 

main.o: main.cpp personnage.h labyrinthe.h 
	g++ -c $< 

personnage.o: personnage.cpp personnage.h 
	g++ -c $< 

labyrinthe.o: labyrinthe.cpp labyrinthe.h
	g++ -c $< 

clean:
	rm -rf *.o
	rm -rf ./rogue

mrproper: clean
	rm -rf hello