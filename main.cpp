/* 

Mon Jan  2 01:58:03 CET 2017
version 0.1
All source under GPL version 3 
(GNU General Public License - http://www.gnu.org/)
contact traxplayer@gmail.com for more information about this code

 */

#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include "main.h"
#include "mastermindboard.h"
#include "util.h"

using namespace std;

Mastermindboard mb;

/* the moves played in the current game  */
vector <string>* moveHistory=new vector<string>;      

void mastermind_init()
{
}

void userDisplay() 
{
    string border;

    //mb.dump();
}

void userExit() 
{
    goodbye();
}

void userHelp(vector<string> command)
{
    string dummy;
    string topic;

    if (command.size()>1)
	topic=command[1];
    else
	topic="";
    cout << endl;
    if (topic=="") {
	cout << "display...................displays the board\n";
	cout << "exit/quit.................terminates program.\n";
	cout << "help [command]............displays help.\n";
	cout << "history...................display game moves.\n";
	cout << "new.......................initialize and start new game.\n";
	cout << "reset n...................reset game to move n.\n";
	cout << endl;
	return;  
    }
    cout << "No help found on topic:" << topic << endl;
}

void userHistory() 
{
    vector<string>::size_type numOfMoves;
    vector<string>::const_iterator iter;
    int i;
    unsigned  long int original_width;

    original_width=cout.width();
    cout.width(2);
    iter=moveHistory->begin();
    numOfMoves=moveHistory->size();
    if (numOfMoves==0) return;
    i=1;
    while (iter!=moveHistory->end()) {
	cout << "  " << i << " " << (*iter);
	iter++;
	cout << endl;
	i++;
    }
    cout.width(original_width);
}

void userNew()
{
    mb=Mastermindboard();
    delete(moveHistory);
    moveHistory=new vector<string>;
}


