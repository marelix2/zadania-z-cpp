#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <exception>
#include <cmath>

class MyExec{

    std::string txt_;
public:
    MyExec(std::string txt): txt_(txt) {}
    std::string printInfo(){return txt_;}
};

class IpAddress{
protected:
    std::string ss_;
    bool isCorrect;
    int howMany_;



    IpAddress(std::string ss, int howMany):ss_(ss), isCorrect(true),howMany_(howMany){}

    virtual void printIp(){
        std::cout<<ss_<<std::endl;

    }

    virtual ~IpAddress(){}

};

class IpAddressCheck: public IpAddress{

    std::string prefix;
    int lastNumber;
public:
    IpAddressCheck(std::string ss, int a): IpAddress(ss,a){

    }


    bool isNumber(std::string ss){
        bool todo =false;
        //std::locale loc;

        for(int i = 0; i< ss.length(); i++){
            if (isdigit(ss[i]))todo = true;
            else
                return false;
        }
        return todo;


    }

    void ChceckIp() throw (MyExec){
        int pos = 0;
        int position = 0;
        int a;
        int lastpart= 0;
        int tmp[9];
        bool corr= false;
        for(int i = 0 ; i< 9 ; i++) if((howMany_  == (int) pow(2,i) )) corr= true;
         if(!corr)  throw MyExec("liczba elementow nie jest potaga liczby 2");



        for(;;){
            lastpart++;
            if(position != std::string::npos) position = ss_.find('.',pos);
            else break;


            std::string tmp1 = ss_.substr(pos, position- pos);

            if(!isNumber(tmp1)) {

                throw MyExec("w czlonie wystepuje litera");
                break;

            }

            std::istringstream iss(tmp1);
            iss >> a;

            if(a < 0 || a > 255) {


                throw MyExec("czlon spoza zakresu");
                break;
            }

            if(lastpart == 4){
                prefix = ss_.substr(0,pos);
                lastNumber = a;
                //std::cout<<prefix<<a<<std::endl;

            }
            pos = position;
            pos++;
            //std::cout<<pos<<std::endl;
            iss.clear();
            iss.ignore();
        }

         if((howMany_ + lastNumber > 256)) throw MyExec("liczba elementow przekracza zakres");
    }

    int TryCheck(){

        try{

            ChceckIp();

        }catch(MyExec &ee){

            std::cout<<ee.printInfo()<<std::endl;
            return 0;
        }

        printIp();


    }

    void printIp(){


        for(int i = 0 ; i < howMany_ ; i++ ){

            std::cout<<prefix<< lastNumber++<<std::endl;
        }
    }


};


int main()
{

    IpAddressCheck aa("1.1.1.228",32);

    aa.TryCheck();



    // cout << "Hello World!" << endl;
    return 0;
}
