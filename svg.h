#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED
#include <vector>
#include <iostream>
#include <string>
#include <windows.h>
#include <winsock2.h>


using namespace std;

void svg_begin(double width, double height);
void svg_end();
void svg_text(double left, double baseline, string text);
void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill = "black");
void show_histogram_svg(const vector<size_t>& bins, size_t image_width, string system, string name);
string
info_system();
string
name_of_computer();

#endif // SVG_H_INCLUDED
