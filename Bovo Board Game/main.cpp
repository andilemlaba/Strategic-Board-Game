/*
 * File:   main.cpp
 * Author: gumedea
 *
 * Created on April 18, 2016, 11:40 AM
 */

#include <QApplication>
#include "MiniBovo.hpp"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);

    MiniBovo game; //create game instance.
    game.start(); //setup then play game to completion.

    return 0;
}
