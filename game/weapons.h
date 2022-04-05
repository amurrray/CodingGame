#ifndef WEAPONS_H
#define WEAPONS_H

#include <iostream>
using namespace std;

class Weapons
{
private:
    int damage;
    int range;

public:
    Weapons();
    int getDamage();
    int getRange();

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