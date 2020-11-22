BINARY := picasino
COMPILE := g++

.PHONY: all clean

all: $(BINARY)

clean:
	rm -f bin/$(BINARY)

$(BINARY):
	$(COMPILE) src/$(BINARY).cpp -o bin/$(BINARY)
