#include <sstream>
#include <thread>
#include <chrono>

#include "ConsolePicture.hpp"

using namespace Sango;

int main() {
	using namespace cv;
	using namespace std;
	using namespace std::chrono_literals;

	constexpr auto progress = 100;
	for (int i = 0; i < progress / 2; i++) {
		std::cout << '[';
		for (int j = 0; j < progress; j++) {
			std::cout << (i < j && j < progress - 1 - i ? ' ' : '-');
		}
		std::cout << "]\r";
		std::cout.flush();
		std::this_thread::sleep_for(10ms);
	}

	std::cout << "\n";

	cv::Mat frame;
	cv::VideoCapture video("input.mp4");
	video >> frame;
	
	stringstream buffer0, buffer1, *buffer;
	int buffer_index = 0;
	buffer = &buffer0;


	while (!frame.empty()) {
		buffer = buffer_index ? &buffer0 : &buffer1;
		buffer_index = (buffer_index + 1) % 1;

		ConsolePicture::Convert(frame, *buffer);
		video >> frame;
		cv::waitKey(1);

		std::string content;
		content = buffer[0].str();
		buffer[0].str("");
		buffer[0].clear();
		std::cout << content << std::endl;
	}

	return 0;
}
