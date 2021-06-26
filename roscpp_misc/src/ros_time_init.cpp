#include <ros/ros.h>

#include <iostream>

void common(const std::string & label)
{
  std::cout << "[" << label << "]" << std::endl;
  try {
    const auto now = ros::Time::now();
    std::cout << "ros::Time::now() = " << now << std::endl;
  } catch (std::exception & e) {
    std::cout << "Fail to call ros::Time::now()" << std::endl;
    std::cout << e.what() << std::endl;
  }
}

int main()
{
  common("Before ros::Time::init()");

  std::cout << std::endl;
  ros::Time::init();

  common("After ros::Time::init()");
}
