//
// Created by apple on 2021/4/5.
//

#ifndef PROJECT2_STAFF_SYSTEM_BOSS_H
#define PROJECT2_STAFF_SYSTEM_BOSS_H

#endif //PROJECT2_STAFF_SYSTEM_BOSS_H

#pragma once
#include <iostream>
#include <string.h>
#include "worker.h"

class Boss: public Worker{
public:
    Boss(int id, string name, int position);
    virtual void showInfo();
    virtual void showPosition();
};