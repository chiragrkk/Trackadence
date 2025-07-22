# 🧑‍🏫 Trackadence – Intelligent Attendance Monitoring System

**Trackadence** is a real-time face recognition-based attendance system designed to automate and streamline attendance tracking in classrooms, workplaces, or events. Using deep learning models like **RetinaFace** for face detection and **FaceNet** for face recognition, the system processes live camera input or static images to mark attendance accurately and efficiently.

---

## 🌟 Features

- 🎯 **High-Accuracy Face Recognition**  
  Utilizes **RetinaFace** for robust detection and **FaceNet embeddings** for accurate face matching.

- 📸 **Live Camera or Image Input**  
  Captures input via webcam or class photo for batch processing.

- 📁 **Automatic Attendance Logging**  
  Matches detected faces with a database and generates an attendance log with timestamps.

- 📄 **Excel Report Generation**  
  Exports attendance data as an Excel sheet for administrative use.

- 💡 **Smart Lighting Based on Student Presence**  
  Controls classroom lighting based on detected student count, ensuring energy efficiency.

- 📦 **Scalable and Customizable**  
  Supports adding/removing individuals and can be scaled for classrooms or large events.

---

## 🧠 Technologies Used

- **Face Detection:** RetinaFace (Pre-trained deep learning model)  
- **Face Recognition:** FaceNet embeddings + Cosine similarity  
- **Programming Language:** Python, Embedded C  
- **Libraries:** OpenCV, NumPy, Pandas, TensorFlow/Keras, `face_recognition`, `xlsxwriter`  
- **Smart Control:** Python and Blynk Iot Cloud for controlling light states  

---

## 🛠️ Implementation Steps

### 👁️ Face Detection & Alignment
- Detect faces in input image/frame using **RetinaFace**.
- Crop and align faces for consistent embeddings.

### 🧬 Face Embedding & Matching
- Extract 128-D FaceNet embeddings.
- Compare with stored embeddings using cosine similarity threshold.

### 🗂️ Attendance Management
- Mark present if similarity > threshold.
- Append name and timestamp to a CSV/Excel log file.

### 💡 Smart Lighting Logic
- If student present, **turn on lights** via ESP32 and Blynk IoT Cloud.  
- If student is not present, **turn off lights** to save energy.

### 📤 Report Generation
- Generate `.xlsx` attendance reports with student names, date, and presence status.

---

## 📋 Output Format (Excel)

| Name         | Date       | Time     | Status  |
|--------------|------------|----------|---------|
| John Doe     | 2025-07-09 | 09:02 AM | Present |
| Jane Smith   | 2025-07-09 | 09:03 AM | Absent  |

---

## 🔌 Hardware Requirements

- NVIDIA Jetson TX2  
- ESP32 (for lighting control)  
- Relay module (to switch lights)
- Ultrasonic Sensors

---

## 💼 Use Cases

- Classroom attendance automation  
- Corporate meeting check-ins  
- Workshop/event participant tracking  
- Smart energy saving in classrooms

---

## 👥 Acknowledgements

- Built with ❤️ using **RetinaFace**, **FaceNet**, and **OpenCV**
- Smart control via **ESP32** and **Python automation**
- Inspired by the need for efficient and non-intrusive attendance systems in education and industry
