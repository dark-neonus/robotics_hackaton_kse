#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <StackArray.h> // Needed for Arduino compatibility

class MoveStamp {
public:
    int speed;
    int delta_rotation;
    int time;
    MoveStamp(int speed, int delta_rotation, int time) {
        this->speed = speed;
        this->delta_rotation = delta_rotation;
        this->time = time;
    }
};

class Node {
public:
    bool left_branch;
    bool right_branch;
    bool center_branch;

    StackArray<MoveStamp> moves;

    Node(bool left, bool center, bool right)
    : left_branch(left), right_branch(right), center_branch(center) {}

    void addMove(MoveStamp move) {
        moves.push(move);
    }
};

#endif