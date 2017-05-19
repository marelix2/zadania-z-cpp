
#include <iostream>
#include <string>
class StringValidator
{
public:
    virtual ~StringValidator() {};
    virtual bool isValid(std::string input) = 0;
};

class MinLengthValidator
{
    int min_;
public:
    MinLengthValidator(int min): min_(min){};


    bool isValid(std::string password){

        if(password.length() <= min_) return false;
        else return true;

    }
};

class MaxLengthValidator
{

    int max_;
public:
    MaxLengthValidator(int max): max_(max){};


    bool isValid(std::string password){
        //std::cout<<"cotam"<<std::endl;

        if(password.length() >= max_) return false;
        else return true;

    }
};



class AtLeastOneLowerChar
{
public:
    bool isValid(std::string pass){
 //std::cout<<"cotam"<<std::endl;
        for(int i = 0; i< pass.length(); i++){

            int a = (int) pass[i] - 97;

            //std::cout<<a<<std::endl;

            if(a > -1 && a<=26) return true;

        }
        return false;

    }
};

class AtLeastOneUpperChar
{
public:
    bool isValid(std::string pass){
//std::cout<<"cotam"<<std::endl;


        for(int i = 0; i< pass.length(); i++){

            int a = (int) pass[i] - 65;

            if(a > -1 && a<=26) return true;

        }
        return false;
    }
};
class AtLeastOneSpecialChar
{
public:
    bool isValid(std::string pass){



        for(int i = 0; i< pass.length(); i++){

            int a = (int) pass[i] - 48;
       // std::cout<<a<<std::endl;

            if(a > -1 && a<=10) return true;

        }
        return false;

    }
};

class AtLeastOneNumber
{

public:
    bool isValid(std::string pass){



        for(int i = 0; i< pass.length(); i++){

            int a = (int) pass[i] - 33;

          // std::cout<<a<<std::endl;

            if(a > -1 && a<=14 || a>=24 && a<=30) return true;

        }
        return false;

    }
};

class LengthValidator : public StringValidator
{

public:
    LengthValidator(int min, int max):
        min_validator(min), max_validator(max),at(),nr(),spc(),uc()
    {
    };
    bool isValid(std::string input);
private:
    MinLengthValidator min_validator;
    MaxLengthValidator max_validator;
    AtLeastOneLowerChar at;
    AtLeastOneNumber nr;
    AtLeastOneSpecialChar spc;
    AtLeastOneUpperChar uc;

};


bool LengthValidator::isValid(std::string input)
{
    return ( min_validator.isValid(input) && max_validator.isValid(input) && at.isValid(input) && nr.isValid(input) && spc.isValid(input) && uc.isValid(input) ) ;
}
// Your code here





void printValid(StringValidator &validator, std::string input)
{
    std::cout << "The string '" << input << "' is "
              << (validator.isValid(input) ? "valid" : "invalid")<< std::endl;
}


int main()
{


    LengthValidator exact(8,20);
    printValid(exact, "hello");
    printValid(exact, "Karakan12!");
    return 0;



return 0;
}
