#pragma once

#include <opencv2/opencv.hpp>
#include <ostream>
#include <format>

namespace Sango {
	class ConsolePicture {
	public:
		inline static void Convert(const cv::Mat& picture, std::ostream& stream) {
			using namespace cv;
			using namespace std;
			
			Mat image;  
			resize(picture, image, Size(180, 94));
			cvtColor(image, image, COLOR_BGR2GRAY);

			for (auto row = 0; row < image.rows; row++) {
				for (auto col = 0; col < image.cols; col++) {
					const unsigned char value = image.ptr(row, col)[0];
					char result = ".*+#&%@"[(10 - ((value / 21) % 12))/2];	
					stream << std::format("{} ", result);
				}
				stream << '\n';
			}
		}
       	};
}
