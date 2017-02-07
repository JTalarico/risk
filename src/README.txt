Assignment # 1
James Talarico
40008054

I chose to do question 2, which is making the map observer pattern.

The main file is risk.cpp.

The program was compiled with g++ version 4.8.4, using the command

make -f Makefile

The compile details are in Makefile.

The program can then be run by executing the Risk file, using the command:

./Risk

The examples shown in class were used for the Observer and Subject class.

In the main program, I created all my borders and countries on the heap.
This is because they should stay until the end of the game (or until they are 
explicitly deallocated) especially since i passing my country lists as pointers to country objects.

Note:
I've included a file called output.txt. 

This is just the output Risk, copied into a text file.
This might make it easier for you to see.


