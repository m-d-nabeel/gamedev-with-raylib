### CMake

- Clone the repository using the following command:

```sh
git clone https://github.com/m-d-nabeel/game-dev-with-raylib.git
```

- Change to the project directory:

```sh
cd game-dev-with-raylib
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

### WebAssembly with Emscripten

To build and run the project for the web using Emscripten, follow these steps:

1. **Install Emscripten**: Make sure you have Emscripten installed and activated.

2. **Compile the Project**: Use the following `em++` command to compile the project:

```sh
em++ -o game.html \
  $(find src -name '*.cpp') \
  -I./src/include \
  -I./build/_deps/raylib-src/src \
  -L./build/_deps/raylib-src/src \
  -lraylib -s USE_GLFW=3 -s ASYNCIFY \
  --preload-file src/resources \
  --shell-file src/minshell.html -DPLATFORM_WEB
```

#### Explanation:

- `-o game.html`: Specifies the output file to be `game.html`.
- `$(find src -name '*.cpp')`: Finds all `.cpp` files in the `src` directory and its subdirectories.
- `-I./src/include`: Adds the `src/include` directory to the list of directories to search for header files.
- `-I/home/m-d-nabeel/Projects/game-dev-with-raylib/build/_deps/raylib-src/src`: Adds the Raylib include directory.
- `-L/home/m-d-nabeel/Projects/game-dev-with-raylib/build/_deps/raylib-src/src`: Adds the Raylib library directory.
- `-lraylib`: Links against the Raylib library.
- `-s USE_GLFW=3`: Uses GLFW version 3 for window and context creation.
- `-s ASYNCIFY`: Enables asyncify to support asynchronous operations.
- `--preload-file src/resources`: Preloads the `resources` directory so that it will be available at runtime.
- `--shell-file src/minshell.html`: Uses a custom HTML shell file.
- `-DPLATFORM_WEB`: Defines the `PLATFORM_WEB` macro for conditional compilation.

3. **Run the Generated HTML File**: Use Emscripten’s `emrun` to run the generated HTML file:

```sh
emrun game.html
```

This command starts a local web server and opens `game.html` in your default web browser.

### License

This game's sources are licensed under an unmodified zlib/libpng license, which is an OSI-certified, BSD-like license that allows static linking with closed-source software. Check [LICENSE](LICENSE) for further details.
