/*Definitions for Movie class
*/

#include "media.h"
#include "movie.h"
#include <cstring>
#include "itoa.h"

Movie::Movie(char* title, int year, char* director, int duration, int rating):Media(title, year) {
	this->director = new char[80];
	strcpy(this->director, director);
	this->duration = duration;
	this->rating = rating;
}

Movie::~Movie() {
	delete[] director;
}

MediaType Movie::getType() {
	return MMOVIE;
}

char* Movie::getInfo() {
	char* info = new char[256];
	char* nums = new char[32];

	strcpy(info, getTitle());
	strcat(info, ", ");
	strcat(info, itoa(getYear(), nums));
	strcat(info, ", ");
	strcat(info, director);
	strcat(info, ", ");
	strcat(info, itoa(duration, nums));
	strcat(info, ", ");
	strcat(info, itoa(rating, nums));

	return info;
}