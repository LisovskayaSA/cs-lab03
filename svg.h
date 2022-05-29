#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED
#include <vector>
#include <iostream>
#include "histogram.h"
#include <string>
#include <sstream>
#include <winsock2.h>
#include <windows.h>



using namespace std;

void svg_begin(double width, double height);
void svg_end();
void svg_text(double left, double baseline, string text);
void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill = "black");
void svg_separator(double x, double y, double width, double height, size_t lin, size_t sep, ostream& stream);
void show_histogram_svg(const vector<size_t>& bins, size_t image_width, const vector<string>& strings, size_t line_length, size_t separator_lenght, string system, string name);
void show_histogram_svg(const vector<size_t>& bins, size_t image_width);
string
info_system();
string
name_of_computer();


#endif // SVG_H_INCLUDED
