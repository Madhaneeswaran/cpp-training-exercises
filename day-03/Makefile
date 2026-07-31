CXX = g++
CXXFLAGS = -Wall -std=c++17

SOURCES = $(wildcard [0-9]*.cpp)
TARGETS = $(SOURCES:.cpp=.exe)

all: $(TARGETS)

%.exe: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

run-%: %.exe
	./$<

clean:
	rm -f *.exe

.PHONY: all clean
