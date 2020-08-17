#include "post.h"
#include <iostream>

post::post()
{
	
}
post::post(string poster, time_t DateTime, string message, string tags, string TaggedUsers)
{
	setposter(poster);
	setDateTime(DateTime);
	setmessage(message);
	settags(tags);
	setTaggedUsers(TaggedUsers);
}
post::post(const post& other)
{
	poster = other.poster;
	DateTime = other.DateTime;
	message = other.message;
	tags = other.tags;
	TaggedUsers = other.TaggedUsers;
}

string post::getposter()const
{
	return poster;
}
void post::setposter(string poster)
{
	if (poster.length() >= 4)
	{
		this->poster = poster;
	}
}

time_t post::getDateTime()const
{
	return DateTime;
}
void post::setDateTime(time_t DateTime)
{
	if (DateTime > 00.00)
	{
		this->DateTime = DateTime;
	}
}

string post::getmessage()const
{
	return message;
}
void post::setmessage(string message)
{
	if (message.length() >= 4)
	{
		this->message = message;
	}
}

string post::gettags()const
{
	return tags;
}
void post::settags(string tags)
{
	if (tags.length() >= 4)
	{
		this->tags = tags;
	}
}

string post::getTaggedUsers()const
{
	return TaggedUsers;
}
void post::setTaggedUsers(string TaggedUsers)
{
	if (TaggedUsers.length() >= 4)
	{
		this->TaggedUsers = TaggedUsers;
	}
}

void post::print()
{
	cout << "Post(poster: " << poster << ", DateTime: " << DateTime << ", message: " << message << ", tags: " << tags << ", TaggedUsers: " << TaggedUsers <<  ")" << endl;
}

//overloaded operators
ostream& operator<<(ostream& os, const post* Post)
{
	os << "Post(poster: " << Post->poster << ", DateTime: " << Post->DateTime << ", message: " << Post->message << ", tags: " << Post->tags << ", TaggedUsers: " << Post->TaggedUsers << ")" << endl;
	return os;
}
istream& operator>>(istream& is, post* Post)
{
	is >> Post->poster >> Post->DateTime >> Post->message >> Post->tags >> Post->TaggedUsers;
	return is;
}