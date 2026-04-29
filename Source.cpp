#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;
class Customer;
class Claim;
class InspectionReport;
// Base abstract class representing a person with common attributes
class Person
{
protected:
    int id;
    string firstName;
    string lastName;
    string cnic;
    string phoneNumber;
    string address;

public:
    Person() : id(0), firstName(""), lastName(""), cnic(""), phoneNumber(""), address("") {}

    Person(int id, string fName, string lName, string cnic, string phone, string addr)
        : id(id), firstName(fName), lastName(lName), cnic(cnic), phoneNumber(phone), address(addr) {
    }

    int getId() const { return id; }
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    string getCnic() const { return cnic; }
    string getPhoneNumber() const { return phoneNumber; }
    string getAddress() const { return address; }

    void setId(int id) { this->id = id; }
    void setFirstName(string fName) { this->firstName = fName; }
    void setLastName(string lName) { this->lastName = lName; }
    void setCnic(string cnic) { this->cnic = cnic; }
    void setPhoneNumber(string phone) { this->phoneNumber = phone; }
    void setAddress(string addr) { this->address = addr; }
    virtual void display() const = 0;
    virtual ~Person() {}
};
// Derived class representing a staff member in the insurance company
class Staff : public Person
{
protected:
    string employeeId;
    string joinDate;
    double salary;
    string department;

public:
    Staff() : Person(), employeeId(""), joinDate(""), salary(0.0), department("") {}

    Staff(int id, string fName, string lName, string cnic, string phone, string addr,
        string empId, string jDate, double sal, string dept)
        : Person(id, fName, lName, cnic, phone, addr),
        employeeId(empId), joinDate(jDate), salary(sal), department(dept) {
    }

    string getEmployeeId() const { return employeeId; }
    string getJoinDate() const { return joinDate; }
    double getSalary() const { return salary; }
    string getDepartment() const { return department; }

    void setEmployeeId(string empId) { employeeId = empId; }
    void setJoinDate(string jDate) { joinDate = jDate; }
    void setSalary(double sal) { salary = sal; }
    void setDepartment(string dept) { department = dept; }

    void display() const override {
        cout << "Employee ID: " << employeeId << endl;
        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "CNIC: " << cnic << endl;
        cout << "Phone: " << phoneNumber << endl;
        cout << "Address: " << address << endl;
        cout << "Join Date: " << joinDate << endl;
        cout << "Salary: " << salary << endl;
        cout << "Department: " << department << endl;
    }

    virtual ~Staff() {}
};

// Salesman class: Responsible for selling policies and earning commission
class Salesman : public Staff
{
private:
    int policiesSold;
    double commission;

public:
    Salesman() : Staff(), policiesSold(0), commission(0.0) {}

    Salesman(int id, string fName, string lName, string cnic, string phone, string addr,
        string empId, string jDate, double sal, string dept,
        int sold, double comm)
        : Staff(id, fName, lName, cnic, phone, addr, empId, jDate, sal, dept),
        policiesSold(sold), commission(comm) {
    }

    int getPoliciesSold() const { return policiesSold; }
    double getCommission() const { return commission; }

    void setPoliciesSold(int sold) { policiesSold = sold; }
    void setCommission(double comm) { commission = comm; }

    void display() const override {
        cout << "=== SALESMAN ===" << endl;
        Staff::display();
        cout << "Policies Sold: " << policiesSold << endl;
        cout << "Commission: " << commission << endl;
    }

    ~Salesman() {}
};
// Surveyor class: Responsible for inspecting damaged vehicles and creating reports
class Surveyor : public Staff
{
private:
    int inspectionsCompleted;
    string specialization;

public:
    Surveyor() : Staff(), inspectionsCompleted(0), specialization("") {}

    Surveyor(int id, string fName, string lName, string cnic, string phone, string addr,
        string empId, string jDate, double sal, string dept,
        int inspections, string spec)
        : Staff(id, fName, lName, cnic, phone, addr, empId, jDate, sal, dept),
        inspectionsCompleted(inspections), specialization(spec) {
    }

    int getInspectionsCompleted() const { return inspectionsCompleted; }
    string getSpecialization() const { return specialization; }

    void setInspectionsCompleted(int inspections) { inspectionsCompleted = inspections; }
    void setSpecialization(string spec) { specialization = spec; }

    void display() const override {
        cout << "=== SURVEYOR ===" << endl;
        Staff::display();
        cout << "Inspections Completed: " << inspectionsCompleted << endl;
        cout << "Specialization: " << specialization << endl;
    }

    ~Surveyor() {}
};

// Manager class: High-level authority responsible for approving/rejecting claims and generating reports
class Manager : public Staff
{
private:
    string accessLevel;

public:
    Manager() : Staff(), accessLevel("HIGH") {}

    Manager(int id, string fName, string lName, string cnic, string phone, string addr,
        string empId, string jDate, double sal, string dept, string access)
        : Staff(id, fName, lName, cnic, phone, addr, empId, jDate, sal, dept),
        accessLevel(access) {
    }

    string getAccessLevel() const { return accessLevel; }
    void setAccessLevel(string access) { accessLevel = access; }

    void display() const override {
        cout << "=== MANAGER ===" << endl;
        Staff::display();
        cout << "Access Level: " << accessLevel << endl;
    }

    void viewNewCustomers(vector<Customer>& customers, string month, string year);
    void viewPendingClaims(vector<Claim>& claims);
    void viewInspectionReports(vector<InspectionReport>& reports);
    void viewCustomerClaimHistory(vector<Claim>& claims, int customerId);
    void approveClaim(Claim& claim, InspectionReport& report);
    void rejectClaim(Claim& claim, InspectionReport& report, string reason);

    ~Manager() {}
};

