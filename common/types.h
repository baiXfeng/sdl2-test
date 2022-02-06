//
// Created by baifeng on 2021/7/12.
//

#ifndef SDL2_TEST_TYPES_H
#define SDL2_TEST_TYPES_H

template<typename T>
class Vector {
public:
    T x;
    T y;
};

typedef Vector<int> Vector2i;
typedef Vector<float> Vector2f;

#endif //SDL2_TEST_TYPES_H
