//Author:    ARBAB ALI
//Date:      2020.03.15
//Title:     XTYPE matrix

#pragma once
#include <iostream>
#include <vector>

//Class of  double Xtype matrices
//Methods: add, multiply, write, read, refer to an element
//Representation: only the elements of the both X type
class Xmat
{
public:
    enum Exceptions{OVERINDEXED, NULLPART, DIFFERENT, INVALID};

   Xmat(){_n=0; _v.clear();};

    Xmat(int k);
    ~Xmat() { }
    Xmat(const std::vector<int> &v);
    Xmat(const Xmat& a);
    Xmat& operator=(const Xmat& a);
    int getSize() const {return _v.size();}

    int operator()(int i, int j) const;
    void setter(int i,int j,int v);
    int& operator()(int i, int j);

    friend Xmat operator+ (const Xmat& a, const Xmat& b);
    friend Xmat operator* (const Xmat& a, const Xmat& b);
    friend std::istream& operator>> (std::istream& s, Xmat& a);
    friend std::ostream& operator<< (std::ostream& s, const Xmat& a);
    void reSize(int k);
   // int get_n(){return _n;};
private:
    std::vector<int> _v;
    int _n;

};
