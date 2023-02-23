#include <iostream>
#include <fstream>
using namespace std;

string usernames[100];
string passwords[100];
int userCount = 0;

void adduser(string username, string password);
void storeuser(string username, string password);
bool signin(string username, string password);
void loaddata();
void viewuser();
bool isvalid(string username);

int main()
{
    loaddata();
    string username;
    string password;
    int choice = 3;
    while (choice != 0)
    {
        cout << "Press 1 to sign up:" << endl;
        cout << "Press 2 to view all users:" << endl;
        cout << "Press 3 to sign in:" << endl;

        cout << "ENter your option: ";
        cin >> choice;

        if (choice == 1)
        {
            bool desision;
            cout << "Enter username: ";
            cin >> username;
            cout << "ENter your password:";
            cin >> password;
            desision = isvalid(username);
            if (desision == true)
            {
                adduser(username, password);
                storeuser(username, password);
            }
            else
            {
                cout << "Username already exits" << endl;
            }
        }

        else if (choice == 2)
        {
            viewuser();
        }

        else if (choice == 3)
        {

            cout << "Enter username: ";
            cin >> username;
            cout << "ENter your password:";
            cin >> password;
            bool flag = signin(username, password);

            if (flag == true)
            {
                cout << "Signin successfully: ";
            }
            else
            {
                cout << "Wrong credientals: ";
            }
        }
    }
}
void adduser(string username, string password)
{
    usernames[userCount] = username;
    passwords[userCount] = password;
    userCount++;
}
void storeuser(string username, string password)
{
    fstream file;
    file.open("Students.txt", ios::app);
    file << username << endl;
    file << password << endl;
    file.close();
}
bool signin(string username, string password)
{
    bool flag = false;
    for (int i = 0; i < userCount; i++)
    {
        if (usernames[i] == username)
        {
            flag = true;
            break;
        }
        else
        {
            flag = false;
        }
    }
    return flag;
}
void viewuser()
{
    for (int i = 0; i < userCount; i++)
    {
        cout << usernames[i] << "    " << passwords[i] << endl;
    }
}
void loaddata()
{
    string username;
    string password;
    fstream file;
    file.open("Students.txt", ios::in);
    while (getline(file, username) && getline(file, password))
    {

        usernames[userCount] = username;
        passwords[userCount] = password;
        userCount++;
    }
    file.close();
}
bool isvalid(string username)
{
    bool flag = true;
    for (int i = 0; i < userCount; i++)
    {
        if (usernames[i] == username)
        {
            flag = false;
            break;
        }
    }
    return flag;
}