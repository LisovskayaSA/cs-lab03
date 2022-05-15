#include <iostream>
#include <vector>
#include <istream>
#include <sstream>
#include <string>
#include "histogram.h"
#include "svg.h"
#include <curl/curl.h>

using namespace std;



vector<double>
input_numbers(istream& in, size_t count)
{
    vector<double> result(count);
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

    if(prompt){
    cerr << "Enter bin count: ";
    }
    in >> data.bin_count;

    if(prompt){
    cerr << "Enter width of image: ";
    }
    in >> data.image_width;


    return data;
}

size_t
write_data(void* items, size_t item_size, size_t item_count, void* ctx) {
    size_t data_size = item_size * item_count;
    stringstream* buffer = reinterpret_cast<stringstream*>(ctx);
    buffer->write(reinterpret_cast<char*>(items), data_size);
    return data_size;
}

Input
download(const string& address) {
    stringstream buffer;

    curl_global_init(CURL_GLOBAL_ALL);
        CURL* curl = curl_easy_init();
        if(curl)
        {
            CURLcode res;
            curl_easy_setopt(curl, CURLOPT_URL, address.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
            res = curl_easy_perform(curl);
            if (res != CURLE_OK){
                cerr << curl_easy_strerror(res);
                exit(1);
            }
            long req;
            res = curl_easy_getinfo(curl, CURLINFO_REQUEST_SIZE, &req);
            cerr << "REQUEST_SIZE: " << req << endl;
        }
        curl_easy_cleanup(curl);

    return read_input(buffer, false);
}



int main(int argc, char* argv[])
{

    Input input;
    if (argc > 1)
    {
        input = download(argv[1]);

    }
    else {
        input = read_input(cin, true);
    }

    //ввод данных
    /*size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    const auto numbers = input_numbers(cin, number_count);

    size_t bin_count;
    cerr << "Enter bin count: ";
    cin >> bin_count;*/


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
    find_minmax(input.numbers,min,max);
    const auto bins = make_histogram(input);

    //вывод гистограммы
    show_histogram_svg(bins, input.image_width);


    return 0;
}
