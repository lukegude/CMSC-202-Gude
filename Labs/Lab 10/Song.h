#ifndef SONG_H
#define SONG_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Song{
    public:
    Song();
    Song(string title, string artist);
    void SetArtist(string artist);
    void SetTitle(string title);
    string GetArtist();
    string GetTitle();
    virtual void Play();
    virtual void Request();
    virtual void Playlist();

    private:
    string m_title;
    string m_artist;
};

class HipHop : public Song{
    public:
    HipHop();
    HipHop(string title, string artist);
    virtual void Play();
    virtual void Request();
    virtual void Playlist();
};
class Pop: public Song{
    public:
    Pop();
    Pop(string title, string artist);
    virtual void Play();
    virtual void Request();
    virtual void Playlist();
};


#endif