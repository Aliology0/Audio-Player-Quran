#include <iostream>
#include <string>
#include <fstream>

#include "playlist.h"
#include "player.h"

#include <SFML/Graphics.hpp>
using namespace std;

void Menu()
{
    cout << "\n"
    << "\t\t\t=====================================================" << "\n";
    cout << "\t\t\tQuraan Playlist Manager Simulation System\n";
    cout << "\t\t\tdeveloped by Mahmoud Alnamoly\n\n";
    cout << "\t\t\tQuraan Playlist Manager Menu: \n";
    cout << "\t\t\t1. Add a new playlist\n";
    cout << "\t\t\t2. Add Surah to an existing playlist\n";
    cout << "\t\t\t3. Remove Surah from an existing playlist\n";
    cout << "\t\t\t4. Update the order of existing playlist\n";
    cout << "\t\t\t5. Display All Current Playlists\n";
    cout << "\t\t\t6. Display all Surahs in a specific playlist\n";
    cout << "\t\t\t7. Display Surah in a specific playlist\n";
    cout << "\t\t\t8. Play Surah from specific playlist\n";
    cout << "\t\t\tPress left arrow (<-) to play the previous surah\n";
    cout << "\t\t\tPress right arrow (->) to play the next surah\n";
    cout << "\t\t\tPress up arrow (^) to raise volume\n";
    cout << "\t\t\tPress down arrow (v) to lower volume\n";
    cout << "\t\t\tPress Space to pause the current surah\n";
    cout << "\t\t\tPress Space to resume the current surah\n";
    cout << "\t\t\tPress Esc to exit current playlist & return back to menu\n";
    cout << "\t\t\t9. Save an existing playlist to a file\n";
    cout << "\t\t\t10. Load an existing playlist from a file\n";
    cout << "\t\t\t11. Remove an existing playlist\n";
    cout << "\t\t\t12. Exit\n";
    cout << "\t\t\t=====================================================" << "\n";
}

void AddNewPlaylist(Playlist *playlists[], int &playlistCount)
{
    string name;
    cout << "Enter the playlist name: ";
    cin.ignore();
    getline(cin, name);
    if (playlistCount < 10)
    {
        playlists[playlistCount] = new Playlist(name);
        playlistCount++;
        cout << "Playlist created: " << name << "\n";
    }
    else
    {
        cout << "Maximum playlist limit reached!" << "\n";
    }
}

void AddSurahToPlaylist(Playlist *playlists[], int playlistCount)
{
    string playlistName, surahName, surahType, surahPath;
    cout << "Enter the playlist name: ";
    cin.ignore();
    getline(cin, playlistName);

    Playlist *playlist = nullptr;
    for (int i = 0; i < playlistCount; ++i)
    {
        if (playlists[i]->getName() == playlistName)
        {
            playlist = playlists[i];
            break;
        }
    }

    if (playlist)
    {
        cout << "Enter the Surah name: ";
        getline(cin, surahName);
        cout << "Enter the Surah type (Makki/Madani): ";
        getline(cin, surahType);
        cout << "Enter the Surah path: ";
        getline(cin, surahPath);

        Surah *surah = new Surah(surahName, surahType, surahPath);
        playlist->AddSurah(surah);
        cout << "Surah added to playlist: " << playlistName << "\n";
    }
    else
    {
        cout << "Playlist not found!" << "\n";
    }
}

void RemoveSurahFromPlaylist(Playlist *playlists[], int playlistCount)
{
    string playlistName, surahName;
    cout << "Enter the playlist name: ";
    cin.ignore();
    getline(cin, playlistName);

    Playlist *playlist = nullptr;
    for (int i = 0; i < playlistCount; ++i)
    {
        if (playlists[i]->getName() == playlistName)
        {
            playlist = playlists[i];
            break;
        }
    }

    if (playlist)
    {
        cout << "Enter the Surah name to remove: ";
        getline(cin, surahName);

        Node *current = playlist->GetHead();
        bool surahFound = false;
        while (current)
        {
            if (current->surah->getName() == surahName)
            {
                playlist->RemoveSurah(current->surah);
                cout << "Surah removed from playlist: " << playlistName << "\n";
                surahFound = true;
                break;
            }
            current = current->next;
        }
        if (!surahFound)
        {
            cout << "Surah Not Found!" << "\n";
        }
    }
    else
    {
        cout << "Playlist not found!" << "\n";
    }
}

