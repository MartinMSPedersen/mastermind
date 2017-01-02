/* 

   Mon Jan  2 01:58:58 CET 2017
   version 0.1
   All source under GPL version 3 or later
   (GNU General Public License - http://www.gnu.org/)
   contact traxplayer@gmail.com for more information about this code

*/

#ifndef MASTERMINDBOARD_H
#define MASTERMINDBOARD_H

#include <vector>
#include <iostream>
#include "board.h"

using namespace std;

class Mastermindboard: public Board {
    public:

    	string makeMove(string move);
	bool isGameOver();
	vector <string> getMoveHistory() const;
	string toString() const;
	string cheat() const;

	Mastermindboard();  

	friend ostream& operator<< (ostream& o, Mastermindboard& b);
	bool operator==(const Mastermindboard& another) const;
	bool operator!=(const Mastermindboard& another) const;

    private:
	void switchPlayer() const;

        string code;
	bool gameover;
};

#endif
