#include "user.h"

user::user()
{
	
}
user::user(string email, string password, string userName, time_t lastLogin)
{
	setemail(email);
	setpassword(password);
	setuserName(userName);
	setlastLogin(lastLogin);
}

string user::getemail()const
{
	return email;
}
void user::setemail(string email)
{
	if (email.length() >= 6)
	{
		this->email = email;
	}
}

string user::getpassword()const
{
	return password;
}
void user::setpassword(string password)
{
	if (password.length() >= 6)
	{
		this->password = password;
	}
}

string user::getuserName()const
{
	return userName;
}
void user::setuserName(string userName)
{
	if (userName.length() >= 6)
	{
		this->userName = userName;
	}
}

time_t user::getlastLogin()const
{
	return lastLogin;
}
void user::setlastLogin(time_t lastLogin)
{
	if (lastLogin > 00.00)
	{
		this->lastLogin = lastLogin;
	}
}

//overloaded operators
ostream& operator<<(ostream& os, const user User)
{
	//os << user.email << ", " << user.password << ", " << user.userName << ", " << user.lastLogin;
	return os;

}
istream& operator>>(istream& is, user User)
{
	//is >> user.email >> user.password >> user.userName >> user.lastLogin;
	return is;
}
user& user::operator=(const user& User)
{
	if (this == &User)
	{
		return *this;
	}
	else
	{
		email = User.getemail();
		password = User.getpassword();
		userName = User.getuserName();
		lastLogin = User.getlastLogin();
		return *this;
	}
}
bool operator ==(const user& User1, const user& User2)
{
	if ((User1.getemail() == User2.getemail()) &&
		(User1.getpassword() == User1.getpassword()) &&
		(User1.getuserName() == User1.getuserName()) &&
		(User1.getlastLogin() == User1.getlastLogin()))

		return true;
	else
		return false;
}
bool operator !=(const user& User1, const user& User2)
{
	if ((User1.getemail() != User2.getemail()) ||
		(User1.getpassword() != User1.getpassword()) ||
		(User1.getuserName() != User1.getuserName()) ||
		(User1.getlastLogin() != User1.getlastLogin()))

		return true;
	else
		return false;
}

Sale::~Sale()
{

}