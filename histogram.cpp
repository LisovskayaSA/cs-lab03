#include "histogram.h"

using namespace std;

void
find_minmax(const vector<double>& numbers, double& min, double& max)
{
    if(numbers.size() == 0)
    {
        return;
    }
    min = numbers[0];
    max = numbers[0];
    for (double x : numbers)
    {
        if (x < min)
        {
            min = x;
        }
        else if (x > max)
        {
            max = x;
        }
    }
}

vector<size_t>
make_histogram(Input data)
{
    double min,max;
    find_minmax(data.numbers,min,max);
    vector<size_t> bins(data.bin_count,0);
    double bin_size = ((max-min) / data.bin_count);
    for(size_t i = 0; i < data.numbers.size(); i++)
    {
        bool found = false;
        for(size_t j = 0; j < (data.bin_count - 1); j++)
        {
            auto lo = min + j * bin_size;
            auto hi = min + (j + 1) * bin_size;
            if ((lo <= data.numbers[i]) && (data.numbers[i] < hi))
            {
                bins[j]++;
                found = true;
            }
        }
        if (!found)
        {
            bins[data.bin_count - 1]++;
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

