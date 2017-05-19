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

        rrectangle = 0;





}

cout << rsquare << endl << rrectangle << endl;



//add a suitable catch block here

return 0;

}

