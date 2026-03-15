# Turtle Graphics PPM/PNG Image Generator

## Overview

This project implements a **Turtle Graphics engine** written in **Modern C++**.
It reads drawing commands from a script file and generates an image as output.

The program allows the user to:

* Create a Turtle script interactively
* Parse and execute the script
* Render the drawing on a canvas
* Export the result as an image (`PPM` or `PNG`)

The system is inspired by classical **Turtle Graphics systems** used in educational programming environments.

---

# Technologies

The project is written mainly in **Modern C++ (C++17)**.

### Compiler

Example configuration used in this project:

* **Compiler:** GCC (MinGW)
* **Version:** 13.x
* **Standard:** C++17

Compile example:

```bash
g++ main.cpp turtle.cpp canvas.cpp script_parser.cpp color.cpp -std=c++17 -o turtle_app
```

---

# Project Structure

```
project/
│
├── include/
│   ├── canvas.hpp
│   ├── color.hpp
│   ├── turtle.hpp
│   └── script_parser.hpp
│
├── source/
│   ├── canvas.cpp
│   ├── turtle.cpp
│   ├── script_parser.cpp
│   └── color.cpp
│
├── main.cpp
├── test.turtle
└── README.md
```

---

# Turtle Script Language

The program uses a simple script language to describe drawings.

### Supported Commands

```
size w=<width> h=<height>
color pen=<color> bg=<color>

pen down x y
pen up

move forward <distance>
move backward <distance>

turn right <degrees>
turn left <degrees>
```

---

# Example Script

Example `test.turtle` script:

```
size w=256 h=256
color pen=red bg=black

pen down 100 100

move forward 120
turn right 120

move forward 120
turn right 120

move forward 120
```

This script draws a **triangle**.

---

# Interactive Script Generator

The program includes an interactive tool to help users build scripts.

Example console session:

```
==== Turtle System ====

1) Create New Script

Enter Canvas Width: 256
Enter Canvas Height: 256

Select Pen Color:
1) Black
2) White
3) Red
4) Green
5) Blue
6) Yellow
3

Select Background Color:
1) Black
2) White
3) Red
4) Green
5) Blue
6) Yellow
1

Start Pen State:
1) Pen Down
2) Pen Up
Choice: 1

Enter Start X: 100
Enter Start Y: 100

Select Commands:
1) Move Forward
2) Move Backward
3) Turn Right
4) Turn Left
5) Pen Down
6) Pen Up
0) Finish

Enter choice: 1
Distance: 120

Enter choice: 3
Degrees: 120

Enter choice: 1
Distance: 120

Enter choice: 3
Degrees: 120

Enter choice: 1
Distance: 120

Enter choice: 0
```

Output:

```
Script saved successfully to test.turtle
Image generated successfully
```

---

# Output

The program generates an image file such as:

```
output.ppm
```

or

```
output.png
```

which contains the rendered drawing.

---

# Features

* Modern C++ design
* Modular architecture
* Script parsing engine
* Turtle graphics renderer
* Interactive script generator
* Image export (PPM / PNG)

---

# Future Improvements

Possible enhancements:

* GUI editor for scripts
* More drawing primitives
* Curves and circles
* PNG export by default
* Animation support

---

# Author

**Abdelrahman Ashraf Gomaa**
Embedded Systems Engineer