// Customer class: Represents the policyholders who buy insurance and file claims
class Customer : public Person
{
private:
    string registrationDate;
    string password;
    vector<int> policyIds;
    vector<int> claimIds;

public:
    Customer() : Person(), registrationDate(""), password("") {}

    Customer(int id, string fName, string lName, string cnic, string phone, string addr, string regDate, string pass = "password")
        : Person(id, fName, lName, cnic, phone, addr), registrationDate(regDate), password(pass) {
    }

    string getRegistrationDate() const { return registrationDate; }
    string getPassword() const { return password; }
    vector<int> getPolicyIds() const { return policyIds; }
    vector<int> getClaimIds() const { return claimIds; }

    void setRegistrationDate(string regDate) { registrationDate = regDate; }
    void setPassword(string pass) { password = pass; }
    void addPolicy(int policyId) { policyIds.push_back(policyId); }
    void addClaim(int claimId) { claimIds.push_back(claimId); }

    void display() const override {
        cout << "=== CUSTOMER ===" << endl;
        cout << "Customer ID: " << id << endl;
        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "CNIC: " << cnic << endl;
        cout << "Phone: " << phoneNumber << endl;
        cout << "Address: " << address << endl;
        cout << "Registration Date: " << registrationDate << endl;
        cout << "Number of Policies: " << policyIds.size() << endl;
        cout << "Number of Claims: " << claimIds.size() << endl;
    }

    ~Customer() {}
};

// Claim class: Stores details about a repair request filed by a customer
class Claim
{
private:
    int claimId;
    int customerId;
    int policyId;
    int vehicleId;
    string claimDate;
    string incidentDate;
    string incidentDescription;
    double claimedAmount;
    double approvedAmount;
    string status;
    int inspectionReportId;
    int surveyorId;
    int managerId;
    string approvalDate;
    string rejectionReason;

public:
    Claim() : claimId(0), customerId(0), policyId(0), vehicleId(0),
        claimedAmount(0.0), approvedAmount(0.0), status("PENDING"),
        inspectionReportId(0), surveyorId(0), managerId(0) {
    }

    Claim(int cId, int custId, int polId, int vehId, string cDate,
        string incDate, string desc, double amount)
        : claimId(cId), customerId(custId), policyId(polId), vehicleId(vehId),
        claimDate(cDate), incidentDate(incDate), incidentDescription(desc),
        claimedAmount(amount), approvedAmount(0.0), status("PENDING"),
        inspectionReportId(0), surveyorId(0), managerId(0) {
    }

    int getClaimId() const { return claimId; }
    int getCustomerId() const { return customerId; }
    int getPolicyId() const { return policyId; }
    int getVehicleId() const { return vehicleId; }
    string getClaimDate() const { return claimDate; }
    string getIncidentDate() const { return incidentDate; }
    string getIncidentDescription() const { return incidentDescription; }
    double getClaimedAmount() const { return claimedAmount; }
    double getApprovedAmount() const { return approvedAmount; }
    string getStatus() const { return status; }
    int getInspectionReportId() const { return inspectionReportId; }
    int getSurveyorId() const { return surveyorId; }
    int getManagerId() const { return managerId; }
    string getApprovalDate() const { return approvalDate; }
    string getRejectionReason() const { return rejectionReason; }

    void setClaimId(int id) { claimId = id; }
    void setCustomerId(int id) { customerId = id; }
    void setPolicyId(int id) { policyId = id; }
    void setVehicleId(int id) { vehicleId = id; }
    void setClaimDate(string date) { claimDate = date; }
    void setIncidentDate(string date) { incidentDate = date; }
    void setIncidentDescription(string desc) { incidentDescription = desc; }
    void setClaimedAmount(double amount) { claimedAmount = amount; }
    void setApprovedAmount(double amount) { approvedAmount = amount; }
    void setStatus(string stat) { status = stat; }
    void setInspectionReportId(int id) { inspectionReportId = id; }
    void setSurveyorId(int id) { surveyorId = id; }
    void setManagerId(int id) { managerId = id; }
    void setApprovalDate(string date) { approvalDate = date; }
    void setRejectionReason(string reason) { rejectionReason = reason; }

    void display() const {
        cout << "=== CLAIM ===" << endl;
        cout << "Claim ID: " << claimId << endl;
        cout << "Customer ID: " << customerId << endl;
        cout << "Policy ID: " << policyId << endl;
        cout << "Vehicle ID: " << vehicleId << endl;
        cout << "Claim Date: " << claimDate << endl;
        cout << "Incident Date: " << incidentDate << endl;
        cout << "Description: " << incidentDescription << endl;
        cout << "Claimed Amount: " << claimedAmount << endl;
        cout << "Approved Amount: " << approvedAmount << endl;
        cout << "Status: " << status << endl;
        if (inspectionReportId > 0)
            cout << "Inspection Report ID: " << inspectionReportId << endl;
        if (status == "APPROVED")
            cout << "Approval Date: " << approvalDate << endl;
        if (status == "REJECTED")
            cout << "Rejection Reason: " << rejectionReason << endl;
    }
};

// InspectionReport class: Created by a Surveyor to document vehicle damage and recommend approval/rejection
class InspectionReport
{
private:
    int reportId;
    int claimId;
    int surveyorId;
    int vehicleId;
    string inspectionDate;
    string damageAssessment;
    double estimatedRepairCost;
    string recommendation;
    vector<string> damagePhotos;
    string workshopId;
    bool isApproved;

public:
    InspectionReport() : reportId(0), claimId(0), surveyorId(0), vehicleId(0),
        estimatedRepairCost(0.0), isApproved(false) {
    }

