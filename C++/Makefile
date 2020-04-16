CC=g++
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=kmp

all: $(EXEC)

kmp: kmp.o main.o
	$(CC) -o kmp kmp.o main.o $(LDFLAGS)

kmp.o: fonctions.cc
	$(CC) -o kmp.o -c fonctions.cc $(CFLAGS)

main.o: main.cc fonctions.h
	$(CC) -o main.o -c main.cc $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)


# OPTS=0 1 2 3
# NB_TESTS=10000
# MIN_N_VALUE=0
# MAX_N_VALUE=100000
# STEP_N_VALUE=10000

# OPT=2
# CFLAGS=-Wall -ansi -pedantic -g -O$(OPT)

# LDFLAGS=

# SOURCES = fonctions.c 
# HEADERS = fonctions.h
# ALGOS=Iter Rec Simple Avancee V2

# CSV_FILES = $(foreach opt,$(OPTS),$(foreach algo,$(ALGOS),res-$(algo)-O$(opt).csv))

# PNG_FILES1 = $(foreach opt,$(OPTS),valeurs-O$(opt).png)
# PNG_FILES2 = $(subst valeurs,performances,$(PNG_FILES1))
# PNG_FILES = $(PNG_FILES1) $(PNG_FILES2)

# PROGS = $(foreach opt,$(OPTS),$(PROG)-O$(opt))


# all_tests: $(PNG_FILES)
# all: Makefile $(PROG)

# .SUFFIXES: .c .h .o

# $(PROG): $(SOURCES:.c=.o)
# 	$(CC) $(LDFLAGS) $^ -o $@

# $(PROGS): mostlyclean
# 	make OPT=$(subst O,,$(word 3,$(subst -, ,$@))) $(PROG)
# 	mv $(PROG) $@

# .c.o:
# 	$(CC) $(CFLAGS) -c $<

# $(CSV_FILES):
# 	make $(PROG)-$(basename $(word 3,$(subst -, ,$@)))
# 	bash -c 'for ((n = $(MIN_N_VALUE); n <= $(MAX_N_VALUE); n+=$(STEP_N_VALUE))); do \
# 	  ./$(PROG)-$(basename $(word 3,$(subst -, ,$@))) \
# 	     $(basename $(word 2,$(subst -, ,$@))) $${n} $(NB_TESTS);\
# 	done > "$@"'

# $(PNG_FILES): $(CSV_FILES)
# 	echo $@
# 	./make-plot.gp

# mostlyclean:
# 	rm -f $(PROG)
# 	rm -f $(SOURCES:.c=.o)
# 	rm -f *~

# clean: mostlyclean
# 	rm -f $(PROG) $(PROGS)
# 	rm -f $(CSV_FILES)
# 	rm -f $(PNG_FILES)

