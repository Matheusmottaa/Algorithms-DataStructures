APPS = ./apps
BIN = ./bin
INCLUDE = ./include/
OBJ = ./obj
SRC = ./src

all: libed Apps

Apps:
	gcc $(APPS)/main.c -I $(INCLUDE) $(OBJ)/*.o -o $(BIN)/app

libed: 
	gcc -c $(SRC)/arrayADT.c -I $(INCLUDE) -o $(OBJ)/arrayADT.o


run: 
	$(BIN)/app

clean: 
	rm -rf $(BIN)/*.o rm -rf $(OBJ)/*.o