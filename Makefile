CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = biquadris
OBJECTS =  main.o centralcommand.o board.o playercommands.o playerinfo.o subject.o observer.o choice.o observeroftimeandactivationtime.o factoryblock.o level.o level1block.o blockcontent.o tblockcontent.o blockoperation.o cell.o theboard.o leftoperation.o setup.o sblockcontent.o jblockcontent.o lblockcontent.o iblockcontent.o zblockcontent.o oblockcontent.o rotateoperation.o counterrotateoperation.o rightoperation.o downoperation.o level2block.o level3block.o  level0block.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
