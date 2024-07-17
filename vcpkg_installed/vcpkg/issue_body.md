Package: glfw3:x64-linux@3.4

**Host Environment**

- Host: x64-linux
- Compiler: Clang 16.0.6
-    vcpkg-tool version: 2024-07-10-d2dfc73769081bdd9b782d08d27794780b7a99b9
    vcpkg-scripts version: 1318ab14a 2024-07-16 (13 hours ago)

**To Reproduce**

`vcpkg install `

**Failure logs**

```
-- Using cached glfw-glfw-3.4.tar.gz.
-- Cleaning sources at /home/m-d-nabeel/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean. Use --editable to skip cleaning for the packages you specify.
-- Extracting source /home/m-d-nabeel/vcpkg/downloads/glfw-glfw-3.4.tar.gz
-- Using source at /home/m-d-nabeel/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean
GLFW3 currently requires the following libraries from the system package manager:
    xinerama
    xcursor
    xorg
    libglu1-mesa
    pkg-config

These can be installed on Ubuntu systems via sudo apt install libxinerama-dev libxcursor-dev xorg-dev libglu1-mesa-dev pkg-config

Alternatively, when targeting the Wayland display server, use the packages listed in the GLFW documentation here:

https://www.glfw.org/docs/3.3/compile.html#compile_deps_wayland
-- Found external ninja('1.12.1').
-- Configuring x64-linux
CMake Error at scripts/cmake/vcpkg_execute_required_process.cmake:127 (message):
    Command failed: /usr/bin/ninja -v
    Working Directory: /home/m-d-nabeel/vcpkg/buildtrees/glfw3/x64-linux-rel/vcpkg-parallel-configure
    Error code: 1
    See logs for more information:
      /home/m-d-nabeel/vcpkg/buildtrees/glfw3/config-x64-linux-dbg-CMakeCache.txt.log
      /home/m-d-nabeel/vcpkg/buildtrees/glfw3/config-x64-linux-rel-CMakeCache.txt.log
      /home/m-d-nabeel/vcpkg/buildtrees/glfw3/config-x64-linux-dbg-CMakeConfigureLog.yaml.log
      /home/m-d-nabeel/vcpkg/buildtrees/glfw3/config-x64-linux-rel-CMakeConfigureLog.yaml.log
      /home/m-d-nabeel/vcpkg/buildtrees/glfw3/config-x64-linux-out.log

Call Stack (most recent call first):
  /home/m-d-nabeel/Projects/raylib-cpp-gamedev/vcpkg_installed/x64-linux/share/vcpkg-cmake/vcpkg_cmake_configure.cmake:269 (vcpkg_execute_required_process)
  ports/glfw3/portfile.cmake:40 (vcpkg_cmake_configure)
  scripts/ports.cmake:192 (include)



```

<details><summary>/home/m-d-nabeel/vcpkg/buildtrees/glfw3/config-x64-linux-out.log</summary>

```
[1/2] "/usr/bin/cmake" -E chdir "../../x64-linux-dbg" "/usr/bin/cmake" "/home/m-d-nabeel/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean" "-G" "Ninja" "-DCMAKE_BUILD_TYPE=Debug" "-DCMAKE_INSTALL_PREFIX=/home/m-d-nabeel/vcpkg/packages/glfw3_x64-linux/debug" "-DFETCHCONTENT_FULLY_DISCONNECTED=ON" "-DGLFW_BUILD_EXAMPLES=OFF" "-DGLFW_BUILD_TESTS=OFF" "-DGLFW_BUILD_DOCS=OFF" "-DGLFW_BUILD_WAYLAND=OFF" "-DCMAKE_MAKE_PROGRAM=/usr/bin/ninja" "-DCMAKE_SYSTEM_NAME=Linux" "-DBUILD_SHARED_LIBS=OFF" "-DVCPKG_CHAINLOAD_TOOLCHAIN_FILE=/home/m-d-nabeel/vcpkg/scripts/toolchains/linux.cmake" "-DVCPKG_TARGET_TRIPLET=x64-linux" "-DVCPKG_SET_CHARSET_FLAG=ON" "-DVCPKG_PLATFORM_TOOLSET=external" "-DCMAKE_EXPORT_NO_PACKAGE_REGISTRY=ON" "-DCMAKE_FIND_PACKAGE_NO_PACKAGE_REGISTRY=ON" "-DCMAKE_FIND_PACKAGE_NO_SYSTEM_PACKAGE_REGISTRY=ON" "-DCMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_SKIP=TRUE" "-DCMAKE_VERBOSE_MAKEFILE=ON" "-DVCPKG_APPLOCAL_DEPS=OFF" "-DCMAKE_TOOLCHAIN_FILE=/home/m-d-nabeel/vcpkg/scripts/buildsystems/vcpkg.cmake" "-DCMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION=ON" "-DVCPKG_CXX_FLAGS=" "-DVCPKG_CXX_FLAGS_RELEASE=" "-DVCPKG_CXX_FLAGS_DEBUG=" "-DVCPKG_C_FLAGS=" "-DVCPKG_C_FLAGS_RELEASE=" "-DVCPKG_C_FLAGS_DEBUG=" "-DVCPKG_CRT_LINKAGE=dynamic" "-DVCPKG_LINKER_FLAGS=" "-DVCPKG_LINKER_FLAGS_RELEASE=" "-DVCPKG_LINKER_FLAGS_DEBUG=" "-DVCPKG_TARGET_ARCHITECTURE=x64" "-DCMAKE_INSTALL_LIBDIR:STRING=lib" "-DCMAKE_INSTALL_BINDIR:STRING=bin" "-D_VCPKG_ROOT_DIR=/home/m-d-nabeel/vcpkg" "-D_VCPKG_INSTALLED_DIR=/home/m-d-nabeel/Projects/raylib-cpp-gamedev/vcpkg_installed" "-DVCPKG_MANIFEST_INSTALL=OFF"
FAILED: ../../x64-linux-dbg/CMakeCache.txt 
"/usr/bin/cmake" -E chdir "../../x64-linux-dbg" "/usr/bin/cmake" "/home/m-d-nabeel/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean" "-G" "Ninja" "-DCMAKE_BUILD_TYPE=Debug" "-DCMAKE_INSTALL_PREFIX=/home/m-d-nabeel/vcpkg/packages/glfw3_x64-linux/debug" "-DFETCHCONTENT_FULLY_DISCONNECTED=ON" "-DGLFW_BUILD_EXAMPLES=OFF" "-DGLFW_BUILD_TESTS=OFF" "-DGLFW_BUILD_DOCS=OFF" "-DGLFW_BUILD_WAYLAND=OFF" "-DCMAKE_MAKE_PROGRAM=/usr/bin/ninja" "-DCMAKE_SYSTEM_NAME=Linux" "-DBUILD_SHARED_LIBS=OFF" "-DVCPKG_CHAINLOAD_TOOLCHAIN_FILE=/home/m-d-nabeel/vcpkg/scripts/toolchains/linux.cmake" "-DVCPKG_TARGET_TRIPLET=x64-linux" "-DVCPKG_SET_CHARSET_FLAG=ON" "-DVCPKG_PLATFORM_TOOLSET=external" "-DCMAKE_EXPORT_NO_PACKAGE_REGISTRY=ON" "-DCMAKE_FIND_PACKAGE_NO_PACKAGE_REGISTRY=ON" "-DCMAKE_FIND_PACKAGE_NO_SYSTEM_PACKAGE_REGISTRY=ON" "-DCMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_SKIP=TRUE" "-DCMAKE_VERBOSE_MAKEFILE=ON" "-DVCPKG_APPLOCAL_DEPS=OFF" "-DCMAKE_TOOLCHAIN_FILE=/home/m-d-nabeel/vcpkg/scripts/buildsystems/vcpkg.cmake" "-DCMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION=ON" "-DVCPKG_CXX_FLAGS=" "-DVCPKG_CXX_FLAGS_RELEASE=" "-DVCPKG_CXX_FLAGS_DEBUG=" "-DVCPKG_C_FLAGS=" "-DVCPKG_C_FLAGS_RELEASE=" "-DVCPKG_C_FLAGS_DEBUG=" "-DVCPKG_CRT_LINKAGE=dynamic" "-DVCPKG_LINKER_FLAGS=" "-DVCPKG_LINKER_FLAGS_RELEASE=" "-DVCPKG_LINKER_FLAGS_DEBUG=" "-DVCPKG_TARGET_ARCHITECTURE=x64" "-DCMAKE_INSTALL_LIBDIR:STRING=lib" "-DCMAKE_INSTALL_BINDIR:STRING=bin" "-D_VCPKG_ROOT_DIR=/home/m-d-nabeel/vcpkg" "-D_VCPKG_INSTALLED_DIR=/home/m-d-nabeel/Projects/raylib-cpp-gamedev/vcpkg_installed" "-DVCPKG_MANIFEST_INSTALL=OFF"
-- The C compiler identification is GNU 13.3.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Success
-- Found Threads: TRUE
-- Including X11 support
CMake Error at /usr/share/cmake-3.29/Modules/FindPackageHandleStandardArgs.cmake:230 (message):
  Could NOT find X11 (missing: X11_X11_INCLUDE_PATH X11_X11_LIB)
Call Stack (most recent call first):
  /usr/share/cmake-3.29/Modules/FindPackageHandleStandardArgs.cmake:600 (_FPHSA_FAILURE_MESSAGE)
  /usr/share/cmake-3.29/Modules/FindX11.cmake:676 (find_package_handle_standard_args)
  /home/m-d-nabeel/vcpkg/scripts/buildsystems/vcpkg.cmake:857 (_find_package)
  src/CMakeLists.txt:181 (find_package)


-- Configuring incomplete, errors occurred!
[2/2] "/usr/bin/cmake" -E chdir ".." "/usr/bin/cmake" "/home/m-d-nabeel/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean" "-G" "Ninja" "-DCMAKE_BUILD_TYPE=Release" "-DCMAKE_INSTALL_PREFIX=/home/m-d-nabeel/vcpkg/packages/glfw3_x64-linux" "-DFETCHCONTENT_FULLY_DISCONNECTED=ON" "-DGLFW_BUILD_EXAMPLES=OFF" "-DGLFW_BUILD_TESTS=OFF" "-DGLFW_BUILD_DOCS=OFF" "-DGLFW_BUILD_WAYLAND=OFF" "-DCMAKE_MAKE_PROGRAM=/usr/bin/ninja" "-DCMAKE_SYSTEM_NAME=Linux" "-DBUILD_SHARED_LIBS=OFF" "-DVCPKG_CHAINLOAD_TOOLCHAIN_FILE=/home/m-d-nabeel/vcpkg/scripts/toolchains/linux.cmake" "-DVCPKG_TARGET_TRIPLET=x64-linux" "-DVCPKG_SET_CHARSET_FLAG=ON" "-DVCPKG_PLATFORM_TOOLSET=external" "-DCMAKE_EXPORT_NO_PACKAGE_REGISTRY=ON" "-DCMAKE_FIND_PACKAGE_NO_PACKAGE_REGISTRY=ON" "-DCMAKE_FIND_PACKAGE_NO_SYSTEM_PACKAGE_REGISTRY=ON" "-DCMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_SKIP=TRUE" "-DCMAKE_VERBOSE_MAKEFILE=ON" "-DVCPKG_APPLOCAL_DEPS=OFF" "-DCMAKE_TOOLCHAIN_FILE=/home/m-d-nabeel/vcpkg/scripts/buildsystems/vcpkg.cmake" "-DCMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION=ON" "-DVCPKG_CXX_FLAGS=" "-DVCPKG_CXX_FLAGS_RELEASE=" "-DVCPKG_CXX_FLAGS_DEBUG=" "-DVCPKG_C_FLAGS=" "-DVCPKG_C_FLAGS_RELEASE=" "-DVCPKG_C_FLAGS_DEBUG=" "-DVCPKG_CRT_LINKAGE=dynamic" "-DVCPKG_LINKER_FLAGS=" "-DVCPKG_LINKER_FLAGS_RELEASE=" "-DVCPKG_LINKER_FLAGS_DEBUG=" "-DVCPKG_TARGET_ARCHITECTURE=x64" "-DCMAKE_INSTALL_LIBDIR:STRING=lib" "-DCMAKE_INSTALL_BINDIR:STRING=bin" "-D_VCPKG_ROOT_DIR=/home/m-d-nabeel/vcpkg" "-D_VCPKG_INSTALLED_DIR=/home/m-d-nabeel/Projects/raylib-cpp-gamedev/vcpkg_installed" "-DVCPKG_MANIFEST_INSTALL=OFF"
FAILED: ../CMakeCache.txt 
"/usr/bin/cmake" -E chdir ".." "/usr/bin/cmake" "/home/m-d-nabeel/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean" "-G" "Ninja" "-DCMAKE_BUILD_TYPE=Release" "-DCMAKE_INSTALL_PREFIX=/home/m-d-nabeel/vcpkg/packages/glfw3_x64-linux" "-DFETCHCONTENT_FULLY_DISCONNECTED=ON" "-DGLFW_BUILD_EXAMPLES=OFF" "-DGLFW_BUILD_TESTS=OFF" "-DGLFW_BUILD_DOCS=OFF" "-DGLFW_BUILD_WAYLAND=OFF" "-DCMAKE_MAKE_PROGRAM=/usr/bin/ninja" "-DCMAKE_SYSTEM_NAME=Linux" "-DBUILD_SHARED_LIBS=OFF" "-DVCPKG_CHAINLOAD_TOOLCHAIN_FILE=/home/m-d-nabeel/vcpkg/scripts/toolchains/linux.cmake" "-DVCPKG_TARGET_TRIPLET=x64-linux" "-DVCPKG_SET_CHARSET_FLAG=ON" "-DVCPKG_PLATFORM_TOOLSET=external" "-DCMAKE_EXPORT_NO_PACKAGE_REGISTRY=ON" "-DCMAKE_FIND_PACKAGE_NO_PACKAGE_REGISTRY=ON" "-DCMAKE_FIND_PACKAGE_NO_SYSTEM_PACKAGE_REGISTRY=ON" "-DCMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_SKIP=TRUE" "-DCMAKE_VERBOSE_MAKEFILE=ON" "-DVCPKG_APPLOCAL_DEPS=OFF" "-DCMAKE_TOOLCHAIN_FILE=/home/m-d-nabeel/vcpkg/scripts/buildsystems/vcpkg.cmake" "-DCMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION=ON" "-DVCPKG_CXX_FLAGS=" "-DVCPKG_CXX_FLAGS_RELEASE=" "-DVCPKG_CXX_FLAGS_DEBUG=" "-DVCPKG_C_FLAGS=" "-DVCPKG_C_FLAGS_RELEASE=" "-DVCPKG_C_FLAGS_DEBUG=" "-DVCPKG_CRT_LINKAGE=dynamic" "-DVCPKG_LINKER_FLAGS=" "-DVCPKG_LINKER_FLAGS_RELEASE=" "-DVCPKG_LINKER_FLAGS_DEBUG=" "-DVCPKG_TARGET_ARCHITECTURE=x64" "-DCMAKE_INSTALL_LIBDIR:STRING=lib" "-DCMAKE_INSTALL_BINDIR:STRING=bin" "-D_VCPKG_ROOT_DIR=/home/m-d-nabeel/vcpkg" "-D_VCPKG_INSTALLED_DIR=/home/m-d-nabeel/Projects/raylib-cpp-gamedev/vcpkg_installed" "-DVCPKG_MANIFEST_INSTALL=OFF"
-- The C compiler identification is GNU 13.3.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Success
-- Found Threads: TRUE
-- Including X11 support
CMake Error at /usr/share/cmake-3.29/Modules/FindPackageHandleStandardArgs.cmake:230 (message):
  Could NOT find X11 (missing: X11_X11_INCLUDE_PATH X11_X11_LIB)
Call Stack (most recent call first):
  /usr/share/cmake-3.29/Modules/FindPackageHandleStandardArgs.cmake:600 (_FPHSA_FAILURE_MESSAGE)
  /usr/share/cmake-3.29/Modules/FindX11.cmake:676 (find_package_handle_standard_args)
  /home/m-d-nabeel/vcpkg/scripts/buildsystems/vcpkg.cmake:857 (_find_package)
  src/CMakeLists.txt:181 (find_package)


-- Configuring incomplete, errors occurred!
ninja: build stopped: subcommand failed.
```
</details>

