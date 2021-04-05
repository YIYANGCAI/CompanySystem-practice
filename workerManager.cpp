//
// Created by apple on 2021/4/3.
//

#include "workerManager.h"
// 构造函数
WorkerManager::WorkerManager() {
    // 文件不存在
    ifstream ifs;
    ifs.open(FILE_NAME, ios::in);
    if (!ifs.is_open()){
        // 文件不存在，初始化为0
        this->fileisEmpty = true;
        this->empNum = 0;
        this->m_EmpArray = NULL;
    }
    // 文件存在
    else{
        char ch;
        ifs >> ch;
        if (ifs.eof()){
            // 文件存在但是为空
            this->fileisEmpty = true;
            this->empNum = 0;
            this->m_EmpArray = NULL;
        }
        else {
            this->initEmpData();
        }
    }
    ifs.close();
}

// 获取txt文件中的人数
int WorkerManager::get_num() {
    ifstream ifs;
    ifs.open(FILE_NAME, ios::in);
    int id;
    string name;
    int position;
    int total_num = 0;
    while(ifs >> id && ifs >> name && ifs >> position){
        total_num ++;
    }
    ifs.close();
    return total_num;
}

// 初始化文件
void WorkerManager::initEmpData(){
    int num = this->get_num();
    this->empNum = num;
    this->m_EmpArray = new Worker*[this->empNum];
    // 读入文件
    ifstream ifs;
    ifs.open(FILE_NAME, ios::in);
    int id;
    string name;
    int position;

    int i = 0;
    while(ifs >> id && ifs >> name && ifs >> position){
        Worker * worker = NULL;
        if (position == 1){
            worker = new Employee(id, name, position);
        }
        else if (position == 2){
            worker = new Manager(id, name, position);
        }
        else if (position == 3){
            worker = new Boss(id, name, position);
        }
        this->m_EmpArray[i] = worker;
        i++;
    }
    ifs.close();
}

// 析构函数
WorkerManager::~WorkerManager() {

}

// 存储信息到txt文件
void WorkerManager::saveFile() {
    /*
     * 写文件操作
     * 1 包含头文件 # include <fstream>
     * 2 创建流对象 ofstream ofs;
     * 3 打开文件 ofs.open(file_path, mode= ios.out)
     * 4 写数据 ofs << "the content you want to write"
     * 5 关闭文件
     * */
    ofstream ofs;
    ofs.open(FILE_NAME, ios::out);
    for (int i = 0; i < this->empNum; ++i){
        cout << this->m_EmpArray[i]->m_Position << endl;
        ofs << this->m_EmpArray[i]->m_id << " " << this->m_EmpArray[i]->m_name << " " << this->m_EmpArray[i]->m_Position << endl;
    }
    ofs.close();
}

// 添加用户
void WorkerManager::addEmp() {
    cout << "请输入添加的员工数量" << endl;
    int add_num = 0; // 保存用户的输入数量
    cin >> add_num;
    if (add_num >= 0){
        // 合法输入
        // 计算新空间大小
        int newSize = this->empNum + add_num;
        // 建立一个新的数组
        Worker ** newSpace = new Worker*[newSize];
        // 首先写入原来的全部数据
        for (int i = 0; i < this->empNum; ++i) {
            newSpace[i] = this->m_EmpArray[i];
        }
        //随后输入新的数据
        for (int i = 0; i < add_num; ++i) {
            int id;
            string name;
            int position;

            cout << "请输入第" << i+1 << "个新增员工的编号" << endl;
            cin >> id;
            cout << "请输入第" << i+1 << "个新增员工的名字" << endl;
            cin >> name;
            cout << "请输入第" << i+1 << "个新增员工的岗位（1为普通职工 2为经理 3为老板）" << endl;
            cin >> position;

            Worker * newInput = NULL;
            switch (position) {
                case 1:
                    newInput = new Employee(id, name, position);
                    break;
                case 2:
                    newInput = new Manager(id, name, position);
                    break;
                case 3:
                    newInput = new Boss(id, name, position);
                    break;
            }
            // 保存到数组中
            newSpace[this->empNum + i] = newInput;

        }
        // 释放原来的空间
        delete[] this->m_EmpArray;
        this->m_EmpArray = newSpace;
        this->empNum = newSize;
        cout << "添加成功" << endl;

        // 保存数据到文件中
        this->saveFile();
        this->fileisEmpty = false;
    }
    else{
        cout << "输入有误" << endl;
    }
}

// 显示一个菜单
void WorkerManager::showMenu(){
    cout << "***************************************************************************" << endl;
    cout << "*****************************欢迎使用职工管理系统******************************" << endl;
    cout << "******************************0 退出管理系统*********************************" << endl;
    cout << "******************************1 增加员工信息*********************************" << endl;
    cout << "******************************2 显示职工信息*********************************" << endl;
    cout << "******************************3 删除职工信息*********************************" << endl;
    cout << "******************************4 修改职工信息*********************************" << endl;
    cout << "******************************5 查找职工信息*********************************" << endl;
    cout << "******************************6 按照编号排序*********************************" << endl;
    cout << "******************************7 清空所有信息*********************************" << endl;
    cout << "***************************************************************************" << endl;
}

// 退出程序
void WorkerManager::exitSystem(){
    cout << "程序退出，欢迎下次使用!" << endl;
    exit(0);
}

// 显示所有的用户
void WorkerManager::showEmps() {
    if (this->m_EmpArray == NULL){
        cout << "the database is empty!" << endl;
    }
    else{
        for (int i = 0;i < this->empNum; i++){
            cout << "职工编号：" << this->m_EmpArray[i]->m_id << "\t"
            << "职工姓名：" << this->m_EmpArray[i]->m_name << "\t"
            << "职工岗位：" << this->m_EmpArray[i]->m_Position << "\t" << endl;
        }
    }
}

void WorkerManager::delEmp(int del_id){
    int flag = this->isExist(del_id);
    int new_length = this->empNum - 1;
    int j = 0;
    if (flag >= 0){
        Worker ** new_array = new Worker*[new_length];
        for (int i=0; i<this->empNum; i++){
            if (i != flag){
                new_array[j] = this->m_EmpArray[i];
                j++;
            }
            else{
                continue;
            }
        }
        this->m_EmpArray = new_array;
        this->empNum = new_length;
        this->saveFile();
    }
    else{
        cout << "不存在该编号的用户" << endl;
    }
}

int WorkerManager::isExist(int w_id){
    int flag = -1;
    for(int i = 0; i < this->empNum; i++){
        if(this->m_EmpArray[i]->m_id == w_id){
            flag = i;
        }
    }
    return flag;
}

void WorkerManager::changeEmp(int change_id) {
    int flag = this->isExist(change_id);
    if (flag >=0){
        // 存在
        int id;
        string name;
        int position;
        cout << "请输入员工的编号" << endl;
        cin >> id;
        cout << "请输入员工的名字" << endl;
        cin >> name;
        cout << "请输入员工的岗位（1为普通职工 2为经理 3为老板）" << endl;
        cin >> position;

        Worker * newInput = NULL;
        switch (position) {
            case 1:
                newInput = new Employee(id, name, position);
                break;
            case 2:
                newInput = new Manager(id, name, position);
                break;
            case 3:
                newInput = new Boss(id, name, position);
                break;
        }
        this->m_EmpArray[flag] = newInput;
        this->saveFile();
    }
    else{
        cout << "不存在该编号的用户" << endl;
    }
}

void WorkerManager::redundancyFunc(){
    cout << "冗余模块，待写入特定功能" << endl;
}