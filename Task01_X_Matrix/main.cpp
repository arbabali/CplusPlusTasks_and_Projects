//Author:    ARBAB ALI
//Date:      2020.03.15
//Title:     X TYPE MATRIX

#define NORMAL_MODE
#include <iostream>
#include "Xmat.h"
#include <fstream>
using namespace std;
///TO RUN THE TESTS CASES PLEASE REPLACE ifdef NORMAL_MODE with ifndef  NORMAL_MODE
#ifndef NORMAL_MODE

//class of menu for XTYPE matrix
class Menu
{
  public:
    Menu(){a.reSize(3);}
    void run();
  private:
    Xmat a;

    void menuWrite();
    void get() const;
    void set();
    void read();
    void write();
    void sum();
    void mul();
};
int main()
{
//    setlocale(LC_ALL,"Hun");

   Menu m;
   m.run();


}

void Menu::run()
{
    int n = 0;
    do{
        menuWrite();
        cout << endl << ">>>>" ; cin >> n;
        switch(n){
            case 1: get();
                    break;
            case 2: set();
                    break;
            case 3: read();
                    break;
            case 4: write();
                    break;
            case 5: sum();
                    break;
            case 6: mul();
                    break;
        }
    }while(n!=0);
}

void Menu::menuWrite()
{
     cout << endl << endl;
     cout << " 0. - Quit" << endl;
     cout << " 1. - Get an element of the matrix" << endl;
     cout << " 2. - Overwrite an element of the matrix" << endl;
     cout << " 3. - Read matrix" << endl;
     cout << " 4. - Write matrix" << endl;
     cout << " 5. - Add matrices" << endl;
     cout << " 6. - Multiply matrices" << endl;
}

void Menu::get() const
{
    int i,j;
    cout << "Give the index of the row: "; cin >> i;
    cout << "Give the index of the column: "; cin >> j;
    try{
        cout << "a[" << i << "," << j << "]= " << a(i-1,j-1) << endl;
    }catch(Xmat::Exceptions ex){
        if(ex == Xmat::OVERINDEXED)
            cout << "Overindexing!" << endl;
        else cout << "Unhandled ecxeption!" << endl;
    }
}

void Menu::set()
{
    int i,j,e;
    cout << "Give the index of the row: "; cin >> i;
    cout << "Give the index of the column: "; cin >> j;
    cout << "Give the value: "; cin >> e;
    try{
        a(i-1,j-1) = e;
    }catch(Xmat::Exceptions ex){
        if(ex == Xmat::OVERINDEXED)
   		      cout << "Overindexing!" << endl;
        if (ex == Xmat::NULLPART)
   		      cout << "These indexes does not point to the elements !" << endl;
    }
}

void Menu::read()
{
    try{
    cin >> a;
    }
     catch(Xmat::Exceptions ex){
         if (ex==Xmat::INVALID){
            cout<<"INVALID INPUT"<<endl;
         //   exit(1);
        }
        else{
            cout<<"UNKNOWN ERROR,PROGRAM TERMINATING  "<<endl;
            exit(1);
        }

    }
}

void Menu::write()
{
    cout << a << endl;


}

void Menu::sum()
{
    Xmat a(3), b(3), c(3);

    try{

    cout << "Give the size and Elements of the first matrix: " << endl;
    cin >> a;
    cout << "Give the size and  Elements of the second  matrix: " << endl;
    cin >> b;
        cout << "Summation of matrices: " << endl;
    cout << a+b << endl;
    }
    catch(Xmat::Exceptions ex){
        if(ex==Xmat::DIFFERENT){
            cout<<"DIFFERENT SIZE matrix  SUMMATION NOT ALLOWED"<<endl;
            //exit(1);
        }
        else if (ex==Xmat::INVALID){
            cout<<"INVALID ELEMENT"<<endl;
         //   exit(1);
        }

        else{
            cout<<"UNKNOWN EXEPTION "<<endl;
            exit(1);
        }

    }
}

