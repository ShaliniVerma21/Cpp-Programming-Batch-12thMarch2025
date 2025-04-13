//Problem 21: Playlist Management

#include <iostream>
#include <string>
using namespace std;

struct Song {
    string title;
    string artist;
};

void displayPlaylist(Song playlist[], int count) {
    cout << "Song Title\tArtist\n";
    for (int i = 0; i < count; i++) {
        cout << playlist[i].title << "\t\t" << playlist[i].artist << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of songs in playlist: ";
    cin >> n;
    Song playlist[n];
    for (int i = 0 
; i < n; i++) {
        cout << "Enter song title and artist: ";
        cin >> playlist[i].title >> playlist[i].artist;
    }
    displayPlaylist(playlist, n);
    return 0;
}