BISON_OPTIONS = -vd
BISON_OUTPUT_CPP = bison_sql.cpp

FLEX_OPTIONS = -vd
FLEX_OUTPUT_CPP = flex_sql.cpp

all: bison_sql.cpp flex_sql.cpp

bison_sql.cpp : bison_sql.ypp
	bison $(BISON_OPTIONS) --output=$(BISON_OUTPUT_CPP) bison_sql.ypp

flex_sql.cpp: flex_sql.lpp 
	flex $(FLEX_OPTIONS) flex_sql.lpp

clean:
	rm *.cpp bison_sql.h* *.o*
