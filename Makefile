BINDIR=./bin
OBJDIR=./obj
SRCDIR=./src
INCDIR=./include
TESTDIR=./testsuite

CC=gcc
CFLAGS=-std=c99 -O0 -g -Wall -Wextra -I$(INCDIR)
LDFLAGS=-g

SRC_FILES=$(wildcard $(SRCDIR)/*.c)
OBJ_FILES=$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC_FILES))


EXEC=$(BINDIR)/quiestce

all: $(BINDIR)/quiestce

run: $(BINDIR)/quiestce
	$(BINDIR)/quiestce

# Règle générique

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/%.h
	$(CC) -c $(CFLAGS) $< -o $@

# Coeur du fil rouge

$(EXEC): $(OBJ_FILES)
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJDIR)/jeu.o: $(INCDIR)/ensemble.h $(INCDIR)/suspect.h

$(OBJDIR)/suspect.o: $(INCDIR)/ensemble.h

.PHONY: clean

clean:
	rm -rf $(EXEC) $(OBJ_FILES) $(TESTS_OBJ) $(TESTS) $(TESTDIR)/*.o
