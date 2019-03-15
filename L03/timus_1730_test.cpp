//
//  timus_1730_test.cpp
//  lab3
//
//  Created by Илья Ершов on 15/03/2019.
//  Copyright © 2019 Ilia Ershov. All rights reserved.
//


#include <stdio.h>
#include "Header.h"
#define TAP_COMPILE
#include "libperl---master/tap++/headers/tap++.h"

using namespace TAP;
int _tmain()
 {
 
 plan(4); // указываем количество тестов
 // тесты:
 // ok(x,msg) - тест проходит если условие x выполняется, msg - название теста
 // ok1(x) - тоже что и ok(x,msg), в качестве названия автоматически подставляется текст условия
 
 ok(GCD(4,8)==1);
 ok(GCD(4,8)==1,"factorial of zero is equal 1");
 //ok(factorial(-5)==-1,"factorial of -5 - error (-1)");
 //ok(factorial(100)==-2,"factorial of 100 - error (-2)");
 return exit_status(); // вывод отчета по тестам
 
 }
