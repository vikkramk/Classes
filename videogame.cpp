/*Definitions for Videogame class
*/

#include "media.h"
#include "videogame.h"
#include <cstring>
#include "itoa.h"

Videogame::Videogame(char* title, int year, char* publisher, int rating):Media(title, year) {
	this->publisher = new char[80];
	strcpy(this->publisher, publisher);
	this->rating = rating;
}

Videogame::~Videogame() {
	delete[] publisher;
}

MediaType Videogame::getType() {
	return MVIDEOGAME;
}

char* Videogame::getInfo() {
	char* info = new char[256];
	char* nums = new char[32];

	strcpy(info, getTitle());
	strcat(info, ", ");
	strcat(info, itoa(getYear(), nums));
	strcat(info, ", ");
	strcat(info, publisher);
	strcat(info, ", ");
	strcat(info, itoa(rating, nums));

	return info;
}