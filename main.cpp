#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
class UserAccount{
    private:
    char username[40];
    int personal_number;
    int number;

    public:
    UserAccount(char u[40], int id, int n){
        strcpy(username, u);
        personal_number = id;
        number = n;
    }

    const char* GetUsername(){
        return username;
    }

    int GetPersonal(){
        return personal_number;
    }

    int GetNumber(){
        return number;
    }

    void file(string& name){
        ofstream f(name);
        if (!f){
            cout << "The file cannot be opened right now!";
        }

        f << username << " | " << personal_number << " | " << number;
        cout << endl;
        cout << "Your data has been saved!";
        f.close();
    }

    void ReadFromFile(string& name){
        ifstream f(name);
        while( f >> username >> personal_number >>  number){
            cout << username << " | " << personal_number << " | " << number;
        }
        cout << endl;
        f.close();
    }

};

int main(){
    string name = "Data.txt";
    char u[40];
    int id, n;
    int users;

    cout << "Enter how many users:";
    cin >> users;
    cin.ignore();

    for(int i = 0; i < users; i++){
    cout << "Your name:";
    cin.getline(u, 40);

    cout << "Your id:";
    cin >> id;

    cout << "Your number:";
    cin >> n;
    cin.ignore();

    UserAccount user(u, id, n);
    user.file(name);
    user.ReadFromFile(name);
    }
    return 0;
}