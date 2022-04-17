#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED
#include <vector>
#include <iostream>


using namespace std;

void find_minmax(const vector<double>& numbers, double& min, double& max);
void svg_begin(double width, double height);
void svg_end();
void svg_text(double left, double baseline, string text);
void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill = "black");
void show_histogram_svg(const vector<size_t>& bins, size_t image_width);
#endif // HISTOGRAM_H_INCLUDED
