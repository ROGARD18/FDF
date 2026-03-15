# 🗺️ FdF - Fil de Fer

<p align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&color=0:00ffe0,100:7b5cfa&height=200&section=header&text=FdF%20-%2042%20Project&fontSize=70&fontColor=ffffff" alt="FdF Header" />
</p>

## 📌 Overview
**FdF** (Fil de Fer) is a project at **42 School** that aims to create a simplified 3D graphic representation of a relief landscape. Using the **MiniLibX** library, the program reads a `.fdf` file representing a map and renders it in a 3D wireframe mesh using **Isometric Projection**.

> This project covers fundamental graphics concepts: coordinates systems, projections, line-drawing algorithms (Bresenham), and event handling.

---

## 🚀 Key Features

* **Dynamic Parsing**: Handles any map size without hardcoded limits.
* **Isometric Projection**: 3D rendering with adjustable altitude (Z-axis).
* **Smooth Controls**:
    * **Zoom**: Scroll mouse to zoom in/out.
    * **Rotation**: Use arrows to change the projection angle.
    * **Translation**: Move the map across the screen.
* **Performance**: Optimized with **O3 flags** and pixel-buffer rendering for flicker-free display.

---

## 🛠️ Installation & Usage

### Prerequisites
You need a Linux environment with `X11` and `MiniLibX` dependencies installed.

### Compilation
```bash
git clone git@github.com:ROGARD18/FDF.git FDF
cd FDF/minilibx-linux
make
cd ..
make
./fdf 42.fdf
