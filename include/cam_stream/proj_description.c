/** \mainpage ROS library for image transmission.                                       
*
* \brief This template for a ROS library was intended to be implemented in the
* Rescue Robot design by us for Tec de Monterrey, Campus Guadalajara.\n
* The same library contain both nodes (transmit and recevie), but it is not
* necessary to include the receive node in the robot (this could avoid unnecessary
* use of memory).
*     
* \authors
* Humberto Regla González\n
* Antonio Emmanuel García Vázquez\n
* Moisés Alejandro García Pérez
*
* \section use Use and explore the library
* Here you could find the information regarding the code. All the code related
* documentation can be found under each code file and these files can be found
* under the "Files" section above.
* You can also find a page, under the "Related Pages" section above, called
* "ROS intro"; in this page you can find a very brief introduction to how to
* install and use ROS.
* 
* \section contact Contact info
* Students from Tec de Monterrey Campus Guadalajara can get in contact with us
* for future references and support. This apply for any components of the robot.\n
* We understand the complexity of the system is in the mechanic section.\n
* You can try to get our phone numbers from Oscar Carbajal, but here I put
* our personal emails for contact purposes:\n
* Antonio Garcia (mechanics chief): tony.garcia.vz@gmail.com / aegv.com.mx\n
* Humberto Regla (software, mechanics): htoregla1@hotmail.com\n
* Moisés García (mechanics): magp.imt@gmail.com
*
*/

/**
\page ros ROS intro

ROS Melodic installation for Ubuntu 18:\n
http://wiki.ros.org/melodic/Installation/Ubuntu

******************************CREATE ENVIRONMENT

It is important to first create a folder to put the ROS environment in it.

You could add the default environment variables with:\n
<tt>source /opt/ros/kinetic/setup.bash</tt>

Depending on version you need, instead of the above:\n
<tt>source /opt/ros/melodic/setup.bash</tt>

<b>YOU DO NOT ALWAYS HAVE TO SOURCE THE DEFAULT VARIABLES, BUT IT IS CONVENIENT</b>.

Create the workspace creating the two main directories (must place the terminal in desired folder first):\n
<tt>mkdir -p <environment_folder_name>/src</tt>

Initialize the environment with:\n
<tt>cd <environment_folder_name>\n
catkin_make</tt>

Overlay catkin workspace with:\n
<tt>source devel/setup.bash</tt>

Finally, you can check your workspace with:\n
<tt>echo $ROS_PACKAGE_PATH</tt>

********************************USEFUL COMMANDS

Start a master in a separate terminalwith:\n
<tt>roscore</tt>

To be able to run a node from a created package you must add it as source.\n
To do this you must go to the environment folder and run:\n
<tt>catkin_make</tt>

This will run all of your packages and add them to this environment.\n
Now, add the environment with:\n
<tt>source devel/setup.bash</tt>

Once you did this, you can use rosrun to run your node.

Run a node with:\n
<tt>rosrun <package_name> <node_name></tt>

Check active nodes with:\n
<tt>rosnode list</tt>

Retrieve information about a node with:\n
<tt>rosnode info <node_name></tt>

List active topics with:\n
<tt>rostopic list</tt>

Subscribe and print the contents of a topic with:\n
<tt>rostopic echo /topic</tt>

Show information about a topic with:\n
<tt>rostopic info /topic</tt>

*******************************CREATE A PACKAGE

Once you created the environment, locate a terminal in the src folder and run:\n
<tt>catkin_create_pkg <package_name> {<dependencies>}</tt>

<b>NOTE:</b> <em>DEPENDENCIES ARE OTHER PACKAGES NEEDED BY THE FIRST PACKAGE.</em>

Once you run the command you will have to modify the package.xml file.\n
Important thing to modify are:\n
\arg Package name: Name of the package. Defined at creation.
\arg Version number: Version of the developed project.
\arg Authors: Project contributors.
\arg Dependencies on other packages: Very important. Some options appear commented. Check for necessary ones.

You will also have to modify the CMakeLists.txt, taking care of at least:\n
\arg <tt>cmake_minimum_required(VERSION 2.8.3)</tt>                  : Version
\arg <tt>project(<package_name>)</tt>                                : Package name
\arg <tt>add_definitions(--std=c++11)</tt>                           : C++11 by default
\arg <tt>find_package(catkin REQUIRED</tt>                           : Required packages
\arg <tt>COMPONENTS <package1> <package2> )</tt>
\arg <tt>catkin_package (</tt>                                       : Starting from here, required files are included\n
     <tt>INCLUDE_DIRS <directory_with_include_files></tt>            : Directory with headers\n
     <tt># LIBRARIES</tt>                                            : Libraries in the project\n
     <tt>CATKIN_DEPENDS <library_A> <library_B></tt>                 : Required libraries\n
     <tt># DEPENDS )</tt>                                            : Package dependent projects\n
\arg <tt>include_directories(include ${catkin_INCLUDE_DIRS})</tt>
\arg <tt>add_executable(${PROJECT_NAME}</tt>                        : Declare a C++ executable name
\arg <tt>src/${PROJECT_NAME}_node.cpp</tt>                          : Declare all source files
\arg <tt>src/comm_interface.cpp )</tt>
\arg <tt>target_link_libraries(${PROJECT_NAME}</tt>                 : Specify the libraries to link the executable against
\arg <tt>${catkin_LIBRARIES})</tt>

The main components of a CMakeLists.txt are:\n
\arg Required CMake Version\n
     <tt>cmake_minimum_required()</tt>
\arg Package Name:\n
     <tt>project(<package_name>)</tt>
\arg Find other CMake/Catkin packages needed for build:\n
     <tt>find package(<dependencies>)</tt>
\arg Message/Service/Action Generators:\n
     <tt>add message files()\n
     add service files()\n
     add action files()</tt>
\arg Invoke message/service/action generation:\n
     <tt>generate messages()</tt>
\arg Specify package build info export:\n
     <tt>catkin package()</tt>
\arg Libraries/Executable to build:\n
     <tt>add library()\n
     add executable()\n
     target link libraries()</tt>
\arg Tests to build:\n
     <tt>catkin add gtest()</tt>
\arg Install rules\n
     <tt>install()</tt>

**/