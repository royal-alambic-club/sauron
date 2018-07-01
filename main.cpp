#include <iostream>
#include "ScreenCapture.h"

int main(int argc, char **argv) {
    OutputCapture::ScreenCapture *capturer = OutputCapture::ScreenCapture::GetOrCreateInstance();

    capturer->CaptureFullScreen("./screenshot.bmp");

    return 0;
}
