#include<bits/stdc++.h>

using namespace std;

class customer
{
    string name;
    string ordernames[10];
    int product_codes[10];
    string address;
    int orderCode;
    string orderStatus;
    int bill;
    int i,j,k;
    public:
        friend class revenue;
        customer()
        {

        }
        void setval(string n,string add,int oc,string os,int b)
        {
            name=n;
            address=add;
            orderCode=oc;
            orderStatus=os;
            bill=b;

            int x;
            cout<<"Confirm order numbers:"<<endl;
            cin>>x;


            cin.ignore();
            cout<<"Confirm order name and product code: "<<endl;
            for(int i=0; i<x; i++){
                cin.ignore();
                getline(cin,ordernames[i]);
                cin>>product_codes[i];
            }


        }
    friend class customerManagement;

};

class pets
{   string species;
    string breed;
    int numbers;
    int price;
    int petCode;
public:

    pets()
    {

    }
    void setval1(string s,string br,int number,int p,int pc)
    {
        species=s;
        breed=br;
        numbers=number;
        price=p;
        petCode=pc;
    }
    friend class customerManagement;

};

class Revenue;
class customerManagement
{
    customer customerRecord[10];
    pets pet[10];
    int no_of_customers,no_of_pets,i,j,k;
    public:
        customerManagement()
        {
           no_of_customers=0;
           no_of_pets=0;
        }



    void addnewbreeds()
    {
        int num;
    string n1;
    string br;
    int p;
    int pc;
    int number;


       cout<<"How many breeds do you want to add?"<<endl;
        cin>>num;

        for(i=0;i<num;i++)
        {  cin.ignore();
           cout<<"Enter species name:"<<endl;
           getline(cin,n1);
           cout<<"Enter breed:"<<endl;
           getline(cin,br);
           cout<<"Enter price:"<<endl;
           cin>>p;
           cout<<"Enter number of pets:"<<endl;
           cin>>number;
           cout<<"Enter pet code:"<<endl;
           cin>>pc;
           pet[i+no_of_pets].setval1(n1,br,number,p,pc);}
           no_of_pets=no_of_pets+num;
        }
        void add_to_existing_breed()
        {
           int num;
            string br;
            int p;
            int pc;
            int number;
             cout<<"How many breeds do you want to add?"<<endl;
            cin>>num;
            for(i=0;i<num;i++)
            {   cin.ignore();
                cout<<"Enter "<<i+1<<"th "<<"breed name:"<<endl;
                getline(cin,br);
                cout<<"Enter number of pets you want to add:"<<endl;
                cin>>number;
                for(j=0;j<no_of_pets;j++)
                {if(br==pet[j].breed)
                pet[j].numbers=pet[j].numbers+number;}


            }
        }

        void addcustomer()
        {   int a,b,c,i,j,k;
            string n;
            string on[10];
            int m[10];
            string add;
            int oc;
            string os;
            int bl;

            cout<<"How many customer do you want to add?"<<endl;
            cin>>a;

            for(i=0;i<a;i++)
            {   bl=0;

            cout<<"Enter customer name:"<<endl;
            cin.ignore();
            getline(cin,n);
            cout<<"Enter customer address:"<<endl;
            getline(cin,add);
            cout<<"Enter order code:"<<endl;
            cin>>oc;
            os="Not delivered";
            cout<<"How many orders do you want to add?"<<endl;
            cin>>b;
            cout<<"Enter product codes:"<<endl;
            for(j=0;j<b;j++)
            {
                cin>>m[j];
            }
            for(j=0;j<b;j++)
            {
                for(k=0;k<no_of_pets;k++)
                {
                    if(m[j]==pet[k].petCode)
                        {bl=bl+pet[k].price;

                        pet[k].numbers--;

                        }

                }

            }
            customerRecord[i+no_of_customers].setval(n,add,oc,os,bl);

            }
            no_of_customers=no_of_customers+a;
        }




    void displayallpets()
    {
        for(i=0;i<no_of_pets;i++){
            cout<<"----------------------------***----------------------------"<<endl;
            cout<<"Species name:  "<<pet[i].species<<endl<<"Breed: "<<pet[i].breed<<endl<<"Price: "<<pet[i].price<<endl<<"Pet Code: "<<pet[i].petCode<<endl<<"Pet Number: "<<pet[i].numbers<<endl;
            cout<<"----------------------------***----------------------------"<<endl;
        }

    }



    void dis(int code){
        for(int i=0; i<10; i++){
            if(customerRecord[i].orderCode==code){

                cout<<"order Code: "<<code<<endl;
                cout<<"Name: "<<customerRecord[i].name<<endl;
                cout<<"Product Code--------------Order Name"<<endl;
                for(int j=0; j<no_of_customers; j++){
                    if(customerRecord[i].product_codes[j]==0){
                        break;
                    }
                    else{
                        cout<<customerRecord[i].product_codes[j]<<"--------------------"<<customerRecord[i].ordernames[j]<<endl;
                    }
                }
                cout<<"Address: "<<customerRecord[i].address<<endl;
                cout<<"Order Status: "<<customerRecord[i].orderStatus<<endl;
                cout<<"Bill: "<<customerRecord[i].bill<<endl;
            }
        }
    }




    friend class revenue;


};
class revenue
{
    int profit;
    public:
        revenue()
        {
            profit=0;
        }
     int getrev(customerManagement m1)
    {

        for(int i=0;i<m1.no_of_customers;i++)
        profit=profit+m1.customerRecord[i].bill;
        return profit;
    }
    friend class customerManagement;

};
int main()
{   int code;
    customerManagement m1;
    revenue r1;
    int choice;
    do{
    cout<<"1.Add new breeds"<<endl;
    cout<<"2.Add to existing breeds"<<endl;
    cout<<"3.Add new customers"<<endl;
    cout<<"4.Search customer"<<endl;
    cout<<"5.Display all available pets"<<endl;
    cout<<"6.See total sold amount"<<endl;
    cout<<"7.exit"<<endl;
    cout<<"Choose one:"<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1:
        m1.addnewbreeds();
        break;
        case 2:
            m1.add_to_existing_breed();
            break;
        case 3:
            m1.addcustomer();
            break;
        case 4:
            cout<<"input order code to search"<<endl;
            cin>>code;
            m1.dis(code);
            break;
        case 5:
            m1.displayallpets();
            break;
        case 6:
            cout<<r1.getrev(m1)<<endl;
            break;
        case 7:
            return 0;

    }

    }while(1);

   return 0;
}
