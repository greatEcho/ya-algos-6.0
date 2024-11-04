PROGRAM := c
CC := g++
CFLAGS := -g
SRC := sol.cc
SRC_TEST := test.cc sol.cc

$(PROGRAM): $(SRC)
	$(CC) $(CFLAGS) -o $@ $<

test: $(SRC_TEST)
	@$(CC) -DTEST -o $@ $<
	@./$@
