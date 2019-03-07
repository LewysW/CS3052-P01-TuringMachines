all: clean runtm

runtm:
	g++ -Wall -Wextra main.cpp state.cpp tm.cpp alphabet.cpp fileParser.cpp tape.cpp transition.cpp -o runtm -std=c++11

clean:
	rm -rf runtm *.o
