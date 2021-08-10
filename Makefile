all:
	g++ -std=c++17 -c Main.cpp Screen.cpp WindowManager.cpp
	g++ -std=c++17 Main.o Screen.o WindowManager.o -o Main
