CC=g++ #Name of compiler
FLAGS=-std=c++20 #Compiler flags
TARGET=RUN #Executable name
OBJECTS=AnalyseData.o CustomFunctions.o #Intermediate object files

#First target
${TARGET}:${OBJECTS} #Make target from objects
	@echo "Linking..."
	${CC} ${FLAGS} ${OBJECTS} -o ${TARGET}
	@make clean #Calls the clean target to remove object files

AnalyseData.o : AnalyseData.cpp
	${CC} ${FLAGS} -c AnalyseData.cpp

CustomFunctions.o : CustomFunctions.cpp	
	${CC} ${FLAGS} -c CustomFunctions.cpp

clean : #running the rm shell command
	@rm -f *.o *~

cleantarget: #Deletes the executable
	@rm -f ${TARGET}
