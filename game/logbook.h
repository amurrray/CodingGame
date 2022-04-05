#ifndef LOGBOOK_H
#define LOGBOOK_H

#include <iostream>
using namespace std;

class Logbook
{
private:
    int suitGrade;
    int medKits;

public:
    Logbook();
    int getsuitGrade();
    int getmedKits();

    int readMovies(string fileName);
    void printMoviesByYear(string releaseYear);

    int readRatings(string fileName);
    int getRating(string username, string title);
    int getCountWatchedMovies(string username);
    double calcAvgRating(string title);
    int addUser(string username);
    int rentMovie(string username, string title, int newRating);
};
#endif