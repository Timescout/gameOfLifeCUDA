/** DataSet.h
 * Game of Life CUDA
 * Author: Andrew Bergman
 * 6/12/26
 * Personal Project
 * 
 * This file defines a class which holds a set of game of life cells, a single "frame" or "step" of the simulation.
 */


#pragma once


#include <vector>


namespace game_of_life {


    class DataSet {
    private:
        std::vector<bool> cells_;
        int number_rows_;
        int number_columns_;
    public:
        DataSet();
        DataSet(DataSet& original);
        ~DataSet();
    };


} // namespace game_of_life