/** Simulation.cu
 * Game of Life CUDA
 * Author: Andrew Bergman
 * 6/12/26
 * Personal Project
 * 
 * This file implements the Simulation class.
 */


#pragma once


#include "Simulation.h"
#include "DataSet.h"


namespace game_of_life {


    ///// Constructors and Destructors /////

    Simulation::Simulation(DataSet cell_data) :
        number_steps_(0) 
    {
        SetDataSet(cell_data);
    }

    Simulation::~Simulation() {}


    ///// Get and Set Functions /////

    DataSet Simulation::GetDataSet() const {
        return cell_data_;
    }

    void Simulation::SetDataSet(DataSet new_dataset) {
        cell_data_ = new_dataset;
    }

    unsigned int Simulation::GetNumberSteps() const {
        return number_steps_;
    }


    ///// Simulation functions /////

    void Simulation::Simulate(unsigned int number_steps) {
        // TODO: Implement this
    }

    void Simulation::SimulateToStep(unsigned int step_number) {
        // TODO: Implement this
    }


} // namespace game_of_life