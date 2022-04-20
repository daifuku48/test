#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human
{
    public:
    string Name;
    string Surname;
    string Patronymic;
    string Sex;
    int year;
};

class Library__User : public Human
{
    public:
    vector<string> Books;
    bool status;
    float vnesok = 100;
    float balance = false;
    int number, monthV , yearV, number__books;
    int back = 0;

    void inputUser(int n,Library__User* mas);

};

void inputUser(int n,Library__User* mas)
{
    string buffer__books;
    for (int i = 0; i < n; i++ ){
        cout << "Number: ";
        cin >> mas[i].number;
        cout << "Name: ";
        cin.sync();
        getline(cin , mas[i].Name);
        cout << "Surname: ";
        getline(cin , mas[i].Surname);
        cout << "Patronymic: ";
        getline(cin , mas[i].Patronymic);
        cout << "Sex: ";
        getline(cin , mas[i].Sex);
        cout << "Year: ";
        cin >> mas[i].year;
        cout << "Registration date:" << endl;
        cout << "Year of registration: ";
        cin >> mas[i].yearV;
        cout << "Month of registration: ";
        cin >> mas[i].monthV;
        cout << "Number of books the user has taken: ";
        cin >> mas[i].number__books;
        cout << "Books: " << endl;
        for (int j = 0; j < mas[i].number__books; j++){
            cout << j+1 << ") ";
            cin.sync();
            getline(cin , buffer__books);
            mas[i].Books.push_back(buffer__books);
        }
    }
}

int plusUser (int n,Library__User*& mas)
{
    n = n + 1;
    string buffer__books;
    Library__User* tmpArr = new Library__User[n];
    for (int i = 0; i < n-1; i++){
        tmpArr[i].number = mas[i].number;
        tmpArr[i].Name = mas[i].Name;
        tmpArr[i].Surname = mas[i].Surname;
        tmpArr[i].Patronymic = mas[i].Patronymic;
        tmpArr[i].Sex = mas[i].Sex;
        tmpArr[i].year = mas[i].year;
        tmpArr[i].yearV = mas[i].yearV;
        tmpArr[i].monthV = mas[i].monthV;
        tmpArr[i].number__books = mas[i].number__books;
        for (int j = 0; j < tmpArr[i].number__books; j++){
            tmpArr[i].Books = mas[i].Books;
        }
    }

        cout << "Number: ";
        cin >> tmpArr[n-1].number;
        cout << "Name: ";
        cin.sync();
        getline(cin , tmpArr[n-1].Name);
        cout << "Surname: ";
        getline(cin , tmpArr[n-1].Surname);
        cout << "Patronymic: ";
        getline(cin , tmpArr[n-1].Patronymic);
        cout << "Sex: ";
        getline(cin , tmpArr[n-1].Sex);
        cout << "Year: ";
        cin >> tmpArr[n-1].year;
        cout << "Registration date:" << endl;
        cout << "Year of registration: ";
        cin >> tmpArr[n-1].yearV;
        cout << "Month of registration: ";
        cin >> tmpArr[n-1].monthV;
        cout << "Number of books the user has taken: ";
        cin >> tmpArr[n-1].number__books;
        cout << "Books: " << endl;
        for (int j = 0; j < tmpArr[n-1].number__books; j++){
            cout << j+1 << ") ";
            cin.sync();
            getline(cin , buffer__books);
            tmpArr[n-1].Books.push_back(buffer__books);
        }

    delete[] mas;
    mas = tmpArr;
    return n;
}

void deletebook(int n, Library__User*& mas)
{
    int k,del;
    string buffer_book;
    cout << "Which user's book do you want to delete?" << endl;
    for (int i = 0; i < n; i++){
        cout << i+1 << ") " << mas[i].Surname << " " << mas[i].Name << " " << mas[i].Patronymic << endl;
    }
    cin >> k;
    k--;
    cout << "Which user book do you want to delete ?" << endl;
        for (int d = 0; d < mas[k].number__books; d++){
            cout << d+1 << ") " << mas[k].Books[d] << endl;
        }
    cin >> del;
    del--;

    buffer_book = mas[k].Books[del];
    mas[k].Books.erase(mas[k].Books.begin() + del);
    mas[k].number__books = mas[k].number__books - 1;
    mas[k].back = mas[k].back + 1;

    cout << "Book - " << buffer_book << " deleted successfully" << endl;
}
void addbook(int n,Library__User*& mas)
{
    int k;
    string buffer__books;
    cout << "Which user do you want to add the book to?" << endl;
    for (int i = 0; i < n; i++){
        cout << i+1 << ") " << mas[i].Surname << " " << mas[i].Name << " " << mas[i].Patronymic << endl;
    }
    cin >> k;
    k--;

    cout << "Enter book title" << endl;
    cin.sync();
    getline(cin , buffer__books);
    mas[k].Books.push_back(buffer__books);
    mas[k].number__books = mas[k].number__books + 1;

    cout << "Book - " << buffer__books << " successfully added" << endl;
}

