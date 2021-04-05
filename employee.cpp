//
// Created by apple on 2021/4/3.
//

#include "employee.h"

Employee::Employee(int id, string name, int position) {
    this->m_id = id;
    this->m_name = name;
    this->m_Position = position;
}

// 显示个人信息
void Employee::showInfo() {
    cout << "职工的信息：" << endl;
    cout << "\t编号：" << this->m_id << endl;
    cout << "\t姓名：" << this->m_name << endl;
    cout << "\t岗位：" << this->m_Position << endl;
}

// 显示岗位
void Employee::showPosition() {
    cout << "该员工为普通员工" << endl;
}