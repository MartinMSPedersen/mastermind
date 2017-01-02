/* 

Mon Jan  2 01:58:48 CET 2017
version 0.1
All source under GPL version 3 or later
(GNU General Public License - http://www.gnu.org/)
contact traxplayer@gmail.com for more information about this code

*/

#ifndef MAIN_H
#define MAIN_H

#include "mastermindboard.h"

void mastermind_init();
void userDisplay();
void userEnd();
void userExit();
void userHelp(vector<string> command);
void userHistory();
void userLog(vector<string> command);
void userNew();
void welcome();
void goodbye();
void checkForWin();
void gotAMove(const string theMove);
vector<string> getInput();

#endif
