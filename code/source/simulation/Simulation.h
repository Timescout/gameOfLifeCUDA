/** Simulation.h
 * Game of Life CUDA
 * Author: Andrew Bergman
 * 6/12/26
 * Personal Project
 * 
 * This file defines the Simulation class, which contains the logic for the game of life simulation.
 */


#pragma once


#include "DataSet.h"


namespace game_of_life {


    /// @brief Runs the Game of Life simulation on a Dataset of cells.
    class Simulation {
    private:
        ///// Member Variables /////

        /// @brief Contains current cell data.
        DataSet cell_data_;

        /// @brief Counts the number of steps since the start of the simulation.
        unsigned int number_steps_;

    public:
        ///// Constructors and Destructors /////

        Simulation(DataSet cell_data = DataSet());

        ~Simulation();


        ///// Get and Set /////

        DataSet GetDataSet() const;

        void SetDataSet(DataSet new_dataset);

        unsigned int GetNumberSteps() const;

        // Note number_steps_ cannot be set with a setter function, it can only be altered via progressing the simulation.


        ///// Simulation functions /////

        /// @brief Run the simulation for a number of steps.
        /// @param number_steps 
        void Simulate(unsigned int number_steps = 1);

        /// @brief Runs the simulation until the given step number. I.e. If the current number of steps is 10, and 100 is passed to this function the simulation will run for 90 steps. If the step number has already been reached then the function will pass and do nothing.
        /// @param step_number 
        void SimulateToStep(unsigned int step_number);
    };


} // namespace game_of_life