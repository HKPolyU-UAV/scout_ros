#ifndef UGV_MISSION_H
#define UGV_MISSION_H

#include "common.h"

deque<Vec4> waypoints;
double velocity_mission = 0.5;
double velocity_angular = 0.3;

deque<Vec4> Finite_stage_mission(){ //Normal mission
    waypoints.clear();
    // Waypoints
    Vec4 stage; // state x y duration
    stage << 1, 0, 1, 10;
    waypoints.push_back(stage);
    stage << 1, 1.5, 1.5, 10;
    waypoints.push_back(stage);
    stage << 1,-1.5, 1.5, 10;
    waypoints.push_back(stage);
    stage << 1,-1.5,-1.5, 10;
    waypoints.push_back(stage);
    stage << 1, 1.5,-1.5, 10;
    waypoints.push_back(stage);
    stage << 1, 0, 0, 60;  // state = 5; land.
    waypoints.push_back(stage);
    cout << " Mission generated!" << " Stage count: " << waypoints.size() << endl;
    return(waypoints);
}
#endif