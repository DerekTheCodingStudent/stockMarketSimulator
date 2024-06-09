FLAGS = -Wall -Werror -g

main.bin : main.o economy.o event.o market.o stock.o user.o 
	g++ $(FLAGS)  main.o economy.o event.o market.o stock.o user.o -o main.bin


main.o : main.cpp main.h user.h market.h stock.h
	g++ $(FLAGS) -c main.cpp

economy.o : economy.cpp economy.h 
	g++ $(FLAGS) -c economy.cpp 

event.o : event.cpp event.h 
	g++ $(FLAGS) -c event.cpp 

market.o : market.cpp market.h stock.h 
	g++ $(FLAGS) -c market.cpp

stock.o : stock.cpp stock.h market.h user.h
	g++ $(FLAGS) -c stock.cpp
	
user.o : user.cpp user.h 
	g++ $(FLAGS) -c user.cpp


clean :
	rm -f *.o *.bin
