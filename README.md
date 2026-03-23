Scientific calculator with C++ and Qt library. For details visit its user manual:
https://vahagmardyan.github.io/Synopsys_Course_Project_User_Manual/

<img width="686" height="597" alt="Scientific_Calculator" src="https://github.com/user-attachments/assets/9bd9c4b8-0834-45e8-a1b3-a3603ee10b23" />

---
# Qt Calculator Application

A cross-platform graphical calculator built using **C++17** and the **Qt Framework**. This project implements a structured approach to UI and logic separation, utilizing a controller-based architecture.

## 🛠 Tech Stack
* **Language:** C++17
* **Framework:** Qt 5/6 (Core, GUI, Widgets)
* **Build System:** qmake
* **Interface:** Qt Designer (.ui)

## 📂 Project Architecture
The project is organized into logical components to ensure maintainability:
* **UI Layer:** `mainwindow.h/cpp` handles the graphical interface and user input events.
* **Logic Layer:** `calc.h/cpp` contains the core mathematical engine and expression processing.
* **Control Layer:** `calculator_controller.h/cpp` acts as the bridge between the UI and the math logic.
* **State Management:** `calculator_state.h` and `unar_ids.h` manage the internal state machine and operation types (e.g., unary operators).

## 🚀 Building and Running (Windows 11)

To run this project without using Qt Creator, follow these steps using the **Qt Command Prompt**:

### 1. Compile the Project
Navigate to the project root directory and run:
```cmd
# Generate the Makefile
qmake

# Compile the application (for MinGW)
mingw32-make

# Compile the application (for MSVC Visual Studio)
nmake
```

### 2. Run the Application
Once the build is complete, navigate to the output folder and run the executable:
```cmd
.\release\CalculatorApp.exe
```

### 3. Standalone Deployment
To create a version that runs on any Windows machine without Qt installed, use the deployment tool:
```cmd
cd release
windeployqt CalculatorApp.exe
```
