#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>
#include <vector>
#include <fstream>

using namespace std;

class City;
class Product;
class Buyer;
class Shop;
void CheckK(int&, int);
Shop* CinShop(string&, City&, int&);
Product* CinName(string&, Shop&, int&);
void forfstream(string, string&);


class Product
{
    string pname, sort;
    int k;
    float cost;
    friend void forBuy(City&, Buyer&);
public:
    Product(const Product&);
    Product();
    string Getname(void) { return pname; };
    string Getsort(void) { return sort; };
    int Getk(void) { return k; };
    float Getcost(void) { return cost; };
    void Set(string, string, int, float);
    Product(string, string, int, float);
};

Product::Product()
{
    char* argv = new char[6];
    char* argv2 = new char[6];
    for (int i = 0; i < 5; i++)
    {
        argv[i] = 'A' + rand() % 50;
        argv2[i] = 'A' + rand() % 25;
    }
    argv[5] = '\0';
    argv2[5] = '\0';
    pname = string(argv);
    sort = string(argv2);
    k = rand() % 50 + 1;
    cost = float(((rand() % 100) + 1) / 1.5);
    delete[] argv;
    delete[] argv2;
}

Product::Product(string na, string so, int n, float co)
{
    pname = na;
    sort = so;
    k = n;
    cost = co;
}

void Product:: Set(string na, string so, int n, float co)
{
    pname = na;
    sort = so;
    k = n;
    cost = co;
}

Product::Product(const Product& product)
{
    this->cost = product.cost;
    this->k = product.k;
    this->sort = product.sort;
    this->pname = product.pname;
}

class Shop
{
    string sname, type;
    int n;
    vector<Product> products;
    friend void forBuy(City&, Buyer&);
    friend Product* CheckName(string, Shop&,int&);
public:
    Shop(const Shop&);
    Shop(void);
    string GetSname(void) { return sname; }
    string GetType(void) { return type; }
    int GetN(void) { return n; }
    void ShowProducts(void);
    void SetName(string name) { sname = name; }
    void SetType(string stype) { type = stype; }
    void WriteInFile(string);
};

void Shop::WriteInFile(string filename)
{
    string str;
    str += sname + " " + type + " " + to_string(n) + " ";
    for (int i = 0;i < n;i++)
        str += products[i].Getname() +" " + products[i].Getsort() + " " + to_string(products[i].Getk()) + " " + to_string(products[i].Getcost()) + "\n";
    forfstream(filename, str);
}

Shop::Shop(const Shop& shop)
{
    this->n = shop.n;
    this->sname = shop.sname;
    this->type = shop.type;
    this->products.resize(this->n);
    this->products = shop.products;
}

Shop::Shop(void)
{
    products.resize(10);
    n = 10;
    for (int i = 0; i < 10; i++)
    {
        char* argv = new char[6];
        char* argv2 = new char[6];
        for (int i = 0; i < 5; i++)
        {
            argv[i] = 'A' + rand() % 50;
            argv2[i] = 'A' + rand() % 25;
        }
        argv[5] = '\0';
        argv2[5] = '\0';
        products[i].Set(string(argv), string(argv2), rand() % 50 + 1, float(((rand() % 100)+1) / 1.5));
        delete[] argv;
        delete[] argv2;
    }
}

void Shop::ShowProducts(void)
{
    cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
    cout << "\nНазвание магазина : " << sname<<endl;
    for (int i = 0;i < n;i++)
        cout << "\nНазвание продукта : " << products[i].Getname() << "\nСорт продукта : " << products[i].Getsort() << "\nКоличество продуктов : " << products[i].Getk() << "\nЦена : " << products[i].Getcost() << endl;
}

class City
{
    string name;
    int shopsK;
    vector<Shop> shops;
    friend void forBuy(City&, Buyer&);
    friend Shop* CheckShop(string, City&,int&);
public:
    City(void);
    City(const City&);
    string GetName(void) { return name; };
    void WriteInFile(string);
};

void City::WriteInFile(string filename)
{
    string str;
    str += name+ " " + to_string(shopsK) + " ";
    for (int i = 0;i < shopsK;i++)
        str += shops[i].GetSname() + " " + shops[i].GetType() + " " + to_string(shops[i].GetN()) + "\n";
    forfstream(filename, str);
}

