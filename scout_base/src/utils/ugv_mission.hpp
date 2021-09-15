#ifndef UGV_MISSION_H
#define UGV_MISSION_H

#include "common.h"

deque<Vec4> waypoints;

deque<Vec4> Finite_stage_mission(){ //Normal mission
    waypoints.clear();
    // Waypoints
    Vec4 stage; // state x y duration
    stage << 1, 0, 0, 3;
    waypoints.push_back(stage);
    stage << 1, 1.5, 1.5, 3;
    waypoints.push_back(stage);
    stage << 1,-1.5, 1.5, 3;
    waypoints.push_back(stage);
    stage << 1,-1.5,-1.5, 3;
    waypoints.push_back(stage);
    stage << 1, 1.5,-1.5, 3;
    waypoints.push_back(stage);
    stage << 1, 0, 0, 60;  // state = 5; land.
    waypoints.push_back(stage);
    cout << " Mission generated!" << " Stage count: " << waypoints.size() << endl;
    return(waypoints);
}
#endif