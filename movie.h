/*Movie class derived from Media
*/

#ifndef MOVIE_H
#define MOVIE_H

class Movie : public Media {
	public:
		Movie(char* title, int year, char* director, int duration, int rating);
		~Movie();
		MediaType getType();
		char* getInfo();

	private:
		char* director;
		int duration;
		int rating;	
};

#endif