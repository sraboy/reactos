
#ifndef WINCODECS_PRECOMP_H
#define WINCODECS_PRECOMP_H

#include <wine/config.h>
#include <wine/port.h>

#include <stdarg.h>

#define WIN32_NO_STATUS
#define _INC_WINDOWS
#define COM_NO_WINDOWS_H

#define COBJMACROS
#define NONAMELESSUNION
#define NONAMELESSSTRUCT

#include <windef.h>
#include <winbase.h>
#include <wingdi.h>
#include <winreg.h>
#include <objbase.h>
#include <oleauto.h>

#include "wincodecs_private.h"

#include <wine/debug.h>
#include <wine/heap.h>
#include <wine/library.h>

#endif /* !WINCODECS_PRECOMP_H */
