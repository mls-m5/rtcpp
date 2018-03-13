CXXFLAGS = -std=c++11


all: main.o api.o
	g++ main.o -o rtc++ -ldl

%.%: %.cpp api.h


run: all
	./rtc++
