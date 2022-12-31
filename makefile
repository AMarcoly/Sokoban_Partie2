.PHONY: all clean doc archive archiveclean

CFLAGS= -Wall -Wextra 
export LD_LIBRARY_PATH= install_dir/lib 
LDFLAGS += -Linstall_dir/lib -lSDL2
CC= gcc -g -std=c99
IPATH= -l include
BIN = bin/
OBJ = obj/
Doc= doc/
OBJETS = obj/main.o obj/grid.o obj/player.o obj/sdl2.o 

vpath %.c src 
vpath %.h include 

$(BIN)main: $(OBJETS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ)%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@ $(IPATH)

config:
	cd SDL2 && ./configure --prefix=$$PWD/../install_dir
	cd SDL2 && make install -j6


clean :
	$(RM) -r $(OBJ)* $(BIN)* $(Doc)*  install_dir SDL2

documentation:
	doxygen Doxyfile 

