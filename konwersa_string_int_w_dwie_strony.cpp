#include <iostream>
#include <string>
#include <sstream>

using namespace std;
class Fraction{
public:
    Fraction(int numerator, int denominator);
    string toString();
    double toDouble();
private:
    int numerator_;
    int denominator_;
};
// implement Fraction methods

Fraction::Fraction(int numerator, int denominator){
    numerator_ = numerator;
    denominator_ = denominator;

};

std::string Fraction::toString(){

    std::string a, b;

    std::ostringstream ss;
    std::ostringstream ss2;
    ss << numerator_;
    a = ss.str();

    ss2 << denominator_;

    b = ss2.str();

    return (a + "/" + b);

};

double Fraction::toDouble(){


    return (double)numerator_/denominator_;


};


int main(void) {
    int num, den;
    std::string input = "";
    getline(std::cin,input);

   std::string tmpn = input.substr(0,1);
   std::string tmpd = input.substr(4);

        std::istringstream iss(tmpn);
        iss >> num;
        std::istringstream is2(tmpd);
        is2 >> den;

       // std::cout<<num<<den<<endl;

    Fraction fraction(num, den);
    cout << fraction.toString() << " is " << fraction.toDouble() <<" in decimal "<< endl;
    return 0;
}
