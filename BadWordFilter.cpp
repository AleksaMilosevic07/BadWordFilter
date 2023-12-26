#include <bits/stdc++.h>
using namespace std;
string s, w, swear; //s is our sentence, while w is the word we are looking at
vector <string> sw = {"Fuck", "Shit", "Bitch", "Cock", "Ass", "Bitch", "nigga", "nigger"}; //This is the ugly part of our code.... Writing out all of the common swears, I am sorry!!!
vector <string> wl = {"Duck", "Ship", "Beach", "Clock", "Bass", "Grass", "Witch", "Pitch", "Grasses"}; //This is our white-list array. There are lot of swears that look like a swear, with a singular letter changing the meaning. For example, duck. If you would replace the d with f you would get a swear.

float m, one; //m stands for "Match". We will use this value to see what is the percentage of match with the word. One stands for "one percent". We will use this value to calculate what is one letter match for each swear word.
int swearWordSize = sw.size(); //This variable will monitor the size of our swear-list. So in case you add a word, you don't need to worry about updating the array size in the for loop.
int whiteListWordSize = wl.size(); //This variable will monitor the size of our white-list. So in case you add a word to the white-list, you don't need to worry about updating the array size in the for loop.

bool filtering(string word) //this will be our filtering function. We will run our word trough it to try and figure out if it is a swear, or not
{
    for(int i = 0; i < whiteListWordSize; i++) //First for is going trough all the white-listed words. If a word in sentence matched with the word in the white-list, we will automatically skip any other filtering measure and leave the word as it is.
    {
        if(word == wl[i]) return false;
    }
    printf("Nije na whitelisti\n");
    for(int i = 0; i < swearWordSize; i++) //This for loop is going to go trough all of our swear words list. If they match 100%, we will not waste time looking further and will automatically flag them.
    {
        if(word == sw[i]) return true;
    }
    printf("Nije na listi psovki\n");

    for(int i = 0; i < swearWordSize; i++)
    return 0;
}

int main()
{
    //Input
    cout<<"Welcome to Bad Word filtering. Please give us your sentence and we will try to filter the bad words out:"<<endl;
    getline(cin, s);
    for(int i = 0; i < s.size() + 1; i++) //We are using this loop to go trough the sentence
    {
        if(s[i] == ' ' or i == s.size())
        {
            filtering(w);
            cout<<w<<endl;
            w.clear();
        }
        else
        {
            w.push_back(s[i]);
        }
    }
}
