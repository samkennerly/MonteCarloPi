BINS := picasino
CC := g++

.PHONY: all clean

all: $(BINS)

clean:
	rm -f bin/$(BINS)

$(BINS):
	$(CC) src/$(BINS).cpp -o bin/$(BINS)
