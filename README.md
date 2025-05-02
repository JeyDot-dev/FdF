# FDF - Fil De Fer

## Overview
FDF is a graphical project that involves creating a wireframe representation of a landscape. It visually represents a terrain in relief by connecting different points (x, y, z) with line segments.

## Features

### Basic Functionality
- Create the wireframe representation of a landscape.
- Use MiniLibX for graphical rendering.
- Provide a Makefile for compiling source files without relinking.

### Rendering
- Display the rendering using an isometric projection.
- Accept coordinates of the terrain from a parameterized file in the *.fdf format.

### Function restrictions
- Restricted to these standard functions: `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `exit`
- All functions from the math library
- All functions from MiniLibX

### Additional Rendering Features
- Implement zoom in and zoom out functionality.
- Implement translation (movement) of the rendered terrain.

### Visual Enhancements
- Multiple background color gradient options.
- Objects have a gradient representing the Z value of the point.

## Usage

Please install the right pre-requisites depending on your OS: [MiniLibx](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)

Compile the program using the provided Makefile:

```bash
make
```

Run FDF with a parameterized file:

```bash
./fdf example.fdf
```

### Interactive Controls
- **Arrow Keys**: Move the object/map in the pressed direction.
- **"+" and "-" Keys**: Zoom in and out, respectively.
- **1, 2, 3, and 0 Keys**: Change the gradient of the background. Pressing 0 disables the background or makes it solid black.
- **Esc Key**: Close the program.

Feel free to navigate, zoom, adjust gradients, and explore the graphical representation using these interactive controls.

## Makefile Commands
- `make`: Compile the program.
- `make clean`: Remove object files.
- `make fclean`: Remove object files and the executable.
- `make re`: Recompiles the program from scratch.

## Screenshots
![42 map](https://github.com/JeyDot-dev/FdF/blob/main/screenshots/42_01.png)
![42 map bg 1](https://github.com/JeyDot-dev/FdF/blob/main/screenshots/42_02.png)
![fractal map](https://github.com/JeyDot-dev/FdF/blob/main/screenshots/fractal_01.png)
![fractal map bg 2](https://github.com/JeyDot-dev/FdF/blob/main/screenshots/fractal_02.png)
![t1 map](https://github.com/JeyDot-dev/FdF/blob/main/screenshots/mountains_01.png)
![t1 map bg 3](https://github.com/JeyDot-dev/FdF/blob/main/screenshots/mountains_02.png)


Thanks for checking my version of FDF !
