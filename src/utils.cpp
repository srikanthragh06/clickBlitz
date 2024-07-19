#include "utils.h"

float generateRandomFloat(float min, float max)
{
    float randVal = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    return min + randVal * (max - min);
}