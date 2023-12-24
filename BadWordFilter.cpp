#include <bits/stdc++.h>
using namespace std;
string s, w; //s is our sentence, while w is the word we are looking at
string sw[] = {"Fuck", "Shit", "Bitch", "Cock", "Ass", "Bitch", "nigga", "nigger"}; //This is the ugly part of our code.... Writing out all of the common swears, I am sorry!!!
string wl[] = {"Duck", "Ship", "Beach", "Clock", "Bass", "Grass", "Witch", "Pitch", "Grasses"}; //This is our white-list array. There are lot of swears that look like a swear, with a singular letter changing the meaning. For example, duck. If you would replace the d with f you would get a swear.

float m, one; //m stands for "Match". We will use this value to see what is the percentage of match with the word. One stands for "one percent". We will use this value to calculate what is one letter match for each swear word.
int swearWordSize = sizeof(sw); //This variable will monitor the size of our swear-list. So in case you add a word, you don't need to worry about updating the array size in the for loop.
int whiteListWordSize = sizeof(wl); //This variable will monitor the size of our white-list. So in case you add a word to the white-list, you don't need to worry about updating the array size in the for loop.

bool filtering(string word) //this will be our filtering function. We will run our word trough it to try and figure out if it is a swear, or not
{
    for(int i = 0; i < whiteListWordSize; i++) //First for is going trough all the white-listed words. If a word in sentence matched with the word in the white-list, we will automatically skip any other filtering measure and leave the word as it is.
    {
        if(word == wl[i]) return 0;
    }
    for(int i = 0; i < swearWordSize; i++) //This for loop is going to go trough all of our swear words list. If they match 100%, we will not waste time looking further and will automatically flag them.
    {
        if(word == sw[i]) return 1;
    }
    for(int i = 0; i < swearWordSize; i++) //This for loop will go trough our swear words, and check the percentage of what they match. If the word typed is 70% simular to a swear in our swear-list, we will flag it.
    {
        one =  sw[i].size() / 100; //Calculating the percentage of one word match
        string swear = sw[i]; //Setting the word out of our swear-list that we will be checking
        m = 0; //reseting the value
        for(int k = 0; k < word.size(); k++) //We are now going trough every character in the word to check for the match
        {
            if(word[k] == swear[k]) m+=one;
        }
    }
    if(m >= 70.00) return 1;
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
            filtering();
            cout<<w<<endl;
            w.clear();
        }
        else
        {
            w.push_back(s[i]);
        }
    }
}