void Menu::mul()
{
    Xmat a(3), b(3);
try
{
    cout << "Give the size and  elements of the first matrix: " << endl;
    cin >> a;
    cout << "Give the size and elements of the second  matrix: " << endl;
    cin >> b;
    cout << "Multiplication of matrices: " << endl;
    cout << a*b << endl;
}
catch(Xmat::Exceptions ex)
{
        if(ex==Xmat::DIFFERENT){
            cout<<"DIFFERENT SIZE matrix  MULTIPLICATION NOT ALLOWED"<<endl;
            //exit(1);
        }
        else if (ex==Xmat::INVALID){
            cout<<"INVALID SIZE"<<endl;
         //   exit(1);
        }
        else{
            cout<<"UNKNOWN EXEPTION "<<endl;
            exit(1);
        }

    }
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("create", "inp.txt")
{
    const string fileName = "inp.txt";

    ifstream in(fileName.c_str());
    if(in.fail())
    {
        cout << "File name error!" << endl;
        exit(1);
    }
//    Xmat f;
//    in>>f; //5
//    CHECK(c(0,0) == 1);
//    CHECK(c(0,4) == 2);
//    CHECK(c(1,1) == 3);
//    CHECK(c(1,3) == 4);
//    CHECK(c(2,2) == 5);
//    CHECK(c(3,1) == 6);
//    CHECK(c(3,3) == 7);
//    CHECK(c(4,0) == 8);
//    CHECK(c(4,4) == 9);
    Xmat c;
    in >> c; // 3
    CHECK(c(0,0) == 1);
    CHECK(c(0,2) == 2);
    CHECK(c(1,1) == 3);
    CHECK(c(2,0) == 4);
    CHECK(c(2,2) == 5);

    Xmat b;
    in >> b; // 2
    CHECK(b(0,0) == 1);
    CHECK(b(0,1) == 2);
    CHECK(b(1,0) == 3);
    CHECK(b(1,1) == 4);


    Xmat a;
    in >> a; // 1
    CHECK(a(0,0)==1);
}

TEST_CASE("getting and changing an element of the matrix", "")
{
    ///primrary Xmatonal T
    Xmat a( {1,1,1,1,1} );
    CHECK(a(0,0) == 1);
        a(0,0) = 0;
    CHECK(a(0,0) == 0);
    ///secondary Xmatonal T
    CHECK(a(0,2)==1);
        a(0,2)=0;
    CHECK(a(0,2)==0);
    ///ZERO MATRIX F
//    Xmat c(0);
//    CHECK(a(0,0)==1);
//    ///ILLEGAL INDEX F F
//    CHECK(a(-1,-1)==1);
//    CHECK (a(4,4)==1);

}

TEST_CASE("copy constructor", "inp.txt")
{
    const string fileName = "inp.txt";

    ifstream in(fileName.c_str());
    if(in.fail())
    {
        cout << "File name error!" << endl;
        exit(1);
    }

    Xmat a;
    in >> a; // 3

    Xmat b = a;

    CHECK(a(0,0) == b(0,0));
    CHECK(a(0,2) == b(0,2));
    CHECK(a(1,1) == b(1,1));
    CHECK(a(2,0) == b(2,0));
    CHECK(a(2,2) == b(2,2));
    //CHECK(a(,2) == b(2,2));
}

TEST_CASE("assignment operator", "inp.txt")
{
    const string fileName = "inp.txt";

    ifstream in(fileName.c_str());
    if(in.fail())
    {
        cout << "File name error!" << endl;
        exit(1);
    }

    Xmat a, b; // 3
    in >> a;

    b = a; // check every non-zero item

    CHECK(a(0,0) == b(0,0));
    CHECK(a(1,1) == b(1,1));
    CHECK(a(2,2) == b(2,2));
    CHECK(a(0,2) == b(0,2));
    CHECK(a(2,0) == b(2,0));
    Xmat c; // 3
    c = b = a; // check every non-zero item

    CHECK(a(0,0) == c(0,0));
    CHECK(a(1,1) == c(1,1));
    CHECK(a(2,2) == c(2,2));
    CHECK(a(0,2) == c(0,2));
    CHECK(a(2,0) == c(2,0));
    a = a; // check every non-zero item
    CHECK(a(0,0) == 1);
    CHECK(a(0,2) == 2);
    CHECK(a(1,1) == 3);
    CHECK(a(2,0) == 4);
    CHECK(a(2,2) == 5);
}

TEST_CASE("add", "inp2.txt")
{
     const string fileName = "inp2.txt";

    ifstream in(fileName.c_str());
    if(in.fail())
    {
        cout << "File name error!" << endl;
        exit(1);
    }

    Xmat a, b, c, d, f, e, z; // 3
    in >> a >> b >> z >> e;

    c = a + b; // check every non-zero item
    CHECK(c(0,0) == 4);
    CHECK(c(0,2) == 5);
    CHECK(c(1,1) == 6);
    CHECK(c(2,2) == 8);
    CHECK(c(2,0)== 7);

    d = b + a; // check every non-zero item
    CHECK(c(0,0) == d(0,0));
    CHECK(c(0,2) == d(0,2));
    CHECK(c(1,1) == d(1,1));
    CHECK(c(2,0) == d(2,0));
    CHECK(c(2,2) == d(2,2));

    d = (a + b) + c;
    f = a + (b + c); // check every non-zero item
CHECK   (d(0,0) == f(0,0));
CHECK   (d(0,2) == f(0,2));
CHECK   (d(1,1) == f(1,1));
CHECK   (d(2,0) == f(2,0));
CHECK   (d(2,2) == f(2,2));

    c = a + z; // check every non-zero item
CHECK   (c(0,0) == a(0,0));
CHECK   (c(0,2) == a(0,2));
CHECK   (c(1,1) == a(1,1));
CHECK   (c(2,0) == a(2,0));
CHECK   (c(2,2) == a(2,2));
}

TEST_CASE("multiply", "inp2.txt")
{
    const string fileName = "inp2.txt";

    ifstream in(fileName.c_str());
    if(in.fail())
    {
        cout << "File name error!" << endl;
        exit(1);
    }

    Xmat a, b, c, d, f, e, z,g; // 3
    in >> a >> b >> z >> e;

    c = a * b;
    CHECK(c(0,0) == 15);
    CHECK(c(0,2) == 21);
    CHECK(c(1,1) == 9);
    CHECK(c(2,2) == 21);
    CHECK(c(2,0)== 15);

    d = b * a; ///X MATRIX IS NOOT COMMUTATIVE  FALSE
   CHECK(c(0,0) != d(0,0));
    CHECK(c(0,2) != d(0,2));
    CHECK(c(1,1) == d(1,1));
    CHECK(c(2,0) != d(2,0));
    CHECK(c(2,2) != d(2,2));

    ///ASSOCIATIVITY X TYPE MATRIX IS ASSOCIATIVE TRUE
    d = (a * b) * c;
    f = a * (b * c);
  CHECK   (d(0,0) == f(0,0));
CHECK   (d(0,2) == f(0,2));
CHECK   (d(1,1) == f(1,1));
CHECK   (d(2,0) == f(2,0));
CHECK   (d(2,2) == f(2,2));

///CHECKING WITH IDENTITY  MATRIX  ( X MAT DOESNT HOLD IDENTITY ) FALSE
    c = a * e;
CHECK   (c(0,0) != a(0,0));
CHECK   (c(0,2) != a(0,2));
CHECK   (c(1,1) == a(1,1));
CHECK   (c(2,0) != a(2,0));
CHECK   (c(2,2) != a(2,2));
///CHECKING WITH NULL MATRIX FALSE
    g=  a * z;
CHECK   (g(0,0) != a(0,0));
CHECK   (g(0,2) != a(0,2));
CHECK   (g(1,1) != a(1,1));
CHECK   (g(2,0) != a(2,0));
CHECK   (g(2,2) != a(2,2));

}

TEST_CASE("exceptions", "")
{

    Xmat a(3);

    try
    {
        a(3,3) = 4;
    }
    catch(Xmat::Exceptions ex)
    {
        CHECK(ex == Xmat::OVERINDEXED);
    }

    try
    {
        a(-1,4) = 4;
    }
    catch(Xmat::Exceptions ex)
    {
        CHECK(ex == Xmat::OVERINDEXED);
    }

    Xmat b(2);
    Xmat c(3);

    try
    {
        a = b;
    }
    catch(Xmat::Exceptions ex)
    {
        CHECK(ex == Xmat::DIFFERENT);
    }

    try
    {
        c = a + b;
    }
    catch(Xmat::Exceptions ex)
    {
        CHECK(ex == Xmat::DIFFERENT);
    }

    try
    {
        c = a * b;
    }
    catch(Xmat::Exceptions ex)
    {
        CHECK(ex == Xmat::DIFFERENT);
    }


    try
    {
        a(1,0) = 4;
    }
    catch(Xmat::Exceptions ex)
    {
        CHECK(ex == Xmat::NULLPART);
    }

    try
    {
        int  k = a(1,0);
    }
    catch(Xmat::Exceptions ex)
    {
        CHECK(ex == Xmat::NULLPART);
    }
}


#endif
