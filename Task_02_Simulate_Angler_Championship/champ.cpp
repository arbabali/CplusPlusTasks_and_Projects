//Author:   ARBAB ALI
//Date:     2020.4.11
//Title:    LIST ALL THE CHAMPIONSHIPS WITH TUNA

#include "champ.h"
using namespace std;

//Task: 	Reading the next championship with his ability
//Input:    ContestEnor tt  - the enumerator of contests
//Output:   champ _cur     - the next championship
//          bool _end       - the end of the enumeration
//Activity:
void champEnor::next()
{
    if( !(_end = _tt.end()) ){
        _cur.champ = _tt.current().contest;

    _cur.tuna = false;
        _cur.counter=0;
        for( ; !_tt.end() && _tt.current().contest == _cur.champ  ; _tt.next() ){
            _cur.tuna = _cur.tuna || (_tt.current().tuna);
          if(_tt.current().tuna && _cur.tuna==true)
           ++ _cur.counter;
        }

    }
}
