#include<bits/stdc++.h>
#include<sys/stat.h>
using namespace std;

class Shop                              //ancestor class of the diamond problem
{
public:
    string name,address;
    float ratings;
    int clos_time,shoptag;

    void Setval()
    {
        string m,a;
        float r;
        int c,t;
        cout<<"Enter Details--tag , name , address , closing time and ratings:\n";
        cin>>t>>m>>a>>c>>r;
        name=m;
        address=a;
        ratings=r;
        clos_time=c ;
        shoptag=t;
    }
};

class CakeShop : virtual public Shop       //intermediate class of the diamond problem
{
public:
    void CreateMap();
    void ShowMap();
};
class CoffeeShop : virtual public Shop     //intermediate class of the diamond problem
{
public:
    void CreateMap();
    void ShowMap();
};

void CoffeeShop :: CreateMap()
{
    fstream fout;
    fout.open("CoffeeMap.csv",ios::out | ios::app);
    cout<<"Enter no of coffee shops you would like to add:";
    int n,i;
    cin>>n;
    for(i=0; i<n; i++)
    {
        Setval();
        fout <<1<<", " <<shoptag<< ", " << name << ", "<< address << ", "<< ratings << ", "<< clos_time<<endl;
    }
    fout.close();
}
void CoffeeShop :: ShowMap()
{
    fstream fin;
    fin.open("CoffeeMap.csv",ios::in);
    vector<string>row;
    string line, word, temp,l;
    double r;
    int i=1;
    cout<<"Name of Shop\tAddress\tRatings\tClosing Time\n";
    while(fin>>temp)
    {
        row.clear();
        getline(fin,line);
        stringstream s(line);

        while(getline(s,word,','))
        {
            row.push_back(word);
        }
        l=row[3].substr(1,row[3].size()-1);
        r=atof(l.c_str());
        cout << "Details of Shops " << row[0] << " : \n";

        cout << row[1] << "\t";
        cout << row[2] << "\t";
        cout <<  r << "\t";
        cout <<row[4] << "\n";
        i++;
    }
    fin.close();
}

void CakeShop :: CreateMap()
{
    fstream fout;
    fout.open("CakeMap.csv",ios::out | ios::app);
    cout<<"Enter no of cake & pastry shops you would like to add:";
    int n,i;
    cin>>n;
    for(i=0; i<n; i++)
    {
        Setval();
        fout <<1<<", " <<shoptag<< ", " << name << ", "<< address << ", " << ratings << ", "<< clos_time<<endl;
    }
    fout.close();
}
void CakeShop :: ShowMap()
{
    fstream fin;
    fin.open("CakeMap.csv",ios::in);
    vector<string>row;
    string line, word, temp;
    float r;
    int i=1;
    cout<<"Name of Shop\tAddress\tRatings\tClosing Time\n";
    while(fin>>temp)
    {
        row.clear();
        getline(fin,line);
        stringstream s(line);

        while(getline(s,word,','))
        {
            row.push_back(word);
        }
        r=atof(row[3].substr(1,row[3].size()-1).c_str());
        cout << "Details of Shops " << row[0] << " : \n";

        cout << row[1] << "\t";
        cout << row[2] << "\t";
        cout <<  r << "\t";
        cout <<row[4] << "\n";
        i++;
    }
    fin.close();
}


class Admin : public CakeShop, public CoffeeShop        //Derived class of the diamond problem
{
public:
    void CreateAdmin();
    void ShowAdmin();
    bool AdValidity();
    void CreateMem();
    void ShowMem();
    void CreateMenu();
};

