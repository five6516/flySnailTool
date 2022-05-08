#pragma once
#include <QApplication>

#define SAFE_DELETE(p) {if(p){delete p;p=nullptr;}}
#define SAFE_DELETE_ARRAY(p) {if(p){delete[] p;p=nullptr;}}

#if (defined(_MSC_VER))
#pragma execution_character_set("utf-8")
#endif
