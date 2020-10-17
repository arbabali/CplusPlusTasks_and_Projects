#pragma once

#include <string>
#include <cmath>
class Colony
{
    protected:
    std::string _name;
    std::string _specie;
    int  _noOfAnimal;
    int _counter=0;
    bool _extinct= false;
    Colony(const std::string &name ,const std::string &S, int e=0):_noOfAnimal(e){_name=name;_specie=S;}
public:
    std::string getName(){return _name;}
    void setName(std::string n){_name=n;}
    void setSpecie(std::string s){_specie=s;}
    std::string getSpecie(){return _specie;}
    int getNoOFAnimals() const {return _noOfAnimal;}
    void setAnimal(int n) {_noOfAnimal=n;}
    void Count(){_counter+=1;}
        int getCount(){return _counter; }
    bool getStatus()const {return _extinct;}
    void setStatus(bool b){_extinct=b;}
    //virtual void ChangeAnimals(int e){ _noOfAnimal+=e;}
   // virtual void setAnimals(int n) {_noOfAnimal=n;}
    ///virtual void transmute(Colony* &col)=0;

    virtual ~Colony(){}

       // virtual bool isPrey() const { return false; }
};
class Predator;
class Prey : public Colony ///Haszonnövény
{
        protected:
        Prey(const std::string &name ,const std::string &S, int e=0) : Colony(name,S,e) { _firstPopulation=e;}
    private:

        int _firstPopulation;
    public:
        int getFirstPopulation()const {return _firstPopulation; }
        virtual void transmute(Predator &pred)=0;

      //  void ChangeAnimals(int e) override {};

      ~Prey(){

      //delete this;
    }


};

class Predator : public Colony
{
    public:
   ~Predator(){
      //delete this;
    }
    virtual void transmute(Prey &prey)=0;
    protected:
        Predator(const std::string &name ,const std::string &S, int e=0) : Colony(name,S,e) {}
};

///LEMMING
class Lemming : public Prey
{
    public:
    Lemming(const std::string &name ,const std::string &S, int e=0) : Prey(name,S,e) {}
   // void ChangeAnimals(int e) override {_noOfAnimal+=e;}
     void transmute(Predator &pred)override{

        /*

        Lemming: If they are preyed upon by a predator colony,
        the number of animals in their colony decreases by four times the number of animals  in the  predator colony.
        The  number of animals in their colony doubles every second turn.
        If there are less than 20 animals in the colony, all predatorcolonies have 20% lessoffsprings.
        If there are more than 200 animals in the colony, the number of animals in the colony decreases to 30
        */


        Count();
        if(this->getNoOFAnimals()<=0){
               // std::cout<<"do oyu even come here bro "<<std::endl;
            setStatus(true);
            setAnimal(0);
        }
//////         if(getNoOFAnimals()<prey.getNoOFAnimals()*4){
//////          setAnimal(getNoOFAnimals()*0.75);
//////        }
        if(getCount()%2==0 && getCount()!=0){
            this->setAnimal(this->getNoOFAnimals()*2);
        }
//

        if(this->getNoOFAnimals()<=20){
         //   std::cout<<"truncating works"<<std::trunc(((pred.getNoOFAnimals()*80)/100))<<std::endl;
        //   std::cout<<"no ofo prey  now"<<pred.getNoOFAnimals()<<std::endl;

          // std::cout<<"no of pred  now: "<<pred.getNoOFAnimals()<<std::endl;
            pred.setAnimal((((pred.getNoOFAnimals()* 0.8))));
           // std::cout<<"no of pred  now: "<<pred.getNoOFAnimals()<<std::endl;


        }
        else if (this->getNoOFAnimals()>200)
        {
            this->setAnimal(30);
        }


        else{
        this->setAnimal(this->getNoOFAnimals()- pred.getNoOFAnimals()*4);
        }
        pred.transmute(*this);

}
};

class Hare : public Prey
{
       public:
        Hare(const std::string &name ,const std::string &S, int e=0) : Prey(name,S,e) {}
/*Hare: If they are preyed upon by a predatorcolony,
the number of animals in their colony decreases by double the number of animals in the predator colony.
The number of animals in their colony grows by 50 percent (to one and a half times their previous number)
every second turn. If there are less than 10 animals in the colony, every predator colonies have20%less offsprings.
If there are more than 100 animals in the colony, the number of animals in the colony decreases to 20. */
    void transmute(Predator &pred)override{
 ///  std::cout<<this->getName()<<" 's  predetor is "<<pred.getName()<<std::endl;

        Count();
        if(getNoOFAnimals()<=0){
            setStatus(true);
            setAnimal(0);
        }
         if(getCount()%2==0 && getCount()>0){
            this->setAnimal(this->getNoOFAnimals()*1.5);
        }
////////        if(pred.getNoOFAnimals()<this->getNoOFAnimals()*4){
////////            pred.setAnimal(pred.getNoOFAnimals()*0.75);
////////        }
        if(this->getNoOFAnimals()<=10){
            pred.setAnimal(pred.getNoOFAnimals()*0.8);
        }
        else if (this->getNoOFAnimals()>100)
        {
            this->setAnimal(20);
        }
        else{
        this->setAnimal(this->getNoOFAnimals()- pred.getNoOFAnimals()*2);
        }

         pred.transmute(*this);
        }

};