void UpdatePlaylistOrder(Playlist *playlists[], int playlistCount)
{
    string playlistName;
    cout << "Enter the playlist name to update the order: ";
    cin.ignore();
    getline(cin, playlistName);

    Playlist *playlist = nullptr;
    for (int i = 0; i < playlistCount; ++i)
    {
        if (playlists[i]->getName() == playlistName)
        {
            playlist = playlists[i];
            break;
        }
    }

    if (playlist)
    {
        cout << "Enter the Surah name to move: ";
        string surahName;
        getline(cin, surahName);

        Node *current = playlist->GetHead();
        Node *targetNode = nullptr;

        while (current)
        {
            if (current->surah->getName() == surahName)
            {
                targetNode = current;
                break;
            }
            current = current->next;
        }

        if (targetNode != nullptr)
        {
            Surah *tempSurah = targetNode->surah;
            playlist->RemoveSurah(tempSurah);
            playlist->AddSurah(tempSurah);
            cout << "Surah moved to the end: " << surahName << "\n";
        }
        else
        {
            cout << "Surah not found!" << "\n";
        }
    }
    else
    {
        cout << "Playlist not found!" << "\n";
    }
}

void DisplayAllPlaylists(Playlist *playlists[], int playlistCount)
{
    cout << "Displaying all playlists:\n";
    for (int i = 0; i < playlistCount; ++i)
    {
        cout << "Playlist: " << playlists[i]->getName() << "\n";
    }
}

void DisplaySurahsInPlaylist(Playlist *playlists[], int playlistCount)
{
    string playlistName;
    cout << "Enter the playlist name: ";
    cin >> playlistName;

    Playlist *playlist = nullptr;
    for (int i = 0; i < playlistCount; ++i)
    {
        if (playlists[i]->getName() == playlistName)
        {
            playlist = playlists[i];
            break;
        }
    }

    if (playlist)
    {
        playlist->DisplayAllSurahs();
    }
    else
    {
        cout << "Playlist not found!" << "\n";
    }
}

void DisplaySurahInPlaylist(Playlist *playlists[], int playlistCount)
{
    string playlistName;
    cout << "Enter the playlist name: ";
    cin.ignore();
    getline(cin, playlistName);

    Playlist *playlist = nullptr;
    for (int i = 0; i < playlistCount; ++i)
    {
        if (playlists[i]->getName() == playlistName)
        {
            playlist = playlists[i];
            break;
        }
    }

    if (playlist)
    {
        cout << "Enter the Surah name: ";
        string surahName;
        getline(cin, surahName);

        Node *current = playlist->GetHead();
        bool surahFound = false;
        while (current)
        {
            if (current->surah->getName() == surahName)
            {
                cout << "Surah Found: " << current->surah->getName() << "\n";
                surahFound = true;
                break;
            }
            current = current->next;
        }
        if (!surahFound)
        {
            cout << "Surah Not Found!" << "\n";
        }
    }
    else
    {
        cout << "Playlist not found!" << "\n";
    }
}

void PlaySurahFromPlaylist(Playlist *playlists[], int playlistCount, Player *&player)
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "Quraan Playlist Manager");

    string playlistName;
    cout << "Enter playlist name: ";
    cin.ignore();
    getline(cin, playlistName);

    Playlist *playlist = nullptr;
    for (int i = 0; i < playlistCount; i++)
    {
        if (playlists[i]->getName() == playlistName)
        {
            playlist = playlists[i];
            break;
        }
    }

    if (playlist)
    {
        if (player)
            delete player;
        player = new Player(playlist);
        player->SetCurrentSurah(playlist->GetHead());
        player->Play();
        PlaySurah(player, playlist, window);
    }
    else
    {
        cout << "Playlist not found!" << "\n";
    }
}

void RemovePlaylist(Playlist *playlists[], int &playlistCount)
{
    string playlistName;
    cout << "Enter the playlist name to remove: ";
    cin.ignore();
    getline(cin, playlistName);

    bool playlistFound = false;
    for (int i = 0; i < playlistCount; ++i)
    {
        if (playlists[i]->getName() == playlistName)
        {
            delete playlists[i];
            playlists[i] = nullptr;
            cout << "Playlist removed: " << playlistName << "\n";

            // Shift the remaining playlists
            for (int j = i; j < playlistCount - 1; ++j)
            {
                playlists[j] = playlists[j + 1];
            }
            playlistCount--;
            playlistFound = true;
            break;
        }
    }

    if (!playlistFound)
    {
        cout << "Playlist not found!" << "\n";
    }
}

