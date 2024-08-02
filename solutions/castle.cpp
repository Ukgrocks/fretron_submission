#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void find_home_path(vector<pair<int,int>>& answer, vector<vector<char>>& boards, pair<int,int>castle, pair<int,int> home)
{
if(castle.first<0 or castle.first>7 or castle.second<0 or castle.second>7)
{
    return;
}
if(castle.first==home.first and castle.second==home.second) //checking if current position is home
{
    answer.push_back(make_pair(castle.first,castle.second));
    return;
}
if(boards[castle.first][castle.second]=='S') //checking if current position has soldier
{
    boards[castle.first][castle.second]=' ';
    castle.first=castle.first-1;
    castle.second=castle.second;
    find_home_path(answer,boards,castle,home); //moving to the left after killing soldier
}

pair<int,int> o = make_pair(castle.first,castle.second+1); //moving front normally
find_home_path(answer,boards,o,home); //moving to the front
}
int main(){
    vector<vector<char>>boards(8,vector<char>(8)); //making the board array
    int n;
    cout<<"Enter number of soldiers: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cout<<"Enter the position of soldier "<<i+1<<" (x,y): ";
        cin>>x>>y;
        if(x>7 and y>7 and x<0 and y<0){
            cout<<"Wrong coordinates";
            exit(0);
        }
        boards[x][y] = 'S';
        
    
}
cout<<"Enter position of castle: "<<endl;
int x,y;
cin>>x>>y;
boards[x][y] = 'C';
pair<int,int>castle_position = make_pair(x,y);

cout<<"Enter position of Home: "<<endl;
int a,b;
cin>>a>>b;
boards[a][b] = 'H';
pair<int,int>home= make_pair(a,b);

vector<pair<int,int>> answer;
find_home_path(answer,boards,castle_position,home);

}