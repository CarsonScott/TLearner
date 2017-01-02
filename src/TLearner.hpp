#ifndef TLEARNER_HPP_INCLUDED
#define TLEARNER_HPP_INCLUDED

#include <vector>
#include <cmath>

class TLearner
{
    int input_size;
    float learning_rate;
    float error_tolerance;
    std::vector<float> expected_input;

    float computeError(std::vector<float> x)
    {
        float error = 0;
        for(int i = 0; i < input_size; i++)
        {
            error += pow(x[i]-expected_input[i], 2);
        }
        return error / x.size();
    }

public:

    TLearner(int inputs, float tolerance, float rate)
    {
        error_tolerance = tolerance;
        learning_rate = rate;
        input_size = inputs;

        for(int i = 0; i < input_size; i++)
        {
            expected_input.push_back(0);
        }
    }

    float computeOutput(std::vector<float> x)
    {
        return error_tolerance-computeError(x);
    }

    void train(std::vector<float> x)
    {
        for(int i = 0; i < input_size; i++)
        {
            expected_input[i] += learning_rate * (x[i]-expected_input[i]);
        }
    }
};

#endif // TLEARNER_HPP_INCLUDED
