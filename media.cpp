/*Definitions of Media class
*/

#include "media.h"
#include <cstring>
#include "itoa.h"

Media::Media(char* title, int year) {
	this->title = new char[80];
	strcpy(this->title, title);
	this->year = year;
}

Media::~Media() {
	delete[] title;
}

char* Media::getTitle() {
	return title;
}

int Media::getYear() {
	return year;
}

MediaType Media::getType() {
	return MMEDIA;
}

char* Media::getInfo() {
	char* info = new char[256];
	char* nums = new char[32];

	strcpy(info, title);
	strcat(info, ", ");
	strcat(info, itoa(year, nums));

	return info;
}