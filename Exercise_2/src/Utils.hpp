#pragma once
#include <iostream>

using namespace std;

//ImportValues return the result of the reading, true is success, false is error
bool ImportValues(const string& inputFilePath,
                  double& S,
                  size_t& n,
                  double*& w,
                  double*& r);

//RateOfReturn return the average earning percentage on invested capital
double RateOfReturn(double& S,
                    double& V);

//return the final value of portfolio
double ValueOfPort(const double& S,
                   const size_t& n,
                   const double* const& w,
                   const double* const& r);

//Export the results in file
bool ExportResults(const string& outputFilePath,
                   const double& S,
                   const size_t& n,
                   const double& V,
                   const double& rateOfReturn,
                   string& arrayToStringW,
                   string& arrayToStringR);


//export a vector in a string
string ArrayToString(const size_t& n,
                     const double* const& v);
