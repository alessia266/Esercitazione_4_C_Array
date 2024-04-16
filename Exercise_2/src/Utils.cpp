#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"
#include "iomanip"

using namespace std;

bool ImportValues(const string& inputFilePath,
                  double& S,
                  size_t& n,
                  double*& w,
                  double*& r)
{
    //open file
    ifstream file;
    file.open(inputFilePath);

    if (file.fail())
    {
        cerr << "file open failed" << endl;
        return false;
    }

    //get total sum S
    string line;
    getline(file, line, ';');
    getline(file, line);
    istringstream convertS;
    convertS.str(line);
    convertS >> S;

    //get number of assets n
    getline(file, line, ';');
    getline(file, line);
    istringstream convertN;
    convertN.str(line);
    convertN >> n;

    //skip line "w;r"
    getline(file, line);


    //get vectors w, r
    w = new double[n];
    r = new double[n];
    for (unsigned int i = 0; i < n; i++)
    {
        //get vector w
        getline(file, line, ';');
        istringstream convertW;
        convertW.str(line);
        convertW >> w[i];

        //get vector r
            getline(file, line);
        istringstream convertR;
        convertR.str(line);
        convertR >> r[i];
    }

    file.close();

    return true;
}

double ValueOfPort(const double& S,
                   const size_t& n,
                   const double* const& w,
                   const double* const& r)
{
    double V = 0;
    for (unsigned int i = 0; i< n; i++)
        V += S*w[i]*(1+r[i]);

    return V;
}


double RateOfReturn(double& S,
                    double& V)
{
    return (V-S)/S;
}

bool ExportResults(const string& outputFilePath,
                   const double& S,
                   const size_t& n,
                   const double& V,
                   const double& rateOfReturn,
                   string& arrayToStringW,
                   string& arrayToStringR)
{
    //open file
    ofstream file;
    file.open(outputFilePath);

    if (file.fail())
    {
        cerr << "file open failed" << endl;
        return false;
    }

    file << "S = " << fixed << setprecision(2) << S << ", n = " << n << "\nw = "
        << arrayToStringW << "\nr = " << arrayToStringR << endl;

    file << "Rate of return of the portfolio: " << fixed << setprecision(4) << rateOfReturn << endl;

    file << "V: " << fixed << setprecision(2) << V << endl;

    //close file
    file.close();

    return true;
}


string ArrayToString(const size_t& n,
                     const double* const& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString << v[i] << " ";
    toString << "]";

    return toString.str();
}
