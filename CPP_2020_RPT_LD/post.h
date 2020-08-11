#pragma once
#include <string>
using namespace std;

class post
{
	string poster;
	time_t DateTime;
	string message;
	string tags;
	string TaggedUsers;
public:
	post();
	post(string poster, time_t DateTime, string message, string tags, string TaggedUsers);
	post(const post& other);

	string getposter()const;
	void setposter(string poster);

	time_t getDateTime()const;
	void setDateTime(time_t DateTime);

	string getmessage()const;
	void setmessage(string message);

	string gettags()const;
	void settags(string tags);

	string getTaggedUsers()const;
	void setTaggedUsers(string TaggedUsers);

	void print();

	friend ostream& operator<<(ostream& os, const post* post);
	friend istream& operator>>(istream& is, post* post);
	post& operator=(const post& post);
	friend bool operator==(const post& post1, const post& post2);
	friend bool operator!=(const post& post1, const post& post2);

	~post();
};