void Admin :: CreateAdmin()
{
    fstream fout;
    fout.open("Admin.csv",ios::out | ios::app);
    cout<<"Enter details of Admins:name,admin_id,password:"<<endl;
    string name,admin_id,password;
    int i=1,ini=1;
    while(i)
    {
        cin>>name>>admin_id>>password;
        fout <<ini<< ", " << name << ", "<< admin_id << ", "<< password <<endl;
        ini++;
        cout<<"Do you want another Admin? Press 1 for YES and 0 for NO."<<endl;
        cin>>i;
    }
    fout.close();
}
void Admin :: ShowAdmin()
{
    fstream fin;
    fin.open("Admin.csv",ios::in);
    vector<string>row;
    string line, word, temp;
    int i=1;
    while(fin>>temp)
    {
        row.clear();
        getline(fin,line);
        stringstream s(line);

        while(getline(s,word,','))
        {
            row.push_back(word);
        }
        cout << "Details of Admins " << i << " : \n";
        cout << "Name:" << row[0] << "\n";
        cout << "Admin Id:" << row[1] << "\n";
        cout << "Password:" << row[2] << "\n";
        i++;
    }
    fin.close();
}
bool Admin :: AdValidity()
{
    ifstream fin;
    fin.open("Admin.csv",ios::in);
    string a,b;
    cout<<"Enter Admin Id:";
    cin>>a;
    cout<<"Enter Admin Password:";
    cin>>b;
    int flag = 0;
    bool valid;
    vector<string> row;
    string line, word, temp;
    while (fin>>temp)
    {
        row.clear();
        getline(fin, line);
        stringstream s(line);

        while (getline(s,word,','))
        {
            row.push_back(word);
        }
        if ((row[1].substr(1,row[1].size()-1) == a) && (row[2].substr(1,row[2].size()-1) == b))
        {
            flag = 1;
            valid=true;
            break;
        }
    }
    if (flag == 0)
    {
        valid=false;
    }
    return valid;
}
void Admin :: CreateMem()
{
    fstream fout;
    fout.open("Member.csv",ios::out | ios::app);
    int n;
    cout<<"Enter number of members:";
    cin>>n;
    cout<<"Enter details of members:name,userid,password,balance,address,customer_type"<<endl;
    int i,j,balance;
    string name,userid,password,address,customer_type;
    for (i = 0; i < n; i++)
    {

        cin >> name >> userid >> password >> balance >> address >>customer_type;


        fout <<1<< ", " << name << ", "
             << userid << ", "
             << password << ", "
             << balance << ", "
             << address << ", "
             <<customer_type<< "\n";
    }
    fout.close();
}
void Admin :: ShowMem()
{
    cout<<"Displaying Member Details:\n";
    fstream fin;
    fin.open("Member.csv",ios::in);
    vector<string>row;
    string line, word,temp;
    int i=1;
    cout<<"Name\tUser ID\tPassword\tBalance\tAddress\tCustomer Type\n";
    while(fin>>temp)
    {
        row.clear();
        getline(fin,line);
        stringstream s(line);

        while(getline(s,word,','))
        {
            row.push_back(word);
        }
        cout << "\nDetails of member " << i << " : \n";

        cout << row[0] << "\t";
        cout << row[1] << "\t";
        cout << row[2] << "\t";
        cout << row[3] << "\t";
        cout << row[4] << "\t";
        cout << row[5] << "\t";
        i++;
    }

    fin.close();
}
void Admin :: CreateMenu()
{
    cout<<"Create Menu for the Coffee Shops:\n";
    cout<<"Barista:\n";
    fstream fout;
    fout.open("Barista.csv",ios::out | ios::app);
    int i,n;
    cout<<"Enter number of items:";
    cin>>n;
    cout<<"Enter details:item tag , item name , price:\n"<<endl;
    int tag,price;
    string name;
    for (i = 0; i < n; i++)
    {

        cin >> tag >> name >> price ;


        fout <<1<< ", " << tag << ", "
             << name << ", "
             << price << "\n";
    }
    fout.close();
    cout<<"North End:\n";
    fstream f1out;
    f1out.open("NorthEnd.csv",ios::out | ios::app);
    cout<<"Enter number of items:";
    cin>>n;
    cout<<"Enter details:item tag , item name , price:\n"<<endl;
    for (i = 0; i < n; i++)
    {

        cin >> tag >> name >> price ;


        f1out <<1<< ", " << tag << ", "
              << name << ", "
              << price << "\n";
    }
    f1out.close();
    cout<<"Jhonny Rockets:\n";
    fstream f2out;
    f2out.open("JhonnyRockets.csv",ios::out | ios::app);
    cout<<"Enter number of items:";
    cin>>n;
    cout<<"Enter details:item tag , item name , price:\n"<<endl;
    for (i = 0; i < n; i++)
    {

        cin >> tag >> name >> price ;


        f2out <<1<< ", " << tag << ", "
              << name << ", "
              << price << "\n";
    }
    f2out.close();
    cout<<"Coffee Zone:\n";
    fstream f3out;
    f3out.open("CoffeeZone.csv",ios::out | ios::app);
    cout<<"Enter number of items:";
    cin>>n;
    cout<<"Enter details:item tag , item name , price:\n"<<endl;
    for (i = 0; i < n; i++)
    {

        cin >> tag >> name >> price ;


        f3out <<1<< ", " << tag << ", "
              << name << ", "
              << price << "\n";
    }
    f3out.close();
    cout<<"Extremely Espresso:\n";
    fstream f4out;
    f4out.open("ExtremelyEspresso.csv",ios::out | ios::app);
    cout<<"Enter number of items:";
    cin>>n;
    cout<<"Enter details:item tag , item name , price:\n"<<endl;
    for (i = 0; i < n; i++)
    {

        cin >> tag >> name >> price ;


        f4out <<1<< ", " << tag << ", "
              << name << ", "
              << price << "\n";
    }
    f4out.close();
    cout<<"Create Menu for the Cake Shops:\n";
    cout<<"Coopers:\n";
    fstream f5out;
    f5out.open("Coopers.csv",ios::out | ios::app);
    cout<<"Enter number of items:";
    cin>>n;
    cout<<"Enter details:item tag , item name , price:\n"<<endl;
    for (i = 0; i < n; i++)
    {

        cin >> tag >> name >> price ;


        f5out <<1<< ", " << tag << ", "
              << name << ", "
              << price << "\n";
    }
    f5out.close();
    cout<<"Mr.Baker:\n";
    fstream f6out;
    f6out.open("Mr.Baker.csv",ios::out | ios::app);
    cout<<"Enter number of items:";
    cin>>n;
    cout<<"Enter details:item tag , item name , price:\n"<<endl;
    for (i = 0; i < n; i++)
    {

        cin >> tag >> name >> price ;


        f6out <<1<< ", " << tag << ", "
              << name << ", "
              << price << "\n";
    }
    f6out.close();
    cout<<"Kings:\n";
    fstream f7out;
    f7out.open("Kings.csv",ios::out | ios::app);
    cout<<"Enter number of items:";
    cin>>n;
    cout<<"Enter details:item tag , item name , price:\n"<<endl;
    for (i = 0; i < n; i++)
    {

        cin >> tag >> name >> price ;


        f7out <<1<< ", " << tag << ", "
              << name << ", "
              << price << "\n";
    }
    f7out.close();
    cout<<"Hot Cake:\n";
    fstream f8out;
    f8out.open("HotCake.csv",ios::out | ios::app);
    cout<<"Enter number of items:";
    cin>>n;
    cout<<"Enter details:item tag , item name , price:\n"<<endl;
    for (i = 0; i < n; i++)
    {

        cin >> tag >> name >> price ;


        f8out <<1<< ", " << tag << ", "
              << name << ", "
              << price << "\n";
    }
    f8out.close();
    cout<<"Ajwah:\n";
    fstream f9out;
    f9out.open("Ajwah.csv",ios::out | ios::app);
    cout<<"Enter number of items:";
    cin>>n;
    cout<<"Enter details:item tag , item name , price:\n"<<endl;
    for (i = 0; i < n; i++)
    {

        cin >> tag >> name >> price ;


        f9out <<1<< ", " << tag << ", "
              << name << ", "
              << price << "\n";
    }
    f9out.close();
}

