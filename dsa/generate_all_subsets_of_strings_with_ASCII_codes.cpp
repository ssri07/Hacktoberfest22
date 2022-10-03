#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

void generateWithASCII(string str, string txt)
{
    if(str.length()==0)
    {
        cout<<txt<<endl;
        return  ;
    }
    char ch = str[0] ; 
    string ros = str.substr(1) ;
    int ascii = str[0] ;
    generateWithASCII(ros,txt) ;
    generateWithASCII(ros,txt+ch) ; 
    generateWithASCII(ros,txt+to_string(ascii));

}

int main()
{
    generateWithASCII("ABC","") ;
}