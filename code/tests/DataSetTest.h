/** DataSetTest.h
 * Game of Life CUDA
 * Author: Andrew Bergman
 * 6/12/26
 * Personal Project
 * 
 * This file contains tests for the DataSet class.
 */


#pragma once


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

TEST(DataSetUnitTest, CopyConstructor_Constructs_CorrectDataSet) {
    int number_rows = 1, number_columns = 2;
    DataSet test_set(number_rows, number_columns);
    test_set.SetCell(0, 0, true);

    DataSet duplicate_test_set(test_set);

    EXPECT_EQ(duplicate_test_set.GetNumberRows(), number_rows);
    EXPECT_EQ(duplicate_test_set.GetNumberColumns(), number_columns);
    EXPECT_EQ(duplicate_test_set.GetCells(), test_set.GetCells());
}

TEST(DataSetUnitTest, CopyConstructor_Constructs_DeepCopy) {
    DataSet test_set;
    
    DataSet duplicate_test_set(test_set);
    duplicate_test_set.SetCell(0, 0, true);

    EXPECT_NE(duplicate_test_set.GetCells(), test_set.GetCells());
}

TEST(DataSetUnitTest, SetNumberRows_Zero_ThrowsError) {
    DataSet test_set;

    EXPECT_THROW(test_set.SetNumberRows(0), std::logic_error);
}

TEST(DataSetUnitTest, SetNumberRows_One_DoesNotThrowError) {
    DataSet test_set;

    EXPECT_NO_THROW(test_set.SetNumberRows(1));
}

TEST(DataSetUnitTest, SetNumberColumns_Zero_ThrowsError) {
    DataSet test_set;

    EXPECT_THROW(test_set.SetNumberColumns(0), std::logic_error);
}

TEST(DataSetUnitTest, SetNumberColumns_One_DoesNotThrowError) {
    DataSet test_set;

    EXPECT_NO_THROW(test_set.SetNumberColumns(1));
}

TEST(DataSetUnitTest, GetCell_OutsideDataSetRange_ThrowsOutOfRangeError) {
    DataSet test_set(1, 1);

    EXPECT_THROW(test_set.GetCell(1, 1), std::out_of_range);
}

TEST(DataSetUnitTest, ToggleCell_FalseCell_InvertsCell) {
    int row = 0, column = 0;
    DataSet test_set;
    test_set.SetCell(row, column, false);

    test_set.ToggleCell(row, column);

    EXPECT_EQ(test_set.GetCell(row, column), true);
}

TEST(DataSetUnitTest, ToggleCell_TrueCell_InvertsCell) {
    int row = 0, column = 0;
    DataSet test_set;
    test_set.SetCell(row, column, true);

    test_set.ToggleCell(row, column);

    EXPECT_EQ(test_set.GetCell(row, column), false);
}