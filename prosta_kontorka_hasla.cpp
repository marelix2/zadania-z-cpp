#include <string>
#include <iostream>

bool lengthOfPassword(std::string pass){

     if(pass.length() <= 8) return false;
     else return true;

}

bool checkLower(std::string pass){



    for(int i = 0; i< pass.length(); i++){

        int a = (int) pass[i] - 97;

        // cout<<a<<endl;

        if(a > -1 && a<=26) return true;

    }
    return false;

}

bool checkUpper(std::string pass){



    for(int i = 0; i< pass.length(); i++){

        int a = (int) pass[i] - 65;

        // cout<<a<<endl;

        if(a > -1 && a<=26) return true;

    }
    return false;

}

bool checkDigit(std::string pass){



    for(int i = 0; i< pass.length(); i++){

        int a = (int) pass[i] - 48;

        // cout<<a<<endl;

        if(a > -1 && a<=10) return true;

    }
    return false;

}

bool checkSpecial(std::string pass){



    for(int i = 0; i< pass.length(); i++){

        int a = (int) pass[i] - 33;

        // cout<<a<<endl;

        if(a > -1 && a<=14 || a>=24 && a<=30) return true;

    }
    return false;

}




int main()
{
std::string password;
std::getline(std::cin, password);

std::cout<<"ma 8 znakow "<<lengthOfPassword(password)<<std::endl;
std::cout<<"zawiera liczbe "<<checkDigit(password)<<std::endl;
std::cout<<"zawiera maly znak "<<checkLower(password)<<std::endl;
std::cout<<"zawiera duzy znak "<<checkUpper(password)<<std::endl;
std::cout<<"zawiera znak specjalny "<<checkSpecial(password)<<std::endl;


// manipulate the password here
// and print validation result
return 0;
}