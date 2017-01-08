/* 

Mon Jan  2 01:59:11 CET 2017
version 0.1
All source under GPL version 3 or later
(GNU General Public License - http://www.gnu.org/)
contact traxplayer@gmail.com for more information about this code

 */

#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <vector>
#include <iostream>


class Util {

    public: 
	static std::vector<std::string> getInput(std::istream &in);

    private:
	Util();
};

#endif

