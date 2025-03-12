#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string a ;
    cin>>a;
    string output;
    for(int i=0;i<a.length();i++){
        if(a[i]=='p'){
           output.push_back(q); 
        }
        else if(a[i]=='q'){
            output = 'p';
        }
        else if (a[i]=='w'){
            output = 'w';
        }
    }
cout<<output;
return 0;
}