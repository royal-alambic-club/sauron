#pragma once

#include <windows.h>
#include <iostream>

namespace OutputCapture
{
    class ScreenCapture
    {
        private:
            ScreenCapture(const ScreenCapture &) = delete;
            ScreenCapture(const ScreenCapture &&) = delete;
            const ScreenCapture &operator=(const ScreenCapture &) = delete;
            const ScreenCapture &&operator=(const ScreenCapture &&) = delete;

            static ScreenCapture *pInstance;

            ScreenCapture();

            bool SaveBMPFile(const char *filename, HDC bitmapDC, uint16_t width, uint16_t height) const;
            bool StartCapture(uint16_t x, uint16_t y, uint16_t width, uint16_t height, const char *filename) const;
            const std::tuple<uint16_t, uint16_t> GetDesktopResolution() const;
            int GetFilePointer(HANDLE FileHandle) const;

        public:
            ~ScreenCapture();


            static ScreenCapture *GetOrCreateInstance()
            {
                if (!pInstance)
                {
                    pInstance = new ScreenCapture;
                }
                return pInstance;
            }

            static void DeleteInstance()
            {
                if (pInstance)
                {
                    delete pInstance;
                }
            }

            bool CaptureFullScreen(std::string outputFileName) const;
    };
}
