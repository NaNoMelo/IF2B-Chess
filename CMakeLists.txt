cmake_minimum_required(VERSION 3.21)
project(IF2B_Chess C)

set(CMAKE_C_STANDARD 11)

add_executable(IF2B_Chess
        main.c saisie.c saisie.h board.c board.h verif.c verif.h save.c save.h game.c game.h)
