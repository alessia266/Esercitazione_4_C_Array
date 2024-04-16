#include <iostream>
#include <fstream>
#include <sstream>
#include "Utils.hpp"
#include <iomanip>

using namespace std;

int main()
{
    string inputFileName = "./data.csv";
    size_t n = 0;
    double S;
    double* w = nullptr;
    double* r = nullptr;


    if (!ImportValues(inputFileName, S, n, w, r))
    {
        cerr << "Something goes wrong with import" << endl;
        return -1;
    }
    else
    {
        cout << "Import successful" << endl;
        // cout << "S = " << fixed << setprecision(2) << S << ", n = " << n << "\nw = "
        //     << ArrayToString(n, w) << "\nr = " << ArrayToString(n,r) << endl;
    }

    double V = ValueOfPort(S, n, w, r);
    double rateOfReturn = RateOfReturn(S, V);
    string arrayToStringW = ArrayToString(n,w);
    string arrayToStringR = ArrayToString(n,r);

    string outputFileName = "./result.txt";
    if (!ExportResults(outputFileName, S, n, V, rateOfReturn, arrayToStringW, arrayToStringR))
    {
        cerr << "Something goes wrong with export" << endl;
        return -1;
    }
    else
    {
        cout << "Export successful" << endl;
        // cout << "Rate of return of the portfolio: " << fixed << setprecision(4) << rateOfReturn <<
        //     "\nV: " << fixed << setprecision(2) << V << endl;
    }


    delete[] w;
    delete[] r;

    return 0;
}

