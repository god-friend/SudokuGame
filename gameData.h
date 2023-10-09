#ifndef GAMEDATA_H
#define GAMEDATA_H
#include <QDataStream>

template<class T>
class GameData{
public:
    T atDate;
    T timeTaken;

    GameData(){}
    GameData(T date, T time){
        atDate = date;
        timeTaken = time;
    }

    friend QDataStream &operator << (QDataStream &out, GameData data){
        out << data.atDate << data.timeTaken;
        return out;
    }

    friend QDataStream &operator >> (QDataStream &in, GameData &obj){
        in >> obj.atDate >> obj.timeTaken;
        return in;
    }

};


#endif // GAMEDATA_H
