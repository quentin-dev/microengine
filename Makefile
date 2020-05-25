CC = clang++

CXXFLAGS = -Wall -Wextra -pedantic -std=c++2a

LDFLAGS_SFML = -lsfml-graphics -lsfml-window -lsfml-system
LDFLAGS_BOOST = -lboost_program_options
LDFLAGS_BASE =  $(LDFLAGS_SFML) $(LDFLAGS_BOOST)

vpath %.cc src/ src/Engine src/Engine/Graphics src/Engine/Input src/Engine/Gameplay src/Engine/Options

OBJS = main.o Engine.o GraphicsManager.o InputManager.o Scene.o Player.o GameplayManager.o GraphicsOptions.o
EXE = µEngine

DOXYFILE = doc/Doxyfile
DOCDIR = html/

.PHONY: release debug clean doc

release: LDFLAGS += $(LDFLAGS_BASE)
release: CXXFLAGS += -O3
release: $(EXE)

debug: LDFLAGS += -lasan $(LDFLAGS_BASE)
debug: CXXFLAGS += -DDEBUG -g3 -O0 -fsanitize=address
debug: $(EXE)

doc: $(DOXYFILE)
	doxygen $^

$(EXE): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.cc
	$(CC) $(CXXFLAGS) -c -o $@ $^

clean:
	$(RM) $(OBJS) $(EXE) $(DOCDIR)