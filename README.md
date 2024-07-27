### CMake

- Clone the repository using the following command:

```sh
git clone https://github.com/m-d-nabeel/gamedev-with-raylib.git
```

- Change to the project directory:

```sh
cd gamedev-with-raylib
```

- Type the following command to configure your project:

```sh
cmake -S . -B build
```

> If you want debug symbols, put the flag `-DCMAKE_BUILD_TYPE=Debug`. 

- After CMake configures your project, build it:

```sh
cmake --build build
```

- Inside the build folder is another folder (named the same as the project name on CMakeLists.txt) with the executable and resources folder.

Here's the updated `### WebAssembly with Emscripten` section for your README:

### WebAssembly with Emscripten

To build and run the project for the web using Emscripten, follow these steps:

1. **Install Emscripten**: Make sure you have Emscripten installed and activated.

2. **Compile Raylib Source Files**: Use the following `emcc` commands to compile the necessary Raylib source files:

```sh
emcc -c build/_deps/raylib-src/src/rcore.c -Os -Wall -DPLATFORM_WEB -DGRAPHICS_API_OPENGL_ES2 -o build/_deps/raylib-src/src/rcore.o
emcc -c build/_deps/raylib-src/src/rshapes.c -Os -Wall -DPLATFORM_WEB -DGRAPHICS_API_OPENGL_ES2 -o build/_deps/raylib-src/src/rshapes.o
emcc -c build/_deps/raylib-src/src/rtextures.c -Os -Wall -DPLATFORM_WEB -DGRAPHICS_API_OPENGL_ES2 -o build/_deps/raylib-src/src/rtextures.o
emcc -c build/_deps/raylib-src/src/rtext.c -Os -Wall -DPLATFORM_WEB -DGRAPHICS_API_OPENGL_ES2 -o build/_deps/raylib-src/src/rtext.o
emcc -c build/_deps/raylib-src/src/rmodels.c -Os -Wall -DPLATFORM_WEB -DGRAPHICS_API_OPENGL_ES2 -o build/_deps/raylib-src/src/rmodels.o
emcc -c build/_deps/raylib-src/src/utils.c -Os -Wall -DPLATFORM_WEB -o build/_deps/raylib-src/src/utils.o
emcc -c build/_deps/raylib-src/src/raudio.c -Os -Wall -DPLATFORM_WEB -o build/_deps/raylib-src/src/raudio.o
```

3. **Create a Static Library**: Use the following `emar` command to create a static library from the compiled Raylib object files:

```sh
emar rcs  build/_deps/raylib-src/src/libraylib.a \
          build/_deps/raylib-src/src/rcore.o \
          build/_deps/raylib-src/src/rshapes.o \
          build/_deps/raylib-src/src/rtextures.o \
          build/_deps/raylib-src/src/rtext.o \
          build/_deps/raylib-src/src/rmodels.o \
          build/_deps/raylib-src/src/utils.o \
          build/_deps/raylib-src/src/raudio.o
```

4. **Compile the Project**: Use the following `em++` command to compile the project:

```sh
em++ -o index.html \
  $(find src -name '*.cpp') \
  -I./src/include \
  -I./build/_deps/raylib-src/src \
  -L./build/_deps/raylib-src/src \
  -lraylib -s USE_GLFW=3 -s ASYNCIFY \
  --preload-file src/resources \
  --shell-file src/minshell.html -DPLATFORM_WEB
```

#### Explanation:

- `-o index.html`: Specifies the output file to be `index.html`.
- `$(find src -name '*.cpp')`: Finds all `.cpp` files in the `src` directory and its subdirectories.
- `-I./src/include`: Adds the `src/include` directory to the list of directories to search for header files.
- `-I./build/_deps/raylib-src/src`: Adds the Raylib include directory.
- `-L./build/_deps/raylib-src/src`: Adds the Raylib library directory.
- `-lraylib`: Links against the Raylib library.
- `-s USE_GLFW=3`: Uses GLFW version 3 for window and context creation.
- `-s ASYNCIFY`: Enables asyncify to support asynchronous operations.
- `--preload-file src/resources`: Preloads the `resources` directory so that it will be available at runtime.
- `--shell-file src/minshell.html`: Uses a custom HTML shell file.
- `-DPLATFORM_WEB`: Defines the `PLATFORM_WEB` macro for conditional compilation.

5. **Run the Generated HTML File**: Use Emscripten’s `emrun` to run the generated HTML file:

```sh
emrun index.html
```

This command starts a local web server and opens `index.html` in your default web browser.

### License

This game's sources are licensed under an unmodified zlib/libpng license, which is an OSI-certified, BSD-like license that allows static linking with closed-source software. Check [LICENSE](LICENSE) for further details.