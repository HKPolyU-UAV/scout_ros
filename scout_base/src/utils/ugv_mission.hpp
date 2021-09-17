#ifndef UGV_MISSION_H
#define UGV_MISSION_H

#include "common.hpp"

deque<Vec4> waypoints;

deque<Vec4> Finite_stage_mission(){ //Normal mission
    waypoints.clear();
    // Waypoints
    Vec4 stage; // state x y duration
    stage << 1, 0, 0, 10;
    waypoints.push_back(stage);
    stage << 1, 1, 1, 10;
    waypoints.push_back(stage);
    stage << 1, 1,-1, 10;
    waypoints.push_back(stage);
    stage << 1,-1,-1, 10;
    waypoints.push_back(stage);
    stage << 1,-1, 1, 10;
    waypoints.push_back(stage);
    stage << 1, 1, 1, 10;
    waypoints.push_back(stage);
    stage << 1, 1,-1, 10;
    waypoints.push_back(stage);
    stage << 1,-1,-1, 10;
    waypoints.push_back(stage);
    stage << 1,-1, 1, 10;
    waypoints.push_back(stage);
    stage << 1, 1, 1, 10;
    waypoints.push_back(stage);
    stage << 1, 1,-1, 10;
    waypoints.push_back(stage);
    stage << 1,-1,-1, 10;
    waypoints.push_back(stage);
    stage << 1,-1, 1, 10;
    waypoints.push_back(stage);
    stage << 1, 1, 1, 10;
    waypoints.push_back(stage);
    stage << 1, 1,-1, 10;
    waypoints.push_back(stage);
    stage << 1,-1,-1, 10;
    waypoints.push_back(stage);
    stage << 1,-1, 1, 10;
    waypoints.push_back(stage);
    stage << 1, 1, 1, 10;
    waypoints.push_back(stage);
    stage << 1, 1,-1, 10;
    waypoints.push_back(stage);
    stage << 1,-1,-1, 10;
    waypoints.push_back(stage);
    stage << 1,-1, 1, 10;
    waypoints.push_back(stage);
    stage << 1, 1, 1, 10;
    waypoints.push_back(stage);
    stage << 1, 1,-1, 10;
    waypoints.push_back(stage);
    stage << 1,-1,-1, 10;
    waypoints.push_back(stage);
    stage << 1,-1, 1, 10;
    waypoints.push_back(stage);
    stage << 1, 1, 1, 10;
    waypoints.push_back(stage);
    stage << 1, 1,-1, 10;
    waypoints.push_back(stage);
    stage << 1,-1,-1, 10;
    waypoints.push_back(stage);
    stage << 1,-1, 1, 10;
    waypoints.push_back(stage);
    stage << 1, 1, 1, 10;
    waypoints.push_back(stage);
    stage << 1, 1,-1, 10;
    waypoints.push_back(stage);
    stage << 1,-1,-1, 10;
    waypoints.push_back(stage);
    stage << 1,-1, 1, 10;
    waypoints.push_back(stage);
    stage << 1, 1, 1, 10;
    waypoints.push_back(stage);
    stage << 1, 1,-1, 10;
    waypoints.push_back(stage);
    stage << 1,-1,-1, 10;
    waypoints.push_back(stage);
    stage << 1,-1, 1, 10;
    waypoints.push_back(stage);
    stage << 1, 1, 1, 10;
    waypoints.push_back(stage);
    stage << 1, 1,-1, 10;
    waypoints.push_back(stage);
    stage << 1,-1,-1, 10;
    waypoints.push_back(stage);
    stage << 1,-1, 1, 10;
    waypoints.push_back(stage);
    stage << 1, 1, 1, 10;
    waypoints.push_back(stage);
    stage << 1, 1,-1, 10;
    waypoints.push_back(stage);
    stage << 1,-1,-1, 10;
    waypoints.push_back(stage);
    stage << 1,-1, 1, 10;
    waypoints.push_back(stage);
    stage << 1, 0, 0, 60;
    waypoints.push_back(stage);
    cout << " Mission generated!" << " Stage count: " << waypoints.size() << endl;
    return(waypoints);
}
#endif