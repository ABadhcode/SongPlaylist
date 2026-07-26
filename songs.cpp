#include "songs.h"

song_list::song_list()
{
    start = NULL;
    last = NULL;
}

void song_list::add_song(song s1)
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

void song_list::input()
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

void song_list::display()
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

void song_list::search()
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

void song_list::remove_song()
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

void song_list::play_artist()
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

void song_list::play_theme()
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

void song_list::sort()
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

void song_list::randomize()
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