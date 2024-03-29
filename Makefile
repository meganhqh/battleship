FLAGS = -pedantic-errors -std=c++11

setship.o: setship.cpp setship.h gameflow.h save_load.h quit.h battleship.h
	g++ $(FLAGS) -c $<

attack_easy.o: attack_easy.cpp attack_easy.h battleship.h
	g++ $(FLAGS) -c $<

attack_difficult.o: attack_difficult.cpp attack_difficult.h gameflow.h save_load.h quit.h check_winner.h battleship.h
	g++ $(FLAGS) -c $<

gameflow.o: gameflow.cpp gameflow.h gameflow.h save_load.h quit.h check_winner.h battleship.h
	g++ $(FLAGS) -c $<

check_winner.o: check_winner.cpp check_winner.h battleship.h
	g++ $(FLAGS) -c $<

quit.o: quit.cpp quit.h battleship.h
	g++ $(FLAGS) -c $<

save_load.o: save_load.cpp save_load.h battleship.h
	g++ $(FLAGS) -c $<

battleship.o: battleship.cpp gameflow.h setship.h attack_easy.h attack_difficult.h save_load.h battleship.h
	g++ $(FLAGS) -c $<

battleship: battleship.o gameflow.o setship.o attack_easy.o attack_difficult.o check_winner.o save_load.o quit.o 
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f battleship *.o

.PHONY: clean
