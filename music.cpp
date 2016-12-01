/*Definitions for Music class
*/

#include "media.h"
#include "music.h"
#include <cstring>
#include "itoa.h"

Music::Music(char* title, int year, char* artist, char* publisher, int duration):Media(title, year) {
	this->artist = new char[80];
	this->publisher = new char[80];
	strcpy(this->artist, artist);
	strcpy(this->publisher, publisher);
	this->duration = duration;
}

Music::~Music() {
	delete[] artist;
	delete[] publisher;
}

MediaType Music::getType() {
	return MMUSIC;
}

char* Music::getInfo() {
	char* info = new char[256];
	char* nums = new char[32];

	strcpy(info, getTitle());
	strcat(info, ", ");
	strcat(info, itoa(getYear(), nums));
	strcat(info, ", ");
	strcat(info, artist);
	strcat(info, ", ");
	strcat(info, publisher);
	strcat(info, ", ");
	strcat(info, itoa(duration, nums));

	return info;
}