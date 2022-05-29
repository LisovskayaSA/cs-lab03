#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED
#include <vector>
#include <iostream>


using namespace std;

struct Input {
    vector<double> numbers;
    vector<string> strings;
    size_t bin_count;
    size_t image_width;
    size_t line_length;
    size_t separator_lenght;
};

vector<size_t>
make_histogram(Input data);

void find_minmax(const vector<double>& numbers, double& min, double& max);

void show_histogram_text(const vector <size_t>& bins);

#endif // HISTOGRAM_H_INCLUDED
