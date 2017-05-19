#include <iostream>

#include <sstream>

#include <string>

#include <cctype>





class IpAddress{

    protected:

   std::string ss_;

   bool isCorrect;







    IpAddress(std::string ss):ss_(ss), isCorrect(true){}



    virtual void printIp(){

        std::cout<<ss_<<std::endl;



    }



    virtual ~IpAddress(){}



};



class IpAddressCheck: public IpAddress{





public:

    IpAddressCheck(std::string ss): IpAddress(ss){



    }



    std::string IsCorr(){

        if(isCorrect) return "Correct";



        return "Not Correct";

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



    void ChceckIp(){

        int pos = 0;

        int position = 0;

        int a;



        for(;;){



                       if(position != std::string::npos) position = ss_.find('.',pos);

                       else break;





                       std::string tmp1 = ss_.substr(pos, position- pos);



                       if(!isNumber(tmp1)) {

                           isCorrect = false;

                          break;



                       }



                     std::istringstream iss(tmp1);

                       iss >> a;



                       if(a < 0 || a > 255) {



                           isCorrect = false;

                          break;

                       }

                           pos = position;

                           pos++;

                        //std::cout<<pos<<std::endl;

                         iss.clear();

                         iss.ignore();

       }





    }



    void printIp(){





        std::cout<<ss_<<" "<<IsCorr()<<std::endl;

    }





};





int main()

{



    IpAddressCheck aa("1.1.1.1");



    aa.ChceckIp();



    aa.printIp();





   // cout << "Hello World!" << endl;

    return 0;

}

