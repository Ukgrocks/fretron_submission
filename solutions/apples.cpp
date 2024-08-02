//Ram,shyam and rahim went for shopping apple. They bought apple worth
//100 rupees. Ram paid 50 rupees, sham paid 30 rupees and rahim paid 20
//rupees. Each apple is tagged with its weight on it. Write a program to
//distribute apples such that the quantity of apple they get is in best
//proportionate to the amount they paid.

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    vector<pair<int,bool>>apples;
    cout<<"Enter the number of apple you want to: ";
    int n;
    cin>>n;
    int total_weight;
    for(int i=0;i<n;i++){
        cout<<"Enter the weight of apples"<<endl;
        int weight;
        total_weight +=weight;
        cin>>weight;
        pair<int,bool> apple = make_pair(weight,false);
        apples.push_back(apple);
    }
    sort(apples.begin(), apples.end());
    int ram_share = total_weight * 0.5;
    int shyam_share = total_weight * 0.3;
    int rahim_share = total_weight * 0.2;

    vector<int>ram_count; 
    vector<int>shyam_count; 
    vector<int>rahim_count;
    for(int i=0;i<n;i++){
        if(apples[i].first <= ram_share &&!apples[i].second){
            apples[i].second = true;
            ram_share -= apples[i].first;
            ram_count.push_back(apples[i].first);
        }
    }
           for(int i=0;i<n;i++){
        if(apples[i].first <= shyam_share &&!apples[i].second){
            apples[i].second = true;
            shyam_share -= apples[i].first;
            shyam_count.push_back(apples[i].first);
        }
           }
           for(int i=0;i<n;i++){
        if(apples[i].first <= rahim_share &&!apples[i].second){
            apples[i].second = true;
            rahim_share -= apples[i].first;
            rahim_count.push_back(apples[i].first);
        }
       }

    for(int i=0;i<ram_count.size();i++){
    cout<<ram_count[i]<<" ";
    }
    cout<<endl;
  for(int i=0;i<shyam_count.size();i++){
        cout<<shyam_count[i]<<" ";
    }
    cout<<endl;
      for(int i=0;i<rahim_count.size();i++){
        cout<<rahim_count[i]<<" ";
    }
}