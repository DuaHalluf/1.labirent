#include "maze.h"
#include <fstream>
#include <iostream>
#include <stack>
#include <vector>
#ifdef _WIN32
#include <windows.h>
#else
#include <thread>
#include <chrono>
#endif

Maze::Maze(const std::string &dosyaAdi) {
    std::ifstream dosya(dosyaAdi);
    if (!dosya) {
        std::cerr << "Dosya açılamadı: " << dosyaAdi << std::endl;
        exit(1);
    }

    std::string satir;
    while (std::getline(dosya, satir)) {
        labirent.push_back(satir);
    }
    dosya.close();

    // Başlangıç ve çıkış konumlarını tanımlayın
    baslangic = {1, 1};  // Başlangıç konumu
    cikis = {19, 20};  // Çıkış konumu (Harita.txt'deki son pozisyon)
}

void Maze::labirentiYazdir() {
    for (const auto &satir : labirent) {
        std::cout << satir << std::endl;
    }
}

void Maze::labirentiGuncelle() {
    system("clear"); // Unix/Linux ve MacOS için
    // system("cls"); // Windows için
    labirentiYazdir();
}

bool Maze::gecerliHareket(Konum konum) {
    return konum.x >= 0 && konum.x < static_cast<int>(labirent.size()) && konum.y >= 0 && konum.y < static_cast<int>(labirent[0].size()) && (labirent[konum.x][konum.y] == ' ' || labirent[konum.x][konum.y] == 'e');
}

bool Maze::hareketEt(Konum konum) {
    std::stack<Konum> yigin;
    yigin.push(baslangic);
    labirent[baslangic.x][baslangic.y] = '>';

    labirentiGuncelle();

    std::vector<Konum> yonler = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    while (!yigin.empty()) {
        Konum mevcut = yigin.top();

        if (mevcut.x == cikis.x && mevcut.y == cikis.y) {
            labirent[cikis.x][cikis.y] = 'e';
            labirentiGuncelle();
            return true;
        }

        yigin.pop();

        bool ileriGidildi = false;

        for (const auto& yon : yonler) {
            Konum yeni = {mevcut.x + yon.x, mevcut.y + yon.y};
            if (gecerliHareket(yeni)) {
                yigin.push(yeni);
                if (labirent[yeni.x][yeni.y] != 'e') {
                    labirent[yeni.x][yeni.y] = '>';
                }
                labirentiGuncelle();

                #ifdef _WIN32
                Sleep(500);  // milliseconds
                #else
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                #endif

                ileriGidildi = true;
                break;
            }
        }

        if (!ileriGidildi) {
            if (labirent[mevcut.x][mevcut.y] != 'e') {
                labirent[mevcut.x][mevcut.y] = ' ';
            }
            if (!yigin.empty()) {
                Konum onceki = yigin.top();
                if (labirent[onceki.x][onceki.y] != 'e') {
                    labirent[onceki.x][onceki.y] = '>';
                }
                labirentiGuncelle();

                #ifdef _WIN32
                Sleep(500);  // milliseconds
                #else
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                #endif
            }
        }
    }

    return false;
}

bool Maze::labirentiCoz() {
    return hareketEt(baslangic);
}
