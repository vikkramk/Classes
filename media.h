/*General Media class
*/

#ifndef MEDIA_H
#define MEDIA_H

enum MediaType {MMEDIA, MMUSIC, MMOVIE, MVIDEOGAME};

class Media {
	public:
		Media(char* title, int year);
		~Media();
		char* getTitle();
		int getYear();
		virtual char* getInfo();
		virtual MediaType getType();

	private:
		char* title;
		int year;
};

#endif