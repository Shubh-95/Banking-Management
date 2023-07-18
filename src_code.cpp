#include <bits/stdc++.h>

using namespace std;
vector<string> s = {"indian bank", "andra bank", "SBI", "HDFC", "canra bank"};
class bank
{
   
   public:
   

    static void addbank()
    {
        string x;
        cin>>x;
        s.push_back(x);
    }
   
};

class account
{
   string bankname;
   string name;
   int account_no;
   int password;
   int balance=0;
   public:
   void selectbank(int n)
   {
       for(int i=0;i<s.size();i++)
       {
           if(i+1==n)
           {
              bankname=s[i];
           }
       }
   }
   void details()
   {
       cout<<"enter your name"<<endl;
       cin>>name;
       cout<<"enter your account_no"<<endl;
       cin>>account_no;
       cout<<"make a strong password"<<endl;
       cin>>password;
       cout<<"your current balance is 0 rs"<<endl;
   }
   void dispaly()
   {
       cout<<"the name is "<<name;
       cout<<"your account_no is"<<account_no;
       cout<<"your balance is"<<balance<<endl;
   }
   friend void deposite(vector<account> &v,int amount,int pass);
   friend void withdrawal(vector<account> &v,int amount,int pass);
   friend void accountdisplay(vector<account> &v,int pass);
   
};
void deposite(vector<account> &v,int ammount,int pass)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i].password==pass)
        {
            v[i].balance+=ammount;
            cout<<v[i].balance<<endl;
            break;
        }
    }
    
}
void withdrawal(vector<account> &v,int amount,int pass)
{
    for(int i=0;i<v.size();i++)
    {
        
        if(v[i].password==pass)
        {
            if(v[i].balance<amount)
            {
                cout<<"insuficient balance"<<endl;
                break;
            }
            else
            {
                v[i].balance=v[i].balance-amount;
                cout<<v[i].balance<<endl;
                break;
            }
        }
    }
}
void accountdisplay(vector<account> &v,int pass)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i].password==pass)
        {
            v[i].dispaly();
            break;
        }
    }
}
int main()
{
   bool m=true;
   vector<account> v;
   while(m==true)
   {
       int select;
       cin>>select;
       if(select==1)
       {
           bank::addbank();
       }
       if(select==2)
       {
           
           for(int i=0;i<s.size();i++)
           {
               cout<<"enter "<<i+1<<" for selecting "<<s[i]<<" bank ";
           }
           int bankselect;
           cin>>bankselect;
           account obj;
           obj.selectbank(bankselect);
           obj.details();
           v.push_back(obj);
           
       }
       if(select==3)
       {
           int pass;
           cin>>pass;
           int amount;
           cin>>amount;
           deposite(v,amount,pass);
       }
        if(select==4)
       {
           int pass;
           cin>>pass;
           int amount;
           cin>>amount;
            withdrawal(v,amount,pass);
       }
        if(select==5)
       {
           int pass;
           cin>>pass;
           
           accountdisplay(v,pass);
       }
       if(select==6)
       {
           m=false;
       }
       
   }
   return 0;
}
