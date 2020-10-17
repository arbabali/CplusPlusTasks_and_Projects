/*
    ARBAB ALI
    
    ASSIGNMENT 3 TASK 06
    
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include<algorithm>
#include "colony.hpp"

using namespace std;
enum ERROR{WRONG_FILE,ANY_OTHER_ERROR,ZERO};
void create(const string &str, vector<Prey*> &preys,vector<Predator*> &predators)
{

    ifstream f(str.c_str());

    if(f.fail()) {throw WRONG_FILE;}


    int n=0; f >> n;
    int k=0; f>> k;
    //std::cout<<"n" <<n<<" "<<k<<endl;
    preys.resize(n);
    predators.resize(k);
    //cout<<"n:"<<n<<" k :"<<k<<endl;
   // cout<<"predators size"<<predators.size()<<endl;
    k=n+k;
    int l=0;int m=0;
    for( int i=0; i<k; i++ ){
        string type; string name; int p;
        f >> name >> type >> p;
        //std::cout<<name<<"TYPE:"<<type<<" "<<p<<std::endl;
        /// The species can be: o -owl, f -fox, w -wolf, l -lemming, h -hare, g -gopher.

        switch(type[0]){
            case 'l' : preys[l] = new Lemming(name,"lemming", p); l++; break;
            case 'h' : preys[l] = new Hare(name,"hare", p); l++; break;
            case 'g' : preys[l] = new Gopher(name,"gopher", p);l++;  break;
            case 'f' : predators[m] = new Fox(name,"arctic Fox", p);m++; break;
            case 'w' : predators[m] = new Wolf(name,"The Wolf", p);m++; break;
            case 'o' : predators[m] = new SnowOwl(name,"Snow owl", p);m++;break;

        }
    }



}


void print(vector<Prey*> preys){
    for (int i=0;i<preys.size();++i){
        cout <<preys[i]->getName() << " of speciee " <<preys[i]->getSpecie() << " have No of animals : " <<preys[i]->getNoOFAnimals()<<endl<<endl;
      //  cout<<" ATTACK COUNT : "<<p->getCount()<<endl;
    }
}
void print(vector<Predator*> predators){
    //std::cout<<"PREDATOR SIZE"<<predators.size()<<std::endl;
    for (int i=0;i<predators.size();++i){
        cout <<predators[i]->getName() << " of speciee " <<predators[i]->getSpecie() << " have No of animals : " <<predators[i]->getNoOFAnimals()<<endl<<endl;
      //  cout<<" ATTACK COUNT : "<<p->getCount()<<endl;
    }
}
void simulate(vector<Prey*> preys,vector<Predator*> predators){

if(preys.size()>0&&predators.size()>0){
  int i=0;
  int j=0;
  bool FINISH_HIM=false;
  while( !FINISH_HIM){


      preys[i]->transmute(*predators[j]);


        cout<<"ATTACK  OF   "<<predators[i]->getName()<<" on "<<preys[i]->getName()<<" :: "<<preys[i]->getCount()<<endl;
  cout<<"\nPrey : "<<preys[i]->getName()<<" " << preys[i]->getNoOFAnimals()<< "\nPredator: "<<predators[i]->getName()<<" "<<predators[i]->getNoOFAnimals()<<endl;

     ++i;
     ++j;
     i=i%preys.size();
     j=j%predators.size();
 FINISH_HIM = true;
for ( int k=0;k<preys.size();++k) {
        ///WITHOUT CONSIDERATION OF PREDATORS COLONIES EXTINCTION
    if ((preys[k]->getNoOFAnimals()<(4* preys[k]->getFirstPopulation()) && preys[k]->getNoOFAnimals()>0 )) {
            FINISH_HIM = false;
         break;
     }

}
  }

  if(FINISH_HIM){
        std::cout<<"RESULTS"<<std::endl;
        for(int i=0;i<preys.size();++i){
            std::cout<<preys[i]->getName()<<" : " <<preys[i]->getNoOFAnimals()<<endl;
        }

    std::cout<<"THE PREY COLONIES HAVE BECOME EXTINCT OR BECOMES quadruples  of THEIR INTIAL SIZE"<<std::endl;
  }
}

else{
    std::cout<<"SIMULATION CANNOT WORK ON EXTINCT OR EMPTY COLONIES "<<std::endl;
    throw ZERO;

}
}

#define NORMAL_MODE
#ifndef NORMAL_MODE
int main()
{
    vector<Prey*> preys;
    vector<Predator*> predators;

    try{
    ///TO CHECK THE EXTINCTION
    create("input9.txt",preys,predators);
    ///TO SEE COLONIES BECOMING QUDRAUPPLE
    //create("input2.txt",preys,predators);
    print(preys);
    print(predators);
    cout<<"______________________________"<<endl;
    simulate(preys,predators);

 ///DEALLOCATION
     int s=preys.size();
for(int i=0;i<s;++i)
    delete preys[i];
s=predators.size();
for(int i=0;i<s;++i)
    delete predators[i];
///---------------

    }
    catch(ERROR e){
        if(e==ERROR::WRONG_FILE)
            cout<<"WRONG FILE NAME ENTERED"<<endl;
    }
    ///TO CHECK THE QUDRAUPLE



    return 0;
     }

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
TEST_CASE("1")
{

    Lemming * lemmo=new Lemming("lemmo","L",20);
    Fox* foxy =new Fox("foxy","f",1);
    lemmo->transmute(*foxy);
    ///EACH ATTACK CHECK
    CHECK(lemmo->getNoOFAnimals()==20);
    lemmo->transmute(*foxy);
    ///2nd ATTACK check
    CHECK(lemmo->getNoOFAnimals()==2*20);
    ///GREATER THAN 200
    lemmo->setAnimal(220);
    lemmo->transmute(*foxy);
    CHECK(lemmo->getNoOFAnimals()==30);
    ///LESSER THAN 20;
    Lemming * lemmo2=new Lemming("lemmo2","L",15);
    Fox* foxy2 =new Fox("foxy2","f",10);
    lemmo2->transmute(*foxy2);
    CHECK(foxy2->getNoOFAnimals()==8);
    delete lemmo,lemmo2,foxy,foxy2;
}
TEST_CASE("2")
{

    Hare * Haro=new Hare("Haro","H",20);
    Fox* foxy =new Fox("foxy","f",1);
    Haro->transmute(*foxy);
    ///EACH ATTACK CHECK 20 - 20% = 18 for each attacks
    CHECK(Haro->getNoOFAnimals()==18);
    Haro->transmute(*foxy);
    ///2nd ATTACK check 20 - 2*1= 18 - 1*1 = 17
    CHECK(Haro->getNoOFAnimals()==int(17*1.5));
    ///GREATER THAN 100
    Haro->setAnimal(110);
    Haro->transmute(*foxy);
    CHECK(Haro->getNoOFAnimals()==20);
    ///LESSER THAN 20;
    Hare * Haro2=new Hare("Haro2","hs",9);
    Fox* foxy2 =new Fox("foxy2","f",10);
    Haro2->transmute(*foxy2);
    CHECK(foxy2->getNoOFAnimals()==8);
    delete Haro,Haro2,foxy,foxy2;
}
TEST_CASE("3")
{

    Gopher * gopi=new Gopher("Gppher","g",40);
    Fox* foxy =new Fox("foxy","f",4);
    gopi->transmute(*foxy); // 40-2*4=32
    ///EACH ATTACK CHECK
    CHECK(gopi->getNoOFAnimals()==32);
    gopi->transmute(*foxy); // 32-2*3= 24
    gopi->transmute(*foxy); // 24-2*2=22
    gopi->transmute(*foxy);//  22*2 = 44 - 2*1 = 42
    ///4th ATTACK check 22*2= 44 - 2*1= 42
    CHECK(gopi->getNoOFAnimals()==(21*2));
    ///GREATER THAN 200
    gopi->setAnimal(210);
    gopi->transmute(*foxy);
    CHECK(gopi->getNoOFAnimals()==40);
    ///LESSER THAN 20;
    Gopher * gopi2=new Gopher("gopi2","g",25);
    Fox* foxy2 =new Fox("foxy2","f",10);
    gopi2->transmute(*foxy2);
    CHECK(foxy2->getNoOFAnimals()==8);
    delete gopi,gopi2,foxy,foxy2;
}
//CHECKING CONSTRUCTION AND READING OF DATA
TEST_CASE("4","input1.txt")
{
    vector<Prey*> preys;
    vector<Predator*> predators;
    create("input1.txt",preys,predators);

    CHECK(preys.size()==3);
    CHECK(predators.size()==3);

    CHECK(preys[0]->getName()=="lem1");
    CHECK(preys[0]->getSpecie()=="lemming" );
    CHECK (preys[0]->getNoOFAnimals()==86);
    CHECK(preys[1]->getName()=="lem2");
    CHECK(preys[1]->getSpecie()=="lemming" );
    CHECK(preys[1]->getNoOFAnimals()==90);
    CHECK(preys[2]->getName()=="hare1");
    CHECK (preys[2]->getSpecie()=="hare" );
    CHECK(preys[2]->getNoOFAnimals()==26);

    CHECK(predators[0]->getName()=="goo");
    CHECK (predators[0]->getSpecie()=="arctic Fox");
    CHECK(predators[0]->getNoOFAnimals()==12);
    CHECK(predators[1]->getName()=="hungry");
    CHECK(predators[1]->getSpecie()=="The Wolf");
    CHECK(predators[1]->getNoOFAnimals()==12);
    CHECK(predators[2]->getName()=="feathery");
    CHECK(predators[2]->getSpecie()=="Snow owl" );
    CHECK(predators[2]->getNoOFAnimals()==66);
int s=preys.size();
for(int i=0;i<s;++i)
    delete preys[i];
s=predators.size();
for(int i=0;i<s;++i)
    delete predators[i];

}
TEST_CASE("5","empty.txt")
{
 vector<Prey*> preys;
    vector<Predator*> predators;
    create("empty.txt",preys,predators);

    CHECK(preys.size()==0);
    CHECK(predators.size()==0);

}
TEST_CASE("6"){
////vector<Prey*> preys;
////    vector<Predator*> predators;
////    try{
////    create("input213.txt",preys,predators);
////
////    }
////    catch(ERROR e){
////
////        check(e==ERROR::WRONG_FILE);
////        check(e!=ERROR::ANY_OTHER_ERROR);
////    }

}

///WHEN PREY BECOMES EXTINCT
TEST_CASE ("7","input1.txt"){

vector<Prey*> preys;
    vector<Predator*> predators;
create("input1.txt",preys,predators);
simulate(preys,predators);

CHECK(preys[0]->getNoOFAnimals()<=0);
CHECK(preys[1]->getNoOFAnimals()<=0);
CHECK(preys[2]->getNoOFAnimals()<=0);


}
///WHEN PREY POPULATION BECOMES QUDRAUBLE
TEST_CASE ("8","input2.txt")
{
vector<Prey*> preys;
    vector<Predator*> predators;
create("input2.txt",preys,predators);
simulate(preys,predators);

CHECK(preys[0]->getNoOFAnimals()>=(4* preys[0]->getFirstPopulation()));
CHECK(preys[1]->getNoOFAnimals()>=(4* preys[1]->getFirstPopulation()));
CHECK(preys[1]->getNoOFAnimals()>=(4* preys[1]->getFirstPopulation()));

}
TEST_CASE( "9","input3.txt")
{
vector<Prey*> preys;
vector<Predator*> predators;
create("input3.txt",preys,predators);
simulate(preys,predators);
CHECK(preys.size()==0);

}
TEST_CASE("10","input4.txt")
{

vector<Prey*> preys;
vector<Predator*> predators;
create("input4.txt",preys,predators);
simulate(preys,predators);
CHECK(preys[0]->getNoOFAnimals() <= 0 );
}
TEST_CASE("11","input5.txt")
{

vector<Prey*> preys;
vector<Predator*> predators;
create("input5.txt",preys,predators);
simulate(preys,predators);
CHECK(preys[0]->getNoOFAnimals()<=0);
CHECK(preys[1]->getNoOFAnimals()<=0);

}
TEST_CASE("12","input6.txt")
{

vector<Prey*> preys;
vector<Predator*> predators;

create("input6.txt",preys,predators);
simulate(preys,predators);

    bool r= (preys[0]->getNoOFAnimals()<=0 || (preys[0]->getNoOFAnimals()>=(4* preys[0]->getFirstPopulation())));
    CHECK(r);

}
TEST_CASE("13","inpupt7.txt")
{

vector<Prey*> preys;
vector<Predator*> predators;

create("input7.txt",preys,predators);
simulate(preys,predators);
CHECK (preys[0]->getNoOFAnimals()<=0);

}
TEST_CASE("14","input8.txt")
{

vector<Prey*> preys;
vector<Predator*> predators;

create("input8.txt",preys,predators);
simulate(preys,predators);
CHECK (preys[0]->getNoOFAnimals()<=0);

}
TEST_CASE("15","input9.txt")
{

vector<Prey*> preys;
vector<Predator*> predators;

create("input9.txt",preys,predators);
simulate(preys,predators);
CHECK (preys[0]->getNoOFAnimals()<=0);


}
#endif
