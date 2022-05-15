#include <iostream>
#include <vector>
#include <istream>
#include <sstream>
#include "histogram.h"
#include "svg.h"

using namespace std;



vector<double>
input_numbers(istream& in, size_t count)
{
    vector<double> result(count);
    cerr << "Enter numbers: ";
    for(size_t i = 0; i < count; i++)
    {
        in >> result[i];
    }
    return result;
}

Input
read_input(istream& in, bool prompt) {
    Input data;

    if(prompt){
    cerr << "Enter number count: ";
    }
    size_t number_count;
    in >> number_count;

    if(prompt){
    cerr << "Enter numbers: ";
    }
    data.numbers = input_numbers(in, number_count);

    size_t bin_count;
    if(prompt){
    cerr << "Enter bin count: ";
    }
    cin >> bin_count;

    return data;
}

int main()
{
    //ввод данных
    /*size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    const auto numbers = input_numbers(cin, number_count);

    size_t bin_count;
    cerr << "Enter bin count: ";
    cin >> bin_count;*/
    struct Input data;
    data = read_input(cin,true);

    size_t image_width;
    cerr << "Enter width of image: ";
    cin >> image_width;

    //для палок-разделителей
    /*size_t line_length;
    cerr << "Enter line lenght: ";
    cin >> line_length;
    size_t separator_lenght;
    cerr << "Enter separator lenght: ";
    cin >> separator_lenght;*/

    //расчет гистограммы

    double min;
    double max;
    find_minmax(data.numbers,min,max);

    const auto bins = make_histogram(data);

    //вывод гистограммы
    show_histogram_svg(bins, image_width);


    return 0;
}
