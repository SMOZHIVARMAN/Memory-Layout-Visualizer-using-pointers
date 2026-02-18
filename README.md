# 🧠 Memory Layout Visualizer

An interactive educational tool to visualize **C pointer arithmetic**, memory layout, and pointer operations in real time.

This project simulates how pointers move across contiguous memory using a graphical interface, while synchronizing with C-style code snippets and explanations for learning purposes.

---

## 🚀 Project Overview

Memory Layout Visualizer is a hybrid learning tool built to:

- Demonstrate how pointer arithmetic works in C
- Visualize memory addresses and pointer movement
- Compare two pointers and calculate element & byte differences
- Provide code-synchronized explanations for educational clarity

It bridges low-level memory concepts with interactive UI learning.

---

## 🎯 Features

### 🟢 Single Pointer Mode
- Move pointer forward
- Move pointer backward
- Jump by offset (positive/negative)
- Modify value at pointer location
- Live memory visualization
- Address simulation
- Code snippet synchronization
- Educational explanation panel
---
### 🔵 Dual Pointer Mode
- Move Pointer 1 forward/backward
- Move Pointer 2 forward/backward
- Compare pointers
- Element difference calculation
- Byte difference calculation
- Real-time visualization of both pointers
- Code + explanation mapping
---
### 🟣 Memory Analysis Mode
- Displays:
  - Array size
  - Size of int (assumed 4 bytes)
  - Total memory usage
  - Pointer arithmetic explanation
---
### 📚 Educational Engine
Each operation dynamically updates:

- 🧾 Code Snippet Panel
- 📖 Explanation Panel

**Example:**

```
ptr2++;
```


### Explanation:
- Pointer 2 moved forward by sizeof(int) = 4 bytes.
---
### 🏗️ Architecture

State Management (Frontend Engine)

###  javascript
```
state = {
    mode,
    arr,
    ptr1,
    ptr2,
    lastAction
}
```
The entire UI is driven by a centralized state model.

Simulated Memory Model
Because browsers cannot access real memory addresses, the system simulates memory using:

```
Base Address: 0x1000

Size of int: 4 bytes

Address formula: baseAddress + (index * sizeOfInt)
```
### Example:

```
arr → 0x1000
arr → 0x1004
arr → 0x1008
```
This accurately represents C pointer arithmetic behavior.
---
### 💻 Tech Stack
- HTML

- CSS (Flexbox layout)

- JavaScript (State-driven UI engine)

- C (CLI-based pointer simulator version)
---
### 🧠 Concepts Demonstrated
- Pointer arithmetic

- Memory address calculation

- Dereferencing

- Pointer subtraction

- Element difference vs byte difference

- Boundary checking

- Simulated contiguous memory model
---
### 📂 Project Structure
```text
MemoryScope/
│
├── index.html
├── style.css
├── script.js
├── main.c
├── memory.c
├── pointer_ops.c
├── memory.h
├── pointer_ops.h
└── README.md
```

▶️ How To Run

## 🔹 Run Frontend Version

- Open project folder

- Use VS Code Live Server

- Open index.html

- Enter array values

- Select mode

- Interact with pointer controls
---
## 🔹 Run C CLI Version
```
gcc main.c memory.c pointer_ops.c -o MemoryScope
./MemoryScope
```
## 🎓 Educational Purpose
- This project was designed to:

- Help students understand pointer behavior visually

- Bridge theory and implementation

- Provide interactive learning of low-level memory concepts

- Demonstrate system-level thinking
---
## 🔥 Advanced Capabilities
- Centralized state architecture

- Dynamic UI rendering

- Code-to-action synchronization

-  Mode-based logic switching

- Memory visualization engine
---
## 🏆 Why This Project Is Unique

### Unlike static memory diagrams, this tool:

 ✔ Allows interactive pointer movement

✔ Calculates real-time memory differences

✔ Explains pointer arithmetic step-by-step

✔ Combines CLI and UI implementations

✔ Maintains strict boundary validation
---
## 📌 Future Enhancements
- Step-by-step execution mode

- Stack vs Heap simulation

- Animated pointer transitions

- Dark theme UI

- Operation history log

- Multi-type data simulation (int, char, double)
---
## 👨‍💻 Author
Built as part of system-level learning and placement preparation.
---
## 📜 License
Educational project — free to use and modify.