build:
  cmake -G Ninja -S . -B build/ 
  ninja -C build

clean:
  rm -rf build

[positional-arguments]
@load program:
  picotool load build/src/app/$1.elf
