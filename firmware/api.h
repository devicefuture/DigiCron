#ifndef API_H_
#define API_H_

#include <wasm3.h>

namespace api {
    m3ApiRawFunction(log);

    void linkFunctions(IM3Runtime runtime);
}

#endif