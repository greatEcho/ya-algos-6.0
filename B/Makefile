PROGRAM := b
CC := g++
CFLAGS := -g
SRC := sol.cc

$(PROGRAM): $(SRC)
	$(CC) $(CFLAGS) -o $@ $<

test: test.cc
	@$(CC) -D TEST -o $@ $<
	@./$@

.PHONY: clean test

clean:
	@rm -f $(PROGRAM)
