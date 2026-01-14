
CC=clang++
FLAGS= -std=c++17 -lraylib

BUILD_FOLDER=build
OUTPUT=out


SOURCE_FILES=$(wildcard ./src/*.cpp) $(wildcard ./src/class/*.cpp) $(wildcard ./src/class/Game/*.cpp) $(wildcard ./src/class/Base/*.cpp)

INCLUDE_FILES=./include

all:
	rm -rf $(BUILD_FOLDER)
	mkdir -p $(BUILD_FOLDER)


	$(CC) $(FLAGS) $(SOURCE_FILES) -o $(BUILD_FOLDER)/$(OUTPUT) -I $(INCLUDE_FILES)
	./$(BUILD_FOLDER)/$(OUTPUT)
