#include<iostream>
#include<fstream>
using namespace std;

class Ac
{
    float balance;
    string pass;

    public:
    string num, name;
    Ac()
    {
    ifstream Num, Name, Balance, Pass;
    Num.open("Num.txt");
    Name.open("Name.txt");
    Pass.open("Pass.txt");
    Balance.open("Balance.txt");
     Num>>num;
     Name>>name;
     Pass>>pass;
     Balance>>balance;
    }
    int checkpass(string pas)
    {
       return pas.compare(pass);
    }
    int send(float a)
    {   if(balance>=a)
          {balance-=a;
           set(balance);
           return 0; }
        else
        return 1;
    }
    void set(float b)
    {
        fstream B;
        B.open("Balance.txt",ios :: in | ios :: out | ios :: trunc);
        B<<b;
        cout<<"\nYour current balance is "<<b<<"\n";;
    }
    void setpass()
    {
        string p;
        cout<<"Enter old password: ";
        cin>>p;
        if(checkpass(p)==0)
        {cout<<"\nEnter new password: ";
        cin>>pass;
        fstream Pass;
        Pass.open("Pass.txt,ios :: in | ios :: out | ios :: trunc");
        Pass<<pass;
        cout<<"\nPassword changed successfully!!";}
        else
        cout<<"\nInvalid Password";
    }
    void setname()
    {
        string p;
        cout<<"Enter new name: ";
        cin>>name;
        cout<<"\nEnter password: ";
        cin>>p;
        if(checkpass(p)==0)
        {fstream Name;
        Name.open("Name.txt,ios :: in | ios :: out | ios :: trunc");
        Name<<name;
        cout<<"\nName changed successfully!!";}
        else
        cout<<"\nInvalid Password";

    }
    void showbal()
    {
     cout<<"Your current balance is ";
     cout<<balance<<" Taka";
    }
};

Ac login()
{
    Ac a;
    string P;
    int i;
    cout<<"Mobile: "<<a.num<<"\nPassword: ";
    cin>>P;
    i=a.checkpass(P);
    if(i==0)
    {cout<<"\nLogin sucssesful\n";
    return a;}
    else
     {cout<<"Invalid password";
      cout<<"\nPlease try agin\n";
     login();}
return a;
}
Ac withdraw(Ac a)
{
    float m;
    string P, use;
    cout<<"\nEnter Agent's number: ";
    cin>>use;
    cout<<"\nEnter amount: ";
    cin>>m;
    cout<<"\nEnter password: ";
    cin>>P;
    if(a.checkpass(P)==0)
    {
        if(a.send(m)==0)
    cout<<m<<" taka sent to "<<use;
    else
        cout<<"Insufficient balance";
    }
    else
    {
        cout<<"\nInvalid password\n";
    }
return a;
}
Ac sendmoney(Ac a)
{
    float m;
    string P, use;
    cout<<"\nEnter Account number to send: ";
    cin>>use;
    cout<<"\nEnter amount: ";
    cin>>m;
    cout<<"\nEnter password: ";
    cin>>P;
    if(a.checkpass(P)==0)
    {
       if(a.send(m)==0)
   {cout<<m<<" taka succesafully sent";
    cout<<" to "<<use;}
    else
    cout<<"Insufficiant balance";
    }
    else
    {
        cout<<"\nInvalid password\n";
    }
return a;
}
Ac acmanage(Ac a)
{
    int i;
    cout<<"\n1.Check balance";
    cout<<"\n2.Change name";
    cout<<"\n3.Change password";
    cout<<"\n0.Back to main menu\n";
    cin>>i;
    switch(i)
    {
        case 0: break;
        case 1: a.showbal(); break;
        case 2: a.setname(); break;
        case 3: a.setpass(); break;
   default : cout<<"\nInvalid input";
    }
return a;
}
Ac recharge(Ac a)
{
    float m;
    string P, use;
    cout<<"\nEnter mobile number: ";
    cin>>use;
    cout<<"Enter amount: ";
    cin>>m;
    cout<<"Enter password: ";
    cin>>P;
    if(a.checkpass(P)==0)
    {
       if(a.send(m)==0)
   {cout<<m<<" taka succesafully sent";
    cout<<" to "<<use;}
    else
    cout<<"Insufficiant balance";
    }
    else
    {
        cout<<"\nInvalid password\n";
    }
return a;
}
Ac bill(Ac a)
{
    float m;
    string P, use, less;
cout<<"\nEnter payer's mobile number:";
    cin>>use;
    cout<<"\nEnter biller ID:";
    cin>>less;
    cout<<"\nEnter amount: ";
    cin>>m;
    cout<<"Enter password :";
    cin>>P;
    if(a.checkpass(P)==0)
    {
       if(a.send(m)==0)
  cout<<"\nPaying bill was succesaful";
    else
    cout<<"Insufficiant balance";
    }
    else
    {
        cout<<"\nInvalid password\n";
    }
return a;
}
int main()
{
    Ac a;
    int go;
    a=login();
    cout<<"\n1.Account management";
    cout<<"\n2.Withdraw money";
    cout<<"\n3.Pay Bill";
    cout<<"\n4.Send money";
    cout<<"\n5.Mobile recharge";
    cout<<"\n0.Exit\n";
    cout<<"\nReplay:";
    cin>>go;
    switch(go)
    {
        case 0: break;
        case 1: a=acmanage(a); break;
        case 2: a=withdraw(a); break;
        case 3: a=bill(a); break;
        case 4: a=sendmoney(a);break;
        case 5: a=recharge(a);break;
    default: cout<<"\nInvalid input\n";
    }
return 0;
}

