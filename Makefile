CC     := gcc

OBJS   := xml_encode.o sample.o
EXE    := sample
CFLAGS := -g -std=c99

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXE)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $<
	
clean:
	rm -f $(OBJS) $(EXE)
	
.PHONY: all clean