Build For Linux and macOS:
```
mkdir build && cd build
cmake ..
make
```

Build For PSP:
```
mkdir build && cd build
psp-cmake ..
make
```

Build For PSVita:
```
mkdir build && cd build
cmake -DPSV=ON ..
make
```

Build For Nintendo Switch:
```
mkdir build && cd build
cmake -DNS=ON ..
make
```