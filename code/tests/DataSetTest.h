/** DataSetTest.h
 * Game of Life CUDA
 * Author: Andrew Bergman
 * 6/12/26
 * Personal Project
 * 
 * This file contains tests for the DataSet class.
 */


#include <gtest/gtest.h>


#include <vector>
#include <stdexcept>


#include "DataSet.h"


using namespace game_of_life;


TEST(DataSetUnitTest, Constructor_Constructs_CorrectDataSet) {
    int number_rows = 1, number_columns = 2;

    DataSet test_set = DataSet(number_rows, number_columns);
    const std::vector<bool> test_set_cells = test_set.GetCells();

    EXPECT_EQ(test_set.GetNumberRows(), number_rows);
    EXPECT_EQ(test_set.GetNumberColumns(), number_columns);
    EXPECT_EQ(test_set_cells.size(), number_rows*number_columns);
    for (auto i : test_set_cells) {
        EXPECT_EQ(i, false);
    }
}

