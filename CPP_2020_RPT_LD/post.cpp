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