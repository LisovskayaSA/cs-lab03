#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED
#include <vector>
#include <iostream>


using namespace std;

void svg_begin(double width, double height);
void svg_end();
void svg_text(double left, double baseline, string text);
void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill = "black");
void svg_separator(double x, double y, double width, double height, size_t lin, size_t sep);
void show_histogram_svg(const vector<size_t>& bins, size_t image_width, size_t line_length, size_t separator_lenght);

#endif // SVG_H_INCLUDED
