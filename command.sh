em++ -o game.html \
  $(find src -name '*.cpp') \
  -I./src/include \
  -I./build/_deps/raylib-src/src \
  -L./build/_deps/raylib-src/src \
  -lraylib -s USE_GLFW=3 -s ASYNCIFY \
  --preload-file src/resources \
  --shell-file src/minshell.html -DPLATFORM_WEB

emrun game.html