#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "playlist.h"
#include <string>

#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace std;

class Player
{
private:
    float Volume = 10;
    Node *currentSurahNode;
    Playlist *playlist;
    sf::Music music;

public:
    Player(Playlist *playlist) : playlist(playlist), currentSurahNode(nullptr)
    {
        music.setVolume(Volume);
    }

    // Set the current Surah to a specific node and start playing
    void SetCurrentSurah(Node *node)
    {
        currentSurahNode = node;
        Play();
    }

    // Play the current Surah
    void Play()
    {
        if (currentSurahNode && currentSurahNode->surah)
            string fullPath = currentSurahNode->surah->getFullPath();
            string fullPath = currentSurahNode->surah->getFullPath();
            if (music.openFromFile(fullPath)) // Load the audio from the full path
            {
                cout << "Playing: " << currentSurahNode->surah->getName() << "\n";
                cout << "Playing: " << currentSurahNode->surah->getName() << "\n";
            }
            else
                cout << "Error: Unable to load audio file: " << fullPath << "\n";
                cout << "Error: Unable to load audio file: " << fullPath << "\n";
            }
        }
        else
            cout << "No surah selected to play." << "\n";
            cout << "No surah selected to play." << "\n";
        }
    }

    // Pause the current Surah
    void Pause()
    {
        if (music.getStatus() == sf::Music::Playing)
        {
            cout << "Paused: " << currentSurahNode->surah->getName() << "\n";
            cout << "Paused: " << currentSurahNode->surah->getName() << "\n";
        }
    }

    // Stop Current Surah
    void Stop()
    {
        if (music.getStatus() != sf::Music::Stopped)
        {
            cout << "Stopped: " << currentSurahNode->surah->getName() << "\n";
            cout << "Stopped: " << currentSurahNode->surah->getName() << "\n";
        }
    }

    // Play Next Surah
    void Next()
    {
        if (currentSurahNode && currentSurahNode->next)
        {
            currentSurahNode = currentSurahNode->next;
            Play();
        }
        else
            cout << "No next surah." << "\n";
            cout << "No next surah." << "\n";
        }
    }

    // Play Previous Surah
    void Previous()
    {
        if (currentSurahNode && currentSurahNode->prev)
        {
            currentSurahNode = currentSurahNode->prev;
            Play();
        }
        else
            cout << "No previous surah." << "\n";
            cout << "No previous surah." << "\n";
        }
    }

    // Resume the current Surah (if paused)
    void Resume()
    {
        if (music.getStatus() == sf::Music::Paused)
        {
            cout << "Resumed: " << currentSurahNode->surah->getName() << "\n";
            cout << "Resumed: " << currentSurahNode->surah->getName() << "\n";
        }
    }

    // Helper Function to know the status of my surah (Chatgpt's Idea)
    sf::SoundSource::Status GetMusicStatus()
    {
        return music.getStatus();
    }

    // Functions to Control Volume(Own Idea)
    void Raise_Volume()
    {
        Volume = Volume + 10;
        if (Volume > 100)
        {
            cout << "Maximum Volume Reached! (" << Volume << ")" << "\n";
            cout << "Maximum Volume Reached! (" << Volume << ")" << "\n";
        }
        else
        {
            cout << "Volume Raised (" << Volume << ")" << "\n";
            cout << "Volume Raised (" << Volume << ")" << "\n";
        }
    }
    void Lower_Volume()
    {
        Volume = Volume - 10;
        if (Volume < 0)
        {
            cout << "Minimum Volume Reached! (" << Volume << ")" << "\n";
            cout << "Minimum Volume Reached! (" << Volume << ")" << "\n";
        }
        else
        {
            cout << "Volume Lowered (" << Volume << ")" << "\n";
            cout << "Volume Lowered (" << Volume << ")" << "\n";
        }
    }
};

#endif // PLAYER_H
