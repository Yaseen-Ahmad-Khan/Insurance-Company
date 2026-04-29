# 🚗 Automobile Insurance Management System

[![C++](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)](https://isocpp.org/)
[![Project Type](https://img.shields.io/badge/Coursework-Software%20Design%20%26%20Analysis-green)](https://github.com/)
[![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-brightgreen.svg)](https://github.com/)

An enterprise-grade C++ console application designed to streamline the lifecycle of automobile insurance. This system implements complex workflows from vehicle onboarding to multi-stage claim approvals.

---

## 👥 Meet the Team
| Name | Roll Number |
| :--- | :--- |
| **Muhammad Ali** | 24L-0705 |
| **Yaseen Ahmad Khan** | 24L-0500 |

---

## 🚀 Project Overview
Developed as part of the **Software Design and Architecture** curriculum, this project applies advanced **Object-Oriented Programming (OOP)** to simulate a real-world insurance ecosystem.

### 🛡️ Stakeholder Ecosystem
| Role | Core Responsibility |
| :--- | :--- |
| **Manager** | Operations oversight, claim adjudication, and workshop management. |
| **Customer** | Profile management, vehicle onboarding, and claim filing. |
| **Surveyor** | Technical damage assessment and inspection report generation. |
| **Salesman** | Policy sales facilitation and performance tracking. |

---

## ✨ Key Technical Features
*   **Persistent Data Layer**: Robust file-based system using `.txt` files with custom serialization.
*   **Role-Based Access Control (RBAC)**: Distinct interfaces and permissions for every user type.
*   **Automated Policy Logic**: Dynamic premium and coverage calculations based on vehicle metadata.
*   **Multi-Stage Claim Pipeline**: Integrated workflow involving customers, surveyors, and managers.
*   **Financial Tracking**: Automated 5% commission calculation for sales conversions.

---

## 🏗️ System Architecture
The system utilizes a clean, hierarchical class structure to ensure scalability and maintainability:

*   **Foundation**: `Person` (Abstract) → `Staff` (Derived).
*   **Logic**: Specialized roles (`Manager`, `Surveyor`, `Salesman`) inherit from `Staff`.
*   **Entities**: `Vehicle`, `Policy`, `Claim`, and `Workshop`.
*   **Utility**: `FileHandler` isolates business logic from I/O operations.

---

## 🛠️ Installation & Usage

### 1. Prerequisites
Ensure you have a C++ compiler installed (e.g., GCC, Clang, or MSVC).

### 2. Build
```bash
g++ Source.cpp -o InsuranceSystem
3. Run
Bash
./InsuranceSystem
📊 Project Artifacts
For a deeper look into the design, refer to the following documents in the repository:

🖼️ Class Diagram: ClassDiagram.png

📑 Use Case Document: UseCase.pdf

📊 Quality Report: CCCC Report.html

⚖️ License
This project was developed for academic purposes. All rights reserved.