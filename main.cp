//
//  main.cpp
//  KMP
//  Copyright (c) 2017  All rights reserved.
//


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <numeric>
#include <map>
#include <string>

using namespace std;

// lock first, add layer
//lock second, add layer
//lock n-1, add layer
// print permutation
//fall back to n-1 locks, how many left to swap? if none fall back
//else go forward again with switch


vector<char>alphabet = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};


map<string, vector<int>> kmpTable(map<string, vector<int>>&Arrangements){
    
    
    for(int i = 0; i != Arrangements.size();++i){
        map<string, vector<int>>::iterator Combi = Arrangements.begin();
        advance(Combi, i);
        cout << " WE ON THIS PNE " << Combi->first << endl;
        string combi = Combi->first;
        int len = 0;
        int t = 1;
        Combi->second.push_back(0);
        while(t < combi.size()){
            if(combi[t] == combi[len]){
                len++;
                Combi->second.push_back(len);
                t++;
            }
            else{
                if(len != 0){
                    len = Combi->second[len-1];
                }
                else{
                    Combi->second.push_back(0);
                    t++;
                }
                
                
            }
            
        }
        
        
    }
    return Arrangements;
    
}






void permutations(vector<int>instancesOfLetter, vector<char>FillMe, map<string, vector<int>>&Combinations){
    static int amount = accumulate(instancesOfLetter.begin(), instancesOfLetter.end(), 0);
    if(FillMe.size() == amount){
        string Combi(FillMe.begin(), FillMe.end());
        Combinations.insert(make_pair(Combi, vector<int>(0)));
    }
    
    for(int i = 0; i != instancesOfLetter.size(); ++i){
        if(instancesOfLetter[i] > 0){
            FillMe.push_back(alphabet[i]);
            instancesOfLetter[i] -= 1;
            permutations(instancesOfLetter,FillMe, Combinations);
            instancesOfLetter[i] += 1;
            FillMe.pop_back();
        }
        
    }
    
}








vector<int> lexico(vector<int>& order){
    
    int largi = 0;
    int largy = 0;
    
    for(int s = 0; s != 3; ++s){
        if (order[s] < order[s+1]){
            largi = s;
        }
    }
    
    for(int p = largi+1; p < 4 ; ++p){
        if(order[largi] < order[p]){
            largy = p;
        }
    }
    
    auto it = next(order.begin(), largi);
    auto pt = next(order.begin(), largy);
    
    reverse(it, pt+1);
    return order;
}



int main() {
    vector<int>instances;
    map<string, vector<int>> Combinations;
    vector<char>FillThis;
    
    for(int inst = 0; inst != 25; ++inst){
        int amount;
        cin >> amount;
        instances.push_back(amount);
    }
    
    permutations(instances, FillThis,Combinations);
   
    for(auto& combi : Combinations){
        cout << combi.first << " ";
        cout << endl;
    }
    
    
    map<string, vector<int>> woo = kmpTable(Combinations);
    
    for(auto& combi : Combinations){
        cout << combi.first << " ";
        for(auto & u : combi.second){
            cout << u << " ";
        }
        cout << endl;
    }
    
    
    //find smallest kmp 
    
    
    return 0;
}










