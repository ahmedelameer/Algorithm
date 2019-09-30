vpath %.c ./Src
vpath %.h ./Inc


CC = gcc
SRC_PATH = ./src/
LINK_TARGET = exe.exe
INCLUDE_PATH = ./inc/

OBJ = Algorithm.o 
CLEAN_TARGET = $(LINK_TARGET) 

exe:$(LINK_TARGET) 	
	
clean:
	-rm $(CLEAN_TARGET)                   
	



$(LINK_TARGET): $(OBJ) 
	$(CC) $(OBJ)  -o $@
	


#%.o: %.c
Algorithm.o : Algorithm.c Algorithm.h 
	$(CC) -c -I$(INCLUDE_PATH) $< -o $@

