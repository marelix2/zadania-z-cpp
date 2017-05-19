#include <iostream>

#include <exception>



using namespace std;

float internaldiv(float arg1, float arg2) throw(string)

{

    if (0.0 == arg2){

        throw string("dividing by 0");

    }

    return arg1 / arg2;

}

bool div(float &res, float arg1, float arg2)throw (string) {

   res  = internaldiv(arg1, arg2);

    return true;

}









int main(void) {

    float r, a, b;

    while(cin >> a) {

        cin >> b;



        try{

        div(r,a,b);

        }catch(string &exc){



            cout<<exc<<endl;

            r = 0.0;

        }





        cout<< r << endl;

    }

    return 0;

}

