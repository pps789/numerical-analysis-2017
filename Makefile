CXXFLAGS = -Wall -O2 -std=c++1y
CPP_FILES = $(wildcard *.cpp)
BIN_FILES = $(patsubst %.cpp,bin/%,$(CPP_FILES))

all: $(BIN_FILES)

bin/%: %.cpp
	g++ $(CXXFLAGS) -o $@ $<

clean:
	rm -rf bin/*