<details><summary>/home/m-d-nabeel/vcpkg/buildtrees/glfw3/config-x64-linux-rel-CMakeCache.txt.log</summary>

```
# This is the CMakeCache file.
# For build in directory: /home/m-d-nabeel/vcpkg/buildtrees/glfw3/x64-linux-rel
# It was generated by CMake: /usr/bin/cmake
# You can edit this file to change values found and used by cmake.
# If you do not want to change any of the values, simply exit the editor.
# If you do want to change a value, simply edit, save, and exit the editor.
# The syntax for the file is as follows:
# KEY:TYPE=VALUE
# KEY is the name of a variable in the cache.
# TYPE is a hint to GUIs for the type of VALUE, DO NOT EDIT TYPE!.
# VALUE is the current value for the KEY.

########################
# EXTERNAL cache entries
########################

//Build shared libraries
BUILD_SHARED_LIBS:BOOL=OFF

//Path to a program.
CMAKE_ADDR2LINE:FILEPATH=/usr/bin/addr2line

//Path to a program.
CMAKE_AR:FILEPATH=/usr/bin/ar

//Choose the type of build, options are: None Debug Release RelWithDebInfo
// MinSizeRel ...
CMAKE_BUILD_TYPE:STRING=Release

CMAKE_CROSSCOMPILING:BOOL=OFF

//C compiler
CMAKE_C_COMPILER:FILEPATH=/usr/bin/cc

//A wrapper around 'ar' adding the appropriate '--plugin' option
// for the GCC compiler
CMAKE_C_COMPILER_AR:FILEPATH=/usr/bin/gcc-ar-13

//A wrapper around 'ranlib' adding the appropriate '--plugin' option
// for the GCC compiler
CMAKE_C_COMPILER_RANLIB:FILEPATH=/usr/bin/gcc-ranlib-13

//Flags used by the C compiler during all build types.
CMAKE_C_FLAGS:STRING=-fPIC

//Flags used by the C compiler during DEBUG builds.
CMAKE_C_FLAGS_DEBUG:STRING=-g

//Flags used by the C compiler during MINSIZEREL builds.
CMAKE_C_FLAGS_MINSIZEREL:STRING=-Os -DNDEBUG

//Flags used by the C compiler during RELEASE builds.
CMAKE_C_FLAGS_RELEASE:STRING=-O3 -DNDEBUG

//Flags used by the C compiler during RELWITHDEBINFO builds.
CMAKE_C_FLAGS_RELWITHDEBINFO:STRING=-O2 -g -DNDEBUG

//Path to a program.
CMAKE_DLLTOOL:FILEPATH=CMAKE_DLLTOOL-NOTFOUND

//No help, variable specified on the command line.
CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION:UNINITIALIZED=ON

//Flags used by the linker during all build types.
CMAKE_EXE_LINKER_FLAGS:STRING=

//Flags used by the linker during DEBUG builds.
CMAKE_EXE_LINKER_FLAGS_DEBUG:STRING=

//Flags used by the linker during MINSIZEREL builds.
CMAKE_EXE_LINKER_FLAGS_MINSIZEREL:STRING=

//Flags used by the linker during RELEASE builds.
CMAKE_EXE_LINKER_FLAGS_RELEASE:STRING=

//Flags used by the linker during RELWITHDEBINFO builds.
CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO:STRING=

//Enable/Disable output of compile commands during generation.
CMAKE_EXPORT_COMPILE_COMMANDS:BOOL=

//No help, variable specified on the command line.
CMAKE_EXPORT_NO_PACKAGE_REGISTRY:UNINITIALIZED=ON

//No help, variable specified on the command line.
CMAKE_FIND_PACKAGE_NO_PACKAGE_REGISTRY:UNINITIALIZED=ON

//No help, variable specified on the command line.
CMAKE_FIND_PACKAGE_NO_SYSTEM_PACKAGE_REGISTRY:UNINITIALIZED=ON

//Value Computed by CMake.
CMAKE_FIND_PACKAGE_REDIRECTS_DIR:STATIC=/home/m-d-nabeel/vcpkg/buildtrees/glfw3/x64-linux-rel/CMakeFiles/pkgRedirects

//No help, variable specified on the command line.
CMAKE_INSTALL_BINDIR:STRING=bin

//Read-only architecture-independent data (DATAROOTDIR)
CMAKE_INSTALL_DATADIR:PATH=

//Read-only architecture-independent data root (share)
CMAKE_INSTALL_DATAROOTDIR:PATH=share

//Documentation root (DATAROOTDIR/doc/PROJECT_NAME)
CMAKE_INSTALL_DOCDIR:PATH=

//C header files (include)
CMAKE_INSTALL_INCLUDEDIR:PATH=include

//Info documentation (DATAROOTDIR/info)
CMAKE_INSTALL_INFODIR:PATH=

//No help, variable specified on the command line.
CMAKE_INSTALL_LIBDIR:STRING=lib

//Program executables (libexec)
CMAKE_INSTALL_LIBEXECDIR:PATH=libexec

//Locale-dependent data (DATAROOTDIR/locale)
CMAKE_INSTALL_LOCALEDIR:PATH=

//Modifiable single-machine data (var)
CMAKE_INSTALL_LOCALSTATEDIR:PATH=var

//Man documentation (DATAROOTDIR/man)
CMAKE_INSTALL_MANDIR:PATH=

//C header files for non-gcc (/usr/include)
CMAKE_INSTALL_OLDINCLUDEDIR:PATH=/usr/include

//Install path prefix, prepended onto install directories.
CMAKE_INSTALL_PREFIX:PATH=/home/m-d-nabeel/vcpkg/packages/glfw3_x64-linux

//Run-time variable data (LOCALSTATEDIR/run)
CMAKE_INSTALL_RUNSTATEDIR:PATH=

//System admin executables (sbin)
CMAKE_INSTALL_SBINDIR:PATH=sbin

//Modifiable architecture-independent data (com)
CMAKE_INSTALL_SHAREDSTATEDIR:PATH=com

//Read-only single-machine data (etc)
CMAKE_INSTALL_SYSCONFDIR:PATH=etc

//No help, variable specified on the command line.
CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_SKIP:UNINITIALIZED=TRUE

//Path to a program.
CMAKE_LINKER:FILEPATH=/usr/bin/ld

//No help, variable specified on the command line.
CMAKE_MAKE_PROGRAM:UNINITIALIZED=/usr/bin/ninja

//Flags used by the linker during the creation of modules during
// all build types.
CMAKE_MODULE_LINKER_FLAGS:STRING=

//Flags used by the linker during the creation of modules during
// DEBUG builds.
CMAKE_MODULE_LINKER_FLAGS_DEBUG:STRING=

//Flags used by the linker during the creation of modules during
// MINSIZEREL builds.
CMAKE_MODULE_LINKER_FLAGS_MINSIZEREL:STRING=

//Flags used by the linker during the creation of modules during
// RELEASE builds.
CMAKE_MODULE_LINKER_FLAGS_RELEASE:STRING=

//Flags used by the linker during the creation of modules during
// RELWITHDEBINFO builds.
CMAKE_MODULE_LINKER_FLAGS_RELWITHDEBINFO:STRING=

//Path to a program.
CMAKE_NM:FILEPATH=/usr/bin/nm

//Path to a program.
CMAKE_OBJCOPY:FILEPATH=/usr/bin/objcopy

//Path to a program.
CMAKE_OBJDUMP:FILEPATH=/usr/bin/objdump

//Value Computed by CMake
CMAKE_PROJECT_DESCRIPTION:STATIC=

...
Skipped 538 lines
...

//Path to a file.
X11_xcb_xfixes_INCLUDE_PATH:PATH=X11_xcb_xfixes_INCLUDE_PATH-NOTFOUND

//Path to a library.
X11_xcb_xfixes_LIB:FILEPATH=X11_xcb_xfixes_LIB-NOTFOUND

//Path to a file.
X11_xcb_xinerama_INCLUDE_PATH:PATH=X11_xcb_xinerama_INCLUDE_PATH-NOTFOUND

//Path to a library.
X11_xcb_xinerama_LIB:FILEPATH=X11_xcb_xinerama_LIB-NOTFOUND

//Path to a file.
X11_xcb_xinput_INCLUDE_PATH:PATH=X11_xcb_xinput_INCLUDE_PATH-NOTFOUND

//Path to a library.
X11_xcb_xinput_LIB:FILEPATH=X11_xcb_xinput_LIB-NOTFOUND

//Path to a file.
X11_xcb_xkb_INCLUDE_PATH:PATH=X11_xcb_xkb_INCLUDE_PATH-NOTFOUND

//Path to a library.
X11_xcb_xkb_LIB:FILEPATH=X11_xcb_xkb_LIB-NOTFOUND

//Path to a file.
X11_xcb_xrm_INCLUDE_PATH:PATH=X11_xcb_xrm_INCLUDE_PATH-NOTFOUND

//Path to a library.
X11_xcb_xrm_LIB:FILEPATH=X11_xcb_xrm_LIB-NOTFOUND

//Path to a file.
X11_xcb_xtest_INCLUDE_PATH:PATH=X11_xcb_xtest_INCLUDE_PATH-NOTFOUND

//Path to a library.
X11_xcb_xtest_LIB:FILEPATH=X11_xcb_xtest_LIB-NOTFOUND

//Path to a file.
X11_xcb_xv_INCLUDE_PATH:PATH=X11_xcb_xv_INCLUDE_PATH-NOTFOUND

//Path to a library.
X11_xcb_xv_LIB:FILEPATH=X11_xcb_xv_LIB-NOTFOUND

//Path to a file.
X11_xcb_xvmc_INCLUDE_PATH:PATH=X11_xcb_xvmc_INCLUDE_PATH-NOTFOUND

//Path to a library.
X11_xcb_xvmc_LIB:FILEPATH=X11_xcb_xvmc_LIB-NOTFOUND

//Path to a file.
X11_xkbcommon_INCLUDE_PATH:PATH=X11_xkbcommon_INCLUDE_PATH-NOTFOUND

//Path to a library.
X11_xkbcommon_LIB:FILEPATH=X11_xkbcommon_LIB-NOTFOUND

//Path to a file.
X11_xkbcommon_X11_INCLUDE_PATH:PATH=X11_xkbcommon_X11_INCLUDE_PATH-NOTFOUND

//Path to a library.
X11_xkbcommon_X11_LIB:FILEPATH=X11_xkbcommon_X11_LIB-NOTFOUND

//Path to a file.
X11_xkbfile_INCLUDE_PATH:PATH=X11_xkbfile_INCLUDE_PATH-NOTFOUND

//Path to a library.
X11_xkbfile_LIB:FILEPATH=X11_xkbfile_LIB-NOTFOUND

//(experimental) Automatically copy dependencies into the install
// target directory for executables. Requires CMake 3.14.
X_VCPKG_APPLOCAL_DEPS_INSTALL:BOOL=OFF

//(experimental) Add USES_TERMINAL to VCPKG_APPLOCAL_DEPS to force
// serialization.
X_VCPKG_APPLOCAL_DEPS_SERIALIZED:BOOL=OFF

//The directory which contains the installed libraries for each
// triplet
_VCPKG_INSTALLED_DIR:PATH=/home/m-d-nabeel/Projects/raylib-cpp-gamedev/vcpkg_installed

//No help, variable specified on the command line.
_VCPKG_ROOT_DIR:UNINITIALIZED=/home/m-d-nabeel/vcpkg


########################
# INTERNAL cache entries
########################

//ADVANCED property for variable: CMAKE_ADDR2LINE
CMAKE_ADDR2LINE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_AR
CMAKE_AR-ADVANCED:INTERNAL=1
//This is the directory where this CMakeCache.txt was created
CMAKE_CACHEFILE_DIR:INTERNAL=/home/m-d-nabeel/vcpkg/buildtrees/glfw3/x64-linux-rel
//Major version of cmake used to create the current loaded cache
CMAKE_CACHE_MAJOR_VERSION:INTERNAL=3
//Minor version of cmake used to create the current loaded cache
CMAKE_CACHE_MINOR_VERSION:INTERNAL=29
//Patch version of cmake used to create the current loaded cache
CMAKE_CACHE_PATCH_VERSION:INTERNAL=6
//Path to CMake executable.
CMAKE_COMMAND:INTERNAL=/usr/bin/cmake
//Path to cpack program executable.
CMAKE_CPACK_COMMAND:INTERNAL=/usr/bin/cpack
//Path to ctest program executable.
CMAKE_CTEST_COMMAND:INTERNAL=/usr/bin/ctest
//ADVANCED property for variable: CMAKE_C_COMPILER
CMAKE_C_COMPILER-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_C_COMPILER_AR
CMAKE_C_COMPILER_AR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_C_COMPILER_RANLIB
CMAKE_C_COMPILER_RANLIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_C_FLAGS
CMAKE_C_FLAGS-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_C_FLAGS_DEBUG
CMAKE_C_FLAGS_DEBUG-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_C_FLAGS_MINSIZEREL
CMAKE_C_FLAGS_MINSIZEREL-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_C_FLAGS_RELEASE
CMAKE_C_FLAGS_RELEASE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_C_FLAGS_RELWITHDEBINFO
CMAKE_C_FLAGS_RELWITHDEBINFO-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_DLLTOOL
CMAKE_DLLTOOL-ADVANCED:INTERNAL=1
//Executable file format
CMAKE_EXECUTABLE_FORMAT:INTERNAL=ELF
//ADVANCED property for variable: CMAKE_EXE_LINKER_FLAGS
CMAKE_EXE_LINKER_FLAGS-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_EXE_LINKER_FLAGS_DEBUG
CMAKE_EXE_LINKER_FLAGS_DEBUG-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_EXE_LINKER_FLAGS_MINSIZEREL
CMAKE_EXE_LINKER_FLAGS_MINSIZEREL-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_EXE_LINKER_FLAGS_RELEASE
CMAKE_EXE_LINKER_FLAGS_RELEASE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO
CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_EXPORT_COMPILE_COMMANDS
CMAKE_EXPORT_COMPILE_COMMANDS-ADVANCED:INTERNAL=1
//Name of external makefile project generator.
CMAKE_EXTRA_GENERATOR:INTERNAL=
//Name of generator.
CMAKE_GENERATOR:INTERNAL=Ninja
//Generator instance identifier.
CMAKE_GENERATOR_INSTANCE:INTERNAL=
//Name of generator platform.
CMAKE_GENERATOR_PLATFORM:INTERNAL=
//Name of generator toolset.
CMAKE_GENERATOR_TOOLSET:INTERNAL=
//Test CMAKE_HAVE_LIBC_PTHREAD
CMAKE_HAVE_LIBC_PTHREAD:INTERNAL=1
//Source directory with the top level CMakeLists.txt file for this
// project
CMAKE_HOME_DIRECTORY:INTERNAL=/home/m-d-nabeel/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean
//ADVANCED property for variable: CMAKE_INSTALL_BINDIR
CMAKE_INSTALL_BINDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_DATADIR
CMAKE_INSTALL_DATADIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_DATAROOTDIR
CMAKE_INSTALL_DATAROOTDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_DOCDIR
CMAKE_INSTALL_DOCDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_INCLUDEDIR
CMAKE_INSTALL_INCLUDEDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_INFODIR
CMAKE_INSTALL_INFODIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_LIBDIR
CMAKE_INSTALL_LIBDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_LIBEXECDIR
CMAKE_INSTALL_LIBEXECDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_LOCALEDIR
CMAKE_INSTALL_LOCALEDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_LOCALSTATEDIR
CMAKE_INSTALL_LOCALSTATEDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_MANDIR
CMAKE_INSTALL_MANDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_OLDINCLUDEDIR
CMAKE_INSTALL_OLDINCLUDEDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_RUNSTATEDIR
CMAKE_INSTALL_RUNSTATEDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_SBINDIR
CMAKE_INSTALL_SBINDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_SHAREDSTATEDIR
CMAKE_INSTALL_SHAREDSTATEDIR-ADVANCED:INTERNAL=1
//Install .so files without execute permission.
CMAKE_INSTALL_SO_NO_EXE:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_SYSCONFDIR
CMAKE_INSTALL_SYSCONFDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_LINKER
CMAKE_LINKER-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_MODULE_LINKER_FLAGS
CMAKE_MODULE_LINKER_FLAGS-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_MODULE_LINKER_FLAGS_DEBUG
CMAKE_MODULE_LINKER_FLAGS_DEBUG-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_MODULE_LINKER_FLAGS_MINSIZEREL
CMAKE_MODULE_LINKER_FLAGS_MINSIZEREL-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_MODULE_LINKER_FLAGS_RELEASE
CMAKE_MODULE_LINKER_FLAGS_RELEASE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_MODULE_LINKER_FLAGS_RELWITHDEBINFO
CMAKE_MODULE_LINKER_FLAGS_RELWITHDEBINFO-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_NM
CMAKE_NM-ADVANCED:INTERNAL=1
//number of local generators
CMAKE_NUMBER_OF_MAKEFILES:INTERNAL=2
//ADVANCED property for variable: CMAKE_OBJCOPY
CMAKE_OBJCOPY-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_OBJDUMP
CMAKE_OBJDUMP-ADVANCED:INTERNAL=1
//Platform information initialized
CMAKE_PLATFORM_INFO_INITIALIZED:INTERNAL=1
//ADVANCED property for variable: CMAKE_RANLIB
CMAKE_RANLIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_READELF
CMAKE_READELF-ADVANCED:INTERNAL=1
//Path to CMake installation.
CMAKE_ROOT:INTERNAL=/usr/share/cmake-3.29
//ADVANCED property for variable: CMAKE_SHARED_LINKER_FLAGS
CMAKE_SHARED_LINKER_FLAGS-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SHARED_LINKER_FLAGS_DEBUG
CMAKE_SHARED_LINKER_FLAGS_DEBUG-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SHARED_LINKER_FLAGS_MINSIZEREL
CMAKE_SHARED_LINKER_FLAGS_MINSIZEREL-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SHARED_LINKER_FLAGS_RELEASE
CMAKE_SHARED_LINKER_FLAGS_RELEASE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO
CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SKIP_INSTALL_RPATH
CMAKE_SKIP_INSTALL_RPATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SKIP_RPATH
CMAKE_SKIP_RPATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STATIC_LINKER_FLAGS
CMAKE_STATIC_LINKER_FLAGS-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STATIC_LINKER_FLAGS_DEBUG
CMAKE_STATIC_LINKER_FLAGS_DEBUG-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STATIC_LINKER_FLAGS_MINSIZEREL
CMAKE_STATIC_LINKER_FLAGS_MINSIZEREL-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STATIC_LINKER_FLAGS_RELEASE
CMAKE_STATIC_LINKER_FLAGS_RELEASE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STATIC_LINKER_FLAGS_RELWITHDEBINFO
CMAKE_STATIC_LINKER_FLAGS_RELWITHDEBINFO-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STRIP
CMAKE_STRIP-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_TAPI
CMAKE_TAPI-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_TOOLCHAIN_FILE
CMAKE_TOOLCHAIN_FILE-ADVANCED:INTERNAL=1
//uname command
CMAKE_UNAME:INTERNAL=/usr/bin/uname
//ADVANCED property for variable: CMAKE_VERBOSE_MAKEFILE
CMAKE_VERBOSE_MAKEFILE-ADVANCED:INTERNAL=1
//Details about finding Threads
FIND_PACKAGE_MESSAGE_DETAILS_Threads:INTERNAL=[TRUE][v()]
//Install the dependencies listed in your manifest:
//\n    If this is off, you will have to manually install your dependencies.
//\n    See https://github.com/microsoft/vcpkg/tree/master/docs/specifications/manifests.md
// for more info.
//\n
VCPKG_MANIFEST_INSTALL:INTERNAL=OFF
//ADVANCED property for variable: VCPKG_VERBOSE
VCPKG_VERBOSE-ADVANCED:INTERNAL=1
//Making sure VCPKG_MANIFEST_MODE doesn't change
Z_VCPKG_CHECK_MANIFEST_MODE:INTERNAL=OFF
//Vcpkg root directory
Z_VCPKG_ROOT_DIR:INTERNAL=/home/m-d-nabeel/vcpkg
//linker supports push/pop state
_CMAKE_LINKER_PUSHPOP_STATE_SUPPORTED:INTERNAL=TRUE
//CMAKE_INSTALL_PREFIX during last run
_GNUInstallDirs_LAST_CMAKE_INSTALL_PREFIX:INTERNAL=/home/m-d-nabeel/vcpkg/packages/glfw3_x64-linux
```
</details>