class Gopher : public Prey
{
    public:
        Gopher(const std::string &name ,const std::string &S, int e=0) : Prey(name,S,e) {}
void transmute(Predator &pred)override{
  /// std::cout<<this->getName()<<" 's  predetor is "<<pred.getName()<<std::endl;

/*
Gopher:If  they  are  preyed  upon  by  a  predator  colony,
 the  number  of  animals  in  their  colony  decreases  by double the number of animals in the predator colony.
 The number of animals in their colony doubles every fourth turn. If there are less than 30 animals in the colony,
  every predator colonies have20%less offsprings.
If there are more than 200 animals in the colony, the number of animals in the colony decreases to 40.
*/

       Count();
         if(getNoOFAnimals()<=0){
            setStatus(true);
            setAnimal(0);
        }
        if(getCount()%4==0 && getCount()!=0){
            this->setAnimal(this->getNoOFAnimals()*2);
        }
//////        if(pred.getNoOFAnimals()<this->getNoOFAnimals()*4){
//////
//////            pred.setAnimal(pred.getNoOFAnimals()*0.75);
//////        }
       if(this->getNoOFAnimals()<=30){
                pred.setAnimal(trunc(((pred.getNoOFAnimals()*0.8))));
        }
        else if (this->getNoOFAnimals()>200)
        {
            this->setAnimal(40);
        }
        else{
             ///   std::cout<<"I M HERE"<<
        this->setAnimal(this->getNoOFAnimals()- pred.getNoOFAnimals()*2);
        }


        pred.transmute(*this);

        }

};

///PREDATORS
class SnowOwl : public Predator
{


    public:
    SnowOwl(const std::string &name ,const std::string &S, int e=0) : Predator(name,S,e) {}
//    void ChangeAnimals(int e) override {_noOfAnimal+=e;}
 //   void ChangeAnimal(Prey &p){ _noOfAnimal+=p.getNoOFAnimals();}
     void transmute(Prey &prey)override{
         //std::cout<<"I SHOULD RUN EACH TIME"<<std::endl;
      Count();
      // if(this->getNoOFAnimals()>4){

if(getNoOFAnimals()<=0){
            setStatus(true);
            setAnimal(0);
        }
        if(prey.getNoOFAnimals()> 10 * this->getNoOFAnimals()){

            if(this->getCount()%8==0 && this->getCount()>0){
            //    std::cout<<"AND I ONLY ON 8th TIME "<<this->getNoOFAnimals() <<" and "<< (int((float(this->getNoOFAnimals())* 0.50)))<<std::endl;
            this->setAnimal(trunc(float(this->getNoOFAnimals())* 1.50));
        }
        }
        else
        {


            if(this->getCount()%8==0 && this->getCount()>0){
            //    std::cout<<"AND I ONLY ON 8th TIME"<<this->getNoOFAnimals() <<"and "<< (int((float(this->getNoOFAnimals())* 0.25)))<<std::endl;
            this->setAnimal(int((float(this->getNoOFAnimals())* 1.25)));
        }


        }
     // }
//      else{
//              this->setAnimal(this->getNoOFAnimals() -1);
//            }


        }


   // ~SnowOwl(){}

};

class Fox : public Predator
{
    public:
        Fox(const std::string &name ,const std::string &S, int e=0) : Predator(name,S,e) {}
     void transmute(Prey &prey)override{
         //std::cout<<"I SHOULD RUN EACH TIME"<<std::endl;
         Count();
        // if(getNoOFAnimals()>4)

        if(getNoOFAnimals()<=0){
            setStatus(true);
            setAnimal(0);
        }

         if(prey.getNoOFAnimals()> 10 * this->getNoOFAnimals()){
            if(this->getCount()%8==0 && this->getCount()>0){
                //std::cout<<"AND I ONLY ON 8th TIME"<<this->getNoOFAnimals() + (int((float(this->getNoOFAnimals()))))<<std::endl;
            this->setAnimal( int((float(this->getNoOFAnimals())* 2.0))) ;
        }
        }

        else
        {

            if(this->getCount()%8==0 && this->getCount()>0){
               // std::cout<<"AND I ONLY ON 8th TIME"<<this->getNoOFAnimals() + (int((float(this->getNoOFAnimals())* 0.75)))<<std::endl;
            this->setAnimal(int((float(this->getNoOFAnimals())* 1.75)));
        }


        }
        //else{
          //  this->setAnimal(getNoOFAnimals()-1);
        //}

        }

};

class Wolf : public Predator
{
    public:

        Wolf(const std::string &name ,const std::string &S, int e=0) : Predator(name,S,e) {}
     void transmute(Prey &prey)override{
         //std::cout<<"I SHOULD RUN EACH TIME"<<std::endl;

        Count();

  if(getNoOFAnimals()<=0){
            setStatus(true);
            setAnimal(0);
        }
       /// if(getNoOFAnimals()>4){
         if(prey.getNoOFAnimals()> 10 * this->getNoOFAnimals()){
            if(this->getCount()%8==0 && this->getCount()>0){
            //    std::cout<<"AND I ONLY ON 8th TIME"<<(int((float(this->getNoOFAnimals())* 1.75)))<<std::endl;
            this->setAnimal(int((float(this->getNoOFAnimals())* 1.75)));
        }
        }
        else
        {
            if(this->getCount()%8==0 && this->getCount()>0){
           ///     std::cout<<"AND I ONLY ON 8th TIME"<<this->getNoOFAnimals() + (int((float(this->getNoOFAnimals())* 0.50)))<<std::endl;
            this->setAnimal(int((float(this->getNoOFAnimals())* 1.50)));
        }
        }
      //  }
//    else
//        {
//            this->setAnimal(getNoOFAnimals()-1);
//        }

        }


};
