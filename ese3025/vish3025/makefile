
objects = gol.o display.o cells.o

include = includes

VPATH = source:includes
CFLAGS = -I$(include)
 

ese3025_project : $(objects)
	gcc -o ese3025_project $(objects) -lpthread -lncurses

gol.o : gol.c gol_config.h display.h cells.h

display.o : display.c display.h gol_config.h 

cells.o : cells.c cells.h gol_config.h

.PHONY : clean
clean :
	-rm ese3025_project $(objects)

