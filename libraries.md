
```
https://www.boost.org/

Why Use Boost?   In a word, Productivity. Use of high-quality libraries like Boost speeds initial development, results in fewer bugs, reduces reinvention-of-the-wheel, and cuts long-term maintenance costs. And since Boost libraries tend to become de facto or de jure standards, many programmers are already familiar with them.
```


```

https://www.cgal.org/documentation.html


CGAL is an open source software project that provides easy access to efficient and reliable geometric algorithms in the form of a C++ library. CGAL is used in various areas needing geometric computation, such as geographic information systems, computer aided design, molecular biology, medical imaging, computer graphics, and robotics.

The library offers data structures and algorithms like triangulations, Voronoi diagrams, Boolean operations on polygons and polyhedra, point set processing, arrangements of curves, surface and volume mesh generation, geometry processing, alpha shapes, convex hull algorithms, shape reconstruction, AABB and KD trees... Explore the complete list of features and capabilities by visiting the CGAL Package Overview.

The CGAL data structures and algorithms are distributed under a dual license, namely under the GPL v3+ and, alternatively, under a commercial license by GeometryFactory.

```

https://gitlab.com/libeigen/eigen

Eigen is a C++ template library for linear algebra: matrices, vectors, numerical solvers, and related algorithms.










From your CMake output, here’s the **full dependency list** your C++ project is using / checking for:
---

✅ **Found & Used**

* **Boost** (1.83.0)
* **Eigen3** (3.4.0)
* **Iconv** (built-in)
* **ICU** (72.1)
* **LibLZMA** (5.4.1)
* **Threads (pthreads)**
* **Zlib** (1.2.13)
* **LibXml2** (2.9.14)
* **LibXslt**
* **NLopt**
* **Comedi** (0.11.0)
* **libdc1394** (camera control)
* **Bullet Physics** (3.24) → BulletCollision, BulletDynamics, BulletSoftBody, LinearMath
* **Coin3D** (4.0.0)
* **ccd** (collision detection)
* **octomap** (1.9.7)
* **fcl** (0.7.0)
* **ODE (Open Dynamics Engine)** (0.16.2)
* **PQP** (collision library, from `/usr/local/include`)
* **solid3** (collision detection, from `/usr/local/include`)
* **ForeignFiles/SoSTLFileKit.h** (custom STL toolkit, detected)
* **OpenGL**
* **SoQt** (1.6.0)
* **Doxygen** (1.9.4, with `dot` support)
* **LaTeX**

---

❌ **Not Found / Missing**

* **ATIDAQ** (force/torque sensor SDK)
* **cifX** (Hilscher fieldbus cards SDK)

---

So your project depends mainly on:

* **Math/Optimization** → Eigen, NLopt
* **Parsing/Data** → LibXml2, LibXslt, ICU, Iconv, Zlib, LZMA
* **Robotics/Physics** → Bullet, ODE, PQP, Solid3, fcl, ccd, octomap
* **Visualization** → Coin3D, SoQt, OpenGL
* **Hardware** → Comedi, libdc1394 (camera), ATIDAQ (optional), cifX (optional)
* **Docs** → Doxygen, LaTeX

---

👉 Do you want me to also generate a **ready-to-install apt list** (like `sudo apt install ...`) for Debian so you can quickly install all found libs?


