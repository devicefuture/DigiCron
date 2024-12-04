#ifndef OLDAPI_H_
#define OLDAPI_H_

#include <wasm3.h>

namespace oldApi {
    m3ApiRawFunction(log);
    m3ApiRawFunction(stop);

    void linkFunctions(IM3Runtime runtime);
}

#endif