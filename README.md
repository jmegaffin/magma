About
=====

*magma* is a simple library that enables anybody to use AMD's Mantle API.  It reconstructs the Mantle headers using information from the [Mantle documentation and reference](http://www.amd.com/Documents/Mantle-Programming-Guide-and-API-Reference.pdf), and it can load the function pointers from the appropriate Mantle DLLs for you.

Status
======

|Header             |Status    |
|:-----------------:|:--------:|
|`mantle.h`         |complete  |
|`mantleDbg.h`      |complete  |
|`mantleWsiWinExt.h`|complete  |

Building
========

*magma* requires no dependencies.  Simply compile `src/magma.c` with your toolchain of choice and link it with your application, or add it to your project's source tree.

Notes:

- *magma* utilizes a couple of C99 features: `stdint.h` and `//`-style comments.
- Since Mantle is a Windows-only API, *magma* will only build on Windows.

Usage
=====

Simply include `magma.h` and use these functions in your application:

- `MAGMA_RESULT magmaInit(void)`: Loads the function pointers.
- `void magmaTerminate(void)`: Frees the function pointers.

It is safe to call `magmaInit` again after calling `magmaTerminate`.  The functions are also reference-counted, so as long as each call to `magmaInit` is matched with a call to `magmaTerminate` the Mantle function pointers will be loaded and freed correctly.

`magmaInit` will return one of these codes:

- `MAGMA_SUCCESS`: Indicates that the function pointers were loaded successfully.
- `MAGMA_ERROR_DLLS_NOT_FOUND`: Indicates that the appropriate Mantle DLLs were not found.  `magmaTerminate` does not need to be called.

In order to access the actual Mantle API, the appropriate headers, such as `mantle.h` and `mantleWsiWinExt.h`, must be included.

Limitations
===========

*magma* is only intended as a resource for learning, especially since the upcoming Vulkan API will be very similar to Mantle.  Incorporate it into a released application at your own risk.

At the moment *magma* only supports the 64-bit Mantle DLL.  Applications will need to be compiled in 64-bit mode.

Acknowledgments
===============

- Alexander "Overv" Overvoorde: For the "Mantle Hello Triangle" article and sample code, off of which I based part of `mantle.h`.
