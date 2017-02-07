###################################
## This is the Makefile for Risk ##
###################################

####################
# Define directories where various files are stored

# BIN is the directory where the executable "Risk" will be stored
BIN  = .

# PG is the directory containing the RISK source code
RG   = .

####################
# Set various options

# Set debug flags
DEBUG   =     -O3

# Output profiling information when running
PROFILE =      -pg

# Set compiler flags
CXXFLAGS  	=   -std=c++11

# Set compilers
CC      	=   g++

####################
# Group related object files

# McPHAC functions
RGOBJS = 	$(RG)/Risk.o \
		$(RG)/Country.o\
		$(RG)/Player.o\
		$(RG)/Border.o\
		$(RG)/Map.o\
		$(RG)/Subject.o\
		$(RG)/Observer.o\
		$(RG)/MapView.o

####################
# Define make rules

# If no arguments or argument 'all', make RISK
all: Risk

Risk: 	$(RGOBJS)
	$(CC) $(RGOBJS) -o $(BIN)/$@

.c.o:
	$(CC) $(CXXFLAGS) -c $< -o $@


# Define rule for cleaning directory (leading dash prevents make from exiting on rm error)
clean	: 
	-rm $(RG)/*.o $(RG)/*~

nuke : clean 
	-rm $(RG)/Risk

