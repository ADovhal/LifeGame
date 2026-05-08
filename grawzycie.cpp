
#include "grawzycie.h"
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

Engine::Engine() : nw(0), nk(0), Tab(0), tmp(0)
{
    ifstream mg("init.txt");
    mg >> nw;
    mg >> nk;

    Tab = new bool*[nw];
    tmp = new bool*[nw];

    for (int n = 0; n < nw; n++) {
        Tab[n] = new bool[nk];
        tmp[n] = new bool[nk];
    }

    for (int i = 0; i < nw; i++) {
        for (int j = 0; j < nk; j++) {
            Tab[i][j] = 0;
            tmp[i][j] = 0;
        }
    }

    int alive, w, k;
    mg >> alive;

    for (int i = 0; i < alive; i++) {
        mg >> w;
        mg >> k;
        Tab[w][k] = 1;
    }

    mg.close();
}

Engine::~Engine()
{
    for (int i = 0; i < nw; i++) {
        delete[] Tab[i];
        delete[] tmp[i];
    }

    delete[] Tab;
    delete[] tmp;
}

void Engine::Analiza()
{
    for (int w = 1; w < nw - 1; w++) {
        for (int k = 1; k < nk - 1; k++) {
            int alive = Analiza1kom(w, k);
            bool ns = Tab[w][k];
	    if (alive == 3) ns = 1;
            else if (alive == 2 && ns) ns = 1;
            else ns = 0;

            tmp[w][k] = ns;
        }
    }

    for (int w = 0; w < nw; w++) {
        for (int k = 0; k < nk; k++) {
            Tab[w][k] = tmp[w][k];
        }
    }
}

int Engine::Analiza1kom(int w, int k)
{
    int cnt = 0;

    if (Tab[w - 1][k - 1]) cnt++;
    if (Tab[w - 1][k])     cnt++;
    if (Tab[w - 1][k + 1]) cnt++;
    
    if (Tab[w][k - 1])     cnt++;
    if (Tab[w][k + 1])     cnt++;
    
    if (Tab[w + 1][k - 1]) cnt++;
    if (Tab[w + 1][k])     cnt++;
    if (Tab[w + 1][k + 1]) cnt++;

    return cnt;
}

Game::Game() {}

void Game::Play()
{
    while (true) {
        View();
        E.Analiza();
        Delay(1000000);
    }
}

void Game::View()
{
    system("cls");

    int w = E.getW();
    int k = E.getK();
    bool** tab = E.getTab();

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < k; j++) {
            cout << (tab[i][j] ? 'O' : '.');
        }
        cout << endl;
    }
    cout << endl;
}

void Game::Delay(int n)
{
    int nt = 0;
    while (nt < n) {
        nt++;
    }
}
