#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal
{
protected:
    float age;
    string sub_kingdom;
    string type;
    string class_;
public:
    float GetAge(void) { return age; };
    string GetSub_Kingdom(void) { return sub_kingdom; };
    string GetClass(void) { return class_; };
    string GetType(void) { return type; };
    void SetAge(float sh) { age = sh; };
    void SetSub_Kingdom(string sh) { sub_kingdom = sh; };
    void SetType(string sh) { type = sh; };
    void SetClass(string sh) { class_ = sh; };
    Animal(void);
    Animal(float, string, string);
    void Info(void);
};

Animal::Animal()
{
    int random_1 = rand() % 2;
    if (random_1 < 1)
    {
        sub_kingdom = "Unicellular";
        int random_2 = rand() % 3;
        switch (random_2)
        {
        case 0:
            type = "Rotifers";
            break;
        case 1:
            type = "Bryozoa";
            break;
        case 2:
            type = "Echinoderms";
            break;
        }
        age = float(rand() % 1 + 0.1);
    }
    else
    {
        sub_kingdom = "Multicellular";
        int random_2 = rand() % 7;
        switch (random_2)
        {
        case 0:
            type = "Chordates";
            break;
        case 1:
            type = "Molluscs";
            break;
        case 2:
            type = "Arthropods";
            break;
        case 3:
            type = "Annelids";
            break;
        case 4:
            type = "Nematodes";
            break;
        case 5:
            type = "Cnidaria";
            break;
        case 6:
            type = "Platyhelminthes";
            break;
        }
        age = float(rand() % 10 + 0.2);
    }
    char* argv = new char[6];
    for (int i = 0; i < 5; i++)
        argv[i] = 'A' + rand() % 50;
    argv[5] = '\0';
    class_ = string(argv);
    delete[] argv;
}

void Animal::Info()
{
    cout << "\nЦарство: Animals\nПодцарство: " << sub_kingdom << "\nТип: " << type << "\nКласс: " << class_<<endl;
}

Animal::Animal(float forage, string fortype, string forsub)
{
    age = forage;
    type = fortype;
    sub_kingdom = forsub;
}

class Human :public Animal
{
    string snm;
public:
    Human(void);
    void SetSNM(string str) { snm = str; };
    string GetSNM(void) { return snm; };
    void Info(void);
};

void Human::Info()
{
    Animal::Info();
    cout << "Фио: " << snm<<endl;
}

Human::Human()
{
    sub_kingdom = "Multicellular";
    type = "Chordates";
    class_ = "Mammals";
    char* argv = new char[16];
    for (int i = 0; i < 5; i++)
        argv[i] = 'A' + rand() % 50;
    argv[5] = ' ';
    for (int i = 6; i < 10; i++)
        argv[i] = 'A' + rand() % 50;
    argv[10] = ' ';
    for (int i = 11; i < 15; i++)
        argv[i] = 'A' + rand() % 50;
    argv[15] = '\0';
    snm = string(argv);
    delete[] argv;
}

class CyberHuman :private Human, public Animal
{
protected:
    int k;
    vector<string> implants;
public:
    CyberHuman();
    CyberHuman(int n);
    void SetK(int n) { k = n; };
    int GetK(void) { return k; };
    string GetName(void) { return Human::GetSNM(); };
    void Info(void);
};

void CyberHuman::Info(void)
{
    Human::Info();
    cout << "Кол-во имплантов: " << k << "\nНазвания имплантов: ";
    for (int i = 0;i < k;i++)
        cout << "\t["<<i+1<<"] - " << implants[i];
};

CyberHuman::CyberHuman()
{
    k = rand() % 5 + 1;
    implants.resize(k);
    for (int i = 0;i < k;i++)
    {
        char* argv = new char[6];
        for (int j = 0; j < 5; j++)
            argv[j] = 'A' + rand() % 50;
        argv[5] = '\0';
        implants[i] = string(argv);
        delete[] argv;
    }
}

CyberHuman::CyberHuman(int n)
{
    k = n;
    for (int i = 0;i < k;i++)
    {
        cout << "\nВведите [" << i << "] имплант :";
        getline(cin, implants[i]);
    }
}

class CyberMayor : public Animal, private Human, private CyberHuman
{
    string district_of_mayor;
public:
    string GetName(void) { return Human::GetSNM(); };
    string GetDistrict(void) { return district_of_mayor; };
    void SetDistrict(string sh) { district_of_mayor = sh; };
    CyberMayor();
    void Info() { CyberHuman::Info(); cout << "\nЯвляется мэром области: " << district_of_mayor << endl; };
};

CyberMayor::CyberMayor()
{
    char* argv = new char[6];
    for (int i = 0; i < 5; i++)
        argv[i] = 'A' + rand() % 50;
    argv[5] = '\0';
    district_of_mayor = string(argv);
    delete[] argv;
}

class CyberEmployee : public CyberHuman, public Animal, private Human
{
    string name_of_firm;
    float salary;
public:
    CyberEmployee();
    void SetSalary(float sal) { salary = sal; };
    void SetName_of_firm(string sh) { name_of_firm = sh; };
    float GetSalary(void) { return salary; };
    string GetName(void) { return Human::GetSNM(); };
    string GetName_of_firm(void) { return name_of_firm; };
    void Info() { CyberHuman::Info(); cout << "\nРаботает в: " << name_of_firm << "\nЗарплата: " << salary << endl; }
};

CyberEmployee::CyberEmployee()
{
    salary = rand() % 70 + 0.1;
    char* argv = new char[6];
    for (int i = 0; i < 5; i++)
        argv[i] = 'A' + rand() % 50;
    argv[5] = '\0';
    name_of_firm = string(argv);
    delete[] argv;
}

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "rus");
    CyberEmployee b;
    b.Info();
    Animal c;
    c.Info();
    Human g;
    g.Info();
    CyberMayor d;
    d.Info();
    system("pause");
    return 0;
}


