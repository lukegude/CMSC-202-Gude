#include "Song.h"

Song::Song() {}
Song::Song(string title, string artist)
{
    m_title = title;
    m_artist = artist;
}
void Song::SetTitle(string title)
{
    m_title = title;
}
void Song::SetArtist(string artist)
{
    m_artist = artist;
}
string Song::GetTitle()
{
    return m_title;
}
string Song::GetArtist()
{
    return m_artist;
}
void Song::Play()
{
    cout << "I know exactly what you're in the mood for, " << Song::GetTitle() << " by " << Song::GetArtist() << endl;
}
void Song::Request() {}
void Song::Playlist()
{
    cout << "Since you liked " << Song::GetTitle() << " by " << Song::GetArtist() << " so much, we are adding it to your playlist." << endl;
}

HipHop::HipHop() {}
HipHop::HipHop(string title, string artist)
{
    HipHop::SetArtist(artist);
    HipHop::SetTitle(title);
}
void HipHop::Play()
{
    cout << "Here is a song for you hip-hop lovers out there, up next playing " << HipHop::GetTitle() << " by " << HipHop::GetArtist() << endl;
}
void HipHop::Request()
{
    cout << "I'm hearing the people want more hip-hop." << endl;
}
void HipHop::Playlist()
{
    cout << "We're gonna add " << HipHop::GetTitle() << " by " << HipHop::GetArtist() << " to your hip-hop playlist." << endl;
}

Pop::Pop() {}
Pop::Pop(string title, string artist)
{
    Pop::SetTitle(title);
    Pop::SetArtist(artist);
}
void Pop::Play()
{
    cout << "Here is a song for you Pop lovers out there, up next playing " << Pop::GetTitle() << " by " << Pop::GetArtist() << endl;
}
void Pop::Request()
{
    cout << "I'm hearing people want more pop music." << endl;
}
void Pop::Playlist()
{
    cout << "We're gonna add " << Pop::GetTitle() << " by " << Pop::GetArtist() << " to your Pop playlist." << endl;
}