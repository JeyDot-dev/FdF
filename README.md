# FDF - Fil De Fer

## Overview
FDF is a graphical project that involves creating a wireframe representation of a landscape. It visually represents a terrain in relief by connecting different points (x, y, z) with line segments.

# Index

1. [Overview](#overview)
2. [Features](#features)
   - [Basic Functionality](#basic-functionality)
   - [Rendering](#rendering)
   - [Supported External Functions](#supported-external-functions)
   - [Additional Rendering Features](#additional-rendering-features)
   - [Visual Enhancements](#visual-enhancements)
3. [Usage](#usage)
   - [Interactive Controls](#interactive-controls)
4. [Makefile Commands](#makefile-commands)
5. [Screenshots](#screenshots)
6. [External Functions](#external-functions)
7. [Libft](#libft)

Navigate through the sections using the index for quick access to specific information in the FDF - Fil De Fer README.
## Features

### Basic Functionality
- Create the wireframe representation of a landscape.
- Use MiniLibX for graphical rendering.
- Provide a Makefile for compiling source files without relinking.

### Rendering
- Display the rendering using an isometric projection.
- Accept coordinates of the terrain from a parameterized file in the *.fdf format.

### Supported External Functions
- `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `exit`
- All functions from the math library (compile with the -lm option)
- All functions from MiniLibX
- Libft is allowed

### Additional Rendering Features
- Implement zoom in and zoom out functionality.
- Implement translation (movement) of the rendered terrain.

### Visual Enhancements
- Multiple background color gradient options.
- Objects have a gradient representing the Z value of the point.

## Usage
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
- `make all`: Same as `make`.
- `make clean`: Remove object files.
- `make fclean`: Remove object files and the executable.
- `make re`: Rebuild the program from scratch.

## Screenshots
![42 map](https://github.com/JeyDot-dev/FdF/blob/main/screenshots/42_01.png)
![42 map bg 1](https://github.com/JeyDot-dev/FdF/blob/main/screenshots/42_02.png)
![fractal map](https://github.com/JeyDot-dev/FdF/blob/main/screenshots/fractal_01.png)
![fractal map bg 2](https://github.com/JeyDot-dev/FdF/blob/main/screenshots/fractal_02.png)
![t1 map](https://github.com/JeyDot-dev/FdF/blob/main/screenshots/mountains_01.png)
![t1 map bg 3](https://github.com/JeyDot-dev/FdF/blob/main/screenshots/mountains_02.png)

## External Functions
- `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `exit`
- All functions from the math library (compile with the -lm option)
- All functions from MiniLibX

## Libft
Libft functions are authorized for use.

Enjoy exploring and visualizing landscapes with FDF!
