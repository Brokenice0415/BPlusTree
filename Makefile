CPP      = g++
OBJ      = Node.o Tree.o demo.o
LINKOBJ  = Node.o Tree.o demo.o
BIN      = B+Tree
CXXFLAGS = $(CXXINCS) -g3 -std=c++11
CFLAGS   = $(INCS) -g3 -std=c++11
RM       = rm -rf

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)

Node.o: Node.cpp
	$(CPP) -c Node.cpp -o Node.o $(CXXFLAGS)

Tree.o: Tree.cpp
	$(CPP) -c Tree.cpp -o Tree.o $(CXXFLAGS)

demo.o: demo.cpp
	$(CPP) -c demo.cpp -o demo.o $(CXXFLAGS)

