#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Song
{
    string name;
    string artist;
    string album;
    int seconds;
};

bool readData(string filename, vector<Song>& songs)
{
    ifstream fin(filename);
    if (!fin)
    {
        cerr << "Cannot open " << filename << '\n';
        return false;
    }

    Song song;
    while (getline(fin, song.name, ';'))
    {
        getline(fin, song.artist, ';');
        int min, sec;
        char ch; // for semicolon
        fin >> min >> ch >> sec >> ch;
        song.seconds = min * 60 + sec;
        getline(fin, song.album);
        songs.push_back(song);
    }

    return true;
}

void printData(const vector<Song>& songs)
{
    for (const auto& song: songs)
        cout << left
             << setw(20) << song.name   << "  "
             << setw(20) << song.artist << "  "
             << right
             << setw(4) << song.seconds / 60 << ':'
             << setfill('0')
             << setw(2) << song.seconds % 60 << "  "
             << setfill(' ')
             << song.album << '\n';
}

int main()
{
    vector<Song> songs;
    if (!readData("songs.txt", songs))
        return 1;
    printData(songs);
    return 0;
}
