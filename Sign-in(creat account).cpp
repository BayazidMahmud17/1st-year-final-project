#include <iostream>
#include <fstream>
using namespace std;

void create()
{
    fstream mobile, name, pass, ac;
    string m,n,p,a;
    mobile.open("Num.txt",ios :: in | ios :: out | ios :: trunc);
    name.open("Name.txt",ios :: in | ios :: out | ios :: trunc);
    pass.open("Pass.txt",ios :: in | ios :: out | ios :: trunc);
    ac.open("Balance.txt",ios :: in | ios :: out | ios :: trunc);
    cout<<"Enter mobile number: ";
    cin>>m;
    mobile<<m;
    cout<<"Enter name: ";
    cin>>n;
    name<<n;
    cout<<"Enter password: ";
    cin>>p;
    pass<<p;
    cout<<"Enter amount of cash-in: ";
    cin>>a;
    ac<<a;
    cout<<"\nAccount created...";
}
int main()
{
    create();
return 0;
}