class Item
{
public:
    string i_name;
    int price;
    Item(string n="",int p=0)
    {
        i_name=n;
        price=p;
    }
    int operator + (Item I2)                     //member function operator overload
    {
        int tot;
        tot=price+I2.price;
        return tot;
    }
    friend int operator + (int i, Item I2);     //friend function and operator overload
};

int operator + (int i, Item I2)
{
    int tot;
    tot=i+I2.price;
    return tot;
}

class CoffeeMenu
{
public:
    int virtual ShowMenu();                 //virtual function used for runtime polymorphism
};

int CoffeeMenu :: ShowMenu()
{
    int n,p,choose=1,expense=0;
    vector<Item>cart;                       //had-a-relation  Item is another class type and we have used an Item type vector
    vector<string>row;
    vector<Item>foodlist;
    string line, word, temp,l;
    int r;
    int i;
    while(choose)
    {
        cout<<"Enter the code of the coffee shop whose menu you would like to check.\n1. Barista\n2. Mr. North end\n3. Johnny Rockets\n4. Coffee Zone\n5. Extremely Espresso\n";
        cin>>n;
        fstream fin;

        if(n==1)
            fin.open("Barista.csv",ios::in);
        else if(n==2)
            fin.open("NorthEnd.csv",ios::in);
        else if(n==3)
            fin.open("JhonnyRockets.csv",ios::in);
        else if(n==4)
            fin.open("CoffeeZone.csv",ios::in);
        else if(n==5)
            fin.open("ExtremelyEspresso.csv",ios::in);
        i=1;
        cout<<"Item Code\tItem Name\tPrice\n";
        while(fin>>temp)
        {
            row.clear();
            getline(fin,line);
            stringstream s(line);

            while(getline(s,word,','))
            {
                row.push_back(word);
            }

            l=row[2].substr(1,row[2].size()-1);
            r=atoi(l.c_str());

            foodlist.push_back(Item(row[1].substr(1,row[1].size()-1),r));

            cout <<  row[0] << " :\t";
            cout <<  row[1] << "\t";
            cout <<  row[2] << "\n";
            i++;
        }
        fin.close();

        cout<<"Enter the item code that you want to purchase. If there is none press 0.\n";
        cin>>p;
        while(p!=0)
        {
            cart.push_back(foodlist[p-1]);
            expense=expense+foodlist[p-1];
            cout<<"To add more items in the cart press item code.Else press 0.\n";
            cin>>p;
        }
        foodlist.clear();
        cout<<"Would you like to add more items in the cart from another shop?\nIf yes press 1 ,else press 0.\n";
        cin>>choose;
        system("CLS");
    }
    cout<<"The list of your purchased items are:\n";
    for(int i=1; i<=cart.size(); i++)
    {
        cout<<i<<". "<<cart[i-1].i_name<<"  "<<cart[i-1].price<<" taka.\n";
    }
    cout<<"Total price: "<<expense<<" taka.\n";
    return expense;
}

