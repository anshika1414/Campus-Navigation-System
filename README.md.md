# Campus Navigation System

A C++ project that helps users find the shortest path and distance between locations within a campus using **Dijkstra’s Algorithm**. The system is interactive, menu-driven, and allows dynamic updates of distances between locations.

---

## 🚀 Features
- Display all campus locations
- Find shortest path between two locations
- Calculate shortest distances from a location to all others
- Update distances dynamically at runtime
- User-friendly menu-driven interface

---

## 🛠️ Technologies Used
- **C++** – Main programming language  
- **Graph Theory** – Represented campus locations as an adjacency matrix  
- **Dijkstra’s Algorithm** – For shortest path calculation  

---

## 📌 How to Run
### Linux / Mac
1. Clone this repository:
   ```bash
   git clone https://github.com/your-username/Campus-Navigation-System.git
   ```
2. Navigate to the project folder:
   ```bash
   cd Campus-Navigation-System
   ```
3. Compile the code:
   ```bash
   g++ main.cpp -o campus_nav
   ```
4. Run the program:
   ```bash
   ./campus_nav
   ```

### Windows
1. Compile the code using:
   ```bash
   g++ main.cpp -o campus_nav.exe
   ```
2. Run the program:
   ```bash
   campus_nav.exe
   ```

---

## 📚 Challenges Faced & Solutions
- **Implementing Dijkstra’s Algorithm** – Understanding priority selection and parent tracking; solved by carefully coding `minDistance()` and parent arrays.  
- **Graph Representation** – Representing campus locations efficiently; solved using an adjacency matrix.  
- **User Interaction** – Designing an intuitive menu and mapping indices to names.  
- **Dynamic Updates** – Adding runtime distance updates without breaking functionality.  
- **Testing & Validation** – Ensuring shortest paths and distances were accurate for all start and end points.

---

## 🔮 Future Scope
- Add **Graphical User Interface (GUI)** with campus map visualization  
- Integrate **GPS or real-time location tracking**  
- Expand to support **more locations and complex routes**  
- Include **weighted factors** like traffic, accessibility, or restricted zones  
- Convert into a **mobile application** for students and visitors  
- Add **voice assistance** for easier navigation  

---

## ✨ Author
- **Anshika Tyagi** – B.Tech Computer Science, Lovely Professional University  
- GitHub: [anshika1414](https://github.com/anshika1414)  