City::City(const City& city)
{
    this->name = city.name;
    this->shopsK = city.shopsK;
    this->shops.resize(this->shopsK);
    this->shops = city.shops;
}

City::City()
{
    shops.resize(10);
    shopsK = 10;
    char* argv = new char[6];
    char* argv2 = new char[6];
    for (int i = 0; i < 5; i++)
    { 
        argv[i] = 'A' + rand() % 50;
        argv2[i] = 'A' + rand() % 50;
    }
    argv[5] = '\0';
    argv2[5] = '\0';
    name = string(argv);
    delete[] argv;
    for (int i = 0; i < 10; i++)
    {
        char* argv3 = new char[6];
        char* argv4 = new char[6];
        for (int i = 0; i < 5; i++)
        {
            argv2[i] = 'A' + rand() % 50;
            argv3[i] = 'A' + rand() % 25;
        }
        argv3[5] = '\0';
        argv4[5] = '\0';
        shops[i].SetName(string(argv2));
        shops[i].SetName(string(argv3));
        delete[] argv3;
        delete[] argv4;
    }
}

class Bank
{
protected:
    string Bname;
    int cardnumber;
    float balance;
public:
    Bank(const Bank&);
    Bank(void);
    Bank(string, int, float);
    string GetBname(void) { return Bname; }
    float GetBmoney(void) { return balance; }
};

Bank::Bank(const Bank& bank)
{
    this->balance = bank.balance;
    this->cardnumber = bank.cardnumber;
    this->Bname = bank.Bname;
}

Bank::Bank(string name, int number, float balan)
{
    Bname = name;
    cardnumber = number;
    balance = balan;
}

Bank::Bank()
{
    char* argv = new char[6];
    for (int i = 0; i < 5; i++)
        argv[i] = 'A' + rand() % 50;
    argv[5] = '\0';
    Bname = string(argv);
    delete[] argv;
    cardnumber = rand() % 10000 +10000;
    balance = float(((rand() % 200)+ 30)/1.1);
}

class Buyer : public Bank
{
    int buy;
    string surname;
    float money;
    friend void forBuy(City&, Buyer&);
    friend bool CheckMoney(int&, float, char, Buyer&);
public:
    Buyer(void);
    Buyer(string,int, float, string, int, float);
    Buyer(const Buyer&);
    string GetSurname(void) { return surname; }
    void Buy(City&);
    float GetMoney(void) { return money; }
    float GetBankMoney(void) { return balance; }
    void ShowInfo(void);
    void WriteInFile(string);
};

Buyer::Buyer(string sname,int b,float mo, string name, int number, float balan)
{
    buy = b;
    surname =sname;
    money = mo;
    Bname = name;
    cardnumber = number;
    balance = balan;
}

void Buyer::WriteInFile(string filename)
{
    string str;
    str += surname + " " + to_string(money) + " " + to_string(buy)+ " " + Bname + " " + to_string(cardnumber) + " " + to_string(balance);
    forfstream(filename, str);
}

Buyer::Buyer(const Buyer& buyer)
{
    this->buy = buyer.buy;
    this->money = buyer.money;
    this->surname = buyer.surname;
}

void Buyer::Buy(City& A)
{
    forBuy(A, *this);
}
void Buyer::ShowInfo(void)
{
    cout << "\nФамилия : " << surname << "\nкол-во наличных денег : " << money << "\nимеет карту банка : " << Bname << "\nНомер карты : " << cardnumber << "\nКол-во на ней денег :" << balance << endl;
    _getch();
}

Buyer::Buyer()
{
    char* argv = new char[6];
    for (int i = 0; i < 5; i++)
        argv[i] = 'A' + rand() % 50;
    argv[5] = '\0';
    surname = string(argv);
    buy = rand() % 10;
    money = float(((rand() % 100) + 20) / 1.1);
    delete[] argv;
}

