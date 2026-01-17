#3D Interactive Car Showroom

## Project Overview
This project is a **3D Interactive Car Showroom** built using **Modern OpenGL (Core Profile)** in **C++**. The application allows users to explore a virtual car showroom with interactive features, multiple camera modes, and realistic lighting and materials.

## Features
- **Indoor and Outdoor Showroom**: A virtual environment with both indoor and outdoor sections.
- **Four Halls**: Dedicated halls for Family, Sport, Luxury, and Electric cars.
- **Camera Modes**:
 - Free Roam Camera
 - Orbit Camera
 - Driver’s Seat Camera
- **Interactive Main Car**: Open doors, rotate wheels, and interact with the driver’s seat.
- **Lighting**:
 - Directional Light
 - Point Light
 - Spot Light
- **Materials**: Phong or Blinn-Phong shading for realistic surfaces.
- **Transparency**: Glass and window effects.
- **Basic Collision Detection**: Prevents the camera from passing through walls.
- **Simple Animations**: Adds life to the showroom.

## Project Structure
```
src/
 core/ # Core application logic
 graphics/ # Rendering and shaders
 camera/ # Camera system
 input/ # Input handling
 scene/ # Scene management
 animation/ # Animation system
 physics/ # Basic collision detection
 audio/ # Audio system (future feature)
Libraries/
 include/ # GLFW, GLAD, GLM headers
 lib/ # Precompiled binaries (if any)
```

## Technologies Used
- **C++14**
- **Modern OpenGL (Core Profile)**
- **GLFW**: Window and input management.
- **GLAD**: OpenGL function loader.
- **GLM**: Mathematics library for3D transformations and vectors.

## Installation
1. Clone the repository:
```
 git clone https://github.com/saei7d7burhani/OpenGl_Project.git
```
2. Open the project in **Visual Studio2022**.
3. Ensure the following libraries are included:
- GLFW
- GLAD
- GLM
4. Build the project using the C++14 standard.

## Usage
- Launch the application to explore the showroom.
- Use the keyboard and mouse to navigate through the environment.
- Interact with the main car using the provided controls.

## Future Plans
- Add audio support for ambient sounds and car interactions.
- Implement advanced animations for car features.
- Enhance collision detection for a more realistic experience.
- Optimize performance for smoother rendering.

## Contributions
Contributions are welcome! Feel free to fork the repository and submit pull requests.

## Acknowledgments
- **GLFW**: For window and input management.
- **GLAD**: For OpenGL function loading.
- **GLM**: For mathematical operations.
- OpenGL tutorials and documentation for guidance.

---

Let me know if you'd like to add or modify any sections!
