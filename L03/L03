
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <iostream>
#include "Header.h"
#define TAP_COMPILE

using namespace std;

int GCD(int a, int b)//наибольший общий делитель
{
    while (a % b != 0)
    {
        a %= b;
        swap(a, b);
    }
    return b;
}

bool Check(int x)//проверка является ли знаментаель числом вида 2^x
{
    for (int i = 0; i <= 10; ++i)
        if (x == (1 << i))//умножение на 2 в степени i(побитовые сдвиги)
            return true;
    return false;
}

int GetLevel(int x) //возвращает номер поколения х
{
    for (int i = 0; i <= 10; ++i)
        if (x < (1 << (i + 1)) - 1)
            return i;
    return -1;
}

bool visited[2048];//почему 2048, откуда такое ограничение
int creature[2048], ind[2048];
queue<int> Q;

int main() {
    int n = 0; // кол-во имён
    char x[201];//максимальная длина имени существа
    string s, name[10];//задефаййнить магические константы!!!
    
    cin >> x;
    //scanf("%s", x);//считали все имя существа и добавили - в конец, чтоб удобно было считывать
    s = string(x) + "-";
    
    int L = s.size();//размер строки
    
    for (int i = 0; i < L; ++i)//парсим строку на массив имен
    {
        name[n] = string();
        while (s[i] != '-')
        {
            name[n] += s[i];
            ++i;
        }
        ++n;
    }
    
    int a[10], b[10];//числители и знаменатели(столько же сколько и имен)
    bool possible = true;
    
    for (int i = 0; i < n; ++i) {
        char x;
        cin >> a[i] >> x >> b[i];
        //scanf("%d/%d", &a[i], &b[i]);//считали
        
        int g = GCD(a[i], b[i]);// нашли НОД
        a[i] /= g; b[i] /= g;// сократили дробь
        a[i] *= 1024 / b[i];//????
        
        if (!Check(b[i])) //
            possible = false;
    }
    
    if (!possible)
        cout << "No solution";
        //puts("No solution");
    else
    {
        int total = 1024, strNum = 0;
        Q.push(0);
        
        memset(visited, false, sizeof(visited));
        memset(creature, -1, sizeof(creature));
        
        while (total != 0)
        {
            int cur = Q.front();
            Q.pop();
            
            int lvl = GetLevel(cur);
            int pow2 = (1 << (10 - lvl));
            bool used = false;
            visited[cur] = true;
            ++strNum; //Всего строк в родословной
            
            for (int i = 0; i < n; ++i)
            {
                if (a[i] >= pow2)
                {
                    a[i] -= pow2;
                    total -= pow2;
                    creature[cur] = i;
                    used = true;
                    break;
                }
            }
            
            if (!used)
            {
                Q.push(2 * cur + 1);
                Q.push(2 * cur + 2);
            }
        }
        
        cout << strNum << endl;
        //printf("%d\n", strNum);
        
        for (int i = 2047, j = 1; i >= 0; --i)
        {
            if (visited[i])
            {
                ind[i] = j++;
                
                if (creature[i] != -1)
                    cout << name[creature[i]] << endl;
                    //printf("%s\n", name[creature[i]].c_str());
                else
                    cout << ind[2 * i + 1] << " " << ind[2 * i + 2] << endl;
                    //printf("%d %d\n", ind[2 * i + 1], ind[2 * i + 2]);
            }
        }
    }
    
    return 0;
}

