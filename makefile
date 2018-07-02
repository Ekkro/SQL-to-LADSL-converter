all: SQLtoLADSL

SQLtoLADSL.tab.c SQLtoLADSL.tab.h:	SQLtoLADSL.y
	bison -d SQLtoLADSL.y

lex.yy.c: SQLtoLADSL.ll SQLtoLADSL.tab.h
	flex SQLtoLADSL.ll

SQLtoLADSL: lex.yy.c SQLtoLADSL.tab.c SQLtoLADSL.tab.h
	g++ -x c++ -o SQLtoLADSL SQLtoLADSL.tab.c lex.yy.c

clean:
	rm SQLtoLADSL SQLtoLADSL.tab.c lex.yy.c SQLtoLADSL.tab.h
