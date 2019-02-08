//
//  teddy_hater.cpp
//  teddyhatters
//
//  Created by Илья Ершов on 18/12/2018.
//  Copyright © 2018 Ilia Ershov. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    int time = 0;
    int manNum, teddyHtr;
    int htrPos = 0;
    cin >> manNum >> teddyHtr;
    for (int i = 0; i < teddyHtr; ++i){
        cin >> htrPos;
        if (htrPos == 1){
            break;
        }
    }
    //
    if (manNum / 3 > teddyHtr) {
        time = 0;
    } else if (manNum / 3 == teddyHtr) {
        time = teddyHtr * (manNum - teddyHtr - 1);
    } else {
        if (htrPos != 1) {
            time = teddyHtr * (manNum - teddyHtr - 1) + (teddyHtr * (teddyHtr - 1)) / 2;
        } else if (manNum / 3 < teddyHtr - 1) {
            if (htrPos == 1) {
                time = (manNum - teddyHtr) * (teddyHtr - 1) + (teddyHtr - 1) * (teddyHtr - 2) / 2 +
                (manNum - teddyHtr) * (manNum - 1 - teddyHtr) / 2;
            }
        } else {
            time = (manNum - teddyHtr) * (manNum - teddyHtr);
        }
    }
    cout << time;
    return 0;
}
