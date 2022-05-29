#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"
#include <windows.h>
#include <winsock2.h>

using namespace std;

vector<double>
input_numbers(size_t count)
{
    vector<double> result(count);
    cerr << "Enter numbers: ";
    for(size_t i = 0; i < count; i++)
    {
        cin >> result[i];
    }
    return result;
}




vector<size_t>
make_histogram(const vector<double>& numbers, size_t bin_count)
{
    double min,max;
    find_minmax(numbers,min,max);
    vector<size_t> bins(bin_count,0);
    double bin_size = ((max-min) / bin_count);
    for(size_t i = 0; i < numbers.size(); i++)
    {
        bool found = false;
        for(size_t j = 0; j < (bin_count - 1); j++)
        {
            auto lo = min + j * bin_size;
            auto hi = min + (j + 1) * bin_size;
            if ((lo <= numbers[i]) && (numbers[i] < hi))
            {
                bins[j]++;
                found = true;
            }
        }
        if (!found)
        {
            bins[bin_count - 1]++;
        }
    }
    return bins;
}

void show_histogram_text(const vector <size_t>& bins)
{
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;
    size_t max_bin = bins[0]; //максимальная высота столбца
    for (size_t bin: bins)
    {
        if(max_bin < bin)
        {
            max_bin = bin;
        }
    }

    for(size_t bin: bins)
    {
        size_t height = bin;

        if (height > MAX_ASTERISK)
        {
            height = MAX_ASTERISK * (static_cast<double> (bin) / max_bin);
        }
        if (bin < 100)
        {
            cout << ' ';
        }
        if (bin < 10)
        {
            cout << ' ';
        }
        cout << bin << "|";
        for(size_t i = 0; i < height; i++)
        {
            cout << "*";
        }
        cout << endl;
    }
}



int main()
{
    DWORD info = 0;
    info = GetVersion();
    DWORD mask = 0x0000ffff;
    DWORD version = info & mask;
    DWORD platform = info >> 16;
    printf("dwVersion = %u\n", info);
    printf("dwVersion = %08x\n", info);
    printf("Version = %u\n", version);
    printf("Platform = %u\n", platform);
    DWORD MajorVersion = version & 0x00ff;
    DWORD MinorVersion = version >> 8;
    printf("dwMajorVersion = %u\n", MajorVersion);
    printf("dwMinorVersion = %u\n", MinorVersion);
    if((info & 0x80000000) == 0)
    {
        DWORD build = platform;
        printf("build = %u\n", build);
    }

    char system_dir[MAX_PATH];
    GetSystemDirectory(system_dir, MAX_PATH);
    printf("System directory: %s", system_dir);
    /*

    DWORD mask =0x0000ffff;
    DWORD version = info & mask;

    DWORD platform = info >> 16;



    printf("platform = %08x\n", platform);*/


    return 0;
    //ввод данных
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    const auto numbers = input_numbers(number_count);

    size_t bin_count;
    cerr << "Enter bin count: ";
    cin >> bin_count;

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
    find_minmax(numbers,min,max);

    const auto bins = make_histogram(numbers, bin_count);

    //вывод гистограммы
    show_histogram_svg(bins, image_width);


    return 0;
}