    InspectionReport(int rId, int cId, int sId, int vId, string date)
        : reportId(rId), claimId(cId), surveyorId(sId), vehicleId(vId),
        inspectionDate(date), estimatedRepairCost(0.0), isApproved(false) {
    }

    int getReportId() const { return reportId; }
    int getClaimId() const { return claimId; }
    int getSurveyorId() const { return surveyorId; }
    int getVehicleId() const { return vehicleId; }
    string getInspectionDate() const { return inspectionDate; }
    string getDamageAssessment() const { return damageAssessment; }
    double getEstimatedRepairCost() const { return estimatedRepairCost; }
    string getRecommendation() const { return recommendation; }
    vector<string> getDamagePhotos() const { return damagePhotos; }
    string getWorkshopId() const { return workshopId; }
    bool getIsApproved() const { return isApproved; }

    void setReportId(int id) { reportId = id; }
    void setClaimId(int id) { claimId = id; }
    void setSurveyorId(int id) { surveyorId = id; }
    void setVehicleId(int id) { vehicleId = id; }
    void setInspectionDate(string date) { inspectionDate = date; }
    void setDamageAssessment(string assessment) { damageAssessment = assessment; }
    void setEstimatedRepairCost(double cost) { estimatedRepairCost = cost; }
    void setRecommendation(string rec) { recommendation = rec; }
    void addDamagePhoto(string photo) { damagePhotos.push_back(photo); }
    void setWorkshopId(string id) { workshopId = id; }
    void setIsApproved(bool approved) { isApproved = approved; }

    void display() const {
        cout << "=== INSPECTION REPORT ===" << endl;
        cout << "Report ID: " << reportId << endl;
        cout << "Claim ID: " << claimId << endl;
        cout << "Surveyor ID: " << surveyorId << endl;
        cout << "Vehicle ID: " << vehicleId << endl;
        cout << "Inspection Date: " << inspectionDate << endl;
        cout << "Damage Assessment: " << damageAssessment << endl;
        cout << "Estimated Repair Cost: " << estimatedRepairCost << endl;
        cout << "Recommendation: " << recommendation << endl;
        cout << "Workshop ID: " << workshopId << endl;
        cout << "Number of Photos: " << damagePhotos.size() << endl;
    }
};

// Vehicle class: Stores data about a customer's registered vehicle
class Vehicle
{
private:
    int vehicleId;
    int customerId;
    string registrationNumber;
    string make;
    string model;
    int year;
    string color;
    string engineNumber;
    string chassisNumber;
    double value;

public:
    Vehicle() : vehicleId(0), customerId(0), year(0), value(0.0) {}

    Vehicle(int vId, int custId, string regNum, string mk, string mdl,
        int yr, string clr, string engNum, string chsNum, double val)
        : vehicleId(vId), customerId(custId), registrationNumber(regNum),
        make(mk), model(mdl), year(yr), color(clr), engineNumber(engNum),
        chassisNumber(chsNum), value(val) {
    }

    int getVehicleId() const { return vehicleId; }
    int getCustomerId() const { return customerId; }
    string getRegistrationNumber() const { return registrationNumber; }
    string getMake() const { return make; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    string getColor() const { return color; }
    string getEngineNumber() const { return engineNumber; }
    string getChassisNumber() const { return chassisNumber; }
    double getValue() const { return value; }

    void setVehicleId(int id) { vehicleId = id; }
    void setCustomerId(int id) { customerId = id; }
    void setRegistrationNumber(string regNum) { registrationNumber = regNum; }
    void setMake(string mk) { make = mk; }
    void setModel(string mdl) { model = mdl; }
    void setYear(int yr) { year = yr; }
    void setColor(string clr) { color = clr; }
    void setEngineNumber(string engNum) { engineNumber = engNum; }
    void setChassisNumber(string chsNum) { chassisNumber = chsNum; }
    void setValue(double val) { value = val; }

    void display() const {
        cout << "=== VEHICLE ===" << endl;
        cout << "Vehicle ID: " << vehicleId << endl;
        cout << "Customer ID: " << customerId << endl;
        cout << "Registration Number: " << registrationNumber << endl;
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Color: " << color << endl;
        cout << "Engine Number: " << engineNumber << endl;
        cout << "Chassis Number: " << chassisNumber << endl;
        cout << "Value: " << value << endl;
    }
};

// Policy class: Represents an active insurance contract between the company and a customer
class Policy
{
private:
    int policyId;
    int customerId;
    int vehicleId;
    string policyNumber;
    string policyType;
    string startDate;
    string endDate;
    double premium;
    double coverageAmount;
    string status;
    int salesmanId;

public:
    Policy() : policyId(0), customerId(0), vehicleId(0), premium(0.0),
        coverageAmount(0.0), status("ACTIVE"), salesmanId(0) {
    }

    Policy(int pId, int custId, int vehId, string pNum, string pType,
        string sDate, string eDate, double prem, double coverage, int sId)
        : policyId(pId), customerId(custId), vehicleId(vehId),
        policyNumber(pNum), policyType(pType), startDate(sDate),
        endDate(eDate), premium(prem), coverageAmount(coverage),
        status("ACTIVE"), salesmanId(sId) {
    }

    int getPolicyId() const { return policyId; }
    int getCustomerId() const { return customerId; }
    int getVehicleId() const { return vehicleId; }
    string getPolicyNumber() const { return policyNumber; }
    string getPolicyType() const { return policyType; }
    string getStartDate() const { return startDate; }
    string getEndDate() const { return endDate; }
    double getPremium() const { return premium; }
    double getCoverageAmount() const { return coverageAmount; }
    string getStatus() const { return status; }
    int getSalesmanId() const { return salesmanId; }

