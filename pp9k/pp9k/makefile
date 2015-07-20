CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = flood
OBJECTS = main.o game.o tile.o player.o human.o computer.o view.o textView.o graphicsView.o piece.o pawn.o knight.o rook.o bishop.o queen.o king.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