void Display(int n,Library__User*& mas)
{
    int k;
    cout << "Which user's information do you want to see?" << endl;
    for (int i = 0; i < n; i++){
        cout << i+1 << ") " << mas[i].Surname << " " << mas[i].Name << " " << mas[i].Patronymic << endl;
    }
    cin >> k;
    k--;

        cout << "Number: " << mas[k].number << endl;
        cout << "Name: " << mas[k].Name << endl;
        cout << "Surname: " << mas[k].Surname << endl;
        cout << "Patronymic: " << mas[k].Patronymic << endl;
        cout << "Sex: " << mas[k].Sex << endl;
        cout << "Year: " << mas[k].year << endl;
        cout << "Registration date:" << endl;
        cout << "Year of registration: " << mas[k].yearV << endl;
        cout << "Month of registration: " << mas[k].monthV << endl;
        cout << "Books: " << endl;
        for (int j = 0; j < mas[k].number__books; j++){
            cout << mas[k].Books[j] << ", ";
        }
        cout << endl;
}

void discount(int n,Library__User*& mas)
{
    int k;
    cout << "Which user's discount do you want to calculate?" << endl;
    for (int i = 0; i < n; i++){
        cout << i+1 << ") " << mas[i].Surname << " " << mas[i].Name << " " << mas[i].Patronymic << endl;
    }
    cin >> k;
    k--;

    if (mas[k].back >= 100 ) {mas[k].vnesok = 0.01;}
    else {
        mas[k].vnesok = 100 - mas[k].back;
    }
    cout << "User contribution: " << (100 -mas[k].vnesok) << endl;
}

void userbalance(int n,Library__User*& mas)
{
    int k,sb;
    cout << "To which user do you want to top up the balance?" << endl;
    for (int i = 0; i < n; i++){
        cout << i+1 << ") " << mas[i].Surname << " " << mas[i].Name << " " << mas[i].Patronymic << endl;
    }
    cin >> k;
    k--;

    cout << "Enter the replenishment amount: ";
    cin >> sb;
    mas[k].balance = mas[k].balance + sb;

    cout << "Balance = " << mas[k].balance;
}

void CheckStatus(int n,Library__User*& mas)
{
    int k,tmpm;
    cout << "Which user's status do you want to know?" << endl;
    for (int i = 0; i < n; i++){
        cout << i+1 << ") " << mas[i].Surname << " " << mas[i].Name << " " << mas[i].Patronymic << endl;
    }
    cin >> k;
    k--;

    tmpm = 2022 - mas[k].yearV;
    mas[k].balance = mas[k].balance - ( mas[k].vnesok *((tmpm * 12) + mas[k].monthV));

    if (mas[k].balance < 0) {
        mas[k].status == false;
        cout << "Not paid" << endl;
        }
    else{
        mas[k].status == true;
        cout << "Paid" << endl;
    }
}

int main(){
    int n,k;
    bool cicle = true;
    cout << "Number of users: ";
    cin >> n;
    Library__User* mas = new Library__User[n];
    inputUser(n, mas);
    while (cicle)
    {
    cout << endl;
    cout << "1 - Add user : " << "2 - Delete book : " << "3 - Add book : " << "4 - Displaying user information : " << "5 - Discount calculation : "<< "6 - Top up user balance : " << "7 - Check Status : " << "0 - Exiting the program "<< endl;
    cin >> k;
    switch (k)
        {
        case 1:
            n = plusUser (n,mas);
            break;
        case 2:
            deletebook(n,mas);
            break;
        case 3:
            addbook(n,mas);
            break;
        case 4:
            Display(n,mas);
            break;
        case 5:
            discount(n,mas);
            break;
        case 6:
            userbalance(n,mas);
            break;
        case 7:
            CheckStatus(n,mas);
            break;
        case 0:
            cicle = false;
            break;
        default:
            cout << "You entered an invalid number" << endl;
            break;
        }
    }
    delete[] mas;
    return 0;
}