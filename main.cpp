#include <iostream>
using namespace std;
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

void test(){
    // 父类指针指向子类对象
    Worker * p1 = NULL;
    p1 = new Employee(1, "frank", 1);
    p1->showInfo();
    p1->showPosition();
    // new 使用之后需要手动释放内存
    //delete p1;

    Worker * p2 = NULL;
    p2 = new Manager(2, "frank2", 2);
    p2->showInfo();
    p2->showPosition();
    //delete p2;

    Worker * p3 = NULL;
    p3 = new Boss(3, "frank3", 3);
    p3->showInfo();
    p3->showPosition();
    //delete p3;
}

int main() {
    //test();
    WorkerManager wm;

    while (true){
        wm.showMenu();
        int choice;
        cout << "请输入您的选择" << endl;
        cin >> choice;
        switch (choice) {
            case 0:
                wm.exitSystem();
                break;
            case 1:
                wm.addEmp();
                break;
            case 2:
                wm.showEmps();
                break;
            case 3:
            {
                int del_id;
                cout << "请输入想要删除的用户id:" << endl;
                cin >> del_id;
                wm.delEmp(del_id);
                break;
            }
            case 4:
            {
                int change_id;
                cout << "请输入想要删除的用户id:" << endl;
                cin >> change_id;
                wm.changeEmp(change_id);
                break;
            }
            case 5:
                wm.redundancyFunc();
                break;
            case 6:
                wm.redundancyFunc();
                break;
            case 7:
                wm.redundancyFunc();
                break;
        }
    }

    return 0;
}
