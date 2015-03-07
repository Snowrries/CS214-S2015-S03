CC = gcc
CFLAGS = -std=c99 -pedantic
BUILD_DIR = build
VPATH = src
LIB = lib
REQUIRED_DIRS = $(BUILD_DIR) $(VPATH) $(LIB)
.PHONY = asm provision clean funcs
_MKDIRS := $(shell for dir in $(REQUIRED_DIRS); \
	do \
		[[ -d $$dir ]] || mkdir -p $$dir; \
	done)

debug: CFLAGS = -std=c99 -g
debug: all

all: compileme	

clean:
	@rm -rf $(BUILD_DIR)/*.dSYM
	@rm -f $(BUILD_DIR)/*
	@rm -f $(LIB)/*

libmylib.a: mylib.o
	ar rcs $(LIB)/$@ $(BUILD_DIR)/$^

mylib.o: mylib/mylib.c
	$(CC) $(CFLAGS) -c -o $(BUILD_DIR)/$@ $^
	
compileme: compileme.c libmylib.a 
	$(CC) $(CFLAGS) -L$(LIB) -lmylib -o $(BUILD_DIR)/$@ $<
