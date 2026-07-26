#include "songs.h"

int main()
{
    song_list s1;

    int ch;

    while (true)
    {
        cout << "\n========== MUSIC PLAYER ==========\n";
        cout << "1. Add Songs\n";
        cout << "2. Display Playlist\n";
        cout << "3. Play Specific Song\n";
        cout << "4. Remove Song\n";
        cout << "5. Play Songs By Artist\n";
        cout << "6. Sort Playlist By Artist\n";
        cout << "7. Randomize Playlist\n";
        cout << "8. Play By Theme\n";
        cout << "9. Exit\n";
        cout << "Enter Your Choice : ";

        cin >> ch;

        switch (ch)
        {
        case 1:
            s1.input();
            break;

        case 2:
            s1.display();
            break;

        case 3:
            s1.search();
            break;

        case 4:
            s1.remove_song();
            break;

        case 5:
            s1.play_artist();
            break;

        case 6:
            s1.sort();
            break;

        case 7:
            s1.randomize();
            break;

        case 8:
            s1.play_theme();
            break;

        case 9:
            return 0;

        default:
            cout << "Invalid Choice\n";
        }
    }

    return 0;
}