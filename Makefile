CC=g++
OPTIONS= -g
DEBUG= -D DEBUG
LIBDIR=lib
INCLUDEDIR=include
_OBJ= tabbcom.o tcomplejo.o tvectorcom.o
OBJ = $(patsubst %,$(LIBDIR)/%,$(_OBJ))
all : tad
tad: src/tad.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tad.cpp $(OBJ) -o tad
$(LIBDIR)/%.o : $(LIBDIR)/%.cpp $(INCLUDEDIR)/%.h
	$(CC) $(OPTIONS) $(DEBUG) -c -I$(INCLUDEDIR) -o $@ $<
clean:
	rm -f $(OBJ)