//Author:   ARBAB ALI
//Date:     2020.4.11
//Title:    LIST ALL THE CHAMPIONSHIPS WITH TUNA

#include "contest.h"

using namespace std;

//Task: 	Reading the next row of the inputfile
//Input:    ifstream _f  - the test file
//Output:   Contest _cur - the next contest
//          bool _end    - the end of the enumeration
//Activity:
void ContestEnor::next()
{
    string line;
    getline(_f , line);
    if( !(_end = _f.fail()) ){
        istringstream is(line);
        is >> _cur.angler >> _cur.contest;
            string fish;
        _cur.tuna=false;
        for( is >> fish  ; !is.fail(); is >> fish ){
            if(fish == "tuna") {
                _cur.tuna=true;
            }
        }
    }
}
