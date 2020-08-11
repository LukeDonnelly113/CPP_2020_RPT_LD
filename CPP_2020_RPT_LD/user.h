#pragma once
#include <string>
#include <list>
#include "post.h"
using namespace std;

class user
{
	string email;
	string password;
	string userName;
	time_t lastLogin;
public:
	user();
	user(string email, string password, string userName, time_t lastLogin);

	string getemail()const;
	void setemail(string email);

	string getpassword()const;
	void setpassword(string password);

	string getuserName()const;
	void setuserName(string userName);

	time_t getlastLogin()const;
	void setlastLogin(time_t lastLogin);


	friend ostream& operator<<(ostream& os, const user User);
	friend istream& operator>>(istream& is, user User);
	user& operator=(const user& User);
	friend bool operator==(const user& User1, const user& User2);
	friend bool operator!=(const user& User1, const user& User2);

	~user();
};