<details><summary>/home/m-d-nabeel/vcpkg/buildtrees/glfw3/config-x64-linux-dbg-CMakeCache.txt.log</summary>

```
# This is the CMakeCache file.
# For build in directory: /home/m-d-nabeel/vcpkg/buildtrees/glfw3/x64-linux-dbg
# It was generated by CMake: /usr/bin/cmake
# You can edit this file to change values found and used by cmake.
# If you do not want to change any of the values, simply exit the editor.
# If you do want to change a value, simply edit, save, and exit the editor.
# The syntax for the file is as follows:
# KEY:TYPE=VALUE
# KEY is the name of a variable in the cache.
# TYPE is a hint to GUIs for the type of VALUE, DO NOT EDIT TYPE!.
# VALUE is the current value for the KEY.

########################
# EXTERNAL cache entries
########################

//Build shared libraries
BUILD_SHARED_LIBS:BOOL=OFF

//Path to a program.
CMAKE_ADDR2LINE:FILEPATH=/usr/bin/addr2line

//Path to a program.
CMAKE_AR:FILEPATH=/usr/bin/ar

//Choose the type of build, options are: None Debug Release RelWithDebInfo
// MinSizeRel ...
CMAKE_BUILD_TYPE:STRING=Debug

CMAKE_CROSSCOMPILING:BOOL=OFF

//C compiler
CMAKE_C_COMPILER:FILEPATH=/usr/bin/cc

//A wrapper around 'ar' adding the appropriate '--plugin' option
// for the GCC compiler
CMAKE_C_COMPILER_AR:FILEPATH=/usr/bin/gcc-ar-13

//A wrapper around 'ranlib' adding the appropriate '--plugin' option
// for the GCC compiler
CMAKE_C_COMPILER_RANLIB:FILEPATH=/usr/bin/gcc-ranlib-13

//Flags used by the C compiler during all build types.
CMAKE_C_FLAGS:STRING=-fPIC

//Flags used by the C compiler during DEBUG builds.
CMAKE_C_FLAGS_DEBUG:STRING=-g

//Flags used by the C compiler during MINSIZEREL builds.
CMAKE_C_FLAGS_MINSIZEREL:STRING=-Os -DNDEBUG

//Flags used by the C compiler during RELEASE builds.
CMAKE_C_FLAGS_RELEASE:STRING=-O3 -DNDEBUG

//Flags used by the C compiler during RELWITHDEBINFO builds.
CMAKE_C_FLAGS_RELWITHDEBINFO:STRING=-O2 -g -DNDEBUG

//Path to a program.
CMAKE_DLLTOOL:FILEPATH=CMAKE_DLLTOOL-NOTFOUND

//No help, variable specified on the command line.
CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION:UNINITIALIZED=ON

//Flags used by the linker during all build types.
CMAKE_EXE_LINKER_FLAGS:STRING=

//Flags used by the linker during DEBUG builds.
CMAKE_EXE_LINKER_FLAGS_DEBUG:STRING=

//Flags used by the linker during MINSIZEREL builds.
CMAKE_EXE_LINKER_FLAGS_MINSIZEREL:STRING=

//Flags used by the linker during RELEASE builds.
CMAKE_EXE_LINKER_FLAGS_RELEASE:STRING=

//Flags used by the linker during RELWITHDEBINFO builds.
CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO:STRING=

//Enable/Disable output of compile commands during generation.
CMAKE_EXPORT_COMPILE_COMMANDS:BOOL=

//No help, variable specified on the command line.
CMAKE_EXPORT_NO_PACKAGE_REGISTRY:UNINITIALIZED=ON

//No help, variable specified on the command line.
CMAKE_FIND_PACKAGE_NO_PACKAGE_REGISTRY:UNINITIALIZED=ON

//No help, variable specified on the command line.
CMAKE_FIND_PACKAGE_NO_SYSTEM_PACKAGE_REGISTRY:UNINITIALIZED=ON

//Value Computed by CMake.
CMAKE_FIND_PACKAGE_REDIRECTS_DIR:STATIC=/home/m-d-nabeel/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/pkgRedirects

//No help, variable specified on the command line.
CMAKE_INSTALL_BINDIR:STRING=bin

//Read-only architecture-independent data (DATAROOTDIR)
CMAKE_INSTALL_DATADIR:PATH=

//Read-only architecture-independent data root (share)
CMAKE_INSTALL_DATAROOTDIR:PATH=share

//Documentation root (DATAROOTDIR/doc/PROJECT_NAME)
CMAKE_INSTALL_DOCDIR:PATH=

//C header files (include)
CMAKE_INSTALL_INCLUDEDIR:PATH=include

//Info documentation (DATAROOTDIR/info)
CMAKE_INSTALL_INFODIR:PATH=

//No help, variable specified on the command line.
CMAKE_INSTALL_LIBDIR:STRING=lib

//Program executables (libexec)
CMAKE_INSTALL_LIBEXECDIR:PATH=libexec

//Locale-dependent data (DATAROOTDIR/locale)
CMAKE_INSTALL_LOCALEDIR:PATH=

//Modifiable single-machine data (var)
CMAKE_INSTALL_LOCALSTATEDIR:PATH=var

//Man documentation (DATAROOTDIR/man)
CMAKE_INSTALL_MANDIR:PATH=

//C header files for non-gcc (/usr/include)
CMAKE_INSTALL_OLDINCLUDEDIR:PATH=/usr/include

//Install path prefix, prepended onto install directories.
CMAKE_INSTALL_PREFIX:PATH=/home/m-d-nabeel/vcpkg/packages/glfw3_x64-linux/debug

//Run-time variable data (LOCALSTATEDIR/run)
CMAKE_INSTALL_RUNSTATEDIR:PATH=
...
Skipped 683 lines
...
CMAKE_CACHE_MAJOR_VERSION:INTERNAL=3
//Minor version of cmake used to create the current loaded cache
CMAKE_CACHE_MINOR_VERSION:INTERNAL=29
//Patch version of cmake used to create the current loaded cache
CMAKE_CACHE_PATCH_VERSION:INTERNAL=6
//Path to CMake executable.
CMAKE_COMMAND:INTERNAL=/usr/bin/cmake
//Path to cpack program executable.
CMAKE_CPACK_COMMAND:INTERNAL=/usr/bin/cpack
//Path to ctest program executable.
CMAKE_CTEST_COMMAND:INTERNAL=/usr/bin/ctest
//ADVANCED property for variable: CMAKE_C_COMPILER
CMAKE_C_COMPILER-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_C_COMPILER_AR
CMAKE_C_COMPILER_AR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_C_COMPILER_RANLIB
CMAKE_C_COMPILER_RANLIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_C_FLAGS
CMAKE_C_FLAGS-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_C_FLAGS_DEBUG
CMAKE_C_FLAGS_DEBUG-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_C_FLAGS_MINSIZEREL
CMAKE_C_FLAGS_MINSIZEREL-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_C_FLAGS_RELEASE
CMAKE_C_FLAGS_RELEASE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_C_FLAGS_RELWITHDEBINFO
CMAKE_C_FLAGS_RELWITHDEBINFO-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_DLLTOOL
CMAKE_DLLTOOL-ADVANCED:INTERNAL=1
//Executable file format
CMAKE_EXECUTABLE_FORMAT:INTERNAL=ELF
//ADVANCED property for variable: CMAKE_EXE_LINKER_FLAGS
CMAKE_EXE_LINKER_FLAGS-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_EXE_LINKER_FLAGS_DEBUG
CMAKE_EXE_LINKER_FLAGS_DEBUG-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_EXE_LINKER_FLAGS_MINSIZEREL
CMAKE_EXE_LINKER_FLAGS_MINSIZEREL-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_EXE_LINKER_FLAGS_RELEASE
CMAKE_EXE_LINKER_FLAGS_RELEASE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO
CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_EXPORT_COMPILE_COMMANDS
CMAKE_EXPORT_COMPILE_COMMANDS-ADVANCED:INTERNAL=1
//Name of external makefile project generator.
CMAKE_EXTRA_GENERATOR:INTERNAL=
//Name of generator.
CMAKE_GENERATOR:INTERNAL=Ninja
//Generator instance identifier.
CMAKE_GENERATOR_INSTANCE:INTERNAL=
//Name of generator platform.
CMAKE_GENERATOR_PLATFORM:INTERNAL=
//Name of generator toolset.
CMAKE_GENERATOR_TOOLSET:INTERNAL=
//Test CMAKE_HAVE_LIBC_PTHREAD
CMAKE_HAVE_LIBC_PTHREAD:INTERNAL=1
//Source directory with the top level CMakeLists.txt file for this
// project
CMAKE_HOME_DIRECTORY:INTERNAL=/home/m-d-nabeel/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean
//ADVANCED property for variable: CMAKE_INSTALL_BINDIR
CMAKE_INSTALL_BINDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_DATADIR
CMAKE_INSTALL_DATADIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_DATAROOTDIR
CMAKE_INSTALL_DATAROOTDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_DOCDIR
CMAKE_INSTALL_DOCDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_INCLUDEDIR
CMAKE_INSTALL_INCLUDEDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_INFODIR
CMAKE_INSTALL_INFODIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_LIBDIR
CMAKE_INSTALL_LIBDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_LIBEXECDIR
CMAKE_INSTALL_LIBEXECDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_LOCALEDIR
CMAKE_INSTALL_LOCALEDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_LOCALSTATEDIR
CMAKE_INSTALL_LOCALSTATEDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_MANDIR
CMAKE_INSTALL_MANDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_OLDINCLUDEDIR
CMAKE_INSTALL_OLDINCLUDEDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_RUNSTATEDIR
CMAKE_INSTALL_RUNSTATEDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_SBINDIR
CMAKE_INSTALL_SBINDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_SHAREDSTATEDIR
CMAKE_INSTALL_SHAREDSTATEDIR-ADVANCED:INTERNAL=1
//Install .so files without execute permission.
CMAKE_INSTALL_SO_NO_EXE:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_SYSCONFDIR
CMAKE_INSTALL_SYSCONFDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_LINKER
CMAKE_LINKER-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_MODULE_LINKER_FLAGS
CMAKE_MODULE_LINKER_FLAGS-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_MODULE_LINKER_FLAGS_DEBUG
CMAKE_MODULE_LINKER_FLAGS_DEBUG-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_MODULE_LINKER_FLAGS_MINSIZEREL
CMAKE_MODULE_LINKER_FLAGS_MINSIZEREL-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_MODULE_LINKER_FLAGS_RELEASE
CMAKE_MODULE_LINKER_FLAGS_RELEASE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_MODULE_LINKER_FLAGS_RELWITHDEBINFO
CMAKE_MODULE_LINKER_FLAGS_RELWITHDEBINFO-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_NM
CMAKE_NM-ADVANCED:INTERNAL=1
//number of local generators
CMAKE_NUMBER_OF_MAKEFILES:INTERNAL=2
//ADVANCED property for variable: CMAKE_OBJCOPY
CMAKE_OBJCOPY-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_OBJDUMP
CMAKE_OBJDUMP-ADVANCED:INTERNAL=1
//Platform information initialized
CMAKE_PLATFORM_INFO_INITIALIZED:INTERNAL=1
//ADVANCED property for variable: CMAKE_RANLIB
CMAKE_RANLIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_READELF
CMAKE_READELF-ADVANCED:INTERNAL=1
//Path to CMake installation.
CMAKE_ROOT:INTERNAL=/usr/share/cmake-3.29
//ADVANCED property for variable: CMAKE_SHARED_LINKER_FLAGS
CMAKE_SHARED_LINKER_FLAGS-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SHARED_LINKER_FLAGS_DEBUG
CMAKE_SHARED_LINKER_FLAGS_DEBUG-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SHARED_LINKER_FLAGS_MINSIZEREL
CMAKE_SHARED_LINKER_FLAGS_MINSIZEREL-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SHARED_LINKER_FLAGS_RELEASE
CMAKE_SHARED_LINKER_FLAGS_RELEASE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO
CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SKIP_INSTALL_RPATH
CMAKE_SKIP_INSTALL_RPATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SKIP_RPATH
CMAKE_SKIP_RPATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STATIC_LINKER_FLAGS
CMAKE_STATIC_LINKER_FLAGS-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STATIC_LINKER_FLAGS_DEBUG
CMAKE_STATIC_LINKER_FLAGS_DEBUG-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STATIC_LINKER_FLAGS_MINSIZEREL
CMAKE_STATIC_LINKER_FLAGS_MINSIZEREL-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STATIC_LINKER_FLAGS_RELEASE
CMAKE_STATIC_LINKER_FLAGS_RELEASE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STATIC_LINKER_FLAGS_RELWITHDEBINFO
CMAKE_STATIC_LINKER_FLAGS_RELWITHDEBINFO-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STRIP
CMAKE_STRIP-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_TAPI
CMAKE_TAPI-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_TOOLCHAIN_FILE
CMAKE_TOOLCHAIN_FILE-ADVANCED:INTERNAL=1
//uname command
CMAKE_UNAME:INTERNAL=/usr/bin/uname
//ADVANCED property for variable: CMAKE_VERBOSE_MAKEFILE
CMAKE_VERBOSE_MAKEFILE-ADVANCED:INTERNAL=1
//Details about finding Threads
FIND_PACKAGE_MESSAGE_DETAILS_Threads:INTERNAL=[TRUE][v()]
//Install the dependencies listed in your manifest:
//\n    If this is off, you will have to manually install your dependencies.
//\n    See https://github.com/microsoft/vcpkg/tree/master/docs/specifications/manifests.md
// for more info.
//\n
VCPKG_MANIFEST_INSTALL:INTERNAL=OFF
//ADVANCED property for variable: VCPKG_VERBOSE
VCPKG_VERBOSE-ADVANCED:INTERNAL=1
//Making sure VCPKG_MANIFEST_MODE doesn't change
Z_VCPKG_CHECK_MANIFEST_MODE:INTERNAL=OFF
//Vcpkg root directory
Z_VCPKG_ROOT_DIR:INTERNAL=/home/m-d-nabeel/vcpkg
//linker supports push/pop state
_CMAKE_LINKER_PUSHPOP_STATE_SUPPORTED:INTERNAL=TRUE
//CMAKE_INSTALL_PREFIX during last run
_GNUInstallDirs_LAST_CMAKE_INSTALL_PREFIX:INTERNAL=/home/m-d-nabeel/vcpkg/packages/glfw3_x64-linux/debug
```
</details>

