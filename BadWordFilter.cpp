#include <bits/stdc++.h>
using namespace std;
string s, w, swear; //s is our sentence, while w is the word we are looking at
vector <string> sw = {"fuck", "shit", "bitch", "cock", "ass", "bitch", "nigga", "nigger", "fucking", "whore"}; //This is the ugly part of our code.... Writing out all of the common swears, I am sorry!!!
vector <string> wl = {"duck", "ship", "beach", "clock", "bass", "grass", "witch", "pitch", "whole"}; //This is our white-list array. There are lot of swears that look like a swear, with a singular letter changing the meaning. For example, duck. If you would replace the d with f you would get a swear.

int one, m;
int swearWordSize = sw.size(); //This variable will monitor the size of our swear-list. So in case you add a word, you don't need to worry about updating the array size in the for loop.
int whiteListWordSize = wl.size(); //This variable will monitor the size of our white-list. So in case you add a word to the white-list, you don't need to worry about updating the array size in the for loop.

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

    for(int i = 0; i < swearWordSize; i++)
    {
        swear = sw[i];
        one = 100 / sw[i].size();
        m = 0;
        if(word.size() <= swear.size())
        {
            for(int k = 0; k < sw[i].size(); k++)
            {
                if(word[k] == swear[k]) m+=one;
            }
            if(m >= 70) return 1;
        }
    }
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
            if(filtering(w) == false) cout<<w<<" ";
            else
            {
                for(int i = 0; i < w.size(); i++) cout<<"#";
                cout<<" ";
            }

            w.clear();
        }
        else
        {
            w.push_back(s[i]);
        }
    }
}
