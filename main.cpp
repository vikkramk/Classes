/*Classes: Example of using classes in CPP
 * An inventory system for types of media
 * NOTE: No error checking
 * */

#include <iostream>
#include <vector>

using namespace std;

enum Command {ADD, SEARCH, DELETE}
enum Type {MUSIC, MOVIE, VIDEOGAME}

//Functions
Command getCommand();
Type getTypeRequest();
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
		case SEARCH: searchm();
			  break;
		case DELETE: deletem();
		}
	}
}


Command getCommand() {
	char* input = new char[80];
	
	const char*[3] commands = {"ADD", "SEARCH", "DELETE"};

	cout << "Enter command: ";
	cin >> input;

	for (int i = 0; i < 3; i++) {
		if (strcmp(commands[i], input)
			break;
	}

	return static_cast<Command>(i);
}


Type getTypeRequest() {
	char* input = new char[80];
	
	const char*[3] types = {"MUSIC", "MOVIE", "VIDEOGAME"};

	cout << "Enter type: ";
	cin >> input;

	for (int i = 0; i < 3; i++) {
		if (strcmp(types[i], input)
			break;
	}

	return static_casti;
}


void addm(vector<Media*>* inven) {
	switch(getTypeRequest()) {
	case MUSIC: addmusic();
       		break;
	case MOVIE: addmovie();
		break;
	case VIDEOGAME: addvideogame();
		break;	
	}
}

void addmusic(vector<Media*>* inven) {
	char title[80], artist[80], publisher[80];
	int year, duration;

	cout << "Enter title:";
	cin >> title;
	cout << "Enter year:";

	cout << "Enter artist";
	cout << "Enter publisher";
	cout << "Enter duration";
}

void addmovie(vector<Media*>* inven) {
	
}

void videogame() {
	
}
