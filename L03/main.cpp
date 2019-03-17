
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <iostream>
#include "functions.h"

using namespace std;

int main() {

	bool visited[2048];
	int creature[2048], ind[2048];
	queue<int> Q;
    int n = 0; //кол-во имЄн
    char x[201];//максимальна€ длина имени существа
    string s, name[10];
	int a[10], b[10];//числители и знаменатели(столько же сколько и имен)
	bool possible = true;
    
    cin >> x;
    s = string(x) + "-";
    
    short L = s.size();
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

    //считываем числители и провер€ем можно ли построить родословную
    for (int i = 0; i < n; ++i) {
        char x;
        cin >> a[i] >> x >> b[i];
        
        int g = GCD(a[i], b[i]);//находим Ќќƒ
        a[i] /= g; 
		b[i] /= g;// сокращаем дробь
        a[i] *= 1024 / b[i];
        
        if (!Check(b[i]))
            possible = false;
    }
    
    if (!possible)
        cout << "No solution";
    else
    {
        int total = 1024, strNum = 0;//¬сего строк в родословной(strNum)
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
            ++strNum; 
            
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
        
        for (int i = 2047, j = 1; i >= 0; --i)
        {
            if (visited[i])
            {
                ind[i] = j++;
                if (creature[i] != -1)
                    cout << name[creature[i]] << endl;
                else
                    cout << ind[2 * i + 1] << " " << ind[2 * i + 2] << endl;
            }
        }
    }
    return 0;
}


