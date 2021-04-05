//
// Created by apple on 2021/4/3.
//

#ifndef PROJECT2_STAFF_SYSTEM_WORKER_H
#define PROJECT2_STAFF_SYSTEM_WORKER_H

#endif //PROJECT2_STAFF_SYSTEM_WORKER_H
#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Worker{
public:
    // 显示个人信息
    virtual void showInfo() = 0;
    // 获得岗位名称
    virtual void showPosition() = 0;
    int m_id;//id
    string m_name;//name
    int m_Position;//position
};