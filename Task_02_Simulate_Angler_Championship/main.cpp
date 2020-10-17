//Author:   ARBAB ALI
//Date:     2020.4.11
//Title:    LIST ALL THE CHAMPIONSHIPS WITH TUNA

#include <iostream>
#include "champ.h"
#include <vector>
using namespace std;

//Activity:  list of tuna in contest
bool  search (const string &name, std::vector<std::string> &ID)
{
    champEnor t(name);
     int l=false;
    for(t.first(); !t.end();t.next()){
        if(t.current().tuna)
            ID.push_back(t.current().champ);

          l=t.current().tuna;

    }

        return l;
}

//#define NORMAL_MODE
#ifndef NORMAL_MODE

//Activity:  Looking for a tuna in in contest and printing the list of contest
int main()
{
    std::vector<std::string> ID;
    search("t4.txt",ID);
   for(int i=0;i<ID.size();++i){
        std::cout<<ID[i]<<endl;
   }

   return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// linear search
TEST_CASE("empty file", "t0.txt") {
     std::vector<std::string> id;
    CHECK_FALSE(search("t0.txt", id));
}

TEST_CASE("only 1 championship ", "t2.txt") {
     std::vector<std::string> id;
     search("t2.txt", id);
    CHECK(id.size()==1);
}

TEST_CASE("more championships ", "t4.txt") {
     std::vector<std::string> id;
     search("t4.txt", id);
    CHECK(id.size()>1);
}

TEST_CASE("first contest is with  tuna", "t4.txt") {

     champEnor t("t4.txt");
     t.first();
         CHECK(t.current().tuna);
}

TEST_CASE(" only last championship is with tuna", "t5.txt") {
     std::vector<std::string> id;
    CHECK(search("t5.txt", id));
}

TEST_CASE("no tuna in all  contests ", "t6.txt") {
    std::vector<std::string> id;
    CHECK_FALSE(search("t6.txt", id));
}

TEST_CASE("more than one contest with tuna  in more contests ", "t7.txt") {
     std::vector<std::string> id;
     search("t7.txt", id);
    CHECK(id.size()>1);
}

// optimistic  search

TEST_CASE("no contest", "t1.txt") {
    champEnor t("t1.txt");
    t.first();
    CHECK(t.current().tuna);
}

TEST_CASE("1 and only  contest with tuna", "t2.txt") {
    champEnor t("t2.txt");
    t.first();
    std::vector<std::string> id;
    search("t2.txt",id);
    CHECK(((t.current().tuna)&&(id.size()==1)));
}

TEST_CASE("1 contest with tuna   is not the first contests", "t3.txt") {
    champEnor t("t3.txt");
    t.first();
    CHECK_FALSE(t.current().tuna);
}

TEST_CASE(" IN first contest  with tuna , tuna  is not caught  by both angler", "t11.txt") {
    champEnor t("t11.txt");
    t.first();
    CHECK_FALSE(t.current().counter==2);
}

TEST_CASE(" IN second contest with tuna  is caught by  both angler", "t10.txt") {
    champEnor t("t10.txt");
    t.first();
    t.next();
    CHECK_FALSE(t.current().counter!=2);
}


#endif
