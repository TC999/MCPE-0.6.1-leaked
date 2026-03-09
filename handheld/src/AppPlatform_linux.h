#ifndef APPPLATFORM_LINUX_H
#define APPPLATFORM_LINUX_H

#include "AppPlatform.h"

class AppPlatform_linux : public AppPlatform {
public:
    AppPlatform_linux();
    virtual ~AppPlatform_linux();
    // 这里添加Linux平台相关的重载方法声明
};

#endif // APPPLATFORM_LINUX_H
