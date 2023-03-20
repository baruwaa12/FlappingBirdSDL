clang++ -g -std=c++17 -o main *.cpp -I./vendor/SDL2/include -lX11 -L./vendor/SDL2/lib/x86_x64/libSDL2_2.0.so -lSDL2 -L./vendor/SDL2/lib/x86_x64/libSDL2_image-2.0.so ./vendor/SDL2/lib/x86_x64/libSDL2_image.a
chmod 777 ./main
./main