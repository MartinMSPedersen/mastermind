/* 

Mon Jan  2 01:58:40 CET 2017
   version 0.1
   All source under GPL version 3 or later
   (GNU General Public License - http://www.gnu.org/)
   contact traxplayer@gmail.com for more information about this code

 */

#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>

using namespace std;

class Board {
    public:
	virtual string makeMove(string move) = 0;
	virtual bool isGameOver() = 0;
	virtual vector <string> getMoveHistory() const = 0;
	virtual ~Board() = 0;
};

#endif
