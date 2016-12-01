/*Videogame class derived from Media
*/

#ifndef VIDEOGAME_H
#define VIDEOGAME_H

class Videogame : public Media {
	public:
		Videogame(char* title, int year, char* publisher, int rating);
		~Videogame();
		MediaType getType();
		char* getInfo();

	private:
		char* publisher;
		int rating;	
};

#endif