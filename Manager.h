/* Manager - this object manages programm to do main actions
   actions list:
   1.add object
   2.delete object
   3.delete all
   4.save all
   5.close window
*/
#pragma once
#include<iostream>
#include<string>
using namespace std;

class Manager
{
private:
	string action;
public:
	void get_action();
	void check_action();
	Manager();
	~Manager();
};

