#include"GlobalArray.h"


MapLabel *map[15][10];
bool beltCanUse(int m ,int n){
    if(map[m][n]->belt != nullptr && map[m][n]->belt->need && !(map[m][n]->takenUp)){
        return true;
    }
    return false;
}
bool trashbinCanUse(int m, int n){
    if(map[m][n]->trashbin != nullptr && map[m][n]->trashbin->need){
        return true;
    }
    return false;
}
int money = 0;
