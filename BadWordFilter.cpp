#include <bits/stdc++.h>
using namespace std;
string s, w; //s is our sentence, while w is the word we are looking at
string sw[] = {""};
int main()
{
    //Input
    cout<<"Welcome to Bad Word filtering. Please give us your sentence and we will try to filter the bad words out:"<<endl;
    getline(cin, s);
    for(int i = 0; i < s.size(); i++) //First for loop is going to go trough entire sentence
    {
        for(int k = i; s[k] != ' '; k++)
        {
            w.push_back(s[k]);
        }
        cout<<w<<endl;
    }




}
