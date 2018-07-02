all: SQLtoLADSL

SQLtoLADSL.tab.c SQLtoLADSL.tab.h:	SQLtoLADSL.y
	bison -d SQLtoLADSL.y

lex.yy.c: SQLtoLADSL.l SQLtoLADSL.tab.h
	flex SQLtoLADSL.l

SQLtoLADSL: lex.yy.c SQLtoLADSL.tab.c SQLtoLADSL.tab.h
	g++ -x c++ -o SQLtoLADSL SQLtoLADSL.tab.c lex.yy.c

clean:
	rm SQLtoLADSL SQLtoLADSL.tab.c lex.yy.c SQLtoLADSL.tab.h
