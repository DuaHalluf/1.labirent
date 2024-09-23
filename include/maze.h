#ifndef MAZE_H
#define MAZE_H

#include <string>
#include <vector>

struct Konum {
    int x, y;
};

class Maze {
public:
    Maze(const std::string &dosyaAdi);
    void labirentiYazdir();
    void labirentiGuncelle();
    bool hareketEt(Konum konum);
    bool labirentiCoz();
    
private:
    std::vector<std::string> labirent;
    Konum baslangic;
    Konum cikis;
    bool gecerliHareket(Konum konum);
};

#endif
