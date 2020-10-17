//Author:    ARBAB ALI
//Date:      2020.03.15
//Title:     X TYPE MATRIX

#include "Xmat.h"
#include <iostream>
#include <iomanip>

using namespace std;

//Task: 	constructor with size
//Input:    int k     - the new size
//Output:   Xmat this - default matrix
//Activity: creates the array of the Xmatonal of size k
Xmat::Xmat(int k)
{
    if (k < 0) throw INVALID;
    _n=k;
    _v.clear();
    _v.resize(2*k,0);
}

//Task: 	constructor the elements of the Xmatonal
//Input:    vector<int> v     - the new Xmatonal
//Output:   Xmat this         - default matrix
//Activity: creates the array of the Xmatonal and fills in its elements based on vector v
Xmat::Xmat(const std::vector<int> &v)
{
    _v = v;
    if(v.size()%2==0)
        _n= v.size()/2 ;
    else
        _n=v.size()/2 +1;
}

//Task: 	copy constructor
//Input:    Xmat a    - matrix
//Output:   Xmat this - default matrix
//Activity: creates the array of the Xmatonal and fills in its elements based on matrix a
Xmat::Xmat(const Xmat& a)
{
    int s = a.getSize();
    reSize(a._n);
    for(int i = 0; i < s; ++i) _v[i] = a._v[i];
}

//Task: 	assignment operator
//Input:    Xmat a    - matrix
//Output:   Xmat this - default matrix
//Activity: fills in the elements of the Xmatonal based on matrix a
Xmat& Xmat::operator=(const Xmat& a)
{
  //  if(a._n==_n) throw DIFFERENT;
    int s = a.getSize();
    reSize(a._n);
    for(int i = 0; i < s; ++i) _v[i] = a._v[i];
    return *this;
}

//Task: 	resizing a matrix
//Input:    int k     - the new size
//Output:   Xmat this - default matrix
//Activity: resizes the matrix to k
void Xmat::reSize(int k)
{
    if(k < 0) throw INVALID;
    _n=k;
    if(k%2!=0)
        _v.resize(2*k,0);
    else
        _v.resize(2*k-1,0);
}

//Task: 	adding
//Input:    Xmat a    - matrix
//          Xmat b    - matrix
//Output:   Xmat      - result matrix
//Activity: adds the elements of the Xmatonals of the matrices
Xmat operator+(const Xmat& a ,const Xmat& b)
{
    int s = a._n;
    if(s!= b._n) throw Xmat::DIFFERENT;
  //  cout<<"size of a.getsize"<<a.getSize()<<endl;
    Xmat c(s);
  //  cout<<"size of c size"<<c.getSize()<<endl;
    for(int i = 0; i <=a.getSize(); i++){
            c._v[i] = a._v[i] + b._v[i];
           // cout<<"c"<<i<<c._v[i]<<endl;
    }
    return c;
}

//Task: 	multiplying
//Input:    Xmat a    - matrix
//          Xmat b    - matrix
//Output:   Xmat      - result matrix
//Activity: multiplies the elements of the Xmatonals of the matrices
/// auxulury function for assigeing and setting

void Xmat::setter(int i,int j,int k){
    if ((i >= _n || i < 0 ) || (j >= _n || j < 0 )) throw OVERINDEXED;
    if(i==j)
        _v[i]=k;
    if((i+j)==(_n-1))
        _v[_n+i]=k;

}
Xmat operator*(const Xmat& a ,const Xmat& b)
{
    int s = a.getSize();
    if(a._n != b._n) throw Xmat::DIFFERENT;

    Xmat c(a._n);

    for(int i = 0; i < a._n; ++i){
    for(int j=0;j<a._n;++j){

        int sum=0;
        for (int k=0;k<a._n;++k){
            sum+= a(i,k)*b(k,j);
        }
       // cout<<sum<<endl;
        c.setter(i,j,sum);
    }
    }
    return c;
}

//Task: 	writing
//Input:    ostream os - target of writing
//          Xmat a     - matrix
//Output:   ostream os - target of writing
//Activity: writes the elements of the matrix
ostream& operator<<(ostream& os, const Xmat& a)
{
    int s = a.getSize();
    for(int i = 0; i < a._n; ++i){
        for(int j = 0; j <a._n; ++j)
            os << setw(5) << a(i,j);
        os << endl;
    }
    return os;
}

//Task: 	reading
//Input:    istream is - source of writing
//          Xmat a     - matrix
//Output:   istream is - source of writing
//Activity: reads the elements of the Xmatonal of the matrix
istream& operator>>(istream& is, Xmat& a)
{
    int s;
    is >> s;
    a.reSize(s);
    for(int i = 0; i < s; ++i) {
 //       cout << "[" << i << "," << i << "]=";
    for(int j=0;j<s;++j){
            if(i==j || ((i+j)==(s-1)))
                is >> a(i,j);
    }
    }
    return is;
}

//Task: 	getting
//Input:    int i,j - indexes of the element
//Output:   int     - the element of the matrix in the ith row and jth column
//Activity: gets the given element of the Xmatonal matrix
int Xmat::operator()(int i, int j) const
{
    int s = getSize();
    if ((i >= _n || i < 0 ) || (j >= _n || j < 0 )) throw OVERINDEXED;
    if(i==j) return _v[i];
    if((i+j)==(_n-1)) return _v[_n+i];
    if (i != j) return 0;


}

//Task: 	setting
//Input:    int i,j - indexes of the element
//Output:   int     - the element of the matrix in ith row and jth column
//Activity: gives a reference to the given elements of the Xmatonal matrix
int& Xmat::operator()(int i, int j)
{
   // int s = getSize();
    if ((i >= _n || i < 0 ) || (j >= _n || j < 0 )) throw OVERINDEXED;
    if(i==j) return _v[i];
    if((i+j)==(_n-1)) return _v[_n+i];
    if (i != j) throw NULLPART;
}
