CC = g++

CXXFLAGS = -Wall -Wextra -pedantic -std=c++2a
LDFLAGS_BASE = -lsfml-graphics -lsfml-window -lsfml-system

vpath %.cc src/

OBJS = main.o
EXE = µEngine

.PHONY: release debug clean

release: LDFLAGS += $(LDFLAGS_BASE)
release: CXXFLAGS += -O3
release: $(EXE)

debug: LDFLAGS += -lasan $(LDFLAGS_BASE)
debug: CXXFLAGS += -g3 -O0 -fsanitize=address
debug: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	$(RM) $(OBJS) $(EXE)