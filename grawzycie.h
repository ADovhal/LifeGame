#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

class Engine {
private:
    int nw;
    int nk;
    bool** Tab;
    bool** tmp;

public:
    Engine();
    ~Engine();

    void Analiza();
    int Analiza1kom(int w, int k);
    int getW() const { return nw; }
    int getK() const { return nk; }
    bool** getTab() const { return Tab; }
};

class Game {
private:
    Engine E;

public:
    Game();
    void Play();
    void View();
    void Delay(int n);
};

#endif
