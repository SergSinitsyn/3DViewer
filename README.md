# 3D Viewer
The 3D Viewer is a modern app written C++. The application provides viewing 3D wireframe models, loaded from .obj files and be viewable on the screen with the ability to rotate, scale and translate.

## Table of Contents
- [Description](#description)
    - [Interface](#interface)
    - [Settings](#settings)
    - [Record](#record)
- [Getting Started](#getting-started)
    - [Dependenses](#dependencies)
    - [Installing](#installing)
    - [Usage](#usage)
- [Authors](#authors)
- [License](#license)
- [Acknowledgments](#acknowledgments)

## Description
- The program is developed in C++17.
- The code follows the Google Style guide.
- Full unit test coverage is prepared using the GTest library for expression calculation modules.
- The graphical interface implementation is based on the Qt library.
- The program is implemented using the MVC pattern.

### Interface
- The program provide the ability to:
    - Load a wireframe model from an obj file (vertices and surfaces list support only).
    - Translate the model by a given distance in relation to the X, Y, Z axes.
    - Rotate the model by a given angle in relation to its X, Y, Z axes.
    - Scale the model by a given value.
- The graphical user interface contains:
    - A button to select the model file and a field to output its name.
    - A visualisation area for the wireframe model.
    - Buttons and input fields for translating the model.
    - Buttons and input fields for rotating the model.
    - Buttons and input fields for scaling the model.
    - Information about the uploaded model - file name, number of vertices and edges.

### Settings

- The program allow customizing the type of projection (parallel and central)
- The program allow setting up the type (solid, dashed), color and thickness of the edges, display method (none, circle, square), color and size of the vertices
- The program allow choosing the background color
- Settings saved between program restarts

### Record

- The program allow saving the captured (rendered) images as bmp and jpeg files.
- The program allow recording small screencasts - the current custom affine transformation of the loaded object into gif-animation (640x480, 10fps, 5s) by a special button

## Getting Started

### Dependencies

- MacOS or Linux
- C++17 compiler
- QT5 or QT6 (Widgets, OpenGLWidgets, OpenGL)

### Installing

To build and install this project, please follow the instructions below:
1. Clone this repository to your local machine.
2. Open a terminal and navigate to the project directory.
3. Run: `make install`.
4. This command will compile the source code and create an executable file named "3D_Viewer" in the build directory.

### Usage

- Run the `3D_Viewer` file
- Open any .obj file

## Authors

- [Sergey Sinitsyn](https://github.com/SergSinitsyn) (aka Bernarda Verla)
- [Sergey](https://github.com/sg41) 


## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE.txt) file for details.

## Acknowledgments

© 2023 SergSinitsyn
