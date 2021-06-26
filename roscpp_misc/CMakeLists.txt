cmake_minimum_required(VERSION 3.0.2)
project(roscpp_misc)

find_package(catkin REQUIRED
  COMPONENTS
    roscpp
)

catkin_package()

###########
## Build ##
###########

foreach(bin IN ITEMS
  ros_delete_param
  ros_time_init
)

  add_executable(${bin}
    src/${bin}/main.cpp
  )

  target_include_directories(${bin}
    PRIVATE
      ${catkin_INCLUDE_DIRS}
  )

  target_link_libraries(${bin}
    PRIVATE
      ${catkin_LIBRARIES}
  )

  target_compile_options(${bin}
    PRIVATE
      -Wall
      -Wextra
      -Wpedantic
  )

  target_compile_features(${bin}
    PRIVATE
      cxx_std_14
  )
endforeach()