class CakeMenu : public CoffeeMenu
{
public:
    int ShowMenu();
};

int CakeMenu :: ShowMenu()
{
    int n,p,choose=1,expense=0;
    vector<Item>cart;
    vector<string>row;
    vector<Item>foodlist;
    string line, word, temp,l;
    int r;
    int i;
    while(choose)
    {
        cout<<"Enter the code of the cake shop whose menu you would like to check.\n1. Coopers\n2. Mr. Baker\n3. Kings\n4. Hot Cake\n5. Ajwah\n";
        cin>>n;
        fstream fin;

        if(n==1)
            fin.open("Coopers.csv",ios::in);
        else if(n==2)
            fin.open("Mr.Baker.csv",ios::in);
        else if(n==3)
            fin.open("Kings.csv",ios::in);
        else if(n==4)
            fin.open("HotCake.csv",ios::in);
        else if(n==5)
            fin.open("Ajwah.csv",ios::in);
        i=1;
        cout<<"Item Code\tItem Name\tPrice\n";
        while(fin>>temp)
        {
            row.clear();
            getline(fin,line);
            stringstream s(line);

            while(getline(s,word,','))
            {
                row.push_back(word);
            }

            l=row[2].substr(1,row[2].size()-1);
            r=atoi(l.c_str());

            foodlist.push_back(Item(row[1].substr(1,row[1].size()-1),r));

            cout <<  row[0] << " :\t";
            cout <<  row[1] << "\t";
            cout <<  row[2] << "\n";
            i++;
        }
        fin.close();

        cout<<"Enter the item code that you want to purchase. If there is none press 0.\n";
        cin>>p;
        while(p!=0)
        {
            cart.push_back(foodlist[p-1]);
            expense=expense+foodlist[p-1];
            cout<<"To add more items in the cart press item code.Else press 0.\n";
            cin>>p;
        }
        foodlist.clear();

        cout<<"Would you like to add more items in the cart?\nIf yes press 1 ,else press 0.\n";
        cin>>choose;
        system("CLS");
    }
    cout<<"The list of your purchased items are:\n";
    for(int i=1; i<=cart.size(); i++)
    {
        cout<<i<<". "<<cart[i-1].i_name<<"  "<<cart[i-1].price<<" taka.\n";
    }
    cout<<"Total price: "<<expense<<" taka.\n";
    return expense;
}


