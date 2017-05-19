#include <iostream>

#include <exception>



using namespace std;



class MyExec{



    std::string txt_;

public:

    MyExec(string txt) : txt_(txt) {}



    std::string printInfo(){return txt_;}





};



float square_area(float a) throw(MyExec){



    if(a == 0.0) throw MyExec(" your area equals 0");

     if(a < 0) throw MyExec("cant count area");



   return a*a;





}



float rectangle_area(float a,float b) throw(MyExec){



     if(a == 0.0) throw MyExec(" your area equals 0");

     if( a < 0 || b < 0) throw MyExec("cant count area");

     if(b == 0.0) throw MyExec("cant divide by 0");



   return a*b;





}







//add your own exception class here

//add functions code here



int main(void) {

float a, b, r;

float rrectangle;

float rsquare;

cin >> a;

cin >> b;

try

{

 rsquare = square_area(a);

 rrectangle= rectangle_area(a,b);



}catch(MyExec &ss){



        std::cout<< ss.printInfo()<<endl;

        rsquare = 0;

        rrectangle = 0#include <iostream>
#include <exception>
#include <string>

class MyExec{

    std::string txt_;
public:
    MyExec(std::string txt): txt_(txt) {}
    std::string printInfo(){return txt_;}
};

class CheckClass {

    int value_;
    int min_ , max_;
public:
    CheckClass(int value, int min, int max): min_(min), max_(max), value_(value){
        std::cout<<"dodano"<<std::endl;

    }
    void StartCheckUp() throw (MyExec){
         if(value_ < min_) throw MyExec("value mniejsze od min");
         if(value_> max_) throw MyExec("przekroczono zakres max przy starcie");
         if(min_ > max_) throw MyExec("min wieksze od max");



    }

    void addValue(int a) throw (MyExec){

        if(value_ + a > max_) throw MyExec("przekroczono zakres max");
        else value_ += a;

    }

    void subValue(int a) throw (MyExec){

        if(value_ - a < min_) throw MyExec("przekroczono zakres min");
        else value_ -= a;

    }

    int getValue(){


        return value_;
    }

};


int check(CheckClass &cl1, CheckClass &cl2){

    try{
        cl1.StartCheckUp();
        cl2.StartCheckUp();
        cl1.addValue(cl2.getValue());
        cl2.subValue(cl1.getValue());

    }catch(MyExec &exc){

        std::cout<<exc.printInfo()<<std::endl;
        return 0;


    }

}



int main(void) {

int a, b, c;

std::cin>>a>>b>>c;

CheckClass cl1(a,b,c);

std::cin>>a>>b>>c;

CheckClass cl2(a,b,c);

check(cl1, cl2);








return 0;

}







}

cout << rsquare << endl << rrectangle << endl;



//add a suitable catch block here

return 0;

}

