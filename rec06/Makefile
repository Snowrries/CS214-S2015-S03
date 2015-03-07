CC = gcc
CFLAGS = -std=c99 -Wall -Werror -pedantic
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

all: isascii

clean:
	@rm -rf $(BUILD_DIR)/*.dSYM
	@rm -f $(BUILD_DIR)/*
	@rm -f $(LIB)/*

isascii: isascii.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $^