class Member
{
private:
    string mId,mPass;
    int mB;
public:
    Member() {};                        //constructor
    ~Member() {};                       //destructor
    string getId()
    {
        return mId;
    }
    string getPass()
    {
        return mPass;
    }
    int getbalance(string muserid,string mpass);
    bool mValid;
    bool MemLogin();
    void MemSignup();
    void UpMem(string muserid, string mpass, int nbalance);
    friend class Admin;
};

int Member :: getbalance(string muserid,string mpass)
{
    ifstream fin;
    fin.open("Member.csv",ios::in);
    int flag = 0;
    vector<string> row;
    string line, word, temp;
    while (fin>>temp)
    {
        row.clear();
        getline(fin, line);
        stringstream s(line);

        while (getline(s,word,','))
        {
            row.push_back(word);
        }
        if ((row[1].substr(1,row[1].size()-1) == muserid) && (row[2].substr(1,row[2].size()-1) == mpass))
        {
            flag = 1;
            mB=atoi(row[3].c_str());
            break;

        }
    }
    if (flag == 0)
    {
        return 0;
    }
    return mB;
}
bool Member :: MemLogin()
{
    ifstream fin;
    fin.open("Member.csv",ios::in);
    string a,b;
    cout<<"Enter User Id:";
    cin>>a;
    cout<<"Enter Password:";
    cin>>b;
    int flag = 0;
    bool valid;
    vector<string> row;
    string line, word, temp;
    while (fin>>temp)
    {
        row.clear();
        getline(fin, line);
        stringstream s(line);

        while (getline(s,word,','))
        {
            row.push_back(word);
        }
        if ((row[1].substr(1,row[1].size()-1) == a) && (row[2].substr(1,row[2].size()-1) == b))
        {
            flag = 1;
            valid=true;
            mId=a;
            mPass=b;
            mB=atoi(row[3].substr(1,row[3].size()-1).c_str());
            break;

        }
    }
    if (flag == 0)
    {
        valid=false;

    }
    return valid;
}
void Member :: MemSignup()
{
    fstream fout;
    fout.open("Member.csv",ios::out | ios::app);
    cout<<"Enter details:"<<endl;
    int i,j,balance;
    string name,userid,password,address,customer_type;
    cout<<"Enter Name:";
    cin >> name ;
    cout<<"\nEnter User Id:";
    cin >> userid ;
    mId=userid;
    cout<<"\nEnter Password:";
    cin >> password ;
    mPass=password;
    cout<<"\nEnter Address:";
    cin >> address ;
    cout<<"\nEnter Balance:";
    cin >> balance ;
    mB=balance;

    fout <<1<< ", " << name << ", "
         << userid << ", "
         << password << ", "
         << balance << ", "
         << address << ", "
         <<"New"<< "\n";
    fout.close();
}
void Member :: UpMem(string muserid, string mpass, int nbalance)
{
    fstream fin, fout;
    fin.open("Member.csv", ios::in);

    fout.open("Membernew.csv", ios::out | ios::app);

    int  count = 0, i,balance;
    string name, memid, mempass;
    int index;
    string line, word;
    vector<string> row;
    index=4;
    while (!fin.eof())
    {

        row.clear();

        getline(fin, line);
        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        memid=row[2].substr(1,row[2].size()-1);
        mempass=row[3].substr(1,row[3].size()-1);
        int row_size = row.size();
        if (memid == muserid &&  mempass == mpass)
        {
            count = 1;
            stringstream convert;
            convert << nbalance;

            row[index] = convert.str();

            if (!fin.eof())
            {
                for (i = 0; i < row_size - 1; i++)
                {
                    fout << row[i] << ",";
                }

                fout << row[row_size - 1] << "\n";
            }
        }
        else
        {
            if (!fin.eof())
            {
                for (i = 0; i < row_size - 1; i++)
                {

                    fout << row[i] << ",";
                }
                fout << row[row_size - 1] << "\n";
            }
        }
        if (fin.eof())
            break;
    }
    if (count == 0)
        cout << "Record not found\n";

    fin.close();
    fout.close();
    mB=nbalance;
    remove("Member.csv");
    rename("Membernew.csv", "Member.csv");
}

