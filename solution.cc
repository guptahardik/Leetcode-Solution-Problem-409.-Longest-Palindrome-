#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;


class Solution {
public:
    int longestPalindrome(string s) {
        int plength = 0;
        
        map<char, int> tracker;
        map<char,int>::iterator it;
        for(std::string::size_type i = 0; i<s.size(); i++){
            it = tracker.find(s[i]);
            if(it != tracker.end()){
                tracker[s[i]]++;
            }else{
                tracker.insert({s[i],1});
            }
        }
        for (it=tracker.begin(); it!=tracker.end(); ++it){
            plength = plength +  ((it->second/2)*2);
            if (plength % 2 == 0 && it->second % 2 == 1)
                plength++;
        }
        return plength;
    }
};
