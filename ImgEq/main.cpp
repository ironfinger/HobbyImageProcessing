#include <iostream>
#include <vector>
#include "include/CImg.h"
#include "SequencialEQ.h"
#define cimg_display 1
using namespace cimg_library;


void hello() {
    std::cout << "Hello Function " << std::endl;
}

void display_vector(std::vector<int> my_vec) {
    for (int i = 0; i <= my_vec.size(); i++) {
        std::cout << my_vec[i] << ", ";
    }
    std::cout << std::endl;
}

void display_vector_d(std::vector<double> my_vec) {
    for (int i = 0; i <= my_vec.size(); i++) {
        std::cout << my_vec[i] << ", ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    typedef int mytype;
    hello();
    CImg<unsigned char> image_input("/home/tom/Documents/Algorithms/ImgEq/picture.jpg");
    CImgDisplay disp_input(image_input, "input");

    SequencialEQ hello = SequencialEQ();
    hello.helloWorld();

    std::cout << "Pixel data" << std::endl;
    std::cout << int(image_input[0]) << std::endl;
    std::cout << image_input.size() << std::endl;

    // Right so we need to initialise a vector to hold the counts of each pixel.
    std::vector<int> intensity(255, 0);

    // Get the intensity histogram:
    for (int pic_index = 0; pic_index <= image_input.size(); pic_index++) {
        // We need to get the current value as an int:
        int curr_value = int(image_input[pic_index]);

        // Then we get the curr value of the hist:
        int curr_hist_val = intensity[curr_value];

        // Then we increase the frequency by one:
        int curr_hist_inc = curr_hist_val + 1;

        // Then we set the new value of the vector:
        intensity[curr_value] = curr_hist_inc;
    }

    // Now we need to get the next value:
    std::vector<int> cumulative_hist(255, 0);
    int cumulative_count = 1;

    // Now we need to get the cumulative histogram:
    for (int i = 1; i <= intensity.size(); i++) {
        // We have the current value
        int curr_value = intensity[i];

        //cumulative_count++;

        // ISSUE: It doesn't for some reason add the values to the last index of the vector.
        // So we meed to add all the values before it:
        int running_total = 0;
        for (int x = 0; x <= i + 1; x++) {
            running_total += intensity[x];
        }


        cumulative_hist[i] = running_total;
    }

//    // Now we need to normalise the histogram:
    std::vector<double> normalised(255, 0);
    int image_dimensions = image_input.width() * image_input.height();

    for (int i = 0; i < normalised.size(); i++) {
        normalised[i] = ((double)(cumulative_hist[i]) / (double)(image_dimensions)) * 255;
    }

    std::vector<unsigned char> output_vec(image_input.size());
    // Now we need to back-propogate:
    for (int i = 0; i < image_input.size(); i++) {
        // Take the current intensity as an index:
        int bin_i = image_input[i];

        // Then we need to gather a new intensity value from the normalised vec:
        double new_intensity = normalised[bin_i];

        output_vec[i] = (int)(new_intensity);
    }

    // Create the new image:
    CImg<unsigned char> output_image(output_vec.data(), image_input.width(), image_input.height(), image_input.depth(), image_input.spectrum());
    CImgDisplay disp_output(output_image,"output");

    // Display the vectors:
    display_vector(intensity);
    display_vector(cumulative_hist);
    display_vector_d(normalised);
    while (!disp_input.is_closed()
           && !disp_input.is_keyESC() && !disp_input.is_keyESC()) {
        disp_input.wait(1);
    }
    return 0;
}