    void setPolicyId(int id) { policyId = id; }
    void setCustomerId(int id) { customerId = id; }
    void setVehicleId(int id) { vehicleId = id; }
    void setPolicyNumber(string pNum) { policyNumber = pNum; }
    void setPolicyType(string pType) { policyType = pType; }
    void setStartDate(string sDate) { startDate = sDate; }
    void setEndDate(string eDate) { endDate = eDate; }
    void setPremium(double prem) { premium = prem; }
    void setCoverageAmount(double coverage) { coverageAmount = coverage; }
    void setStatus(string stat) { status = stat; }
    void setSalesmanId(int id) { salesmanId = id; }

    void display() const {
        cout << "=== POLICY ===" << endl;
        cout << "Policy ID: " << policyId << endl;
        cout << "Customer ID: " << customerId << endl;
        cout << "Vehicle ID: " << vehicleId << endl;
        cout << "Policy Number: " << policyNumber << endl;
        cout << "Type: " << policyType << endl;
        cout << "Start Date: " << startDate << endl;
        cout << "End Date: " << endDate << endl;
        cout << "Premium: " << premium << endl;
        cout << "Coverage Amount: " << coverageAmount << endl;
        cout << "Status: " << status << endl;
        cout << "Salesman ID: " << salesmanId << endl;
    }
};

// Workshop class: A registered facility where damaged vehicles are repaired
class Workshop
{
private:
    int workshopId;
    string name;
    string address;
    string phoneNumber;
    string email;
    string registrationNumber;
    string specialization;
    double rating;
    bool isActive;

public:
    Workshop() : workshopId(0), rating(0.0), isActive(true) {}

    Workshop(int wId, string nm, string addr, string phone, string em,
        string regNum, string spec)
        : workshopId(wId), name(nm), address(addr), phoneNumber(phone),
        email(em), registrationNumber(regNum), specialization(spec),
        rating(0.0), isActive(true) {
    }

    int getWorkshopId() const { return workshopId; }
    string getName() const { return name; }
    string getAddress() const { return address; }
    string getPhoneNumber() const { return phoneNumber; }
    string getEmail() const { return email; }
    string getRegistrationNumber() const { return registrationNumber; }
    string getSpecialization() const { return specialization; }
    double getRating() const { return rating; }
    bool getIsActive() const { return isActive; }

    void setWorkshopId(int id) { workshopId = id; }
    void setName(string nm) { name = nm; }
    void setAddress(string addr) { address = addr; }
    void setPhoneNumber(string phone) { phoneNumber = phone; }
    void setEmail(string em) { email = em; }
    void setRegistrationNumber(string regNum) { registrationNumber = regNum; }
    void setSpecialization(string spec) { specialization = spec; }
    void setRating(double rat) { rating = rat; }
    void setIsActive(bool active) { isActive = active; }

