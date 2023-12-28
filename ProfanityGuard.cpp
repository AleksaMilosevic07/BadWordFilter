#include <bits/stdc++.h>
using namespace std;
string s, w, swear; //s is our sentence, while w is the word we are looking at
vector <string> sw = {"fuck", "shit", "bitch", "cock", "ass", "bitch", "nigga", "nigger", "fucking", "whore"}; //This is the ugly part of our code, add any word you want to block.
vector <string> wl = {"duck", "ship", "beach", "clock", "bass", "grass", "witch", "pitch", "whole"}; //This is our white-list. All words here will be ignored by the filter. Add the words you want to allow

int one, m; //m stands for match, one stands for the percentage of what one letter match is
int swearWordSize = sw.size(); //This two variable monitor the sizes of the vectors so you don't have to.
int whiteListWordSize = wl.size();

bool filtering(string word) //this will be our filtering function. We will run our word trough it to try and figure out if it is a swear, or not
{
    for(int i = 0; i < whiteListWordSize; i++) //First for is going trough all the white-listed words.
    {
        if(word == wl[i]) return 0;
    }

    for(int i = 0; i < swearWordSize; i++) //This for loop is going to go trough all of our swear words list.
    {
        if(word == sw[i]) return 1;
    }

    for(int i = 0; i < swearWordSize; i++) //This for loop is going to check how closely does the word resemble a swear.
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
        if(s[i] == ' ' or i == s.size()) //If you get to the end of the word...
        {
            if(filtering(w) == false) cout<<w<<" "; //If it is not a swear, type it out.
            else
            {
                for(int i = 0; i < w.size(); i++) cout<<"#"; //If the word is a swear, filter it.
                cout<<" ";
            }
            w.clear(); //Clear the string
        }
        else
        {
            w.push_back(s[i]);
        }
    }
}
