PROG = main.exe 							# Target file for exe
SRC = main.cpp Services/UserMenu.cpp               		        # Source code files
CFLAGS = -g -std=c++17 -Wall -Werror		# Compile flags
LIBS = 										# Libraries
CC=g++										# Compiler 

all: $(PROG)								# Defining standard behaviour to be - build the PROG executable

$(PROG): $(SRC)								# TARGET : DEPENDENCIES 
	$(CC) -o $@ $(CFLAGS) $(SRC) $(LIBS)	
	
clean: 										# Defining clean command - remove the executable
	rm -f $(PROG)