<details><summary>/home/m-d-nabeel/vcpkg/buildtrees/glfw3/config-x64-linux-dbg-CMakeConfigureLog.yaml.log</summary>

```

---
events:
  -
    kind: "message-v1"
    backtrace:
      - "/usr/share/cmake-3.29/Modules/CMakeDetermineSystem.cmake:205 (message)"
      - "CMakeLists.txt:3 (project)"
    message: |
      The system is: Linux -  - x86_64
  -
    kind: "message-v1"
    backtrace:
      - "/usr/share/cmake-3.29/Modules/CMakeDetermineCompilerId.cmake:17 (message)"
      - "/usr/share/cmake-3.29/Modules/CMakeDetermineCompilerId.cmake:64 (__determine_compiler_id_test)"
      - "/usr/share/cmake-3.29/Modules/CMakeDetermineCCompiler.cmake:123 (CMAKE_DETERMINE_COMPILER_ID)"
      - "CMakeLists.txt:3 (project)"
    message: |
      Compiling the C compiler identification source file "CMakeCCompilerId.c" succeeded.
      Compiler: /usr/bin/cc 
      Build flags: -fPIC
      Id flags:  
      
      The output was:
      0
      
      
      Compilation of the C compiler identification source "CMakeCCompilerId.c" produced "a.out"
      
      The C compiler identification is GNU, found in:
        /home/m-d-nabeel/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/3.29.6/CompilerIdC/a.out
      
  -
    kind: "try_compile-v1"
    backtrace:
      - "/usr/share/cmake-3.29/Modules/CMakeDetermineCompilerABI.cmake:67 (try_compile)"
      - "/usr/share/cmake-3.29/Modules/CMakeTestCCompiler.cmake:26 (CMAKE_DETERMINE_COMPILER_ABI)"
      - "CMakeLists.txt:3 (project)"
    checks:
      - "Detecting C compiler ABI info"
    directories:
      source: "/home/m-d-nabeel/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/CMakeScratch/TryCompile-kfRYjI"
      binary: "/home/m-d-nabeel/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/CMakeScratch/TryCompile-kfRYjI"
    cmakeVariables:
      CMAKE_C_FLAGS: "-fPIC"
      CMAKE_C_FLAGS_DEBUG: "-g"
      CMAKE_EXE_LINKER_FLAGS: ""
      VCPKG_CHAINLOAD_TOOLCHAIN_FILE: "/home/m-d-nabeel/vcpkg/scripts/toolchains/linux.cmake"
      VCPKG_CRT_LINKAGE: "dynamic"
      VCPKG_CXX_FLAGS: ""
      VCPKG_CXX_FLAGS_DEBUG: ""
      VCPKG_CXX_FLAGS_RELEASE: ""
      VCPKG_C_FLAGS: ""
      VCPKG_C_FLAGS_DEBUG: ""
      VCPKG_C_FLAGS_RELEASE: ""
      VCPKG_INSTALLED_DIR: "/home/m-d-nabeel/Projects/raylib-cpp-gamedev/vcpkg_installed"
      VCPKG_LINKER_FLAGS: ""
      VCPKG_LINKER_FLAGS_DEBUG: ""
      VCPKG_LINKER_FLAGS_RELEASE: ""
      VCPKG_PREFER_SYSTEM_LIBS: "OFF"
      VCPKG_TARGET_ARCHITECTURE: "x64"
      VCPKG_TARGET_TRIPLET: "x64-linux"
      Z_VCPKG_ROOT_DIR: "/home/m-d-nabeel/vcpkg"
    buildResult:
      variable: "CMAKE_C_ABI_COMPILED"
      cached: true
      stdout: |
        Change Dir: '/home/m-d-nabeel/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/CMakeScratch/TryCompile-kfRYjI'
        
        Run Build Command(s): /usr/bin/ninja -v cmTC_3f090
        [1/2] /usr/bin/cc   -fPIC    -v -o CMakeFiles/cmTC_3f090.dir/CMakeCCompilerABI.c.o -c /usr/share/cmake-3.29/Modules/CMakeCCompilerABI.c
        Using built-in specs.
        COLLECT_GCC=/usr/bin/cc
        OFFLOAD_TARGET_NAMES=nvptx-none:amdgcn-amdhsa
        OFFLOAD_TARGET_DEFAULT=1
        Target: x86_64-linux-gnu
...
Skipped 138 lines
...
          arg [-plugin-opt=-pass-through=-lgcc] ==> ignore
          arg [-plugin-opt=-pass-through=-lgcc_s] ==> ignore
          arg [-plugin-opt=-pass-through=-lc] ==> ignore
          arg [-plugin-opt=-pass-through=-lgcc] ==> ignore
          arg [-plugin-opt=-pass-through=-lgcc_s] ==> ignore
          arg [--build-id] ==> ignore
          arg [--eh-frame-hdr] ==> ignore
          arg [-m] ==> ignore
          arg [elf_x86_64] ==> ignore
          arg [--hash-style=gnu] ==> ignore
          arg [--as-needed] ==> ignore
          arg [-dynamic-linker] ==> ignore
          arg [/lib64/ld-linux-x86-64.so.2] ==> ignore
          arg [-pie] ==> ignore
          arg [-o] ==> ignore
          arg [cmTC_3f090] ==> ignore
          arg [/usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu/Scrt1.o] ==> obj [/usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu/Scrt1.o]
          arg [/usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu/crti.o] ==> obj [/usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu/crti.o]
          arg [/usr/lib/gcc/x86_64-linux-gnu/13/crtbeginS.o] ==> obj [/usr/lib/gcc/x86_64-linux-gnu/13/crtbeginS.o]
          arg [-L/usr/lib/gcc/x86_64-linux-gnu/13] ==> dir [/usr/lib/gcc/x86_64-linux-gnu/13]
          arg [-L/usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu] ==> dir [/usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu]
          arg [-L/usr/lib/gcc/x86_64-linux-gnu/13/../../../../lib] ==> dir [/usr/lib/gcc/x86_64-linux-gnu/13/../../../../lib]
          arg [-L/lib/x86_64-linux-gnu] ==> dir [/lib/x86_64-linux-gnu]
          arg [-L/lib/../lib] ==> dir [/lib/../lib]
          arg [-L/usr/lib/x86_64-linux-gnu] ==> dir [/usr/lib/x86_64-linux-gnu]
          arg [-L/usr/lib/../lib] ==> dir [/usr/lib/../lib]
          arg [-L/usr/lib/gcc/x86_64-linux-gnu/13/../../..] ==> dir [/usr/lib/gcc/x86_64-linux-gnu/13/../../..]
          arg [-v] ==> ignore
          arg [CMakeFiles/cmTC_3f090.dir/CMakeCCompilerABI.c.o] ==> ignore
          arg [-lgcc] ==> lib [gcc]
          arg [--push-state] ==> ignore
          arg [--as-needed] ==> ignore
          arg [-lgcc_s] ==> lib [gcc_s]
          arg [--pop-state] ==> ignore
          arg [-lc] ==> lib [c]
          arg [-lgcc] ==> lib [gcc]
          arg [--push-state] ==> ignore
          arg [--as-needed] ==> ignore
          arg [-lgcc_s] ==> lib [gcc_s]
          arg [--pop-state] ==> ignore
          arg [/usr/lib/gcc/x86_64-linux-gnu/13/crtendS.o] ==> obj [/usr/lib/gcc/x86_64-linux-gnu/13/crtendS.o]
          arg [/usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu/crtn.o] ==> obj [/usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu/crtn.o]
        ignore line: [collect2 version 13.3.0]
        ignore line: [/usr/bin/ld -plugin /usr/libexec/gcc/x86_64-linux-gnu/13/liblto_plugin.so -plugin-opt=/usr/libexec/gcc/x86_64-linux-gnu/13/lto-wrapper -plugin-opt=-fresolution=/tmp/cco4i4ND.res -plugin-opt=-pass-through=-lgcc -plugin-opt=-pass-through=-lgcc_s -plugin-opt=-pass-through=-lc -plugin-opt=-pass-through=-lgcc -plugin-opt=-pass-through=-lgcc_s --build-id --eh-frame-hdr -m elf_x86_64 --hash-style=gnu --as-needed -dynamic-linker /lib64/ld-linux-x86-64.so.2 -pie -o cmTC_3f090 /usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu/Scrt1.o /usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu/crti.o /usr/lib/gcc/x86_64-linux-gnu/13/crtbeginS.o -L/usr/lib/gcc/x86_64-linux-gnu/13 -L/usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu -L/usr/lib/gcc/x86_64-linux-gnu/13/../../../../lib -L/lib/x86_64-linux-gnu -L/lib/../lib -L/usr/lib/x86_64-linux-gnu -L/usr/lib/../lib -L/usr/lib/gcc/x86_64-linux-gnu/13/../../.. -v CMakeFiles/cmTC_3f090.dir/CMakeCCompilerABI.c.o -lgcc --push-state --as-needed -lgcc_s --pop-state -lc -lgcc --push-state --as-needed -lgcc_s --pop-state /usr/lib/gcc/x86_64-linux-gnu/13/crtendS.o /usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu/crtn.o]
        linker tool for 'C': /usr/bin/ld
        collapse obj [/usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu/Scrt1.o] ==> [/usr/lib/x86_64-linux-gnu/Scrt1.o]
        collapse obj [/usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu/crti.o] ==> [/usr/lib/x86_64-linux-gnu/crti.o]
        collapse obj [/usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu/crtn.o] ==> [/usr/lib/x86_64-linux-gnu/crtn.o]
        collapse library dir [/usr/lib/gcc/x86_64-linux-gnu/13] ==> [/usr/lib/gcc/x86_64-linux-gnu/13]
        collapse library dir [/usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu] ==> [/usr/lib/x86_64-linux-gnu]
        collapse library dir [/usr/lib/gcc/x86_64-linux-gnu/13/../../../../lib] ==> [/usr/lib]
        collapse library dir [/lib/x86_64-linux-gnu] ==> [/lib/x86_64-linux-gnu]
        collapse library dir [/lib/../lib] ==> [/lib]
        collapse library dir [/usr/lib/x86_64-linux-gnu] ==> [/usr/lib/x86_64-linux-gnu]
        collapse library dir [/usr/lib/../lib] ==> [/usr/lib]
        collapse library dir [/usr/lib/gcc/x86_64-linux-gnu/13/../../..] ==> [/usr/lib]
        implicit libs: [gcc;gcc_s;c;gcc;gcc_s]
        implicit objs: [/usr/lib/x86_64-linux-gnu/Scrt1.o;/usr/lib/x86_64-linux-gnu/crti.o;/usr/lib/gcc/x86_64-linux-gnu/13/crtbeginS.o;/usr/lib/gcc/x86_64-linux-gnu/13/crtendS.o;/usr/lib/x86_64-linux-gnu/crtn.o]
        implicit dirs: [/usr/lib/gcc/x86_64-linux-gnu/13;/usr/lib/x86_64-linux-gnu;/usr/lib;/lib/x86_64-linux-gnu;/lib]
        implicit fwks: []
      
      
  -
    kind: "message-v1"
    backtrace:
      - "/usr/share/cmake-3.29/Modules/Internal/CMakeDetermineLinkerId.cmake:40 (message)"
      - "/usr/share/cmake-3.29/Modules/CMakeDetermineCompilerABI.cmake:210 (cmake_determine_linker_id)"
      - "/usr/share/cmake-3.29/Modules/CMakeTestCCompiler.cmake:26 (CMAKE_DETERMINE_COMPILER_ABI)"
      - "CMakeLists.txt:3 (project)"
    message: |
      Running the C compiler's linker: "/usr/bin/ld" "-v"
      GNU ld (GNU Binutils for Debian) 2.42.50.20240710
  -
    kind: "try_compile-v1"
    backtrace:
      - "/usr/share/cmake-3.29/Modules/Internal/CheckSourceCompiles.cmake:101 (try_compile)"
      - "/usr/share/cmake-3.29/Modules/CheckCSourceCompiles.cmake:52 (cmake_check_source_compiles)"
      - "/usr/share/cmake-3.29/Modules/FindThreads.cmake:97 (CHECK_C_SOURCE_COMPILES)"
      - "/usr/share/cmake-3.29/Modules/FindThreads.cmake:163 (_threads_check_libc)"
      - "/home/m-d-nabeel/vcpkg/scripts/buildsystems/vcpkg.cmake:857 (_find_package)"
      - "CMakeLists.txt:60 (find_package)"
    checks:
      - "Performing Test CMAKE_HAVE_LIBC_PTHREAD"
    directories:
      source: "/home/m-d-nabeel/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/CMakeScratch/TryCompile-uCRudv"
      binary: "/home/m-d-nabeel/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/CMakeScratch/TryCompile-uCRudv"
    cmakeVariables:
      CMAKE_C_FLAGS: "-fPIC"
      CMAKE_C_FLAGS_DEBUG: "-g"
      CMAKE_EXE_LINKER_FLAGS: ""
      CMAKE_MODULE_PATH: "/home/m-d-nabeel/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean/CMake/modules"
      VCPKG_CHAINLOAD_TOOLCHAIN_FILE: "/home/m-d-nabeel/vcpkg/scripts/toolchains/linux.cmake"
      VCPKG_CRT_LINKAGE: "dynamic"
      VCPKG_CXX_FLAGS: ""
      VCPKG_CXX_FLAGS_DEBUG: ""
      VCPKG_CXX_FLAGS_RELEASE: ""
      VCPKG_C_FLAGS: ""
      VCPKG_C_FLAGS_DEBUG: ""
      VCPKG_C_FLAGS_RELEASE: ""
      VCPKG_INSTALLED_DIR: "/home/m-d-nabeel/Projects/raylib-cpp-gamedev/vcpkg_installed"
      VCPKG_LINKER_FLAGS: ""
      VCPKG_LINKER_FLAGS_DEBUG: ""
      VCPKG_LINKER_FLAGS_RELEASE: ""
      VCPKG_PREFER_SYSTEM_LIBS: "OFF"
      VCPKG_TARGET_ARCHITECTURE: "x64"
      VCPKG_TARGET_TRIPLET: "x64-linux"
      Z_VCPKG_ROOT_DIR: "/home/m-d-nabeel/vcpkg"
    buildResult:
      variable: "CMAKE_HAVE_LIBC_PTHREAD"
      cached: true
      stdout: |
        Change Dir: '/home/m-d-nabeel/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/CMakeScratch/TryCompile-uCRudv'
        
        Run Build Command(s): /usr/bin/ninja -v cmTC_0ee16
        [1/2] /usr/bin/cc -DCMAKE_HAVE_LIBC_PTHREAD  -fPIC -o CMakeFiles/cmTC_0ee16.dir/src.c.o -c /home/m-d-nabeel/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/CMakeScratch/TryCompile-uCRudv/src.c
        [2/2] : && /usr/bin/cc -fPIC  CMakeFiles/cmTC_0ee16.dir/src.c.o -o cmTC_0ee16   && :
        
      exitCode: 0
...
```
</details>

