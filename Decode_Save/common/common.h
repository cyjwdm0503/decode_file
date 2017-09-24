#include "json.h"
#include "request.h"
#include "sqlite3.h"

#ifdef UNIX

#else
#pragma comment(lib, "sqlite3.lib")
#pragma comment(lib, "lib_json.lib")
#endif

