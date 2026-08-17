CC       := gcc
CXX      := g++
CFLAGS   := -Wall -Wextra
CXXFLAGS := -std=c++17 -Wall -Wextra
OUT_DIR  := output
TARGET   := $(OUT_DIR)/main.exe

all: $(OUT_DIR) $(TARGET)

$(OUT_DIR):
	mkdir -p $(OUT_DIR)

$(OUT_DIR)/factorial.o: factorial.c factorial.h | $(OUT_DIR)
	$(CC) $(CFLAGS) -c factorial.c -o $(OUT_DIR)/factorial.o

$(TARGET): main.cpp $(OUT_DIR)/factorial.o
	$(CXX) $(CXXFLAGS) main.cpp $(OUT_DIR)/factorial.o -o $(TARGET)

clean:
	rm -rf $(OUT_DIR)
