# Convex Hull
## Project Description
This project is an implementation of the [Quickhull Algorithm](https://en.wikipedia.org/wiki/Quickhull) that allows to calculate the
convex hull of a set of point and then render it and the set.

You can reset the set of points by pressing R.

## Setup
### Dependencies
On a Debian system you can install the needed dependencies using:
```shell
sudo apt install g++ cmake make libsdl2-dev -y
```

### Clone Repository
```shell
git clone https://github.com/llikian/Convex-Hull.git
cd Convex-Hull
```

### Build
To build you can simply run the `build.sh` script at the root of the project using:
```shell
bash build.sh
```

You can also manually build it using:
```shell
cmake -B build && \
cmake --build build -j
```

Then you can run it using:
```shell
bin/Giftwrap
```

## Credits
The rendering is done using [SDL2](https://www.libsdl.org/).