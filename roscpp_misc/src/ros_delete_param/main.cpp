#include <ros/ros.h>

#include <iostream>

void setParams(const ros::NodeHandle & nh)
{
  nh.setParam("foo", 10);
  nh.setParam("bar/buz", 20);
  nh.setParam("bar/fizz", 30);
}

void printParam(const ros::NodeHandle & nh, const std::string & key)
{
  int param{};
  if (nh.getParam(key, param)) {
    std::cout << nh.resolveName(key) << ": " << param << std::endl;
  } else {
    std::cout << nh.resolveName(key) << ": not found\n";
  }
}

void printParams(const ros::NodeHandle & nh, const std::string & label)
{
  std::cout << "[" << label << "]\n";
  printParam(nh, "foo");
  printParam(nh, "bar/buz");
  printParam(nh, "bar/fizz");
}

void common(const ros::NodeHandle & nh, const std::string & delete_key)
{
  std::cout << "=======================================\n";

  const auto full_delete_key = nh.resolveName(delete_key);

  setParams(nh);
  printParams(nh, "Before delete param " + full_delete_key);

  nh.deleteParam(delete_key);

  printParams(nh, "After delete param " + full_delete_key);
}

int main(int argc, char ** argv)
{
  ros::init(argc, argv, "node");

  ros::NodeHandle nh{};
  ros::NodeHandle priv_nh{"~"};

  common(priv_nh, "bar");
  common(priv_nh, "");
  common(nh, "bar");
  common(nh, "");
}