    void display() const {
        cout << "=== WORKSHOP ===" << endl;
        cout << "Workshop ID: " << workshopId << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
        cout << "Registration Number: " << registrationNumber << endl;
        cout << "Specialization: " << specialization << endl;
        cout << "Rating: " << rating << endl;
        cout << "Status: " << (isActive ? "Active" : "Inactive") << endl;
    }
};

// Generates a report of customers who registered in a specific month/year
void Manager::viewNewCustomers(vector<Customer>& customers, string month, string year) {
    cout << "\n=== NEW CUSTOMERS - " << month << " " << year << " ===" << endl;
    bool found = false;
    for (const auto& customer : customers) {
        string regDate = customer.getRegistrationDate();
        if (regDate.find(month) != string::npos && regDate.find(year) != string::npos) {
            customer.display();
            cout << "------------------------" << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No new customers found for this period." << endl;
    }
}

// Displays all claims currently awaiting action
void Manager::viewPendingClaims(vector<Claim>& claims) {
    cout << "\n=== PENDING CLAIMS ===" << endl;
    bool found = false;
    for (const auto& claim : claims) {
        if (claim.getStatus() == "PENDING") {
            claim.display();
            cout << "------------------------" << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No pending claims." << endl;
    }
}

void Manager::viewInspectionReports(vector<InspectionReport>& reports) {
    cout << "\n=== INSPECTION REPORTS ===" << endl;
    for (const auto& report : reports) {
        report.display();
        cout << "------------------------" << endl;
    }
}

void Manager::viewCustomerClaimHistory(vector<Claim>& claims, int customerId) {
    cout << "\n=== CLAIM HISTORY FOR CUSTOMER ID: " << customerId << " ===" << endl;
    bool found = false;
    for (const auto& claim : claims) {
        if (claim.getCustomerId() == customerId) {
            claim.display();
            cout << "------------------------" << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No claims found for this customer." << endl;
    }
}

// Approves a claim based on the Surveyor's recommendation and estimated repair cost
void Manager::approveClaim(Claim& claim, InspectionReport& report) {
    if (report.getRecommendation() == "APPROVE" || report.getRecommendation() == "Approve") {
        claim.setStatus("APPROVED");
        claim.setApprovedAmount(report.getEstimatedRepairCost());
        claim.setManagerId(this->id);
        claim.setApprovalDate("2024-01-15");
        cout << "\nClaim ID " << claim.getClaimId() << " has been APPROVED." << endl;
        cout << "Approved Amount: " << claim.getApprovedAmount() << endl;
    }
    else {
        cout << "\nInspection report does not recommend approval." << endl;
    }
}

void Manager::rejectClaim(Claim& claim, InspectionReport& report, string reason) {
    claim.setStatus("REJECTED");
    claim.setRejectionReason(reason);
    claim.setManagerId(this->id);
    cout << "\nClaim ID " << claim.getClaimId() << " has been REJECTED." << endl;
    cout << "Reason: " << reason << endl;
}

// Utility class to handle persistent data storage using text files
class FileHandler {
public:
    static void loadCustomers(vector<Customer>& customers, const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) return;
        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            int id;
            string fullName, cnic, phone, addr, regDate, pass;
            ss >> id >> fullName >> cnic >> phone >> addr >> regDate >> pass;
            
            // We use underscores to replace spaces in names/strings because 
            // the '>>' operator stops reading at spaces. This ensures 
            // multi-word names are read correctly from the file.
            string fName = fullName;
            string lName = "";
            size_t pos = fullName.find('_');
            if (pos != string::npos) {
                fName = fullName.substr(0, pos);
                lName = fullName.substr(pos + 1);
            }
            
            customers.push_back(Customer(id, fName, lName, cnic, phone, addr, regDate, pass));
        }
        file.close();
    }

    static void saveCustomers(const vector<Customer>& customers, const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) return;
        for (const auto& c : customers) {
            string fullName = c.getFirstName();
            if (!c.getLastName().empty()) {
                fullName += "_" + c.getLastName();
            }
            file << c.getId() << " " << fullName << " " << c.getCnic() << " "
                 << c.getPhoneNumber() << " " << c.getAddress() << " "
                 << c.getRegistrationDate() << " " << c.getPassword() << "\n";
        }
        file.close();
    }

    static void loadClaims(vector<Claim>& claims, const string& approvedFile, const string& pendingFile) {
        // Load approved claims
        ifstream file1(approvedFile);
        if (file1.is_open()) {
            string line;
            while (getline(file1, line)) {
                if (line.empty()) continue;
                stringstream ss(line);
                int cId, custId, polId, vehId, repId = 0, survId = 0, mgrId = 0;
                string cDate, incDate, desc, stat, appDate = "None", rejReason = "None";
                double cAmt = 0.0, aAmt = 0.0;
                
                ss >> cId >> custId >> polId >> vehId >> cDate >> incDate >> desc 
                   >> cAmt >> aAmt >> stat >> repId >> survId >> mgrId >> appDate >> rejReason;
                   
                Claim c(cId, custId, polId, vehId, cDate, incDate, desc, cAmt);
                c.setApprovedAmount(aAmt);
                c.setStatus(stat);
                c.setInspectionReportId(repId);
                c.setSurveyorId(survId);
                c.setManagerId(mgrId);
                c.setApprovalDate(appDate);
                c.setRejectionReason(rejReason);
                claims.push_back(c);
            }
            file1.close();
        }

        // Load pending claims
        ifstream file2(pendingFile);
        if (file2.is_open()) {
            string line;
            while (getline(file2, line)) {
                if (line.empty()) continue;
                stringstream ss(line);
                int cId, custId, polId, vehId;
                string cDate, incDate, desc;
                double cAmt;
                
                ss >> cId >> custId >> polId >> vehId >> cDate >> incDate >> desc >> cAmt;
                   
                Claim c(cId, custId, polId, vehId, cDate, incDate, desc, cAmt);
                claims.push_back(c);
            }
            file2.close();
        }
    }

    static void saveClaims(const vector<Claim>& claims, const string& approvedFile, const string& pendingFile) {
        ofstream appFile(approvedFile);
        ofstream pendFile(pendingFile);
        
        for (const auto& c : claims) {
            if (c.getStatus() == "PENDING") {
                if (pendFile.is_open()) {
                    pendFile << c.getClaimId() << " " << c.getCustomerId() << " " 
                             << c.getPolicyId() << " " << c.getVehicleId() << " "
                             << c.getClaimDate() << " " << c.getIncidentDate() << " "
                             << c.getIncidentDescription() << " " << c.getClaimedAmount() << "\n";
                }
            } else {
                if (appFile.is_open()) {
                    appFile << c.getClaimId() << " " << c.getCustomerId() << " " 
                            << c.getPolicyId() << " " << c.getVehicleId() << " "
                            << c.getClaimDate() << " " << c.getIncidentDate() << " "
                            << c.getIncidentDescription() << " " << c.getClaimedAmount() << " "
                            << c.getApprovedAmount() << " " << c.getStatus() << " "
                            << c.getInspectionReportId() << " " << c.getSurveyorId() << " "
                            << c.getManagerId() << " " 
                            << (c.getApprovalDate().empty() ? "None" : c.getApprovalDate()) << " "
                            << (c.getRejectionReason().empty() ? "None" : c.getRejectionReason()) << "\n";
                }
            }
        }
        appFile.close();
        pendFile.close();
    }

    static void loadPolicies(vector<Policy>& policies, const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) return;
        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            int pId, custId, vehId, sId;
            string pNum, pType, sDate, eDate, stat;
            double prem, cov;
            
            ss >> pId >> custId >> vehId >> pNum >> pType >> sDate >> eDate >> prem >> cov >> stat >> sId;
            
            Policy p(pId, custId, vehId, pNum, pType, sDate, eDate, prem, cov, sId);
            p.setStatus(stat);
            policies.push_back(p);
        }
        file.close();
    }

    static void savePolicies(const vector<Policy>& policies, const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) return;
        for (const auto& p : policies) {
            file << p.getPolicyId() << " " << p.getCustomerId() << " " << p.getVehicleId() << " "
                 << p.getPolicyNumber() << " " << p.getPolicyType() << " " << p.getStartDate() << " "
                 << p.getEndDate() << " " << p.getPremium() << " " << p.getCoverageAmount() << " "
                 << p.getStatus() << " " << p.getSalesmanId() << "\n";
        }
        file.close();
    }
};

