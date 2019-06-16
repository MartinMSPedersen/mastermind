# Sun Jan  8 12:50:55 CET 2017
# version 0.2
# All source under GPL version 2
# (GNU General Public License - http://www.gnu.org/)
# contact martin@linux.com for more information about this code

CXXFLAGS = -ggdb -O3 -Wall -Wunused -Wcast-qual -Wconversion -Woverloaded-virtual  --pedantic-error -finline-functions -std=c++11 -Werror
LDFLAGS  = -lm 
MAIN_OBJECTS += mastermindboard.o board.o main.o util.o 
OBJECTS = $(MAIN_OBJECTS) 

all:	mastermind

mastermind: $(MAIN_OBJECTS)
	$(CXX) $(CXXFLAGS) $(MAIN_OBJECTS) -o $@ $(LDFLAGS)

%.c.o: %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY:	clean tar zip

tar:
	make clean && cd .. && tar cvf mastermind/mastermind.tar mastermind/* && gzip -9 mastermind/mastermind.tar 

zip:
	make clean && cd .. && zip -r mastermind.zip mastermind/* -x mastermind/.\*

clean:
	-/bin/rm -f $(OBJECTS) mastermind mastermind.tar mastermind.tar.gz *~  \#* 2>/dev/null
