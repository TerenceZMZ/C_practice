#This is make file
TAR = plus
CC := gcc
OBJ = plus.c
$(TAR):$(OBJ)
	@$(CC) -o $(TAR) $(OBJ)	
.PHONY:
show:
	./$(TAR) $(para)
	
