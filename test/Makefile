CPP       := g++
CC        := gcc

SRCS      := ../xml_encode.c
OBJS      := $(patsubst %.c,%.o, $(SRCS))

MAIN_SRC  := $(notdir $(OBJS)) test_xml_module.c
EXE       := test_xml_module

INCLUDE   := -I./ -I../
CFLAGS    := -std=c99
CPPFLAGS  := -std=c++14 $(INCLUDE)

LIBRARY   := -L./gtest -lgtest -lpthread

all: $(OBJS)
	$(CPP) $(CPPFLAGS) $(MAIN_SRC) -o $(EXE) $(LIBRARY)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(EXE)
	
.PHONY: all clean