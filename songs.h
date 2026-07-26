#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

struct song
{
    string title;
    int duration;
    string artist;
    string theme;
    song *next;
};

class song_list
{
    song *start;
    song *last;

public:
    song_list();

    void add_song(song s1);
    void input();
    void display();
    void search();
    void remove_song();
    void play_artist();
    void play_theme();
    void sort();
    void randomize();
};

