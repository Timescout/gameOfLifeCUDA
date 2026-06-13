/** gtest.cpp
 * Game of Life CUDA
 * Author: Andrew Bergman
 * 6/12/26
 * Personal Project
 * 
 * This file contains the main function for the tests executable.
 */


#include <gtest/gtest.h>


#include "SimulationTest.h"


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}