// Main controller class that manages system state, menus, and business logic
class Company {
private:
    string name;
    // Database simulated using vectors (In-memory storage)
    vector<Customer> customers;
    vector<Vehicle> vehicles;
    vector<Policy> policies;
    vector<Claim> claims;
    vector<InspectionReport> reports;
    vector<Salesman> salesmen;
    vector<Surveyor> surveyors;
    vector<Manager> managers;
    vector<Workshop> workshops;

public:
    Company(string n) : name(n) {}

    void addCustomer(const Customer& c) { customers.push_back(c); }
    void addVehicle(const Vehicle& v) { vehicles.push_back(v); }
    void addPolicy(const Policy& p) { policies.push_back(p); }
    void addClaim(const Claim& c) { claims.push_back(c); }
    void addReport(const InspectionReport& r) { reports.push_back(r); }
    void addSalesman(const Salesman& s) { salesmen.push_back(s); }
    void addSurveyor(const Surveyor& s) { surveyors.push_back(s); }
    void addManager(const Manager& m) { managers.push_back(m); }
    void addWorkshop(const Workshop& w) { workshops.push_back(w); }

// Main execution loop for the application
    void run() {
        // Load data from files
        FileHandler::loadCustomers(customers, "customers.txt");
        FileHandler::loadClaims(claims, "claims.txt", "pending.txt");
        FileHandler::loadPolicies(policies, "policies.txt");

        // Hardcode a manager, workshop, and report for testing other functionality
        Manager m1(1, "Hassan", "Khan", "98765-4321098-7", "0321-9876543", "Islamabad",
            "EMP001", "2020-01-01", 150000, "Management", "HIGH");
        addManager(m1);

        Salesman s1(1, "Tariq", "Jamil", "11111-2222222-3", "0300-9999999", "Lahore",
            "EMP002", "2021-05-10", 80000, "Sales", 50, 10000.0);
        addSalesman(s1);

        Salesman s2(2, "Omer", "Farooq", "22222-3333333-4", "0333-1111111", "Islamabad",
            "EMP004", "2022-01-20", 75000, "Sales", 30, 6000.0);
        addSalesman(s2);

        Salesman s3(3, "Zain", "Ali", "55555-6666666-7", "0345-2222222", "Karachi",
            "EMP005", "2023-08-01", 70000, "Sales", 10, 2000.0);
        addSalesman(s3);

        Surveyor surv1(1, "Bilal", "Saeed", "33333-4444444-5", "0321-8888888", "Karachi",
            "EMP003", "2019-03-15", 90000, "Inspection", 200, "Engines");
        addSurveyor(surv1);

        InspectionReport rep1(1, 1, 1, 1, "2024-01-13");
        rep1.setDamageAssessment("Front bumper damaged");
        rep1.setEstimatedRepairCost(45000);
        rep1.setRecommendation("APPROVE");
        addReport(rep1);

        Workshop w1(1, "AutoFix", "123 Main St", "0300-1111111", "contact@autofix.com", "REG123", "Bodywork");
        addWorkshop(w1);

        Workshop w2(2, "Speedy Repairs", "456 Oak St", "0300-2222222", "speedy@repairs.com", "REG456", "Engine Tuning");
        addWorkshop(w2);
        
        Workshop w3(3, "City Motors", "789 Pine Ave", "0300-3333333", "info@citymotors.com", "REG789", "General Maintenance");
        addWorkshop(w3);

        int mainChoice;
        do {
            cout << "\n========== " << name << " ==========" << endl;
            cout << "1. Sign in as Manager" << endl;
            cout << "2. Sign in as Customer" << endl;
            cout << "3. Sign up as Customer" << endl;
            cout << "4. Sign in as Surveyor" << endl;
            cout << "5. Sign in as Salesman" << endl;
            cout << "6. View All Customers" << endl;
            cout << "0. Exit" << endl;
            cout << "Enter choice: ";
            cin >> mainChoice;

            if (mainChoice == 1) {
                string user, pass;
                cout << "Username: ";
                cin >> user;
                cout << "Password: ";
                cin >> pass;

                if (user == "admin" && pass == "admin123") {
                    managerMenu();
                } else {
                    cout << "Invalid manager credentials!" << endl;
                }
            } else if (mainChoice == 2) {
                string user, pass;
                cout << "Username (Customer ID): ";
                cin >> user;
                cout << "Password: ";
                cin >> pass;

                int custId = 0;
                try {
                    custId = stoi(user);
                } catch (...) {
                    custId = -1;
                }
                
                bool found = false;
                Customer* currentCustomer = nullptr;

                for (auto& c : customers) {
                    if (c.getId() == custId && c.getPassword() == pass) {
                        found = true;
                        currentCustomer = &c;
                        break;
                    }
                }

                if (found) {
                    customerMenu(*currentCustomer);
                } else {
                    cout << "Invalid customer credentials!" << endl;
                }
            } else if (mainChoice == 3) {
                string fName, lName, cnic, phone, addr, pass;
                cout << "\n--- CUSTOMER SIGN UP ---" << endl;
                cout << "Enter First Name: ";
                cin >> fName;
                cout << "Enter Last Name: ";
                cin >> lName;
                cout << "Enter CNIC: ";
                cin.ignore();
                getline(cin, cnic);
                cout << "Enter Phone: ";
                getline(cin, phone);
                cout << "Enter Address: ";
                getline(cin, addr);
                cout << "Enter Password: ";
                getline(cin, pass);

                int newId = customers.empty() ? 1 : customers.back().getId() + 1;
                
                Customer newCust(newId, fName, lName, cnic, phone, addr, "2026-04-23", pass);
                addCustomer(newCust);
                
                cout << "\nSign up successful! Your Customer ID (Username) is: " << newId << endl;
                cout << "Please remember this ID for signing in." << endl;
            }
            else if (mainChoice == 4)
            {
                string user, pass;
                cout << "Username (Surveyor ID): ";
                cin >> user;
                // Dummy check for surveyor login
                if (user == "1" && !surveyors.empty()) {
                    surveyorMenu(surveyors[0]);
                } else {
                    cout << "Invalid surveyor credentials!" << endl;
                }
            }
            else if (mainChoice == 5)
            {
                string user, pass;
                cout << "Username (Salesman ID): ";
                cin >> user;
                
                int sId = -1;
                try { sId = stoi(user); } catch (...) {}
                
                bool found = false;
                for (auto& s : salesmen) {
                    if (s.getId() == sId) {
                        found = true;
                        salesmanMenu(s);
                        break;
                    }
                }
                if (!found) cout << "Invalid salesman credentials!" << endl;
            }
            else if (mainChoice == 6)
            {
                for (int i = 0; i < customers.size(); i++)
                {
                    customers[i].display();
                    cout << endl;
                }
            }
            else if (mainChoice == 0) {
                cout << "Saving data and exiting..." << endl;
                FileHandler::saveCustomers(customers, "customers.txt");
                FileHandler::saveClaims(claims, "claims.txt", "pending.txt");
                FileHandler::savePolicies(policies, "policies.txt");
            } else {
                cout << "Invalid choice!" << endl;
            }

        } while (mainChoice != 0);
    }

// Interactive menu for the Manager role
    void managerMenu() {
        int choice;
        do {
            cout << "\n--- MANAGER MENU ---" << endl;
            cout << "1. View New Customers" << endl;
            cout << "2. View Pending Claims" << endl;
            cout << "3. View Inspection Reports" << endl;
            cout << "4. View Customer Claim History" << endl;
            cout << "5. Approve Claim" << endl;
            cout << "6. Reject Claim" << endl;
            cout << "7. Display All Customers" << endl;
            cout << "8. Display All Workshops" << endl;
            cout << "0. Logout" << endl;
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
            case 1: {
                string month, year;
                cout << "Enter month (e.g., January): ";
                cin >> month;
                cout << "Enter year: ";
                cin >> year;
                if (!managers.empty()) managers[0].viewNewCustomers(customers, month, year);
                break;
            }
            case 2:
                if (!managers.empty()) managers[0].viewPendingClaims(claims);
                break;
            case 3:
                if (!managers.empty()) managers[0].viewInspectionReports(reports);
                break;
            case 4: {
                int custId;
                cout << "Enter Customer ID: ";
                cin >> custId;
                if (!managers.empty()) managers[0].viewCustomerClaimHistory(claims, custId);
                break;
            }
            case 5: {
                int claimId;
                cout << "Enter Claim ID to approve: ";
                cin >> claimId;
                bool claimFound = false;
                for (auto& c : claims) {
                    if (c.getClaimId() == claimId && c.getStatus() == "PENDING") {
                        claimFound = true;
                        // Security Check: Manager cannot approve until a Surveyor has filed a report
                        if (c.getInspectionReportId() <= 0) {
                            cout << "Cannot approve: Awaiting Surveyor Inspection." << endl;
                            break;
                        }
                        bool reportFound = false;
                        for (auto& r : reports) {
                            if (r.getReportId() == c.getInspectionReportId()) {
                                managers[0].approveClaim(c, r);
                                reportFound = true;
                                break;
                            }
                        }
                        if (!reportFound) cout << "Inspection Report not found!" << endl;
                        break;
                    }
                }
                if (!claimFound) cout << "Valid Pending Claim ID not found!" << endl;
                break;
            }
            case 6: {
                int claimId;
                string reason;
                cout << "Enter Claim ID to reject: ";
                cin >> claimId;
                cout << "Enter rejection reason: ";
                cin.ignore();
                getline(cin, reason);
                bool claimFound = false;
                for (auto& c : claims) {
                    if (c.getClaimId() == claimId && c.getStatus() == "PENDING") {
                        claimFound = true;
                        if (c.getInspectionReportId() <= 0) {
                            cout << "Cannot reject: Awaiting Surveyor Inspection." << endl;
                            break;
                        }
                        bool reportFound = false;
                        for (auto& r : reports) {
                            if (r.getReportId() == c.getInspectionReportId()) {
                                managers[0].rejectClaim(c, r, reason);
                                reportFound = true;
                                break;
                            }
                        }
                        if (!reportFound) cout << "Inspection Report not found!" << endl;
                        break;
                    }
                }
                if (!claimFound) cout << "Valid Pending Claim ID not found!" << endl;
                break;
            }
            case 7:
                for (const auto& c : customers) {
                    c.display();
                    cout << "------------------------" << endl;
                }
                break;
            case 8:
                for (const auto& w : workshops) {
                    w.display();
                    cout << "------------------------" << endl;
                }
                break;
            case 0:
                cout << "Logging out..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
            }
        } while (choice != 0);
    }

