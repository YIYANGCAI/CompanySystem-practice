//
// Created by apple on 2021/4/5.
//

#ifndef PROJECT2_STAFF_SYSTEM_MANAGER_H
#define PROJECT2_STAFF_SYSTEM_MANAGER_H

#endif //PROJECT2_STAFF_SYSTEM_MANAGER_H
#pragma once
#include <iostream>
#include <string.h>
#include "worker.h"

class Manager: public Worker{
public:
    Manager(int id, string name, int position);
    virtual void showInfo();
    virtual void showPosition();
};