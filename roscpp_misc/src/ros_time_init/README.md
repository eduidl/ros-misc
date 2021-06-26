# ros_time_init

ROS Master が立ち上がっていなくても、`ros::Time::now()`は正常に呼び出し可能．ただし、予め`ros::Time::init()`を呼んでおく必要がある．  
テストコードだけに留めておいた方がよい．

```sh-session
$ rosrun roscpp_misc ros_time_init
[Before ros::Time::init()]
Fail to call ros::Time::now()
Cannot use ros::Time::now() before the first NodeHandle has been created or ros::start() has been called.
If this is a standalone app or test that just uses ros::Time and does not communicate over ROS, you may also call ros::Time::init()

[After ros::Time::init()]
ros::Time::now() = 1624692454.178498400
```
