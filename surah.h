#ifndef SURAH_H
#define SURAH_H
#include <string>
#include <iostream>

using namespace std;

class Surah
{
private:
    string Name, Type, Path;
    string FullPath;

public:
    Surah(string N, string T, string p)
    {
        Name = N;
        Type = T;
        Path = p;
        FullPath = Path + "\\" + Name + ".wav";
    }

    void setName(string N)
    {
        Name = N;
    }

    void setType(string T)
    {
        Type = T;
    }

    void setPath(string p)
    {
        Path = p;
    }

    string getName()
    {
        return Name;
    }

    string getType()
    {
        return Type;
    }

    string getPath()
    {
        return Path;
    }
    string getFullPath()
    {
        return FullPath;
    }
};

#endif // SURAH_H
