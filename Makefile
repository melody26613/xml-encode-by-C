OBJS   := xml_encode.o
EXE    := xml_encode
CFLAGS := -g -std=c99
CC     := gcc

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXE)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $<
	
clean:
	rm -f $(OBJS) $(EXE)
	
.PHONY: all clean