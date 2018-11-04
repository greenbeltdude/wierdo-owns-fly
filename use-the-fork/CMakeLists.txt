cmake_minimum_required (VERSION 2.6)

project (use-the-fork)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

find_package(SFML 2 REQUIRED network audio graphics window system)

add_executable(use-the-fork 
	use-the-fork.cpp
	Bullet.cpp
	DumbAlien.cpp
    DumbAlienArmy.cpp
    Player.cpp
    SpaceObject.cpp
    SpaceObjectFactory.cpp
    TrackingAlien.cpp
    TrackingAlienArmy.cpp )

target_include_directories( use-the-fork PUBLIC ${SFML_INCLUDE_DIR})
target_link_libraries( use-the-fork PUBLIC ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
