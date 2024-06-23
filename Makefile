FLAGS = -Wall -Werror -g

main.bin : main.o event.o market.o stock.o user.o json11.o
	g++ $(FLAGS)  main.o event.o market.o stock.o user.o json11.o -o main.bin


main.o : main.cpp main.h user.h market.h stock.h event.h
	g++ $(FLAGS) -c main.cpp

event.o : event.cpp event.h market.h
	g++ $(FLAGS) -c event.cpp 

market.o : market.cpp market.h stock.h json11.hpp
	g++ $(FLAGS) -c market.cpp

stock.o : stock.cpp stock.h market.h user.h
	g++ $(FLAGS) -c stock.cpp
	
user.o : user.cpp user.h 
	g++ $(FLAGS) -c user.cpp

json11.o : json11.cpp json11.hpp
	g++ $(FLAGS) -c json11.cpp

clean :
	rm -f *.o *.bin
