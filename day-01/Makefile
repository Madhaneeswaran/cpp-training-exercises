CXX = g++
CXXFLAGS = -Wall -std=c++17

SOURCES = $(wildcard [0-9]*.cpp)
SOURCES := $(filter-out 05b_%,$(SOURCES))
TARGETS = $(SOURCES:.cpp=.exe)

all: $(TARGETS) extern

%.exe: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

extern: 05b_extern_main.cpp 05b_extern_helper.cpp
	$(CXX) $(CXXFLAGS) 05b_extern_main.cpp 05b_extern_helper.cpp -o 05b_extern.exe

run-%: %.exe
	./$<

clean:
	rm -f *.exe

.PHONY: all clean extern
