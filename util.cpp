/* 

Mon Jan  2 01:58:29 CET 2017
version 0.1
All source under GPL version 3 
(GNU General Public License - http://www.gnu.org/)
contact traxplayer@gmail.com for more information about this code

 */


#include <vector>
#include <string>
#include <iostream>
#include <unistd.h>
#include "util.h"

using namespace std;

vector<string> Util::getInput(istream &in)
{
    vector<string> result;
    string aString;
    long unsigned int start,end,i;

    getline(in, aString);
    if (in.eof()==1) in.clear();

    start=aString.find_first_not_of(' ');
    if (start==string::npos) return result;
    end=aString.find_last_not_of(' ');
    for (i=start+1; i<end; i++) {
	if (aString.at(i)==' ') {
	    result.push_back(aString.substr(start,i-start));
	    start=i+1;
	}
    }
    result.push_back(aString.substr(start,end-start+1));
    return result;
}

