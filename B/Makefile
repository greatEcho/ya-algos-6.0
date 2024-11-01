PROGRAM := b
CC := g++
CFLAGS := -g
SRC := sol.cc

$(PROGRAM): $(SRC)
	$(CC) $(CFLAGS) -o $@ $<

test: test.cc
	@$(CC) -o $@ $<
	@./$@

.PHONY: clean test

clean:
	@rm -f $(PROGRAM)
