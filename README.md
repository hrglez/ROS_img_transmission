# ROS_robocup_lib

Melodic installation for Ubuntu 18

http://wiki.ros.org/melodic/Installation/Ubuntu

**************************************************************************
********************CREATE ENVIRONMENT********************

It is important to first create a folder to put the ROS environment in it.

You could add the default environment variables with:
source /opt/ros/kinetic/setup.bash

Depending on versio you need, instead of the above:
source /opt/ros/melodic/setup.bash

YOU DO NOT ALWAYS HAVE TO SOURCE THE DEFAULT VARIABLES, BUT IT IS CONVENIENT

Create the workspace creating the two main directories (must place the terminal in desired folder first):
mkdir -p <environment_folder_name>/src

Initialize the environment with:
cd <environment_folder_name>
catkin_make

Overlay catkin workspace with:
source devel/setup.bash

Finally, you can check your workspace with:
echo $ROS_PACKAGE_PATH

**************************************************************************
********************USEFUL COMMANDS********************

Start a master with:
roscore

To be able to run a node from a created package you must add it as source.
To do this you must go to the environment folder and run:
catkin_make

This will run all of your packages and add them to this environment.
Now, add the environment with:
source devel/setup.bash

Once you did this, you can use rosrun to run your node.

Run a node with:
rosrun <package_name> <node_name>

Check active nodes with:
rosnode list

Retrieve information about a node with:
rosnode info <node_name>

List active topics with:
rostopic list

Subscribe and print the contents of a topic with:
rostopic echo /topic

Show information about a topic with:
rostopic info /topic

**************************************************************************
********************CREATE A PACKAGE********************

Once you created the environment, locate a terminal in the src folder and run:
catkin_create_pkg <package_name> {<dependencies>}

NOTE: DEPENDENCIES ARE OTHER PACKAGES NEEDED BY THE FIRST PACKAGE.

Once you run the command you will have to modify the package.xml file.
Important thing to modify are:
--Package name
--Version number
--Authors
--__Dependencies on other packages__ (VERY IMPORTANT, SOME OPTIONS APPEAR COMMENTED, CHECK FOR NECESSARY ONES)

You will also have to modify the CMakeLists.txt, taking care of at least:
** cmake_minimum_required(VERSION 2.8.3)                  //Version
** project(<package_name>)                                //Package name
** add_definitions(--std=c++11)                           //C++11 by default
** find_package(catkin REQUIRED                           //Required packages
** COMPONENTS <package1> <package2> )
** catkin_package(                                        //Include required files
** INCLUDE_DIRS <directory_with_include_files>            //Directory with headers
** # LIBRARIES
** CATKIN_DEPENDS <library_A> <library_B>                 //Required libraries
** # DEPENDS                                              //Package dependent projects
** )
** include_directories(include ${catkin_INCLUDE_DIRS})
** add_executable(${PROJECT_NAME}                        //Declare a C++ executable name
** src/${PROJECT_NAME}_node.cpp                          //Declare all source files
** src/comm_interface.cpp )
** target_link_libraries(${PROJECT_NAME}                 //Specify the libraries to link the executable against
** ${catkin_LIBRARIES})

The main components of a CMakeLists.txt are:
--Required CMake Version
  cmake_minimum_required()
--Package Name:
  project(<package_name>)
--Find other CMake/Catkin packages needed for build:
  find package(<dependencies>)
--Message/Service/Action Generators:
  add message files()
  add service files()
  add action files())
--Invoke message/service/action generation:
  generate messages()
--Specify package build info export:
  catkin package()
--Libraries/Executable to build:
  add library()
  add executable()
  target link libraries()
--Tests to build:
  catkin add gtest()
--Install rules
  install()
