/*Music class derived for Media
*/

#ifndef MUSIC_H
#define MUSIC_H

class Music : public Media {
	public:
		Music(char* title, int year, char* artist, char* publisher, int duration);
		~Music();
		MediaType getType();
		char* getInfo();

	private:
		char* artist;
		char* publisher;
		int duration;	
};

#endif