void userShow(vector<string> command)
{
    string dummy;
    string topic;

    if (command.size()>1)
	topic=command[1];
    else
	topic="";

    if (topic=="warranty") {
	cout << "\n        NO WARRANTY\n";
	cout << "BECAUSE THE PROGRAM IS LICENSED FREE OF CHARGE, THERE IS NO WARRANTY\n";
	cout << "FOR THE PROGRAM, TO THE EXTENT PERMITTED BY APPLICABLE LAW.  EXCEPT WHEN\n";
	cout << "OTHERWISE STATED IN WRITING THE COPYRIGHT HOLDERS AND/OR OTHER PARTIES\n";
	cout << "PROVIDE THE PROGRAM \"AS IS\" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED\n";
	cout << "OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF\n";
	cout << "MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  THE ENTIRE RISK AS\n";
	cout << "TO THE QUALITY AND PERFORMANCE OF THE PROGRAM IS WITH YOU.  SHOULD THE\n";
	cout << "PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF ALL NECESSARY SERVICING,\n";
	cout << "REPAIR OR CORRECTION.\n";
	cout << endl;
	cout << "IN NO EVENT UNLESS REQUIRED BY APPLICABLE LAW OR AGREED TO IN WRITING\n";
	cout << "WILL ANY COPYRIGHT HOLDER, OR ANY OTHER PARTY WHO MAY MODIFY AND/OR\n";
	cout << "REDISTRIBUTE THE PROGRAM AS PERMITTED ABOVE, BE LIABLE TO YOU FOR DAMAGES,\n";  
	cout << "INCLUDING ANY GENERAL, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES ARISING\n";
	cout << "OUT OF THE USE OR INABILITY TO USE THE PROGRAM (INCLUDING BUT NOT LIMITED\n";
	cout << "TO LOSS OF DATA OR DATA BEING RENDERED INACCURATE OR LOSSES SUSTAINED BY\n";
	cout << "YOU OR THIRD PARTIES OR A FAILURE OF THE PROGRAM TO OPERATE WITH ANY OTHER\n";    
	cout << "PROGRAMS), EVEN IF SUCH HOLDER OR OTHER PARTY HAS BEEN ADVISED OF THE\n";
	cout << "POSSIBILITY OF SUCH DAMAGES.\n" << endl;
	return;
    }
    if (topic=="conditions") {
	cout << "        GNU GENERAL PUBLIC LICENSE\n";
	cout << "   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION\n";
	cout << endl;
	cout << "  0. This License applies to any program or other work which contains\n";
	cout << "a notice placed by the copyright holder saying it may be distributed\n";
	cout << "under the terms of this General Public License.  The \"Program\", below,\n";
	cout << "refers to any such program or work, and a \"work based on the Program\"\n";
	cout << "means either the Program or any derivative work under copyright law:\n";
	cout << "that is to say, a work containing the Program or a portion of it,\n";
	cout << "either verbatim or with modifications and/or translated into another\n";
	cout << "language.  (Hereinafter, translation is included without limitation in\n";
	cout << "the term \"modification\".)  Each licensee is addressed as \"you\".\n";
	cout << endl;
	cout << "Activities other than copying, distribution and modification are not\n";
	cout << "covered by this License; they are outside its scope.  The act of\n";
	cout << "running the Program is not restricted, and the output from the Program\n";
	cout << "is covered only if its contents constitute a work based on the\n";
	cout << "Program (independent of having been made by running the Program).\n";
	cout << "Whether that is true depends on what the Program does.\n";
	cout << "  1. You may copy and distribute verbatim copies of the Program's\n";
	cout << "source code as you receive it, in any medium, provided that you\n";
	cout << "conspicuously and appropriately publish on each copy an appropriate\n";
	cout << "copyright notice and disclaimer of warranty; keep intact all the\n";
	cout << "notices that refer to this License and to the absence of any warranty;\n";
	cout << "more...\n" << endl;
	getline(cin,dummy);
	cout << "and give any other recipients of the Program a copy of this License\n";
	cout << "along with the Program.\n";
	cout << endl;
	cout << "You may charge a fee for the physical act of transferring a copy, and\n";
	cout << "you may at your option offer warranty protection in exchange for a fee.\n";
	cout << endl;
	cout << "  2. You may modify your copy or copies of the Program or any portion\n";
	cout << "of it, thus forming a work based on the Program, and copy and\n";
	cout << "distribute such modifications or work under the terms of Section 1\n";
	cout << "above, provided that you also meet all of these conditions:\n";
	cout << endl;
	cout << "    a) You must cause the modified files to carry prominent notices\n";
	cout << "    stating that you changed the files and the date of any change.\n";
	cout << endl;
	cout << "    b) You must cause any work that you distribute or publish, that in\n";
	cout << "    whole or in part contains or is derived from the Program or any\n";
	cout << "    part thereof, to be licensed as a whole at no charge to all third\n";
	cout << "    parties under the terms of this License.\n";
	cout << "    c) If the modified program normally reads commands interactively\n";
	cout << "    when run, you must cause it, when started running for such\n";
	cout << "    interactive use in the most ordinary way, to print or display an\n";
	cout << "    announcement including an appropriate copyright notice and a\n";
	cout << "    notice that there is no warranty (or else, saying that you provide\n";
	cout << "    a warranty) and that users may redistribute the program under\n";
	cout << "more...\n" << endl;
	getline(cin,dummy);
	cout << "    these conditions, and telling the user how to view a copy of this\n";
	cout << "    License.  (Exception: if the Program itself is interactive but\n";
	cout << "    does not normally print such an announcement, your work based on\n";
	cout << "    the Program is not required to print an announcement.)\n";
	cout << endl;
	cout << "These requirements apply to the modified work as a whole.  If\n";
	cout << "identifiable sections of that work are not derived from the Program,\n";
	cout << "and can be reasonably considered independent and separate works in\n";
	cout << "themselves, then this License, and its terms, do not apply to those\n";
	cout << "sections when you distribute them as separate works.  But when you\n";
	cout << "distribute the same sections as part of a whole which is a work based\n";
	cout << "on the Program, the distribution of the whole must be on the terms of\n";
	cout << "this License, whose permissions for other licensees extend to the\n";
	cout << "entire whole, and thus to each and every part regardless of who wrote it.\n";
	cout << endl;
	cout << "Thus, it is not the intent of this section to claim rights or contest\n";
	cout << "your rights to work written entirely by you; rather, the intent is to\n";
	cout << "exercise the right to control the distribution of derivative or\n";
	cout << "collective works based on the Program.\n";
	cout << endl;
	cout << "In addition, mere aggregation of another work not based on the Program\n";
	cout << "with the Program (or with a work based on the Program) on a volume of\n";
	cout << "a storage or distribution medium does not bring the other work under\n";
	cout << "the scope of this License.\n";
	cout << "more...\n" << endl;
	getline(cin,dummy);
	cout << "  3. You may copy and distribute the Program (or a work based on it,\n";
	cout << "under Section 2) in object code or executable form under the terms of\n";
	cout << "Sections 1 and 2 above provided that you also do one of the following:\n";
	cout << endl;
	cout << "    a) Accompany it with the complete corresponding machine-readable\n";
	cout << "    source code, which must be distributed under the terms of Sections\n";
	cout << "    1 and 2 above on a medium customarily used for software interchange; or,\n";
	cout << endl;
	cout << "    b) Accompany it with a written offer, valid for at least three\n";
	cout << "    years, to give any third party, for a charge no more than your\n";
	cout << "    cost of physically performing source distribution, a complete\n";
	cout << "    machine-readable copy of the corresponding source code, to be\n";
	cout << "    distributed under the terms of Sections 1 and 2 above on a medium\n";
	cout << "    customarily used for software interchange; or,\n";
	cout << endl;
	cout << "    c) Accompany it with the information you received as to the offer\n";
	cout << "    to distribute corresponding source code.  (This alternative is\n";
	cout << "    allowed only for noncommercial distribution and only if you\n";
	cout << "    received the program in object code or executable form with such\n";
	cout << "    an offer, in accord with Subsection b above.)\n";
	cout << endl;
	cout << "The source code for a work means the preferred form of the work for\n";
	cout << "making modifications to it.  For an executable work, complete source\n";
	cout << "code means all the source code for all modules it contains, plus any\n";
	cout << "more...\n" << endl;
	getline(cin,dummy);
	cout << "associated interface definition files, plus the scripts used to\n";
	cout << "control compilation and installation of the executable.  However, as a\n";
	cout << "special exception, the source code distributed need not include\n";
	cout << "anything that is normally distributed (in either source or binary\n";
	cout << "form) with the major components (compiler, kernel, and so on) of the\n";
	cout << "operating system on which the executable runs, unless that component\n";
	cout << "itself accompanies the executable.\n";
	cout << endl;
	cout << "If distribution of executable or object code is made by offering\n";
	cout << "access to copy from a designated place, then offering equivalent\n";
	cout << "access to copy the source code from the same place counts as\n";
	cout << "distribution of the source code, even though third parties are not\n";
	cout << "compelled to copy the source along with the object code.\n";
	cout << endl;
	cout << "  4. You may not copy, modify, sublicense, or distribute the Program\n";
	cout << "except as expressly provided under this License.  Any attempt\n";
	cout << "otherwise to copy, modify, sublicense or distribute the Program is\n";
	cout << "void, and will automatically terminate your rights under this License.\n";
	cout << "However, parties who have received copies, or rights, from you under\n";
	cout << "this License will not have their licenses terminated so long as such\n";
	cout << "parties remain in full compliance.\n";
	cout << endl;
	cout << "  5. You are not required to accept this License, since you have not\n";
	cout << "signed it.  However, nothing else grants you permission to modify or\n";
	cout << "distribute the Program or its derivative works.  These actions are\n";
	cout << "more...\n" << endl;
	getline(cin,dummy);
	cout << "prohibited by law if you do not accept this License.  Therefore, by\n";
	cout << "modifying or distributing the Program (or any work based on the\n";
	cout << "Program), you indicate your acceptance of this License to do so, and\n";
	cout << "all its terms and conditions for copying, distributing or modifying\n";
	cout << "the Program or works based on it.\n";
	cout << endl;
	cout << "  6. Each time you redistribute the Program (or any work based on the\n";
	cout << "Program), the recipient automatically receives a license from the\n";
	cout << "original licensor to copy, distribute or modify the Program subject to\n";
	cout << "these terms and conditions.  You may not impose any further\n";
	cout << "restrictions on the recipients' exercise of the rights granted herein.\n";
	cout << "You are not responsible for enforcing compliance by third parties to\n";
	cout << "this License.\n";
	cout << endl;
	cout << "  7. If, as a consequence of a court judgment or allegation of patent\n";
	cout << "infringement or for any other reason (not limited to patent issues),\n";
	cout << "conditions are imposed on you (whether by court order, agreement or\n";
	cout << "otherwise) that contradict the conditions of this License, they do not\n";
	cout << "excuse you from the conditions of this License.  If you cannot\n";
	cout << "distribute so as to satisfy simultaneously your obligations under this\n";
	cout << "License and any other pertinent obligations, then as a consequence you\n";
	cout << "may not distribute the Program at all.  For example, if a patent\n";
	cout << "license would not permit royalty-free redistribution of the Program by\n";
	cout << "all those who receive copies directly or indirectly through you, then\n";
	cout << "more...\n" << endl;
	getline(cin,dummy);
	cout << "the only way you could satisfy both it and this License would be to\n";
	cout << "refrain entirely from distribution of the Program.\n";
	cout << endl;
	cout << "If any portion of this section is held invalid or unenforceable under\n";
	cout << "any particular circumstance, the balance of the section is intended to\n";
	cout << "apply and the section as a whole is intended to apply in other\n";
	cout << "circumstances.\n";
	cout << endl;
	cout << "It is not the purpose of this section to induce you to infringe any\n";
	cout << "patents or other property right claims or to contest validity of any\n";
	cout << "such claims; this section has the sole purpose of protecting the\n";
	cout << "integrity of the free software distribution system, which is\n";
	cout << "implemented by public license practices.  Many people have made\n";
	cout << "generous contributions to the wide range of software distributed\n";
	cout << "through that system in reliance on consistent application of that\n";
	cout << "system; it is up to the author/donor to decide if he or she is willing\n";
	cout << "to distribute software through any other system and a licensee cannot\n";
	cout << "impose that choice.\n";
	cout << endl;
	cout << "This section is intended to make thoroughly clear what is believed to\n";
	cout << "be a consequence of the rest of this License.\n";
	cout << endl;
	cout << "  8. If the distribution and/or use of the Program is restricted in\n";
	cout << "certain countries either by patents or by copyrighted interfaces, the\n";
	cout << "more...\n" << endl;
	getline(cin,dummy);
	cout << "original copyright holder who places the Program under this License\n";
	cout << "may add an explicit geographical distribution limitation excluding\n";
	cout << "those countries, so that distribution is permitted only in or among\n";
	cout << "countries not thus excluded.  In such case, this License incorporates\n";
	cout << "the limitation as if written in the body of this License.\n";
	cout << endl;
	cout << "  9. The Free Software Foundation may publish revised and/or new versions\n";
	cout << "of the General Public License from time to time.  Such new versions will\n";
	cout << "be similar in spirit to the present version, but may differ in detail to\n";
	cout << "address new problems or concerns.\n";
	cout << endl;
	cout << "Each version is given a distinguishing version number.  If the Program\n";
	cout << "specifies a version number of this License which applies to it and \"any\n";
	cout << "later version\", you have the option of following the terms and conditions\n";
	cout << "either of that version or of any later version published by the Free\n";
	cout << "Software Foundation.  If the Program does not specify a version number of\n";
	cout << "this License, you may choose any version ever published by the Free Software\n";
	cout << "Foundation.\n";
	cout << endl;
	cout << "  10. If you wish to incorporate parts of the Program into other free\n";
	cout << "programs whose distribution conditions are different, write to the author\n";
	cout << "to ask for permission.  For software which is copyrighted by the Free\n";
	cout << "Software Foundation, write to the Free Software Foundation; we sometimes\n";
	cout << "make exceptions for this.  Our decision will be guided by the two goals\n";
	cout << "more...\n" << endl;
	getline(cin,dummy);
	cout << "of preserving the free status of all derivatives of our free software and\n";
	cout << "of promoting the sharing and reuse of software generally.\n" << endl;
    }
}


