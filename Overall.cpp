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
    song_list()
    {
        start = NULL;
        last = NULL;
    }

    void add_song(song s1)
    {
        song *ns = new song;

        if (ns == NULL)
            return;

        ns->title = s1.title;
        ns->artist = s1.artist;
        ns->duration = s1.duration;
        ns->theme = s1.theme;
        ns->next = NULL;

        if (start == NULL)
        {
            start = last = ns;
            return;
        }

        last->next = ns;
        last = ns;
    }

    void input()
    {
        int choice;
        song s1;

        while (true)
        {
            cout << "\nEnter 1 to Add Song\nEnter 2 to Stop\n";
            cin >> choice;

            if (choice == 1)
            {
                cout << "Enter Song Title : ";
                cin >> s1.title;

                cout << "Enter Song Duration : ";
                cin >> s1.duration;

                cout << "Enter Artist Name : ";
                cin >> s1.artist;

                cout << "Enter Theme (Rain/Patriotic/Romantic/etc.) : ";
                cin >> s1.theme;

                add_song(s1);
            }

            if (choice == 2)
                break;
        }
    }

    void display()
    {
        if (start == NULL)
        {
            cout << "Playlist Empty\n";
            return;
        }

        song *ptr = start;

        while (ptr)
        {
            cout << ptr->title << " "
                 << ptr->duration << " "
                 << ptr->artist << " "
                 << ptr->theme << endl;

            ptr = ptr->next;
        }
    }

    void search()
    {
        string sname;

        cout << "Enter Song Name : ";
        cin >> sname;

        song *ptr = start;

        while (ptr)
        {
            if (ptr->title == sname)
            {
                cout << "\nPlaying Song...\n";
                cout << "Title : " << ptr->title << endl;
                cout << "Artist : " << ptr->artist << endl;
                cout << "Duration : " << ptr->duration << endl;
                cout << "Theme : " << ptr->theme << endl;
                return;
            }

            ptr = ptr->next;
        }

        cout << "Song Not Found\n";
    }

    void remove_song()
    {
        if (!start)
        {
            cout << "Playlist Empty\n";
            return;
        }

        string sname;
        cout << "Enter Song Title to Remove : ";
        cin >> sname;

        song *ptr = start;
        song *prev = NULL;

        while (ptr)
        {
            if (ptr->title == sname)
            {
                if (ptr == start)
                {
                    start = start->next;
                    if (ptr == last)
                        last = NULL;
                }
                else
                {
                    prev->next = ptr->next;

                    if (ptr == last)
                        last = prev;
                }

                delete ptr;
                cout << "Song Removed Successfully\n";
                return;
            }

            prev = ptr;
            ptr = ptr->next;
        }

        cout << "Song Not Found\n";
    }

    
    void play_artist()
    {
        string aname;

        cout << "Enter Artist Name : ";
        cin >> aname;

        song *ptr = start;

        int found = 0;

        while (ptr)
        {
            if (ptr->artist == aname)
            {
                found = 1;
                cout << ptr->title << " (" << ptr->duration << " sec)\n";
            }

            ptr = ptr->next;
        }

        if (!found)
            cout << "No Songs Found\n";
    }

   
    void play_theme()
    {
        string th;

        cout << "Enter Theme : ";
        cin >> th;

        song *ptr = start;

        int found = 0;

        while (ptr)
        {
            if (ptr->theme == th)
            {
                found = 1;
                cout << ptr->title << " - " << ptr->artist << endl;
            }

            ptr = ptr->next;
        }

        if (!found)
            cout << "No Songs Found\n";
    }

    
    void sort()
    {
        if (!start)
            return;

        for (song *i = start; i != NULL; i = i->next)
        {
            for (song *j = i->next; j != NULL; j = j->next)
            {
                if (i->artist > j->artist)
                {
                    swap(i->artist, j->artist);
                    swap(i->title, j->title);
                    swap(i->duration, j->duration);
                    swap(i->theme, j->theme);
                }
            }
        }

        cout << "Playlist Sorted By Artist\n";
    }

    
    void randomize()
    {
        int count = 0;

        song *ptr = start;

        while (ptr)
        {
            count++;
            ptr = ptr->next;
        }

        if (count <= 1)
            return;

        srand(time(0));

        for (int i = 0; i < count; i++)
        {
            int a = rand() % count;
            int b = rand() % count;

            song *p1 = start;
            song *p2 = start;

            for (int j = 0; j < a; j++)
                p1 = p1->next;

            for (int j = 0; j < b; j++)
                p2 = p2->next;

            swap(p1->artist, p2->artist);
            swap(p1->title, p2->title);
            swap(p1->duration, p2->duration);
            swap(p1->theme, p2->theme);
        }

        cout << "Playlist Randomized\n";
    }
};

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
        cout<<"Enter Your Choice : ";
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

