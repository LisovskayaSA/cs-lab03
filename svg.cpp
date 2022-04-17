#include "svg.h"

void
svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void
svg_end()
{
    cout << "</svg>\n";
}


void svg_text(double left, double baseline, string text)
{
    cout << "<text x='"<<left<<"' y='"<<baseline<<"'>"<< text<< "</text>\n";
}

void svg_rect(double x, double y, double width, double height, string stroke, string fill)
{
    cout << "<rect x='" << x << "' y='" << y << "' width='"<< width <<"' height='" << height
    << "' stroke='"<< stroke << "' fill='"<< fill<<"'/>\n";
}

void
show_histogram_svg(const vector<size_t>& bins, size_t image_width)
{
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;

    size_t max_bin;
    for(size_t bin: bins){
        if (bin > max_bin){
            max_bin = bin;
        }
    }
    auto max_width = BLOCK_WIDTH * max_bin;
    const size_t max_show_width = image_width - TEXT_WIDTH;
    svg_begin(image_width, IMAGE_HEIGHT);

    double top = 0;
    for (size_t bin : bins)
    {
        double bin_width = BLOCK_WIDTH * bin;
        if(max_show_width < max_width)
        {
            bin_width = static_cast<double>(bin_width) / max_width * max_show_width;
        }
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "gold", "#ff00ff");
        top += BIN_HEIGHT;
    }
    svg_end();
}