void Choice(Admin A,Member M,CoffeeMenu C,CakeMenu K,CoffeeMenu *pc)
{

    cout<<"Would You Like to See the Locations of the Coffee Shops or Cake & Pastry Shops?\nPress 1 for Coffee Shops.\nPress 2 for Cake & Pastry Shops.\n";
    int x,y,ek=0,ec=0,total=0;
    cin>>x;
    if(x==1)
    {
        A.CoffeeShop::ShowMap();
        system("pause");
        system("CLS");
        cout<<"To See the Menu Press 1.\n";
        pc=&C;                                          //runtime polymorphism
        cin>>y;
        if(y==1)
            ec=pc->ShowMenu();
        cout<<"If You would Like to See the Location of the Cake & Pastry Shops as well Press 2, else Press 0.\n";
        cin>>x;
    }
    system("CLS");
    if(x==2)
    {
        A.CakeShop::ShowMap();
        system("pause");
        system("CLS");
        //
        cout<<"To See the Menu Press 1.\n";
        pc=&K;                                          //runtime polymorphism
        cin>>y;
        if(y==1)
            ek=pc->ShowMenu();
        cout<<"If You would Like to See the Location of the Coffee Shops as well Press 1, else Press 0.\n";
        cin>>x;
    }
    system("CLS");
    if(x==1)
    {
        A.CoffeeShop::ShowMap();
        system("pause");
        system("CLS");
        cout<<"To See the Menu Press 1.\n";
        pc=&C;
        cin>>y;
        if(y==1)
            ec=pc->ShowMenu();
    }
    total=ec+ek;
    cout<<"Your Total Bill is "<<total<<" taka.\n";
    if(M.getbalance(M.getId(),M.getPass())<total)
    {
        cout<<"You Don't have Sufficient Balance.\nTo Add Balance Press y.\nTo Discard Order Press n.\n";
        char v;
        cin>>v;
        if(v=='y')
        {
            cout<<"Enter New Balance:";
            int w;
            cin>>w;
            M.UpMem(M.getId(),M.getPass(),w);
        }
    }
    M.UpMem(M.getId(),M.getPass(),M.getbalance(M.getId(),M.getPass())-total);
    cout<<"Successfully Purchased.\Thank You.\n";
}