void forBuy(City& city, Buyer& buyer)
{
    do
    {
        system("cls");
        buyer.ShowInfo();
        for (int i = 0; i < city.shopsK; i++)
            city.shops[i].ShowProducts();
        int index=0;
        int shopindex = 0;
        string shop_name;
        cout << "\n\nВведите название магазина для покупки : ";
        getline(cin, shop_name);
        Shop* sh = CheckShop(shop_name,city,shopindex);
        if (sh == NULL)
            sh = CinShop(shop_name,city,shopindex);
        cout << "\n\nВведите название продукта для покупки :";
        string cinName;
        getline(cin, cinName);
        Product* b = CheckName(cinName,*sh,index);
        if (b == NULL)
           b = CinName(cinName, *sh,index);
        cout << "\n\nВведите количество для покупки :";
        int amount;
        cin >> amount;
        CheckK(amount, b->Getk());
        cout << "\n\nВыберете тип оплаты: с - картой, n - налличкой : ";
        if (CheckMoney(amount, b->Getcost(), _getch(), buyer))
            b->k -= amount;
        if (!(b->k))
        {
            sh->products.erase(sh->products.begin() + index);
            sh->products.resize(--sh->n);
        }
        if (!sh->n)
        {
            city.shops.erase(city.shops.begin() + shopindex);
            sh->products.resize(--sh->n);
        }
    } while (cout << "\n0 - повтор,другое - выход из покупки", _getch() == '0');
}

void forfstream(string filename, string& string)
{
    ofstream fout;
    fout.open(filename, ios::app);
    if (fout.is_open())
        fout << string;
    fout.close();
}

Shop* CheckShop(string Name, City& city,int& index)
{
    for (int i = 0;i <city.shopsK;i++)
    {
        if (Name == city.shops[i].GetSname())
        {
            index = i;
            return &city.shops[i];
        }
    }
    return NULL;
}

Shop* CinShop(string& shop_name,City& city,int& index)
{
    Shop* sh;
    do
    {
        cin.clear();
        cout << "\n\nТакого имени товара нет,повторите ввод : ";
        getline(cin, shop_name);
        sh = CheckShop(shop_name, city,index);
    } while (!sh);
    return sh;
}

Product* CheckName(string Name, Shop& shop,int& index)
{
    for (int i = 0;i < shop.n;i++)
    {
        if (Name == shop.products[i].Getname())
        {
            index = i;
            return &shop.products[i];
        }
    }
    return NULL;
}

Product* CinName(string& name, Shop& shop,int& index)
{
    Product* b;
    do
    {
        cin.clear();
        cout << "\n\nТакого имени товара нет,повторите ввод : ";
        getline(cin, name);
        b = CheckName(name, shop,index);
    } while (!b);
    return b;
}

bool CheckMoney(int& amount, float cost, char c, Buyer& buyer)
{
    if (c == 'n')
    {
        if (amount * cost > buyer.GetMoney())
        {
            cout << "\n\nНедостаточно денег в наличной, будет произведенеа оплата картой \n";
            if (amount * cost > buyer.GetBankMoney())
            {
                cout << "\nДенег на карте также не достаточно, оплата отменена\n";
                return false;
            }
            else
            {
                cout << "\n\nОплата картой выполнена\n";
                buyer.balance -= amount * cost;
                return true;
            }
        }
        else
        {
            cout << "\nОплата наличкой выполнена\n";
            buyer.money -= amount * cost;
            return true;
        }
    }
    else
    {
        if (amount * cost > buyer.GetBankMoney())
        {
            cout << "\n\nНедостаточно денег на карте, будет произведена оплата наличной \n";
            if (amount * cost > buyer.GetMoney())
            {
                cout << "\nДенег наличкой не достаточно, оплата отменена\n";
                return false;
            }
            else
            {
                cout << "\n\nОплата наличкой выполнена\n";
                buyer.money -= amount * cost;
                return true;
            }
        }
        else
        {
            cout << "\n\nОплата картой выполнена\n";
            buyer.balance -= amount * cost;
            return true;
        }
    }
}

void CheckK(int& checked, int k)
{
    if (cin.fail() || checked < 0 || cin.get() != '\n' || checked >k)
    {
        do
        {
            cin.clear();
            cout << "\nОшибка ввода переменной: либо превышено количество запрашиваемых товаров к количеству в магазине, либо неправильный ввод - повторите ввод : ";
            cin >> checked;
            cout << endl;
        } while (cin.fail() || checked < 0 || cin.get() != '\n' || checked >k);
    }
}

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "rus");
    City A;
    Buyer B;
    B.Buy(A);
    B.ShowInfo();
    return 0;
}
