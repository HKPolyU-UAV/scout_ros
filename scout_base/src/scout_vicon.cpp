#include <ros/ros.h>
#include <numeric>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Geometry>
#include <geometry_msgs/TwistStamped.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Twist.h>
#include "utils/common.h"
#include "utils/kinetic_math.h"
#define PI 3.14159265

// geometry_msgs::Twist speed;
geometry_msgs::Twist UGV_twist_pub;
geometry_msgs::PoseStamped UGV_pose_vicon;
geometry_msgs::PoseStamped UGV_pose_desire;
Vec3 pose_XYyaw;
Vec2 DesUGVpose;
static double MaxTurnrate = 1;      // radius per sec
static double MaxVelocity = 0.5;    // meters per sec

void UGVPose_cb(const geometry_msgs::PoseStamped::ConstPtr& pose){
    UGV_pose_vicon.pose.position.x = pose->pose.position.x;
    UGV_pose_vicon.pose.position.y = pose->pose.position.y;
    UGV_pose_vicon.pose.position.z = pose->pose.position.z;
    UGV_pose_vicon.pose.orientation.w = pose->pose.orientation.w;
    UGV_pose_vicon.pose.orientation.x = pose->pose.orientation.x;
    UGV_pose_vicon.pose.orientation.y = pose->pose.orientation.y;
    UGV_pose_vicon.pose.orientation.z = pose->pose.orientation.z;
    Quaterniond localq(UGV_pose_vicon.pose.orientation.w,
                       UGV_pose_vicon.pose.orientation.x,
                       UGV_pose_vicon.pose.orientation.y,
                       UGV_pose_vicon.pose.orientation.z);
    Vec3 localrpy = Q2rpy(localq);
    pose_XYyaw = Vec3(UGV_pose_vicon.pose.position.x,UGV_pose_vicon.pose.position.y,localrpy[2]);
}
void UGVdesPose_cb(const geometry_msgs::PoseStamped::ConstPtr& pose){
    UGV_pose_desire.pose.position.x = pose->pose.position.x;
    UGV_pose_desire.pose.position.y = pose->pose.position.y;
    DesUGVpose = Vec2(UGV_pose_desire.pose.position.x,UGV_pose_desire.pose.position.y);
}
void twist_pub(Vec2 VA){
    UGV_twist_pub.linear.x  = VA[0];
    UGV_twist_pub.angular.z = VA[1];
}
Vec2 Poistion_controller_PID(Vec3 pose_XYyaw, Vec2 setpoint){ // From VRPN XY position
    // cout << "pose_XY:  " << pose_XYyaw[0] << " " << pose_XYyaw[1] << endl;
    // cout << "setpoint: " << setpoint[0] << " " << setpoint[1] << endl;
    double err_dist = sqrt(pow((setpoint[0]-pose_XYyaw[0]),2)+
                           pow((setpoint[1]-pose_XYyaw[1]),2));
    // cout << "err_dist: " << err_dist << endl;
    Vec2 diff_XY = Vec2(setpoint[0]-pose_XYyaw[0],setpoint[1]-pose_XYyaw[1]);
    double err_yaw = atan2(diff_XY[1],diff_XY[0])-pose_XYyaw[2];
    // cout << "err_yaw: " << err_yaw << endl;
    if (err_dist<0.2 && err_yaw > PI*0.3){err_dist = 0;err_yaw = 0;}
    if (err_dist<0.1){err_dist = 0;err_yaw = 0;}            // Stop if the error is within 10 cm
    if (err_yaw>PI*0.3||err_yaw<PI*-0.3){ err_dist = 0; }   //Turn before going straight

    Vec2 error,last_error,u_p,u_i,u_d,output; // Dist Yaw Error
    double Last_time = ros::Time::now().toSec();
    double iteration_time = ros::Time::now().toSec() - Last_time;
    Vec2 K_p(0.2,0.2);
    Vec2 K_i(0.2,0.2);
    Vec2 K_d(0,0);
    error = Vec2(err_dist,err_yaw);
    last_error = error;
    Vec2 integral = integral+(error*iteration_time);
    Vec2 derivative = (error - last_error)/iteration_time;
    for (int i=0; i<2; i++){                //i = straight_distance,Yaw
        u_p[i] = error[i]*K_p[i];           //P controller
        u_i[i] = integral[i]*K_i[i];        //I controller
        u_d[i] = derivative[i]*K_d[i];      //D controller
        output[i] = u_p[i]+u_i[i]+u_d[i];
    }
    
    if(output[0] >  0.8){ output[0]= 0.8;}  //Clamp the forward speed to 0.8 m/s

    if(output[1] >  MaxTurnrate){ output[1] = MaxTurnrate;}
    if(output[1] < MaxTurnrate*-1){ output[1] = MaxTurnrate*-1;}

    // cout << "output____ v: " << output[0] << " av: " << output[1] << endl;
    return(output);
}
int main(int argc, char **argv)
{
    ros::init(argc, argv, "scout_vicon");
    ros::NodeHandle nh;
    ros::Subscriber ugvpose_sub = nh.subscribe<geometry_msgs::PoseStamped>("/vrpn_client_node/gh034_car/pose", 5, UGVPose_cb);
    ros::Subscriber ugvdespose_sub = nh.subscribe<geometry_msgs::PoseStamped>("/scout_wp/pose", 5, UGVdesPose_cb);
    ros::Publisher pub_twist =nh.advertise<geometry_msgs::Twist>("/cmd_vel",5);
    ros::Rate ros_rate(10);
    cout << "Super Car Initialized" << endl;

    while(ros::ok())
    {
    //   Vec2 XY = Vec2(5,-5);
    //   Vec3 pose_XYyaw = Vec3(0,0,0);
      Vec2 XY = DesUGVpose;

      twist_pub(Poistion_controller_PID(pose_XYyaw,XY));
      pub_twist.publish(UGV_twist_pub);
      ros::spinOnce();
      ros_rate.sleep();
    }

    return 0;
}
