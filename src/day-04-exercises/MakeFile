CXX		 := g++
CXXFLAGS := -std=c++17 -Wall -Wextra
OUT_DIR  := output

SRCS     := $(shell find . -name "*.cpp")
TARGETS  := $(patsubst %.cpp, $(OUT_DIR)/%.exe, $(SRCS))

.PHONY: all clean

all: $(TARGETS) 

$(OUT_DIR)/%.exe: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf $(OUT_DIR)