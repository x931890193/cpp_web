//
// Created by sato on 2021/8/22.
//
template<typename T>
void swap(T &t1, T &t2) {
    T tmpT;
    tmpT = t1;
    t1 = t2;
    t2 = tmpT;
}


