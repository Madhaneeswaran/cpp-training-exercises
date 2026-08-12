CXX		:= g++
CXXFLAGS	:= -std=c++17 -Wall -Wextra

OUT_DIR  := output

SRCS     := $(wildcard *.cpp)
TARGETS  := $(patsubst %.cpp, $(OUT_DIR)/%.exe, $(SRCS))

all: $(OUT_DIR) $(TARGETS) 

$(OUT_DIR):
	mkdir -p $(OUT_DIR)

$(OUT_DIR)/%.exe: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf $(OUT_DIR)