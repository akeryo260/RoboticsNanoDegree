#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <nav_msgs/Odometry.h>

float pickup_zone_x = -2.0;
float pickup_zone_y = 0.3;

float drop_off_zone_x = 1.0;
float drop_off_zone_y = 0.0;

bool reach_pick_up_zone = false;
bool reach_drop_off_zone = false;

void odom_callback(const nav_msgs::Odometry::ConstPtr& msg)
{
  if (!reach_pick_up_zone) {
    float distance_pickup = sqrt(pow((msg->pose.pose.position.x - pickup_zone_x), 2) + pow((msg->pose.pose.position.y - pickup_zone_y), 2));
    reach_pick_up_zone = distance_pickup < 1.0;
    ROS_INFO("pickup distance: %f", distance_pickup);
  }
  if(reach_pick_up_zone && !reach_drop_off_zone) {
    float distance_drop_off = sqrt(pow((msg->pose.pose.position.x - drop_off_zone_x), 2) + pow((msg->pose.pose.position.y - drop_off_zone_y), 2));
    reach_drop_off_zone = distance_drop_off < 1.0;
    ROS_INFO("drop off distance: %f", distance_drop_off);
  }
}

int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  ros::Subscriber sub = n.subscribe("/odom", 10, odom_callback);
	
  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;


  visualization_msgs::Marker marker;
  // Set the frame ID and timestamp.  See the TF tutorials for information on these.
  marker.header.frame_id = "map";
  marker.header.stamp = ros::Time::now();

  // Set the namespace and id for this marker.  This serves to create a unique ID
  // Any marker sent with the same namespace and id will overwrite the old one
  marker.ns = "basic_shapes";
  marker.id = 0;

  // Set our shape type to be a cube
  marker.type = visualization_msgs::Marker::CUBE;

  // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
  marker.pose.position.x = pickup_zone_x;
  marker.pose.position.y = pickup_zone_y;
  marker.pose.position.z = 0;
  marker.pose.orientation.x = 0.0;
  marker.pose.orientation.y = 0.0;
  marker.pose.orientation.z = 0.0;
  marker.pose.orientation.w = 1.0;

  // Set the scale of the marker -- 1x1x1 here means 1m on a side
  marker.scale.x = 0.2;
  marker.scale.y = 0.2;
  marker.scale.z = 0.2;

  // Set the color -- be sure to set alpha to something non-zero!
  marker.color.r = 0.0f;
  marker.color.g = 0.0f;
  marker.color.b = 1.0f;
  marker.color.a = 1.0;

  marker.lifetime = ros::Duration();
  
  while (ros::ok())
  {
    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker.action = visualization_msgs::Marker::ADD;
    
    while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }
    if(reach_pick_up_zone && !reach_drop_off_zone) {
      marker.action = visualization_msgs::Marker::DELETE;
    }
    if(reach_pick_up_zone && reach_drop_off_zone) {
      marker.action = visualization_msgs::Marker::ADD;
      marker.pose.position.x = drop_off_zone_x;
      marker.pose.position.y = drop_off_zone_y;
    }
    marker_pub.publish(marker);
    ros::spinOnce();
  }
  return 0;
}
