#include <IOKit/IOLib.h>
#include <IOKit/IOService.h>

class com_example_driver : public IOService {
    OSDeclareDefaultStructors(com_example_driver)

public:
    virtual bool start(IOService *provider) override;
    virtual void stop(IOService *provider) override;
};

#define super IOService
OSDefineMetaClassAndStructors(com_example_driver, IOService)

bool com_example_driver::start(IOService *provider) {
    if (!super::start(provider)) return false;

    IOLog("com_example_driver::start - Device started\n");
    registerService(); // Make the service available to user space

    return true;
}

void com_example_driver::stop(IOService *provider) {
    IOLog("com_example_driver::stop - Device stopped\n");
    super::stop(provider);
}
