all: compile link run

compile:
	g++ -I"C:\SFML-2.6.2\include" -c math.cpp -o math.o
	g++ -I"C:\SFML-2.6.2\include" -c player.cpp -o player.o
	g++ -I"C:\SFML-2.6.2\include" -c skeleton.cpp -o skeleton.o
	g++ -I"C:\SFML-2.6.2\include" -c main.cpp -o app.o

link: 
	g++ -I"C:\SFML-2.6.2\include" .\app.o .\player.o .\skeleton.o .\math.o -o app.exe -L"C:\SFML-2.6.2\lib" -lmingw32 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-main 

run:
	./app.exe