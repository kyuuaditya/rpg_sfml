all: compile link run

compile:
	g++ -I"C:\SFML-2.6.2\include" -c main.cpp -o app.o

link: 
	g++ -I"C:\SFML-2.6.2\include" .\app.o -o app.exe -L"C:\SFML-2.6.2\lib" -lmingw32 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-main -mwindows

run:
	./app.exe