CC = gcc
CXX = g++
CFLAGS = -std=c99 -Wall -Werror -pedantic
CXXFLAGS = -std=c++03 -g -Wall -pedantic 
BUILD_DIR = build
VPATH = src
LIB = lib
REQUIRED_DIRS = $(BUILD_DIR) $(VPATH) $(LIB)
.PHONY = asm provision clean funcs
_MKDIRS := $(shell for dir in $(REQUIRED_DIRS); \
	do \
		[[ -d $$dir ]] || mkdir -p $$dir; \
	done)

debug: CFLAGS = -Wall -std=c11 -g
debug: all

all: iter_test

clean:
	@rm -rf $(BUILD_DIR)/*.dSYM
	@rm -f $(BUILD_DIR)/*
	@rm -f $(LIB)/*


iter_test: iter_test.cpp
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$@ $^