void SavePlaylists(Playlist *playlists[], int playlistCount)
{
    ofstream out("Playlists.txt");
    if (out.is_open())
    {
        for (int i = 0; i < playlistCount; ++i)
        {
            out << "Playlist " << (i + 1) << "\n";
            out << "Name: " << playlists[i]->getName() << "\n";

            Node *current = playlists[i]->GetHead();
            while (current)
            {
                out << "Surah Name: " << current->surah->getName() << "\n";
                out << "Surah Type: " << current->surah->getType() << "\n";
                out << "Surah Path: " << current->surah->getPath() << "\n";
                current = current->next;
            }
            out << "\n";
        }

        out.close();
        cout << "All playlists saved to Playlists.txt" << "\n";
    }
    else
    {
        cout << "Failed to open file for saving!" << "\n";
    }
}

void LoadPlaylists(Playlist *playlists[], int &playlistCount)
{
    ifstream in("Playlists.txt");
    if (in.is_open())
    {
        string line, playlistName, surahName, surahType, surahPath;
        Playlist *currentPlaylist = nullptr;

        while (getline(in, line))
        {
            if (line.find("Playlist") != string::npos)
            {
                getline(in, line);
                if (line.find("Name: ") != string::npos)
                {
                    playlistName = line.substr(6);
                    currentPlaylist = new Playlist(playlistName);
                    playlists[playlistCount++] = currentPlaylist;
                }
            }
            else if (currentPlaylist)
            {
                if (line.find("Surah Name: ") != string::npos)
                {
                    surahName = line.substr(12);
                    getline(in, line);
                    surahType = line.substr(12);
                    getline(in, line);
                    surahPath = line.substr(12);

                    Surah *surah = new Surah(surahName, surahType, surahPath);
                    currentPlaylist->AddSurah(surah);
                }
            }
        }

        in.close();
        cout << "Playlists loaded successfully!" << "\n";
    }
    else
    {
        cout << "Failed to open file for loading!" << "\n";
    }
}

void PlaySurah(Player *player, Playlist *playlist, sf::RenderWindow &window)
{
    sf::Event event;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                break;
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Left) // Previous
                {
                    player->Previous();
                }
                else if (event.key.code == sf::Keyboard::Right) // Next
                {
                    player->Next();
                }
                else if (event.key.code == sf::Keyboard::Up) // Raise Volume
                {
                    player->Raise_Volume();
                }
                else if (event.key.code == sf::Keyboard::Down) // Lower Volume
                {
                    player->Lower_Volume();
                }
                else if (event.key.code == sf::Keyboard::Space) // Toggle Pause/Resume
                {
                    if (player->GetMusicStatus() == sf::SoundSource::Playing)
                        player->Pause();
                    else if (player->GetMusicStatus() == sf::SoundSource::Paused)
                        player->Resume();
                }
                else if (event.key.code == sf::Keyboard::Escape) // Exit
                {
                    player->Stop();
                    window.close();
                    break;
                }
            }
        }
    }
}

int main()
{
    Menu();
    bool Main_Menu = true;
    Playlist *playlists[10];
    int playlistCount = 0;
    Player *player = nullptr;
    int choice;

    while (Main_Menu)
    {
        cout << "Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            AddNewPlaylist(playlists, playlistCount);
            break;
        case 2:
            AddSurahToPlaylist(playlists, playlistCount);
            break;
        case 3:
            RemoveSurahFromPlaylist(playlists, playlistCount);
            break;
        case 4:
            UpdatePlaylistOrder(playlists, playlistCount);
            break;
        case 5:
            DisplayAllPlaylists(playlists, playlistCount);
            break;
        case 6:
            DisplaySurahsInPlaylist(playlists, playlistCount);
            break;
        case 7:
            DisplaySurahInPlaylist(playlists, playlistCount);
            break;
        case 8:
            PlaySurahFromPlaylist(playlists, playlistCount, player);
            break;
        case 9:
            SavePlaylists(playlists, playlistCount);
            break;
        case 10:
            LoadPlaylists(playlists, playlistCount);
            break;
        case 11:
            RemovePlaylist(playlists, playlistCount);
            break;
        case 12:
            cout << "Exiting the program..." << "\n";
            Main_Menu = false;
            break;
        default:
            cout << "Invalid choice! Please try again." << "\n";
            break;
        }
    }

    cout << "\n"
         << "\t\t\tThanks For Using The Application !" << "\n"
         << "\n";
    cout << "\t\t\tProject By: Ali Emad" << "\n";
    return 0;
}
