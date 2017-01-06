/*Classes: Example of using classes in CPP
 * An inventory system for types of media
 * NOTE: No error checking
 * */

#include <iostream>
#include <vector>
#include <cstring>

#include "media.h"
#include "music.h"
#include "movie.h"
#include "videogame.h"

using namespace std;

enum Command {ADD, SEARCH, DELETE, QUIT};
enum Type {MUSIC, MOVIE, VIDEOGAME};

//Functions
Command getCommand();
Type getTypeRequest();
void searchm(vector<Media*>*);
void deletem(vector<Media*>*);
void addm(vector<Media*>*);
void addmusic(vector<Media*>*);
void addmovie(vector<Media*>*);
void addvideogame(vector<Media*>*);

int main() {
	vector<Media*>* inventory = new vector<Media*>();

	bool done = false;

	while (!done) {
		switch (getCommand()) {
		case ADD: addm(inventory);
			break;
		case SEARCH: searchm(inventory);
			break;
		case DELETE: deletem(inventory);
			break;
		case QUIT: done = true;
		}
	}
}

//Get some input and return codes
Command getCommand() {
	char input[80];
	
	const char* commands[4] = {"ADD", "SEARCH", "DELETE", "QUIT"};

	cout << "Enter command (ADD, SEARCH, DELETE, QUIT): ";
	cin.getline(input, 80);

	int i;
	for (i = 0; i < 4; i++) {
		if (strcmp(commands[i], input) == 0)
			break;
	}

	return static_cast<Command>(i);
}


Type getTypeRequest() {
	char input[80];
	
	const char* types[3] = {"MUSIC", "MOVIE", "VIDEOGAME"};

	cout << "Enter media type (MUSIC, MOVIE, VIDEOGAME): ";
	cin.getline(input, 80);

	int i;
	for (i = 0; i < 3; i++) {
		if (strcmp(types[i], input) == 0)
			break;
	}

	return static_cast<Type>(i);
}


//Search functions
void searchm(vector<Media*>* inven) {
	int searchchoice;
	char title[80];
	int year;
	char* info;

	cout << "Search by title(1) or year(2)?:";
	cin >> searchchoice;
	cin.ignore();

	if (searchchoice == 1) {
		cout << "Enter title:";
		cin.getline(title, 80);
		for (int i = 0; i < inven->size(); i++) {
			if (strcmp(inven->at(i)->getTitle(), title) == 0) {
				info = inven->at(i)->getInfo();
				cout << info << endl;
				delete[] info;
			}
		}
	}

	if (searchchoice == 2) {
		cout << "Enter year:";
		cin >> year;
		cin.ignore();
		for (int i = 0; i < inven->size(); i++) {
			if (inven->at(i)->getYear() == year)
				info = inven->at(i)->getInfo();
				cout << info << endl;
				delete[] info;
		}
	}
}

//Delete functions
void deletem(vector<Media*>* inven) {
	int searchchoice;
	char title[80];
	int year;
	char confirm;
	char* info;

	cout << "Search by title(1) or year(2)?:";
	cin >> searchchoice;
	cin.ignore();

	if (searchchoice == 1) {
		cout << "Enter title:";
		cin.getline(title, 80);
		for (int i = 0; i < inven->size(); i++) {
			if (strcmp(inven->at(i)->getTitle(), title) == 0) {
				info = inven->at(i)->getInfo();
				cout << info << endl;
				delete[] info;
				cout << "Delete? (y/n):";
				cin >> confirm;
				cin.ignore();
				if (confirm == 'y') {
					delete inven->at(i);
					inven->erase(inven->begin()+i);
					cout << "Deleted" << endl;
				}
			}
		}
	}

	if (searchchoice == 2) {
		cout << "Enter year:";
		cin >> year;
		cin.ignore();
		for (int i = 0; i < inven->size(); i++) {
			if (inven->at(i)->getYear() == year) {
				info = inven->at(i)->getInfo();
				cout << info << endl;
				delete[] info;
				cout << "Delete? (y/n):";
				cin >> confirm;
				cin.ignore();
				if (confirm == 'y') {
					delete inven->at(i);
					inven->erase(inven->begin()+i);
					cout << "Deleted" << endl;
				}
			}
		}
	}
}



//Media addition functions
void addm(vector<Media*>* inven) {
	switch(getTypeRequest()) {
	case MUSIC: addmusic(inven);
       		break;
	case MOVIE: addmovie(inven);
		break;
	case VIDEOGAME: addvideogame(inven);
		break;	
	}
}

void addmusic(vector<Media*>* inven) {
	char title[80], artist[80], publisher[80];
	int year, duration;

	cout << "Enter title:";
	cin.getline(title, 80);
	cout << "Enter year:";
	cin >> year;
	cin.ignore();
	cout << "Enter artist:";
	cin.getline(artist, 80);
	cout << "Enter publisher:";
	cin.getline(publisher, 80);
	cout << "Enter duration";
	cin >> duration;
	cin.ignore();

	inven->push_back(new Music(title, year, artist, publisher, duration));
}

void addmovie(vector<Media*>* inven) {
	char title[80], director[80];
	int year, duration, rating;

	cout << "Enter title:";
	cin.getline(title, 80);
	cout << "Enter year:";
	cin >> year;
	cin.ignore();
	cout << "Enter director:";
	cin.getline(director, 80);
	cout << "Enter duration:";
	cin >> duration;
	cin.ignore();
	cout << "Enter rating";
	cin >> rating;
	cin.ignore();

	inven->push_back(new Movie(title, year, director, duration, rating));
}

void addvideogame(vector<Media*>* inven) {
	char title[80], publisher[80];
	int year, rating;

	cout << "Enter title:";
	cin.getline(title, 80);
	cout << "Enter year:";
	cin >> year;
	cin.ignore();
	cout << "Enter publisher:";
	cin.getline(publisher, 80);
	cout << "Enter rating";
	cin >> rating;
	cin.ignore();

	inven->push_back(new Videogame(title, year, publisher, rating));
}
