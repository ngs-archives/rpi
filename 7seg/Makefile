DEBUG	= -O2
CC	= gcc
INCLUDE	= -I/usr/local/include
CFLAGS	= $(DEBUG) -Wall $(INCLUDE) -Winline -pipe

LDFLAGS	= -L/usr/local/lib
LIBS    = -lwiringPi -lpthread -lm

# May not need to  alter anything below this line
###############################################################################

SRC	=	7seg.c

OBJ	=	$(SRC:.c=.o)

all:		7seg

7seg:	7seg.o
	@echo [Link]
	@$(CC) -o $@ 7seg.o $(LDFLAGS) $(LIBS)

.c.o:
	@echo [Compile] $<
	@$(CC) -c $(CFLAGS) $< -o $@

.PHONEY:	clean
clean:
	rm -f $(OBJ) 7seg *~ core tags *.bak

.PHONEY:	tags
tags:	$(SRC)
	@echo [ctags]
	@ctags $(SRC)

.PHONEY:	install
install:
	@echo "[Install]"
	@cp 7seg /usr/local/bin
	@chown root.root /usr/local/bin/7seg
	@chmod 4755 /usr/local/bin/7seg
	# @mkdir -p /usr/local/man/man1
	# @cp 7seg.1 /usr/local/man/man1

.PHONEY:	uninstall
uninstall:
	@echo "[UnInstall]"
	@rm -f /usr/local/bin/7seg
	@rm -f /usr/local/man/man1/7seg.1

.PHONEY:	depend
depend:
	makedepend -Y $(SRC)

# DO NOT DELETE