// Interactive menu for the Salesman role
    void salesmanMenu(Salesman& salesman) {
        int choice;
        do {
            cout << "\n--- SALESMAN MENU (" << salesman.getFirstName() << " " << salesman.getLastName() << ") ---" << endl;
            cout << "1. View My Stats" << endl;
            cout << "0. Logout" << endl;
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                salesman.display();
                break;
            case 0:
                cout << "Logging out..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
            }
        } while (choice != 0);
    }

// Interactive menu for the Surveyor role
    void surveyorMenu(Surveyor& surveyor) {
        int choice;
        do {
            cout << "\n--- SURVEYOR MENU (" << surveyor.getFirstName() << ") ---" << endl;
            cout << "1. View Pending Claims" << endl;
            cout << "2. Inspect Claim (Create Report)" << endl;
            cout << "0. Logout" << endl;
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                if (!managers.empty()) managers[0].viewPendingClaims(claims);
                break;
            case 2: {
                int claimId;
                cout << "Enter Claim ID to inspect: ";
                cin >> claimId;
                bool found = false;
                for (auto& c : claims) {
                    if (c.getClaimId() == claimId && c.getStatus() == "PENDING") {
                        found = true;
                        if (c.getInspectionReportId() > 0) {
                            cout << "This claim has already been inspected!" << endl;
                            break;
                        }
                        string assessment, rec;
                        double cost;
                        cout << "Enter Damage Assessment: ";
                        cin.ignore();
                        getline(cin, assessment);
                        cout << "Enter Estimated Repair Cost: ";
                        cin >> cost;
                        cout << "Enter Recommendation (APPROVE/REJECT): ";
                        cin >> rec;

                        int reportId = reports.empty() ? 1 : reports.back().getReportId() + 1;
                        InspectionReport newRep(reportId, claimId, surveyor.getId(), c.getVehicleId(), "2024-04-24");
                        newRep.setDamageAssessment(assessment);
                        newRep.setEstimatedRepairCost(cost);
                        newRep.setRecommendation(rec);
                        addReport(newRep);
                        
                        c.setInspectionReportId(reportId);
                        cout << "Inspection Report submitted successfully! Report ID: " << reportId << endl;
                        break;
                    }
                }
                if (!found) cout << "Pending claim not found!" << endl;
                break;
            }
            case 0:
                cout << "Logging out..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
            }
        } while (choice != 0);
    }

