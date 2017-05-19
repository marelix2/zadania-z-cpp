#include <iostream>

#include <cstring>

#include <iomanip>

using namespace std;





int main() {

    

    

    int **ptrarr;

    int C,N;

    //double finalGrade = 0.0;

    

    

    

    

    cin>>C;

    

    ptrarr = new int *[C];

    double *finalGrade;

    finalGrade= new double[C];

    

    

    

    for(int i = 0; i < C ; i++){

        cin>> N;

        ptrarr[i] = new int[N + 1];

        ptrarr[i][0] = N;

        

        for(int j = 1; j< ptrarr[i][0]+ 1; j++){

            int tmp;

            cin>>tmp;

            ptrarr[i][j] = tmp;

        }

        cout<<endl;

        

    }

    

    

    for(int i = 0; i < C ; i++){

        

        

        for(int j = 1; j< ptrarr[i][0]+ 1; j++){

            finalGrade[i] += ptrarr[i][j];

        }

        finalGrade[i] /= ptrarr[i][0];

        cout<< setprecision(2) << "Course nr "<< i+1<<" final : "<<finalGrade[i]<< " grades: ";

        

        for(int j = 1; j<ptrarr[i][0]+ 1; j++){

            cout<<ptrarr[i][j]<<" ";

        }

        

        cout<<endl;

        

        

        

    }

    

    for(int i = 0; i < C ; i++){

        

        delete[] ptrarr[i];

        

    }

    delete[] ptrarr;

    delete[] finalGrade;

    

    

    


  return 0;  

}

