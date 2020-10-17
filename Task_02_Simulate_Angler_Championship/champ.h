//Author:   ARBAB ALI
//Date:     2020.4.11
//Title:    LIST ALL THE CHAMPIONSHIP WITH TUNA

#pragma once

#include "contest.h"
#include <string>

//Datatype of champs
struct champ {
   std::string champ;
    bool tuna;
    int counter;
};

//Datatype of enumerator of champs
class champEnor{
    private:
        ContestEnor _tt;
        champ _cur;
        bool _end;
    public:
        champEnor(const std::string &str): _tt(str) { };
        void first() {_tt.first(); next();}
        void next();
        champ current() const { return _cur;}
        bool end() const { return _end;}
};

