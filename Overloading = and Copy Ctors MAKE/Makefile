###########################################################
###                  Example Makefile                   ###
###########################################################


CC = g++ -std=c++14 -Wall
BIN = ./bin
EXE = $(BIN)/example
#wildcard function (Replaces wildcard with actual string/ Otherwise it would literally use the asterisk)
SRCS := $(wildcard *.cpp)
#Pattern subsitution
OBJS := $(patsubst %.cpp, $(BIN)/%.o, $(SRCS))
LINKFLAGS = -o $(EXE)

#Makefiles can remake themselves. This disables make from searching for implicit rules to remake the makefile

run: all
	$(EXE)

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(OBJS) $(LINKFLAGS)

$(OBJS): $(BIN)/%.o: %.cpp | dir
	$(CC) -c $< -o $@

dir:
	@mkdir -p $(BIN)

clean:
	rm -rf $(BIN)/*

.PHONY: run all dir clean
