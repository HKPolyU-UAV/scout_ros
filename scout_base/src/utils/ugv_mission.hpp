#ifndef UGV_MISSION_H
#define UGV_MISSION_H

#include "common.hpp"

deque<Vec4> waypoints;

// deque<Vec4> Finite_stage_mission(){ //Normal mission
//     waypoints.clear();
//     // Waypoints
//     Vec4 stage; // state x y duration
//     stage << 1, 0, 0, 120;
//     waypoints.push_back(stage);
//     stage << 1, 1.2, 1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1,-1.2, 1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1,-1.2,-1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1, 1.2,-1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1, 1.2, 1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1,-1.2, 1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1,-1.2,-1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1, 1.2,-1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1, 1.2, 1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1,-1.2, 1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1,-1.2,-1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1, 1.2,-1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1, 1.2, 1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1,-1.2, 1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1,-1.2,-1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1, 1.2,-1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1, 1.2, 1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1,-1.2, 1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1,-1.2,-1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1, 1.2,-1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1, 1.2, 1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1,-1.2, 1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1,-1.2,-1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1, 1.2,-1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1, 1.2, 1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1,-1.2, 1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1,-1.2,-1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1, 1.2,-1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1, 1.2, 1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1,-1.2, 1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1,-1.2,-1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1, 1.2,-1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1, 1.2, 1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1,-1.2, 1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1,-1.2,-1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1, 1.2,-1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1, 1.2, 1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1,-1.2, 1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1,-1.2,-1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1, 1.2,-1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1, 1.2, 1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1,-1.2, 1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1,-1.2,-1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1, 1.2,-1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1, 1.2, 1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1,-1.2, 1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1,-1.2,-1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1, 1.2,-1.2, 120;
//     waypoints.push_back(stage);
//     stage << 1, 0, 0, 120;
//     waypoints.push_back(stage);
//     cout << " Mission generated!" << " Stage count: " << waypoints.size() << endl;
//     return(waypoints);

// }

deque<Vec4> Finite_stage_mission(){ //Normal mission
    waypoints.clear();
    // Waypoints
    Vec4 stage; // state x y duration
    stage << 1, 0, 0, 120;
    waypoints.push_back(stage);
    stage << 1, 2, 2, 120;
    waypoints.push_back(stage);
    stage << 1, -2, -1.4, 120;
    waypoints.push_back(stage);
    stage << 1, 2, 2, 120;
    waypoints.push_back(stage);
    stage << 1, -2, -1.4, 120;
    waypoints.push_back(stage);
    stage << 1, 2, 2, 120;
    waypoints.push_back(stage);
    stage << 1, -2, -1.4, 120;
    waypoints.push_back(stage);
    stage << 1, 2, 2, 120;
    waypoints.push_back(stage);
    stage << 1, -2, -1.4, 120;
    waypoints.push_back(stage);
    stage << 1, 2, 2, 120;
    waypoints.push_back(stage);
    stage << 1, -2, -1.4, 120;
    waypoints.push_back(stage);
    stage << 1, 2, 2, 120;
    waypoints.push_back(stage);
    stage << 1, -2, -1.4, 120;
    waypoints.push_back(stage);
    stage << 1, 2, 2, 120;
    waypoints.push_back(stage);
    stage << 1, -2, -1.4, 120;
    waypoints.push_back(stage);
    stage << 1, 2, 2, 120;
    waypoints.push_back(stage);
    stage << 1, -2, -1.4, 120;
    waypoints.push_back(stage);
    stage << 1, 2, 2, 120;
    waypoints.push_back(stage);
    stage << 1, -2, -1.4, 120;
    waypoints.push_back(stage);
    stage << 1, 2, 2, 120;
    waypoints.push_back(stage);
    stage << 1, -2, -1.4, 120;
    waypoints.push_back(stage);
    stage << 1, 2, 2, 120;
    waypoints.push_back(stage);
    stage << 1, -2, -1.4, 120;
    waypoints.push_back(stage);
    stage << 1, 2, 2, 120;
    waypoints.push_back(stage);
    stage << 1, -2, -1.4, 120;
    waypoints.push_back(stage);
    stage << 1, 0, 0, 120;
    waypoints.push_back(stage);
    cout << " Mission generated!" << " Stage count: " << waypoints.size() << endl;
    return(waypoints);
}
#endif