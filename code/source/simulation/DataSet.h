/** DataSet.h
 * Game of Life CUDA
 * Author: Andrew Bergman
 * 6/12/26
 * Personal Project
 * 
 * This file declares a class which holds a set of game of life cells, a single "frame" or "step" of the simulation.
 */


#pragma once


#include <vector>
#include <stdexcept>


namespace game_of_life {


    class DataSet {
    private:
        ///// Member Variables /////    

        std::vector<bool> cells_;
        int number_rows_;
        int number_columns_;


    public:
        ///// Constructors and Destructors /////

        DataSet(int number_rows = 8, int number_columns = 8);

        DataSet(const DataSet& original);

        ~DataSet();


        ///// Get and Set functions /////

        int GetNumberRows() const;

        /// @param new_number_rows Must be 1 or greater.
        void SetNumberRows(int new_number_rows);

        int GetNumberColumns() const;

        /// @param new_number_columns Must be 1 or greater.
        void SetNumberColumns(int new_number_columns);

        std::vector<bool> GetCells() const;

        bool GetCell(int column, int row) const;

        void SetCell(int column, int row, bool new_state);

        void ToggleCell(int column, int row);
    };


} // namespace game_of_life