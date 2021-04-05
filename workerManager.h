//
// Created by apple on 2021/4/3.
//

#ifndef PROJECT2_STAFF_SYSTEM_WORKERMANAGER_H
#define PROJECT2_STAFF_SYSTEM_WORKERMANAGER_H

#endif //PROJECT2_STAFF_SYSTEM_WORKERMANAGER_H
#pragma once
# include <iostream>
# include "worker.h"
# include "employee.h"
# include "manager.h"
# include "boss.h"
# include <fstream>
#define FILE_NAME "empfile.txt"

using namespace std;

class WorkerManager{
public:
    // 构造和析构函数
    WorkerManager();
    ~WorkerManager();
    int empNum; //记录总人数
    Worker ** m_EmpArray; // 维护一个员工的数组
    bool fileisEmpty; // 文件是否创建
    // 展示菜单
    void showMenu();
    // 退出系统
    void exitSystem();
    // 冗余函数模块
    void redundancyFunc();
    // 添加员工信息的函数
    void addEmp();
    // 存储文件
    void saveFile();
    // 统计文件中有多少个人
    int get_num();
    // 将文件中的数据读入（初始化）
    void initEmpData();
    // 显示所有的用户
    void showEmps();
    // 删除用户
    int isExist(int id);
    void delEmp(int id);
    // 修改用户
    void changeEmp(int id);
};