// Interactive menu for the Customer role
    void customerMenu(Customer& customer) {
        int choice;
        do {
            cout << "\n--- CUSTOMER MENU (" << customer.getFirstName() << " " << customer.getLastName() << ") ---" << endl;
            cout << "1. View My Details" << endl;
            cout << "2. Apply for Insurance" << endl;
            cout << "3. Request Repair (File Claim)" << endl;
            cout << "4. View My Claims" << endl;
            cout << "5. View Workshops" << endl;
            cout << "0. Logout" << endl;
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                customer.display();
                break;
            case 2: {
                string mk, mdl, regNum;
                int yr;
                cout << "--- Apply for Insurance ---" << endl;
                cout << "Enter Vehicle Make: "; cin >> mk;
                cout << "Enter Vehicle Model: "; cin >> mdl;
                cout << "Enter Vehicle Year: "; cin >> yr;
                cout << "Enter Registration Number: "; cin >> regNum;
                
                int vehId = vehicles.empty() ? 1 : vehicles.back().getVehicleId() + 1;
                Vehicle newVeh(vehId, customer.getId(), regNum, mk, mdl, yr, "Black", "Eng123", "Chas123", 2000000.0);
                addVehicle(newVeh);
                
                int polId = policies.empty() ? 1 : policies.back().getPolicyId() + 1;
                Salesman* assignedSalesman = nullptr;
                if (!salesmen.empty()) {
                    int sIndex = polId % salesmen.size();
                    assignedSalesman = &salesmen[sIndex];
                }
                int salesmanId = assignedSalesman ? assignedSalesman->getId() : 0;
                
                double premium = 50000.0;
                Policy newPol(polId, customer.getId(), vehId, "POL-" + to_string(polId), "Comprehensive", "2024-01-01", "2025-01-01", premium, 2000000.0, salesmanId);
                addPolicy(newPol);
                customer.addPolicy(polId);
                
                // Business Logic: Assign salesman and calculate their 5% commission
                if (assignedSalesman) {
                    assignedSalesman->setPoliciesSold(assignedSalesman->getPoliciesSold() + 1);
                    assignedSalesman->setCommission(assignedSalesman->getCommission() + (premium * 0.05)); // 5% commission
                }
                
                cout << "Insurance applied successfully! Policy ID: " << polId << " assigned to Salesman ID: " << salesmanId << endl;
                break;
            }
            case 3: {
                cout << "--- Request Repair ---" << endl;
                int polId, wsId;
                string desc;
                double amt;
                cout << "Enter your Policy ID: "; cin >> polId;
                
                cout << "\nAvailable Registered Workshops:" << endl;
                for (const auto& w : workshops) {
                    cout << "ID: " << w.getWorkshopId() << " | Name: " << w.getName() << " | Spec: " << w.getSpecialization() << endl;
                }
                cout << "Enter selected Workshop ID: "; cin >> wsId;
                
                bool wsFound = false;
                for (const auto& w : workshops) {
                    if (w.getWorkshopId() == wsId && w.getIsActive()) {
                        wsFound = true;
                        break;
                    }
                }
                
                if (!wsFound) {
                    cout << "Invalid or inactive workshop selected. Repair must be at a registered workshop!" << endl;
                    break;
                }
                
                cout << "Enter Incident Description: ";
                cin.ignore();
                getline(cin, desc);
                cout << "Enter Claimed Amount: ";
                cin >> amt;
                
                int claimId = claims.empty() ? 1 : claims.back().getClaimId() + 1;
                Claim newClaim(claimId, customer.getId(), polId, 1, "2024-04-24", "2024-04-23", desc, amt);
                addClaim(newClaim);
                customer.addClaim(claimId);
                
                cout << "Repair requested and Claim filed successfully! Pending Claim ID: " << claimId << endl;
                break;
            }
            case 4:
                if (!managers.empty()) managers[0].viewCustomerClaimHistory(claims, customer.getId());
                break;
            case 5:
                for (const auto& w : workshops) {
                    w.display();
                    cout << "------------------------" << endl;
                }
                break;
            case 0:
                cout << "Logging out..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
            }
        } while (choice != 0);
    }
};

// Entry point of the application
int main() {
    Company company("INSURANCE MANAGEMENT SYSTEM");
    company.run();
    return 0;
}