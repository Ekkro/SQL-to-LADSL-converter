EXEC=SQLtoLADSL

$(EXEC): $(EXEC).l $(EXEC).y
	flex -o $(EXEC).c $(EXEC).l
	yacc -d -v $(EXEC).y
	gcc -o $(EXEC) y.tab.c -lm

