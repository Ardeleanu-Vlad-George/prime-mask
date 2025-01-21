TRG := run

$(TRG) : main.cpp
	g++ -o $@ $^ -lsfml-graphics -lsfml-system
