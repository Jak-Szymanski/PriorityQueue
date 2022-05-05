TRGDIR=.
OBJ=./obj
SRC=./src
INC=./inc
FLAGS= -Wall -g

${TRGDIR}/main: ${OBJ} ${OBJ}/main.o ${OBJ}/package.o\
                     ${OBJ}/node.o ${OBJ}/queue.o ${OBJ}/receiver.o ${OBJ}/sender.o
	g++ -o ${TRGDIR}/main ${OBJ}/main.o ${OBJ}/package.o\
                     ${OBJ}/node.o ${OBJ}/queue.o ${OBJ}/receiver.o ${OBJ}/sender.o
                   
${OBJ}:
	mkdir ${OBJ}

${OBJ}/main.o: ${SRC}/main.cpp inc/sender.h inc/receiver.h
	g++ -c ${FLAGS} -o ${OBJ}/main.o ${SRC}/main.cpp

${OBJ}/package.o: ${SRC}/package.cpp inc/package.h
	g++ -c ${FLAGS} -o ${OBJ}/package.o ${SRC}/package.cpp

${OBJ}/node.o: ${SRC}/node.cpp inc/node.h
	g++ -c ${FLAGS} -o ${OBJ}/node.o ${SRC}/node.cpp

${OBJ}/queue.o: ${SRC}/queue.cpp inc/queue.h
	g++ -c ${FLAGS} -o ${OBJ}/queue.o ${SRC}/queue.cpp

${OBJ}/receiver.o: ${SRC}/receiver.cpp inc/receiver.h
	g++ -c ${FLAGS} -o ${OBJ}/receiver.o ${SRC}/receiver.cpp
	
${OBJ}/sender.o: ${SRC}/sender.cpp inc/sender.h
	g++ -c ${FLAGS} -o ${OBJ}/sender.o ${SRC}/sender.cpp

run:
	${TRGDIR}/main

clean:
	rm -f ${TRGDIR}/main ${OBJ}/*