<details><summary>/home/m-d-nabeel/vcpkg/buildtrees/glfw3/config-x64-linux-rel-CMakeConfigureLog.yaml.log</summary>

```

---
events:
  -
    kind: "message-v1"
    backtrace:
      - "/usr/share/cmake-3.29/Modules/CMakeDetermineSystem.cmake:205 (message)"
      - "CMakeLists.txt:3 (project)"
    message: |
      The system is: Linux -  - x86_64
  -
    kind: "message-v1"
    backtrace:
      - "/usr/share/cmake-3.29/Modules/CMakeDetermineCompilerId.cmake:17 (message)"
      - "/usr/share/cmake-3.29/Modules/CMakeDetermineCompilerId.cmake:64 (__determine_compiler_id_test)"
      - "/usr/share/cmake-3.29/Modules/CMakeDetermineCCompiler.cmake:123 (CMAKE_DETERMINE_COMPILER_ID)"
      - "CMakeLists.txt:3 (project)"
    message: |
      Compiling the C compiler identification source file "CMakeCCompilerId.c" succeeded.
      Compiler: /usr/bin/cc 
      Build flags: -fPIC
      Id flags:  
      
      The output was:
      0
      
      
      Compilation of the C compiler identification source "CMakeCCompilerId.c" produced "a.out"
      
      The C compiler identification is GNU, found in:
        /home/m-d-nabeel/vcpkg/buildtrees/glfw3/x64-linux-rel/CMakeFiles/3.29.6/CompilerIdC/a.out
      
  -
    kind: "try_compile-v1"
    backtrace:
      - "/usr/share/cmake-3.29/Modules/CMakeDetermineCompilerABI.cmake:67 (try_compile)"
      - "/usr/share/cmake-3.29/Modules/CMakeTestCCompiler.cmake:26 (CMAKE_DETERMINE_COMPILER_ABI)"
      - "CMakeLists.txt:3 (project)"
    checks:
      - "Detecting C compiler ABI info"
    directories:
      source: "/home/m-d-nabeel/vcpkg/buildtrees/glfw3/x64-linux-rel/CMakeFiles/CMakeScratch/TryCompile-d9mr6d"
      binary: "/home/m-d-nabeel/vcpkg/buildtrees/glfw3/x64-linux-rel/CMakeFiles/CMakeScratch/TryCompile-d9mr6d"
    cmakeVariables:
      CMAKE_C_FLAGS: "-fPIC"
      CMAKE_C_FLAGS_DEBUG: "-g"
      CMAKE_EXE_LINKER_FLAGS: ""
      VCPKG_CHAINLOAD_TOOLCHAIN_FILE: "/home/m-d-nabeel/vcpkg/scripts/toolchains/linux.cmake"
      VCPKG_CRT_LINKAGE: "dynamic"
      VCPKG_CXX_FLAGS: ""
      VCPKG_CXX_FLAGS_DEBUG: ""
      VCPKG_CXX_FLAGS_RELEASE: ""
      VCPKG_C_FLAGS: ""
      VCPKG_C_FLAGS_DEBUG: ""
      VCPKG_C_FLAGS_RELEASE: ""
      VCPKG_INSTALLED_DIR: "/home/m-d-nabeel/Projects/raylib-cpp-gamedev/vcpkg_installed"
      VCPKG_LINKER_FLAGS: ""
      VCPKG_LINKER_FLAGS_DEBUG: ""
      VCPKG_LINKER_FLAGS_RELEASE: ""
      VCPKG_PREFER_SYSTEM_LIBS: "OFF"
      VCPKG_TARGET_ARCHITECTURE: "x64"
      VCPKG_TARGET_TRIPLET: "x64-linux"
      Z_VCPKG_ROOT_DIR: "/home/m-d-nabeel/vcpkg"
    buildResult:
      variable: "CMAKE_C_ABI_COMPILED"
      cached: true
      stdout: |
        Change Dir: '/home/m-d-nabeel/vcpkg/buildtrees/glfw3/x64-linux-rel/CMakeFiles/CMakeScratch/TryCompile-d9mr6d'
        
        Run Build Command(s): /usr/bin/ninja -v cmTC_7e993
        [1/2] /usr/bin/cc   -fPIC    -v -o CMakeFiles/cmTC_7e993.dir/CMakeCCompilerABI.c.o -c /usr/share/cmake-3.29/Modules/CMakeCCompilerABI.c
        Using built-in specs.
        COLLECT_GCC=/usr/bin/cc
        OFFLOAD_TARGET_NAMES=nvptx-none:amdgcn-amdhsa
        OFFLOAD_TARGET_DEFAULT=1
        Target: x86_64-linux-gnu
        Configured with: ../src/configure -v --with-pkgversion='Debian 13.3.0-1' --with-bugurl=file:///usr/share/doc/gcc-13/README.Bugs --enable-languages=c,ada,c++,go,d,fortran,objc,obj-c++,m2 --prefix=/usr --with-gcc-major-version-only --program-suffix=-13 --program-prefix=x86_64-linux-gnu- --enable-shared --enable-linker-build-id --libexecdir=/usr/libexec --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --enable-bootstrap --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-libstdcxx-backtrace --enable-gnu-unique-object --disable-vtable-verify --enable-plugin --enable-default-pie --with-system-zlib --enable-libphobos-checking=release --with-target-system-zlib=auto --enable-objc-gc=auto --enable-multiarch --disable-werror --enable-cet --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32,m64,mx32 --enable-multilib --with-tune=generic --enable-offload-targets=nvptx-none=/build/reproducible-path/gcc-13-13.3.0/debian/tmp-nvptx/usr,amdgcn-amdhsa=/build/reproducible-path/gcc-13-13.3.0/debian/tmp-gcn/usr --enable-offload-defaulted --without-cuda-driver --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu --with-build-config=bootstrap-lto-lean --enable-link-serialization=3
        Thread model: posix
        Supported LTO compression algorithms: zlib zstd
        gcc version 13.3.0 (Debian 13.3.0-1) 
...
Skipped 129 lines
...
          arg [/usr/libexec/gcc/x86_64-linux-gnu/13/collect2] ==> ignore
          arg [-plugin] ==> ignore
          arg [/usr/libexec/gcc/x86_64-linux-gnu/13/liblto_plugin.so] ==> ignore
          arg [-plugin-opt=/usr/libexec/gcc/x86_64-linux-gnu/13/lto-wrapper] ==> ignore
          arg [-plugin-opt=-fresolution=/tmp/ccwMUt2T.res] ==> ignore
          arg [-plugin-opt=-pass-through=-lgcc] ==> ignore
          arg [-plugin-opt=-pass-through=-lgcc_s] ==> ignore
          arg [-plugin-opt=-pass-through=-lc] ==> ignore
          arg [-plugin-opt=-pass-through=-lgcc] ==> ignore
          arg [-plugin-opt=-pass-through=-lgcc_s] ==> ignore
          arg [--build-id] ==> ignore
          arg [--eh-frame-hdr] ==> ignore
          arg [-m] ==> ignore
          arg [elf_x86_64] ==> ignore
          arg [--hash-style=gnu] ==> ignore
          arg [--as-needed] ==> ignore
          arg [-dynamic-linker] ==> ignore
          arg [/lib64/ld-linux-x86-64.so.2] ==> ignore
          arg [-pie] ==> ignore
          arg [-o] ==> ignore
          arg [cmTC_7e993] ==> ignore
          arg [/usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu/Scrt1.o] ==> obj [/usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu/Scrt1.o]
          arg [/usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu/crti.o] ==> obj [/usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu/crti.o]
          arg [/usr/lib/gcc/x86_64-linux-gnu/13/crtbeginS.o] ==> obj [/usr/lib/gcc/x86_64-linux-gnu/13/crtbeginS.o]
          arg [-L/usr/lib/gcc/x86_64-linux-gnu/13] ==> dir [/usr/lib/gcc/x86_64-linux-gnu/13]
          arg [-L/usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu] ==> dir [/usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu]
          arg [-L/usr/lib/gcc/x86_64-linux-gnu/13/../../../../lib] ==> dir [/usr/lib/gcc/x86_64-linux-gnu/13/../../../../lib]
          arg [-L/lib/x86_64-linux-gnu] ==> dir [/lib/x86_64-linux-gnu]
          arg [-L/lib/../lib] ==> dir [/lib/../lib]
          arg [-L/usr/lib/x86_64-linux-gnu] ==> dir [/usr/lib/x86_64-linux-gnu]
          arg [-L/usr/lib/../lib] ==> dir [/usr/lib/../lib]
          arg [-L/usr/lib/gcc/x86_64-linux-gnu/13/../../..] ==> dir [/usr/lib/gcc/x86_64-linux-gnu/13/../../..]
          arg [-v] ==> ignore
          arg [CMakeFiles/cmTC_7e993.dir/CMakeCCompilerABI.c.o] ==> ignore
          arg [-lgcc] ==> lib [gcc]
          arg [--push-state] ==> ignore
          arg [--as-needed] ==> ignore
          arg [-lgcc_s] ==> lib [gcc_s]
          arg [--pop-state] ==> ignore
          arg [-lc] ==> lib [c]
          arg [-lgcc] ==> lib [gcc]
          arg [--push-state] ==> ignore
          arg [--as-needed] ==> ignore
          arg [-lgcc_s] ==> lib [gcc_s]
          arg [--pop-state] ==> ignore
          arg [/usr/lib/gcc/x86_64-linux-gnu/13/crtendS.o] ==> obj [/usr/lib/gcc/x86_64-linux-gnu/13/crtendS.o]
          arg [/usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu/crtn.o] ==> obj [/usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu/crtn.o]
        ignore line: [collect2 version 13.3.0]
        ignore line: [/usr/bin/ld -plugin /usr/libexec/gcc/x86_64-linux-gnu/13/liblto_plugin.so -plugin-opt=/usr/libexec/gcc/x86_64-linux-gnu/13/lto-wrapper -plugin-opt=-fresolution=/tmp/ccwMUt2T.res -plugin-opt=-pass-through=-lgcc -plugin-opt=-pass-through=-lgcc_s -plugin-opt=-pass-through=-lc -plugin-opt=-pass-through=-lgcc -plugin-opt=-pass-through=-lgcc_s --build-id --eh-frame-hdr -m elf_x86_64 --hash-style=gnu --as-needed -dynamic-linker /lib64/ld-linux-x86-64.so.2 -pie -o cmTC_7e993 /usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu/Scrt1.o /usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu/crti.o /usr/lib/gcc/x86_64-linux-gnu/13/crtbeginS.o -L/usr/lib/gcc/x86_64-linux-gnu/13 -L/usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu -L/usr/lib/gcc/x86_64-linux-gnu/13/../../../../lib -L/lib/x86_64-linux-gnu -L/lib/../lib -L/usr/lib/x86_64-linux-gnu -L/usr/lib/../lib -L/usr/lib/gcc/x86_64-linux-gnu/13/../../.. -v CMakeFiles/cmTC_7e993.dir/CMakeCCompilerABI.c.o -lgcc --push-state --as-needed -lgcc_s --pop-state -lc -lgcc --push-state --as-needed -lgcc_s --pop-state /usr/lib/gcc/x86_64-linux-gnu/13/crtendS.o /usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu/crtn.o]
        linker tool for 'C': /usr/bin/ld
        collapse obj [/usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu/Scrt1.o] ==> [/usr/lib/x86_64-linux-gnu/Scrt1.o]
        collapse obj [/usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu/crti.o] ==> [/usr/lib/x86_64-linux-gnu/crti.o]
        collapse obj [/usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu/crtn.o] ==> [/usr/lib/x86_64-linux-gnu/crtn.o]
        collapse library dir [/usr/lib/gcc/x86_64-linux-gnu/13] ==> [/usr/lib/gcc/x86_64-linux-gnu/13]
        collapse library dir [/usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu] ==> [/usr/lib/x86_64-linux-gnu]
        collapse library dir [/usr/lib/gcc/x86_64-linux-gnu/13/../../../../lib] ==> [/usr/lib]
        collapse library dir [/lib/x86_64-linux-gnu] ==> [/lib/x86_64-linux-gnu]
        collapse library dir [/lib/../lib] ==> [/lib]
        collapse library dir [/usr/lib/x86_64-linux-gnu] ==> [/usr/lib/x86_64-linux-gnu]
        collapse library dir [/usr/lib/../lib] ==> [/usr/lib]
        collapse library dir [/usr/lib/gcc/x86_64-linux-gnu/13/../../..] ==> [/usr/lib]
        implicit libs: [gcc;gcc_s;c;gcc;gcc_s]
        implicit objs: [/usr/lib/x86_64-linux-gnu/Scrt1.o;/usr/lib/x86_64-linux-gnu/crti.o;/usr/lib/gcc/x86_64-linux-gnu/13/crtbeginS.o;/usr/lib/gcc/x86_64-linux-gnu/13/crtendS.o;/usr/lib/x86_64-linux-gnu/crtn.o]
        implicit dirs: [/usr/lib/gcc/x86_64-linux-gnu/13;/usr/lib/x86_64-linux-gnu;/usr/lib;/lib/x86_64-linux-gnu;/lib]
        implicit fwks: []
      
      
  -
    kind: "message-v1"
    backtrace:
      - "/usr/share/cmake-3.29/Modules/Internal/CMakeDetermineLinkerId.cmake:40 (message)"
      - "/usr/share/cmake-3.29/Modules/CMakeDetermineCompilerABI.cmake:210 (cmake_determine_linker_id)"
      - "/usr/share/cmake-3.29/Modules/CMakeTestCCompiler.cmake:26 (CMAKE_DETERMINE_COMPILER_ABI)"
      - "CMakeLists.txt:3 (project)"
    message: |
      Running the C compiler's linker: "/usr/bin/ld" "-v"
      GNU ld (GNU Binutils for Debian) 2.42.50.20240710
  -
    kind: "try_compile-v1"
    backtrace:
      - "/usr/share/cmake-3.29/Modules/Internal/CheckSourceCompiles.cmake:101 (try_compile)"
      - "/usr/share/cmake-3.29/Modules/CheckCSourceCompiles.cmake:52 (cmake_check_source_compiles)"
      - "/usr/share/cmake-3.29/Modules/FindThreads.cmake:97 (CHECK_C_SOURCE_COMPILES)"
      - "/usr/share/cmake-3.29/Modules/FindThreads.cmake:163 (_threads_check_libc)"
      - "/home/m-d-nabeel/vcpkg/scripts/buildsystems/vcpkg.cmake:857 (_find_package)"
      - "CMakeLists.txt:60 (find_package)"
    checks:
      - "Performing Test CMAKE_HAVE_LIBC_PTHREAD"
    directories:
      source: "/home/m-d-nabeel/vcpkg/buildtrees/glfw3/x64-linux-rel/CMakeFiles/CMakeScratch/TryCompile-hwno8x"
      binary: "/home/m-d-nabeel/vcpkg/buildtrees/glfw3/x64-linux-rel/CMakeFiles/CMakeScratch/TryCompile-hwno8x"
    cmakeVariables:
      CMAKE_C_FLAGS: "-fPIC"
      CMAKE_C_FLAGS_DEBUG: "-g"
      CMAKE_EXE_LINKER_FLAGS: ""
      CMAKE_MODULE_PATH: "/home/m-d-nabeel/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean/CMake/modules"
      VCPKG_CHAINLOAD_TOOLCHAIN_FILE: "/home/m-d-nabeel/vcpkg/scripts/toolchains/linux.cmake"
      VCPKG_CRT_LINKAGE: "dynamic"
      VCPKG_CXX_FLAGS: ""
      VCPKG_CXX_FLAGS_DEBUG: ""
      VCPKG_CXX_FLAGS_RELEASE: ""
      VCPKG_C_FLAGS: ""
      VCPKG_C_FLAGS_DEBUG: ""
      VCPKG_C_FLAGS_RELEASE: ""
      VCPKG_INSTALLED_DIR: "/home/m-d-nabeel/Projects/raylib-cpp-gamedev/vcpkg_installed"
      VCPKG_LINKER_FLAGS: ""
      VCPKG_LINKER_FLAGS_DEBUG: ""
      VCPKG_LINKER_FLAGS_RELEASE: ""
      VCPKG_PREFER_SYSTEM_LIBS: "OFF"
      VCPKG_TARGET_ARCHITECTURE: "x64"
      VCPKG_TARGET_TRIPLET: "x64-linux"
      Z_VCPKG_ROOT_DIR: "/home/m-d-nabeel/vcpkg"
    buildResult:
      variable: "CMAKE_HAVE_LIBC_PTHREAD"
      cached: true
      stdout: |
        Change Dir: '/home/m-d-nabeel/vcpkg/buildtrees/glfw3/x64-linux-rel/CMakeFiles/CMakeScratch/TryCompile-hwno8x'
        
        Run Build Command(s): /usr/bin/ninja -v cmTC_8353c
        [1/2] /usr/bin/cc -DCMAKE_HAVE_LIBC_PTHREAD  -fPIC -o CMakeFiles/cmTC_8353c.dir/src.c.o -c /home/m-d-nabeel/vcpkg/buildtrees/glfw3/x64-linux-rel/CMakeFiles/CMakeScratch/TryCompile-hwno8x/src.c
        [2/2] : && /usr/bin/cc -fPIC  CMakeFiles/cmTC_8353c.dir/src.c.o -o cmTC_8353c   && :
        
      exitCode: 0
...
```
</details>

**Additional context**

<details><summary>vcpkg.json</summary>

```
{
  "name": "raylib-cpp-gamedev",
  "version-string": "1.0",
  "dependencies": [
    "raylib"
  ]
}

```
</details>
