cmake -S . -B build

emcc -c build/_deps/raylib-src/src/rcore.c -Os -Wall -DPLATFORM_WEB -DGRAPHICS_API_OPENGL_ES2 -o build/_deps/raylib-src/src/rcore.o
emcc -c build/_deps/raylib-src/src/rshapes.c -Os -Wall -DPLATFORM_WEB -DGRAPHICS_API_OPENGL_ES2 -o build/_deps/raylib-src/src/rshapes.o
emcc -c build/_deps/raylib-src/src/rtextures.c -Os -Wall -DPLATFORM_WEB -DGRAPHICS_API_OPENGL_ES2 -o build/_deps/raylib-src/src/rtextures.o
emcc -c build/_deps/raylib-src/src/rtext.c -Os -Wall -DPLATFORM_WEB -DGRAPHICS_API_OPENGL_ES2 -o build/_deps/raylib-src/src/rtext.o
emcc -c build/_deps/raylib-src/src/rmodels.c -Os -Wall -DPLATFORM_WEB -DGRAPHICS_API_OPENGL_ES2 -o build/_deps/raylib-src/src/rmodels.o
emcc -c build/_deps/raylib-src/src/utils.c -Os -Wall -DPLATFORM_WEB -o build/_deps/raylib-src/src/utils.o
emcc -c build/_deps/raylib-src/src/raudio.c -Os -Wall -DPLATFORM_WEB -o build/_deps/raylib-src/src/raudio.o

emar rcs  build/_deps/raylib-src/src/libraylib.a \
          build/_deps/raylib-src/src/rcore.o \
          build/_deps/raylib-src/src/rshapes.o \
          build/_deps/raylib-src/src/rtextures.o \
          build/_deps/raylib-src/src/rtext.o \
          build/_deps/raylib-src/src/rmodels.o \
          build/_deps/raylib-src/src/utils.o \
          build/_deps/raylib-src/src/raudio.o


em++ -o index.html \
  $(find src -name '*.cpp') \
  -I./src/include \
  -I./build/_deps/raylib-src/src \
  -L./build/_deps/raylib-src/src \
  -lraylib -s USE_GLFW=3 -s ASYNCIFY \
  --preload-file src/resources \
  --shell-file src/minshell.html -DPLATFORM_WEB

emrun index.html