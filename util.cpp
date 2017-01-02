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
#include <cassert>
#include <cstdlib>
#include <unistd.h>
#include "util.h"
#include "RandMT.h"

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


unsigned int Util::getAPrimeNumber(const unsigned int &num)
{
    int i;
    static const unsigned int primes[] =
    {
	11,
	19,
	37,
	73,
	109,
	163,
	251,
	367,
	557,
	823,
	1237,
	1861,
	2777,
	4177,
	6247,
	9371,
	14057,
	21089,
	31627,
	47431,
	71143,
	106721,
	160073,
	240101,
	360163,
	540217,
	810343,
	1215497,
	1823231,
	2734867,
	4102283,
	6153409,
	9230113,
	13845163,
    };
    static const int numOfPrimes=sizeof(primes)/sizeof(primes[0]); 

    for (i = 0; i < numOfPrimes; i++)
	if (primes[i] > num)
	    return primes[i];

    return primes[numOfPrimes-1];
}

unsigned long int Util::getRandom(unsigned long int i) {
    static bool first_time=true;
    static RandMT r;

    if (first_time) {
	first_time=false;
	//#ifdef DEBUG
	r=RandMT(1+2*getpid()); /* odds numbers are best */ /* should be replaced with reads to /dev/random */
	//#endif
    }
    return (r.randomMT()%i); //   return (int)(i*rand()/(RAND_MAX+1.0));
}