int main()
{

    Admin A;
    Member M;
    CoffeeMenu *pc,C;
    CakeMenu K;

    string MiD,MpASS;
    cout<<"For Admin Panel Press 1, For User Panel Press 2\n";
    int panel,u;
    cin>>panel;
    if(panel==1)
    {
        if(A.AdValidity())
        {
            cout<<"Welcome Admin.\n";
            int yn=1;
            while(yn==1)
            {
                cout<<"\n\nPress 1 to Add More Admin\nPress 2 to See Admin List\nPress 3 to Create User\n";
                cout<<"Press 4 to See User List\nPress 5 to Create the Map for Coffee Shops\nPress 6 to Create the Map for Cake Shops\n";
                cout<<"Press 7 to Create the Menu\nPress 8 to See the Locations of the Coffee Shops\nPress 9 to See the Locations of the Cake Shops\n";
                cout<<"Press 0 to Stop\n";
                int adchoice;
                cin>>adchoice;
                system("CLS");

                if (adchoice==1)
                    A.CreateAdmin();
                else if (adchoice==2)
                    A.ShowAdmin();
                else if (adchoice==3)
                    A.CreateMem();
                else if (adchoice==4)
                    A.ShowMem();
                else if (adchoice==5)
                    A.CoffeeShop::CreateMap();
                else if (adchoice==6)
                    A.CakeShop::CreateMap();
                else if (adchoice==7)
                    A.CreateMenu();
                else if (adchoice==8)
                    A.CoffeeShop::ShowMap();
                else if (adchoice==9)
                    A.CakeShop::ShowMap();
                else if (adchoice==0)
                    yn=0;

            }
        }
        else
        {
            cout<<"Invalid Admin Id or Password. You are not authorized."<<endl;
        }
    }
    else if(panel==2)
    {
        cout<<"Welcome!!\n";
        int yn=1;
        while(yn==1)
        {
            cout<<"\n\nPress 1 to Sign Up\nPress 2 to Log In\n";
            cout<<"Press 0 to Stop\n";
            int adchoice;
            cin>>adchoice;
            system("CLS");
            if (adchoice==1)
            {
                M.MemSignup();
                M.mValid=true;
                cout<<"You are Successfully Signed Up.\n";
                cout<<"\nPress 1 to See and Buy Items.\nPress 2 to See Balance.\nPress 3 to Update File.\nPress 4 to Sign Out.\n";
                cin>>u;
                do
                {
                    if(u==1)
                    {
                        system("pause");
                        system("cls");
                        Choice(A,M,C,K,pc);
                    }
                    else if(u==2)
                    {
                        system("pause");
                        system("cls");
                        cout<<"Your Account Balance is "<<M.getbalance(M.getId(),M.getPass())<<" Taka.\n";
                    }
                    else if(u==3)
                    {
                        system("pause");
                        system("cls");
                        cout<<"To Update Balance Please Enter Your User Id , Password and New Balance.\n";
                        string unm,upw;
                        int unb;
                        cin>>unm>>upw>>unb;
                        M.UpMem(unm,upw,unb);
                    }
                    else if(u==4)
                    {
                        M.~Member();
                        cout<<"You have Signed Out. Thank You!\n";
                    }
                    if(u!=4)
                    {
                        cout<<"\nPress 1 to See and Buy Items.\nPress 2 to See Balance.\nPress 3 to Update Balance.\nPress 4 to Sign Out.\nPress 0 to Stop.\n";
                        cin>>u;
                    }
                    else
                    {
                        u=0;
                    }
                }
                while(u!=0);
            }

            else if (adchoice==2)
            {
                M.mValid=M.MemLogin();
                if(M.mValid==false)
                {
                    cout<<"You have entered wrong id or password.\nTo Login press L and To Signup press S.\n";
                    char slc;
                    cin>>slc;
                    if(slc=='L' || slc=='l')
                    {
                        M.mValid=M.MemLogin();
                        cout<<"You are Successfully Logged In.\n";
                        cout<<"\nPress 1 to See and Buy Items.\nPress 2 to See Balance.\nPress 3 to Update Balance.\nPress 4 to Log Out.\n";
                        cin>>u;
                        do
                        {
                            if(u==1)
                            {
                                system("pause");
                                system("cls");
                                Choice(A,M,C,K,pc);
                            }
                            else if(u==2)
                            {
                                system("pause");
                                system("cls");
                                cout<<"Your Account Balance is "<<M.getbalance(M.getId(),M.getPass())<<" Taka.\n";
                            }
                            else if(u==3)
                            {
                                system("pause");
                                system("cls");
                                cout<<"To Update Balance Please Enter Your User Id , Password and New Balance.\n";
                                string unm,upw;
                                int unb;
                                cin>>unm>>upw>>unb;
                                M.UpMem(unm,upw,unb);
                            }
                            else if(u==4)
                            {
                                M.~Member();
                                cout<<"You have Logged Out. Thank You!\n";
                            }
                            if(u!=4)
                            {
                                cout<<"\nPress 1 to See and Buy Items.\nPress 2 to See Balance.\nPress 3 to Update File.\nPress 4 to Sign Out.\nPress 0 to Stop\n";
                                cin>>u;
                            }
                            else
                            {
                                u=0;
                            }
                        }
                        while(u!=0);
                    }
                    else if (slc=='S' || slc=='s')
                    {
                        M.MemSignup();
                        M.mValid=true;
                        cout<<"You are Successfully Signed Up.\n";
                        cout<<"\nPress 1 to See and Buy Items.\nPress 2 to See Balance.\nPress 3 to Update File.\nPress 4 to Sign Out.\n";
                        cin>>u;
                        do
                        {

                            if(u==1)
                            {
                                system("pause");
                                system("cls");
                                Choice(A,M,C,K,pc);
                            }
                            else if(u==2)
                            {
                                system("pause");
                                system("cls");
                                cout<<"Your Account Balance is "<<M.getbalance(M.getId(),M.getPass())<<" Taka.\n";
                            }
                            else if(u==3)
                            {
                                system("pause");
                                system("cls");
                                cout<<"To Update Balance Please Enter Your User Id , Password and New Balance.\n";
                                string unm,upw;
                                int unb;
                                cin>>unm>>upw>>unb;
                                M.UpMem(unm,upw,unb);
                            }
                            else if(u==4)
                            {
                                M.~Member();
                                cout<<"You have Signed Out. Thank You!\n";
                            }
                            if(u!=4)
                            {
                                cout<<"\nPress 1 to See and Buy Items.\nPress 2 to See Balance.\nPress 3 to Update File.\nPress 4 to Sign Out.\nPress 0 to Stop\n";
                                cin>>u;
                            }
                            else
                            {
                                u=0;
                            }
                        }
                        while(u!=0);
                    }
                }
                else
                {
                    cout<<"You are Successfully Logged In.\n";
                    cout<<"\nPress 1 to See and Buy Items.\nPress 2 to See Balance.\nPress 3 to Update Balance.\nPress 4 to Log Out.\n";
                    cin>>u;
                    do
                    {

                        if(u==1)
                        {
                            system("pause");
                            system("cls");
                            Choice(A,M,C,K,pc);
                        }
                        else if(u==2)
                        {
                            system("pause");
                            system("cls");
                            cout<<"Your Account Balance is "<<M.getbalance(M.getId(),M.getPass())<<" Taka.\n";
                        }
                        else if(u==3)
                        {
                            system("pause");
                            system("cls");
                            cout<<"To Update Balance Please Enter Your User Id , Password and New Balance.\n";
                            string unm,upw;
                            int unb;
                            cin>>unm>>upw>>unb;
                            M.UpMem(unm,upw,unb);
                        }
                        else if(u==4)
                        {
                            M.~Member();
                            cout<<"You have Logged Out. Thank You!\n";
                        }
                        if(u!=4)

                        {
                            cout<<"\nPress 1 to See and Buy Items.\nPress 2 to See Balance.\nPress 3 to Update File.\nPress 4 to Sign Out.\nPress 0 to Stop.\n";
                            cin>>u;
                        }
                        else
                        {
                            u=0;
                        }
                    }
                    while(u!=0);
                }
            }

            else if (adchoice==0)
                yn=0;
        }
    }
    return 0;
}
