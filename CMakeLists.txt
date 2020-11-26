cmake_minimum_required(VERSION 3.15)
project(biquadris)

set(CMAKE_CXX_STANDARD 14)

add_executable(biquadris main.cpp centralcommand.h centralcommand.cc board.h playercommands.cc playercommands.h playerinfo.h subject.h subject.cc
        observer.h choice.h choice.cc observeroftimeandactivationtime.cc observeroftimeandactivationtime.h board.cc factoryblock.h level.cpp level1block.cpp level.h level1block.h
        blockcontent.h tblockcontent.h tblockcontent.cc blockcontent.cpp blockoperation.h blockoperation.cpp
        cell.cpp cell.h theboard.h theboard.cpp leftoperation.cpp leftoperation.h
        setup.cpp setup.h playerinfo.cpp factoryblock.h factoryblock.cpp observer.cpp iblockcontent.cpp iblockcontent.h jblockcontent.cpp jblockcontent.h lblockcontent.cpp lblockcontent.h oblockcontent.cpp oblockcontent.h sblockcontent.cpp sblockcontent.h zblockcontent.cpp zblockcontent.h rightoperation.cpp rightoperation.h downoperation.cpp downoperation.h whatcomesnext.h rotateoperation.cpp rotateoperation.h counterrotateoperation.cpp counterrotateoperation.h level3block.cpp level3block.h level2block.cpp level2block.h level0block.cpp level0block.h)