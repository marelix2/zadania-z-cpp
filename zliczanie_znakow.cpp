#include <iostream>

#include <string>



using namespace std;







void checkLower(string zmienna, int *tab){



    for(int i = 0; i< zmienna.length(); i++){



        int a = (int) zmienna[i] - 97;

        // cout<<a<<endl;

        if(a < -1) continue;



        tab[a] = tab[a] + 1;





    }

}



void checkUpper(string zmienna, int *tab){



                    for(int i = 0; i< zmienna.length(); i++){



                        int a = (int) zmienna[i] - 65;

                        // cout<<a<<endl;

                        if(a < -1) continue;



                        tab[a] = tab[a] + 1;



                    }

                }



int main(int argc, char *argv[])

{

    //cout << "Hello World!" << endl;

    string zmienna;



    //int tab[26] = {};



    int *tab;

    tab = new int[26]();



    //make_zero(tab);





    getline(cin,zmienna);



    checkLower(zmienna, tab);

    checkUpper(zmienna, tab);





    for(int i= 0; i< 26 ;i++){

        char chtr = 'a' + i;

        cout<<  chtr << " - "<< tab[i]<<endl;



    }





    return 0;

}

