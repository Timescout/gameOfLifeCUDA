/** DataSet.cu
 * Game of Life CUDA
 * Author: Andrew Bergman
 * 6/12/26
 * Personal Project
 * 
 * This file implements the DataSet class.
 */


#pragma once


#include <vector>
#include <stdexcept>


#include "DataSet.h"


namespace game_of_life {


    ///// Constructors and Destructors /////

    DataSet::DataSet(int number_rows, int number_columns) {
        SetNumberColumns(number_columns);
        SetNumberRows(number_rows);
        cells_ = std::vector<bool>(GetNumberColumns()*GetNumberRows(), false);
    }

    DataSet::DataSet(const DataSet& original) {
        SetNumberColumns(original.GetNumberColumns());
        SetNumberRows(original.GetNumberRows());
        cells_ = std::vector<bool>(original.GetCells());
    }

    DataSet::~DataSet() {}


    ///// Get and Set functions /////

    int DataSet::GetNumberRows() const {
        return number_rows_;
    }

    void DataSet::SetNumberRows(int new_number_rows) {
        if (new_number_rows < 1) {
            throw std::logic_error("Number of rows must be one or greater.");
        }
        number_rows_ = new_number_rows;
    }

    int DataSet::GetNumberColumns() const {
        return number_columns_;
    }

    void DataSet::SetNumberColumns(int new_number_columns) {
        if (new_number_columns < 1) {
            throw std::logic_error("Number of columns must be one or greater.");
        }
        number_columns_ = new_number_columns;
    }

    std::vector<bool> DataSet::GetCells() const {
        return cells_;
    }

    bool DataSet::GetCell(int row, int column) const {
        return cells_.at((row + 1) * column);
    }

    void DataSet::SetCell(int row, int column, bool new_state) {
        cells_[(row + 1) * column] = new_state;
    }

    void DataSet::ToggleCell(int row, int column) {
        SetCell(column, row, !GetCell(column, row));
    }


} // namespace game_of_life
 