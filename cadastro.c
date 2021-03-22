/*
attron(COLOR_PAIR(1)) destroi o cedilha!
*/
#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>

char *getCharField( int x, int y1, int y2, int tam, char *label) {
    char *retorno;
    retorno = malloc(sizeof(char)*255);
    move(x,y1);
    attron(COLOR_PAIR(1));
    printw(label);
    move(x,y2);
    attron(COLOR_PAIR(3));
    for (int i=0;i<tam;i++) {
        printw(" ");
    }
    move(x,y2);
    echo();
    getnstr(retorno,tam);
    return retorno;
}
int main() {
    initscr();
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_BLUE);
    init_pair(2,COLOR_RED,COLOR_WHITE);
    init_pair(3,COLOR_BLUE,COLOR_WHITE);
    
    bkgd(COLOR_PAIR(1));
    clear();
    noecho();
    cbreak();   
    char *nome, *end, *bairro;
    nome    = getCharField(1,5,15,20,"NOME:");
    end     = getCharField(3,5,15,20,"ENDERECO:");
    bairro  = getCharField(5,5,15,20,"BAIRRO:");
    refresh();
    endwin();
    return 0;
}