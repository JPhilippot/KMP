########################################
#~ définitions
########################################

# nom de l'executable
#BIN=runPeriod

BIN=main  

# liste des fichiers sources 
SRCS=fonc.c main.c

default: $(BIN)

########################################
#~ regles pour l'executable
########################################

%.o: %.c
	gcc -Wall -Iinclude -c $< -o $@

main: $(SRCS:%.c=%.o)
	gcc -lpthread -o $@ $+

clean:
	rm -f $(BIN) /*.o *~