#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>

using namespace std;

class Product;
void CheckK(int&, int);
Product* CheckName(string, Product*);
void CinName(string&, Product*);

class City
{
    string name;
    int n;
    void Random();
public:
    City()
    {
        Random();
    }
    string GetName() { return name; };
};

void City::Random()
{
    char* argv = new char[6];
    for (int i = 0; i < 5; i++)
        argv[i] = 'A' + rand() % 50;
    argv[5] = '\0';
    name = string(argv);
}

class Product
{
protected:
    string pname, sort;
    int k;
    float cost;
public:
    string Getname() { return pname; };
    string Getsort() { return sort; };
    int Getk() { return k; };
    float Getcost() { return cost; };
    void Set(string na, string so, int n, float co)
    {
        pname = na;
        sort = so;
        k = n;
        cost = co;
    }
};

class Shop : public City
{
    string sname, type;
    Product products[10];
    bool random = false;
    void RandomProducts();
public:
    void BuyProducts();
    void ShowProducts();
};

void Shop::ShowProducts()
{
    for (int i = 0;i < 10;i++)
        cout << "Название продукта : " << products[i].Getname() << "\nСорт продукта : " << products[i].Getsort() << "\nКоличество продуктов : " << products[i].Getk() << "\nЦена : " << products[i].Getcost() << endl;
}

void Shop::BuyProducts()
{
    if (!random)
        RandomProducts();
    do
    {
        ShowProducts();
        cout << "Введите название продукта для покупки :";
        string cinName;
        getline(cin, cinName);
        Product* b = CheckName(cinName, products);
        if (b == NULL)
            CinName(cinName, products);
        cout << "Введите количество для покупки :";
        int amount;
        cin >> amount;
        CheckK(amount, b->Getk());
    } while (cout << "0 - повтор,другое - выход из покупки", _getch() == '0');
}

void Shop::RandomProducts()
{
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
        products->Set(string(argv), string(argv2), rand() % 50, float(rand() % 100 / 1.5));
        delete[] argv;
        delete[] argv2;
    }
    random = true;
}
class Bank
{
    int accoutnumber;
    float balance;
};

class Buyer : public Bank
{
    string surname;
    float money;
    float purchase;
public:
    void Buy();
};

void Buyer::Buy()
{
    cout << "Введите название товара: ";
    string prnmae;
    getline(cin, prnmae);

}

//void forfstream(char* filename, string& string)
//{
//    ofstream fout;
//    fout.open(filename, ios::app);
//    if (fout.is_open())
//        fout << string;
//    fout.close();
//}

Product* CheckName(string Name, Product* products)
{
    for (int i = 0;i < 10;i++)
    {
        if (Name == products[i].Getname())
            return &products[i];
    }
    return NULL;
}

void CinName(string& name, Product* products)
{
    do
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "\nТакого имени товара нет,повторите ввод : ";
        getline(cin, name);

    } while (CheckName(name, products) != NULL);
}

void CheckK(int& checked, int k)
{
    if (cin.fail() || checked < 0 || cin.get() != '\n' || checked >k)
    {
        do
        {
            cin.clear();
            cin.ignore(32767, '\n');
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
    cout << A.GetName();
    return 0;
}
