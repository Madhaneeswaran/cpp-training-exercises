CXX      := g++
# Added -Iinclude so the compiler searches the include/ directory for headers
CXXFLAGS := -std=c++17 -Wall -Wextra -Werror -Wno-unused-parameter -Iinclude
OUT_DIR  := output
SRCS     := $(shell find src -name "*.cpp") # Point specifically to src/
TARGETS  := $(OUT_DIR)/ems_app.exe

.PHONY: all clean

all: $(TARGETS)

$(TARGETS): $(SRCS)
	@mkdir -p $(OUT_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf $(OUT_DIR)
	rm -f *.log