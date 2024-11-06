TARGET = bin/main
CFILES = $(shell find ./src -name '*.c')
SRC = $(patsubst ./src/%.c, src/%.c, $(CFILES))
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))

.PHONY: run clean build

default: clean build run

run:
	@./$(TARGET)

build: $(TARGET)

clean:
	@clear
	@rm -rf obj/*
	@rm -rf bin/*

$(TARGET): $(OBJ)
	@gcc -g -o $@ $^ -Isrc -l:libglfw3.a -lm

obj/%.o: src/%.c
	@mkdir -p $(@D)
	@gcc -g -c $< -o $@ -Isrc