/* 

Mon Jan  2 01:58:12 CET 2017
   version 0.1
   All source under GPL version 3 or later
   (GNU General Public License - http://www.gnu.org/)
   contact traxplayer@gmail.com for more information about this code

 */

#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include "mastermindboard.h"
#include "util.h"

using namespace std;

Mastermindboard::Mastermindboard()
{
    for (int i=0; i<4; i++) {
	code+=(const char)('0'+Util::getRandom(4));
    }
    gameover=false;
}

string Mastermindboard::cheat() const {
    return code;
}

bool Mastermindboard::isGameOver() 
{
    return gameover;
}

bool Mastermindboard::operator!=(const Mastermindboard& another) const
{
    return !(*this==another);
}

bool Mastermindboard::operator==(const Mastermindboard& another) const
{
    return (this->code==another.code);
}

string Mastermindboard::makeMove(string move) 
{
    unsigned int correct_placement=0;
    unsigned int correct_colour=0;
    unsigned int i,j;
    stringstream result;

    if (move.size()!=code.size()) throw string("not accepted as a legal guess.");
    for (i=0; i<move.length(); i++) {
	if (move.at(i)==code.at(i)) {
	    correct_placement++;
	}
    }
    for (i=0; i<move.length(); i++) {
	for (j=0; j<move.length(); j++) {
	    if (move.at(j)==code.at(i)) {
		correct_colour++;
		move.at(j)=' ';
		break;
	    }
	}
    }
    if (correct_placement==code.length()) gameover=true;
    switchPlayer();
    result << "correct placed: " << correct_placement;
    if (correct_placement<code.length()) {
	result << ", correct colour: " << correct_colour;
    }
    return result.str();
}

void Mastermindboard::switchPlayer() const
{
    // Mastermind is a single player game. So this function does nothing 
    return;
}

string Mastermindboard::toString() const 
{
    string result;
    result.append("code="+string(code));
    cout << "code=" << code << endl;
    return result;
}

vector <string> Mastermindboard::getMoveHistory() const
{
    vector <string> dummy;
    return dummy;
}


ostream& operator<< (ostream& o, Mastermindboard &m)
{
    string result;
    result=m.toString();
    return o << result;
}

