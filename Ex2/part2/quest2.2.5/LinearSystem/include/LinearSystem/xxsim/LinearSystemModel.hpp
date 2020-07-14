#pragma once

/**********************************************************
 * This file is generated by 20-sim C++ Code Generator
 *
 *  file:  include\LinearSystem\xxsim\LinearSystemModel.hpp
 *  subm:  LinearSystemModel
 *  model: ex2
 *  expmt: ex2
 *  date:  May 26, 2019
 *  time:  7:04:56 PM
 *  user:  Universiteit Twente
 *  from:  20-sim 4.7 Campus License
 *  build: 4.7.0.8692
 *
 **********************************************************/

/* This file describes the model functions
 that are supplied for computation.

 The model itself is the LinearSystemModel.cpp file
 */

#include <debug/Debug.h>

/* 20-sim include files */
#include <xxsim/CLP/xxfuncs.h>
#include <xxsim/CLP/xxmatrix.h>
#include <xxsim/CLP/xxmodel.h>
#include <xxsim/CLP/xxinteg.h>

#include <xxsim/Adapter20Sim.h>

//@todo Use MODEL_NAME for separating generated classes from different projects.
namespace LinearSystem
{
  using namespace LUNA::xxsim;

  class LinearSystemModel: virtual Submodel20sim
  {
    public:

    /**
     * LinearSystemModel constructor
     */
    LinearSystemModel();

    /**
     * LinearSystemModel destructor
     */
    virtual ~LinearSystemModel(void);

    /**
     * @brief Initializes the algorithm and performs the first algorithm computation step.
     * @pre Initial values are set. Otherwise 0 is used. Assuming rest/safe position.
     * @post The algorithm is initialized and ready to calculate periodically outcomes (based on inputs, states and parameters).
     */
    void start();

    /**
     * @brief Copies input variable(s) to the internal inputs, performs one algorithm calculation step and copies the internal outputs to the output variable(s).
     * @pre The required inputs are available in the variable(s) of the adapter(s).
     * @post The outputs are available in the variable(s) of the adapter(s).
     */
    void step();

    /**
     * @brief Copies the input variables(s) to the internal outputs, performs the final algorithm calculations and copies the internal outputs to the output variable(s).
     * @pre The required inputs are available in the variable(s) of the adapter(s).
     * @post The outputs are available in the variable(s) of the adapter(s).
     */
    void stop();

    /**
     * @brief Creates an adapter between the CSP domain and the 20-Sim code generation domain.
     * Currently only variables are supported.
     * @note This function is non real-time.
     */
    template<typename T>
    void addInput(T* variable, XXMATRIX_TYPE t, int index, int rows, int columns)
    {
      assert(t == XXVARIABLE);

      bool found(false);

      for(unsigned int i = 0; i < number_matrices; ++i)
      {
        XXMatrix& matrix = M[i];
        if(matrix.mat == &V[index] && matrix.rows == rows && matrix.columns == columns)
        {
          m_inputs.push_back(new Adapter20Sim<T>(matrix, variable));
          found = true;
          break;
        }
      }

      LOG_IF((rows > 1 || columns > 1), LUNA::LOG_WARN, "Matrix not found in 20-sim matrix array.");

      if(!found)
      {
        XXMatrix m;
        m.mat = &V[index];
        m.rows = rows;
        m.columns = columns;
        m_inputs.push_back(new Adapter20Sim<T>(m, variable));
      }
    }

    /**
     * @brief Creates an adapter between the CSP domain and the 20-Sim code generation domain.
     * Currently only variables are supported.
     * @note This function is non real-time.
     */
    template<typename T>
    void addOutput(T* variable, XXMATRIX_TYPE t, int index, int rows, int columns)
    {
      assert(t == XXVARIABLE);

      bool found(false);

      for(unsigned int i = 0; i < number_matrices; ++i)
      {
        XXMatrix& matrix = M[i];
        if(matrix.mat == &V[index] && matrix.rows == rows && matrix.columns == columns)
        {
          m_outputs.push_back(new Adapter20Sim<T>(matrix, variable));
          found = true;
          break;
        }
      }

      LOG_IF((rows > 1 || columns > 1), LUNA::LOG_WARN, "Matrix not found in 20-sim matrix array.");

      if(!found)
      {
        XXMatrix m;
        m.mat = &V[index];
        m.rows = rows;
        m.columns = columns;
        m_outputs.push_back(new Adapter20Sim<T>(m, variable));
      }
    }

    protected:
    /**
     * @brief Creates the internal arrays.
     */
    void setupComputation();

    /**
     * @brief Initial algorithm equations.
     */
    bool initializeComputation();

    private:
    /**
     * @brief Adapters classified as input, i.e. copying external variables to the internal input variables.
     */
    std::vector<IAdapter20Sim*> m_inputs;

    /**
     * @brief Adapters classified as output, i.e. copying internal output variables to the external variables.
     */
    std::vector<IAdapter20Sim*> m_outputs;

    protected:
    /**
     * CalculateDynamic()
     * This function calculates the dynamic equations of the model.
     * These equations are called from the integration method
     * to calculate the new model rates (that are then integrated).
     */
    inline void CalculateDynamic (void);

    private:
    /* internal submodel computation methods */

    /**
     * CalculateInitial()
     * This function calculates the initial equations of the model.
     * These equations are calculated before anything else
     */
    inline void CalculateInitial (void);

    /**
     * CalculateStatic()
     * This function calculates the static equations of the model.
     * These equations are only dependent from parameters and constants
     */
    inline void CalculateStatic (void);

    /**
     * CalculateInput()
     * This function calculates the input equations of the model.
     * These equations are dynamic equations that must not change
     * in calls from the integration method (like random and delay).
     */
    inline void CalculateInput (void);

    /**
     * CalculateOutput()
     * This function calculates the output equations of the model.
     * These equations are not needed for calculation of the rates
     * and are kept separate to make the dynamic set of equations smaller.
     * These dynamic equations are called often more than one time for each
     * integration step that is taken. This makes model computation much faster.
     */
    inline void CalculateOutput (void);

    /**
     * CalculateFinal()
     * This function calculates the final equations of the model.
     * These equations are calculated after all the calculations
     * are performed
     */
    inline void CalculateFinal (void);

    /**
     * CopyInputsToVariables
     * This private function copies the input variables from the input vector
     * @param u	This is the array with all input signals for this submodel
     */
    void CopyInputsToVariables ();

    /**
     * CopyVariablesToOutputs
     * This private function copies the output variables to the output vector
     * @param y	This is the array with all output signals from this submodel
     */
    void CopyVariablesToOutputs ();

    Euler myintegmethod; ///< pointer to the integration method for this submodel

  };

}

