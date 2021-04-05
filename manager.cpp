//
// Created by apple on 2021/4/5.
//

#include "manager.h"

Manager::Manager(int id, string name, int position){
    this->m_id = id;
    this->m_name = name;
    this->m_Position = position;
}

// 显示个人信息
void Manager::showInfo() {
    cout << "职工的信息：" << endl;
    cout << "\t编号：" << this->m_id << endl;
    cout << "\t姓名：" << this->m_name << endl;
    cout << "\t岗位：" << this->m_Position << endl;
}

// 显示岗位
void Manager::showPosition() {
    cout << "该员工为经理" << endl;
}