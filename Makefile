CXXFLAGS = -Wall -O2 -std=c++1y
CPP_FILES = $(wildcard *.cpp)
BIN_FILES = $(patsubst %.cpp,bin/%,$(CPP_FILES))
MD_FILES = $(wildcard md/*.md)
PDF_FILES = $(patsubst md/%.md,pdf/%.pdf,$(MD_FILES))

all: $(BIN_FILES) $(PDF_FILES)

bin/%: %.cpp
	g++ $(CXXFLAGS) -o $@ $<

pdf/%.pdf: md/%.md
	md-to-pdf $< $@

clean:
	rm -rf bin/*
