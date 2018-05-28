FILES = main.cpp afd.cpp utils.cpp
OUT = automato
CC = g++
WARN = -Wall
FLAGS = -std=c++14

default: $(OUT)
automata: $(FILES)
	$(CC) $(WARN) -o $(OUT) $(FILES) $(FLAGS)

.PHONY: automata