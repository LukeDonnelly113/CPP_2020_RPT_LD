// CPP_2020_RPT_LD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <vector>
#include<functional>
#include "user.h"
#include "post.h"
#include <map>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

list <post*> findPostByUser(string poster, vector<post*>& currentPost)
{
	list <post*> items;
	for (int i = 0; i < currentPost.size(); i++)
	{
		post* item = currentPost[i];
		if (item->getposter() == poster)
		{
			items.push_back(item);
		}
	}
	return items;
}

list <post*> findPostByTag(string tags, vector<post*>& currentTags)
{
	list <post*> items;
	for (int i = 0; i < currentTags.size(); i++)
	{
		post* item = currentTags[i];
		if (item->gettags() == tags)
		{
			items.push_back(item);
		}
	}
	return items;
}

void addPost(vector<post*>& currentPost, const post& postItem)
{
	post* npost = new post(postItem);
	currentPost.push_back(npost);
}





void option1(vector<post*>& currentPost)
{
	cout << ("***********************************************************************************") << endl;
	cout << "Adding a new post: " << endl;
	string poster;
	time_t DateTime;
	string message;
	string tags;
	string TaggedUsers;

	cout << "Poster: ";
	cin >> poster;
	cout << "DateTime: ";
	cin >> DateTime;
	cout << "Message: ";
	cin >> message;
	cout << "Tags: ";
	cin >> tags;
	cout << "TaggedUsers: ";
	cin >> TaggedUsers;

	post npost(poster, DateTime, message, tags, TaggedUsers);

	addPost(currentPost, npost);

	cout << ("***********************************************************************************") << endl;
}

void option2(vector<post*>& currentPost)
{
	cout << ("***********************************************************************************") << endl;
	cout << "Searching for a post: " << endl;
	int choice;
	do
	{
		cout << endl << "Enter 1 to search a post by User," << endl;
		cout << "Enter 2 to search a post by tag," << endl;
		cout << "Enter -1 to exit!" << endl;
		cin >> choice;

		if (choice != -1)
		{
			if (choice == 1)
			{
				string poster;
				cout << "Enter the name of the user to find the post: ";
				cin >> poster;
				list <post*> items = findPostByUser(poster, currentPost);
				for (list<post*>::iterator it = items.begin(); it != items.end(); ++it)
				{
					post* npost = *it;
					npost->print();
					cout << endl;
				}
			}

			else if (choice == 2)
			{
				string tags;
				cout << "Enter the tags of the post you want to find: ";
				cin >> tags;
				list <post*> items = findPostByUser(tags, currentPost);
				for (list<post*>::iterator it = items.begin(); it != items.end(); ++it)
				{
					post* npost = *it;
					npost->print();
					cout << endl;
				}
			}

			
		}

	} while (choice != -1);

	cout << ("***********************************************************************************") << endl;
}

void option3(vector<post*>& currentPost)
{
	cout << ("***********************************************************************************") << endl;
	cout << "Removing a post: " << endl;
	string poster;
	int index;
	vector<post*>::iterator it;
	cout << "Enter the poster of the post you want to remove: ";
	cin >> poster;
	post* item = findPostByUser(poster, currentPost);

	it = find(currentPost.begin(), currentPost.end(), item);

	if (it != currentPost.end())
	{
		index = it - currentPost.begin();
		currentPost.erase(currentPost.begin() + index);
	}
	else
	{
		cout << "Element not found." << endl;
	}
	cout << ("***********************************************************************************") << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
