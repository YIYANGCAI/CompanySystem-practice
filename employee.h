//
// Created by apple on 2021/4/3.
//

#ifndef PROJECT2_STAFF_SYSTEM_EMPLOYEE_H
#define PROJECT2_STAFF_SYSTEM_EMPLOYEE_H

#endif //PROJECT2_STAFF_SYSTEM_EMPLOYEE_H

#pragma once
#include <iostream>
#include <string.h>
#include "worker.h"
using namespace std;

class Employee: public Worker{
public:
    Employee(int id, string name, int position);
    //~Employee();
    virtual void showInfo();
    virtual void showPosition();
};