#include <string>
#include <iostream>

using namespace std;


string makeCleanWS(string sentence,int where_it_begins){

    while(sentence.find(' ',where_it_begins) != string::npos) {
        where_it_begins = sentence.find(' ',where_it_begins);
        where_it_begins++;

    while(sentence[where_it_begins] == ' '){

        sentence.erase(where_it_begins,1);
        //where_it_begins++;
    }


    }

    return sentence;
}


int main()
{
string sentence;
int where_it_begins = 0;
getline(cin, sentence);

// manipulate the sentence here
cout << makeCleanWS(sentence,where_it_begins) << "\n";
}
