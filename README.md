# \# Automobile Insurance Management System

# 

# A comprehensive, console-based information system designed for an automobile insurance company. This project implements key business workflows, including customer registration, vehicle insurance policy management, claim filing, surveyor inspections, and managerial approvals.

# 

# \## 👥 Team Members

# \*   \*\*Muhammad Ali\*\* (Roll No: 24L-0705)

# \*   \*\*Yaseen Ahmad Khan\*\* (Roll No: 24L-0500)

# 

# \---

# 

# \## 🚀 Project Overview

# The system is built using C++ and follows strict object-oriented programming principles. It simulates a real-world insurance environment where multiple actors (Customers, Managers, Surveyors, and Salesmen) interact to manage the lifecycle of an automobile insurance policy and its subsequent claims.

# 

# \### Key Features

# \*   \*\*File-Based Persistence\*\*: Uses simple text files (`customers.txt`, `claims.txt`, `policies.txt`, etc.) for data storage, ensuring no DBMS is required while maintaining data across sessions.

# \*   \*\*Role-Based Access\*\*: 

# &#x20;   \*   \*\*Manager\*\*: Approves/rejects claims, views reports, and manages workshops.

# &#x20;   \*   \*\*Customer\*\*: Registers, applies for insurance, and files repair requests.

# &#x20;   \*   \*\*Surveyor\*\*: Inspects damaged vehicles and submits technical reports.

# &#x20;   \*   \*\*Salesman\*\*: Tracks policy sales and earns commissions.

# \*   \*\*Workflow Integration\*\*: A multi-step pipeline where a manager can only approve a claim once a surveyor has submitted a recommendation.

# \*   \*\*Sales Tracking\*\*: Automated commission calculation (5%) for salesmen upon every successful policy sale.

# \*   \*\*Workshop Management\*\*: Validates that repairs are only conducted at registered workshops.

# 

# \---

# 

# \## 🏗 System Architecture

# The project is structured around several core classes:

# \*   \*\*Person (Abstract)\*\*: Base class for all users.

# \*   \*\*Staff (Derived)\*\*: Base class for company employees.

# \*   \*\*Manager, Surveyor, Salesman\*\*: Specialized roles with unique business logic.

# \*   \*\*Customer\*\*: Manages personal policies and claims.

# \*   \*\*Claim \& InspectionReport\*\*: Core entities for the repair workflow.

# \*   \*\*Policy \& Vehicle\*\*: Core entities for the insurance workflow.

# \*   \*\*FileHandler\*\*: A utility class that isolates all File I/O operations from the business logic.

# 

# \---

# 

# \## 💻 How to Run

# 1\.  \*\*Compile\*\*: Use any standard C++ compiler (e.g., `g++` or the Visual Studio C++ Compiler).

# &#x20;   ```bash

# &#x20;   g++ Source.cpp -o InsuranceSystem

# &#x20;   ```

# 2\.  \*\*Execute\*\*: Run the generated executable.

# &#x20;   ```bash

# &#x20;   ./InsuranceSystem

# &#x20;   ```

# 3\.  \*\*Data Files\*\*: Ensure that `customers.txt`, `claims.txt`, and `pending.txt` exist in the same directory (the system will create them if they are missing).

# 

# \---

# 

# \## 🛠 Programming Practices

# \*   \*\*Encapsulation\*\*: All data members are private/protected with getter and setter methods.

# \*   \*\*Inheritance \& Polymorphism\*\*: Used for the Person/Staff hierarchy.

# \*   \*\*Serialization\*\*: Custom logic to handle spaces in strings (names/descriptions) for reliable file storage.

# \*   \*\*Input Validation\*\*: Ensures valid IDs and workshop selections are entered.



