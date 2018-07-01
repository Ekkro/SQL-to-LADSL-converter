EXEC=SQLtoLADSL
EXEC2=SQLtoLADSL2

$(EXEC): $(EXEC).l $(EXEC2).y
	flex -o $(EXEC).c $(EXEC).l
	yacc -d -v $(EXEC2).y
	g++ -x c++ -o $(EXEC) y.tab.c -lm

