CXX = g++
CXXFLAGS = -std=c++14 -g -Werror=vla -MMD
OBJECTS = cell.o grid.o textdisplay.o block.o iblock.o jblock.o lblock.o oblock.o sblock.o tblock.o zblock.o controller.o main.o levels.o levelzero.o levelone.o leveltwo.o levelthree.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = biquadris

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS}
