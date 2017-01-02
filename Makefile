# Sat Dec 17 18:30:07 CET 2016
# version 0.1
# All source under GPL version 2
# (GNU General Public License - http://www.gnu.org/)
# contact martin@linux.com for more information about this code

CXXFLAGS = -ggdb -O3 -Wall -Wunused -Wcast-qual -Wconversion -Woverloaded-virtual  -Wextra -Werror --pedantic-error -finline-functions
LDFLAGS  = -lm 
MAIN_OBJECTS += mastermindboard.o board.o main.o util.o RandMT.o
OBJECTS = $(MAIN_OBJECTS) 

all:	mastermind

mastermind: $(MAIN_OBJECTS) Makefile
	$(CXX) $(CXXFLAGS) $(MAIN_OBJECTS) -o mastermind $(LDFLAGS)

main.o: main.cpp main.h

player.o: player.h player.cpp

util.o: util.h util.cpp

RandMT.o: RandMT.h RandMT.cpp

mastermindboard.o: mastermindboard.h mastermindboard.cpp

.PHONY:	clean tar

tar:
	make clean && cd .. && tar cvf mastermind/mastermind.tar mastermind/* && gzip -9 mastermind/mastermind.tar 

clean:
	-/bin/rm -f $(OBJECTS) mastermind mastermind.tar mastermind.tar.gz *~  \#* 2>/dev/null
