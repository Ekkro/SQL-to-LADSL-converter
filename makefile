all: SQLtoLADSL

SQLtoLADSL.tab.c SQLtoLADSL.tab.h:	SQLtoLADSL.y
	yacc SQLtoLADSL.y

lex.yy.c: SQLtoLADSL.ll SQLtoLADSL.tab.h
	flex SQLtoLADSL.ll

SQLtoLADSL: lex.yy.c SQLtoLADSL.tab.c SQLtoLADSL.tab.h
	g++ y.tab.c -o SQLtoLADSL

clean:
	rm SQLtoLADSL SQLtoLADSL.tab.c lex.yy.c SQLtoLADSL.tab.h