void welcome() 
{
    cout << "Mastermind is copyright 2017 Martin M. S. Pedersen - email: traxplayer@gmail.com\n";
    cout << "Mastermind comes with ABSOLUTELY NO WARRANTY; for details type \"show warranty\".\n";
    cout << "This is free software, and you are welcome to redistribute it\n";
    cout << "under certain conditions; type \"show conditions\" for details.\n";
    cout << "\n";
    cout << "type \"help\" to get a list of the commands you can use in this program.\n";
    cout << "\n";
    cout << "    ---===###   MASTERMIND version: 0.1 welcomes you.   ###===---\n";
    cout << endl;
}


void goodbye()
{
    ;
}



void checkForWin()
{
    if (!mb.isGameOver()) return;
    cout << "Well done. You guess the correct code in ";
    cout << moveHistory->size() << " moves." << endl << endl;;
}


void gotAMove(const string theMove)
{
    try {
	cout << mb.makeMove(theMove) << endl;
    }
    catch (string e) {
	cout << theMove << ":  " << e << endl; 
	return;
    }
    (*moveHistory).push_back(theMove);
    checkForWin();
}

//int main(int argc, char** argv) 
int main() 
{
    vector<string> command;
    string line; 

    mastermind_init();
    welcome();

    while (true) {
	if (mb.isGameOver()) {
	    cout << "? ";
	}
	else {
	    cout << "Guess " << moveHistory->size()+1 << "? ";
	}
	command=Util::getInput(cin);
	if (command.size()==0) continue; // read more input
	line=command[0];
	if (line=="d") {
	    userDisplay();
	    continue;
	}
	if (line=="display") {
	    if (command.size()==1) 
		userDisplay();
	    continue;
	}
	if ((line=="exit") || (line=="quit")) {
	    userExit();
	    return EXIT_SUCCESS;
	}
	if (line=="help") {
	    userHelp(command);
	    continue;
	}
	if (line=="cheat") {
	    cout << "code = " << mb.cheat() << endl;
	    continue;
	}
	if (line=="history") {
	    userHistory();
	    continue;
	}
	if (line=="new") {
	    userNew();
	    continue;
	}
	if (line=="show") {
	    userShow(command);
	    continue;
	}
	else {
	    if (!mb.isGameOver()) gotAMove(line);
	}
    }
}
