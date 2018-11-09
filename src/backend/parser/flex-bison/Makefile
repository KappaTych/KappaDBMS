BISON_OPTIONS = -vd
FLEX_OPTIONS = -v

all: bison_sql.cpp flex_sql.cpp

bison_sql.cpp : bison_sql.ypp
	bison $(BISON_OPTIONS) bison_sql.ypp -o bison_sql.cpp

flex_sql.cpp: flex_sql.lpp 
	flex $(FLEX_OPTIONS) flex_sql.lpp 

clean:
	rm *.cpp *.h* *.o*
