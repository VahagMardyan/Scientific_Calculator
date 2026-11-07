Scientific calculator with C++ and Qt library. For details visit its user manual:
https://vahagmardyan.github.io/Synopsys_Course_Project_User_Manual/

<img width="686" height="597" alt="Scientific_Calculator" src="https://github.com/user-attachments/assets/9bd9c4b8-0834-45e8-a1b3-a3603ee10b23" />

---
# Qt Calculator Application

A cross-platform graphical calculator built using **C++17** and the **Qt Framework**. This project implements a structured approach to UI and logic separation, utilizing a controller-based architecture.

## Tech Stack
* **Language:** C++17
* **Framework:** Qt 6 (Core, GUI, Widgets)
* **Build System:** qmake
* **Interface:** Qt Designer (.ui)

## Project Architecture
The project is organized into logical components to ensure maintainability:
* **UI Layer:** `mainwindow.h/cpp` handles the graphical interface and user input events.
* **Logic Layer:** `calc.h/cpp` contains the core mathematical engine and expression processing.
* **Control Layer:** `calculator_controller.h/cpp` acts as the bridge between the UI and the math logic.
* **State Management:** `calculator_state.h` and `unar_ids.h` manage the internal state machine and operation types (e.g., unary operators).

## Download & Run (Windows 10/11, 64-bit)

1. Download [`Scientific_Calculator_v1.0_win64.zip`](Scientific_Calculator_v1.0_win64.zip?raw=1) from this repository.
2. Extract the zip.
3. Double-click `scientific_calculator_qt.exe`.

No Qt installation is required. Keep the `.exe` in the same folder as the included DLLs and subfolders.

> Windows SmartScreen may warn that the app is unrecognized because it isn't code-signed.
> Click **More info → Run anyway**.

## Building from Source (Windows)

Tested with **Qt 6.10.1** and its bundled **MinGW 13.1** (`C:\Qt\Tools\mingw1310_64`).
Use the compiler that matches your Qt kit; mixing Qt's MinGW kit with another GCC (e.g. MSYS2) fails at link time.

### 1. Set up the environment (PowerShell)
```powershell
$env:PATH = "C:\Qt\Tools\mingw1310_64\bin;C:\Qt\6.10.1\mingw_64\bin;" + $env:PATH
```
Or simply open the **Qt 6.10.1 (MinGW) command prompt** from the Start menu, or open `scientific_calculator_qt.pro` in Qt Creator.

### 2. Compile
From the project root:
```powershell
qmake
mingw32-make
```

### 3. Run
```powershell
.\release\scientific_calculator_qt.exe
```

### 4. Standalone Deployment
To create a folder that runs on any Windows machine without Qt installed:
```powershell
windeployqt --release --no-translations --no-system-d3d-compiler --no-opengl-sw release\scientific_calculator_qt.exe
```
Then remove the build leftovers (`*.o`, `moc_*`) from `release\` and zip the folder.

## License
Qt is used under the terms of the GNU LGPL v3.
