#include <iostream>
#include <queue>
#include <string>
class Patient {
public:
std::string name;
std::string priority;
Patient(const std::string& patientName, const std::string& patientPriority)
: name(patientName), priority(patientPriority) {}
};
struct PatientComparator {
bool operator()(const Patient& patient1, const Patient& patient2) const {
// Custom comparator to prioritize patients based on their priority levels
if (patient1.priority == "Serious") {
return true;
} else if (patient1.priority == "Non-serious" && patient2.priority != "Serious") {
return true;
} else if (patient1.priority == "General Checkup" && patient2.priority == "GeneralCheckup") {
// If both patients are "General Checkup" type, sort them alphabetically by name
return patient1.name > patient2.name;
}
return false;
}
};
int main() {
std::priority_queue<Patient, std::vector<Patient>, PatientComparator> priorityQueue;
// Add patients to the priority queue
priorityQueue.push(Patient("John", "Serious"));
priorityQueue.push(Patient("Alice", "Non-serious"));
priorityQueue.push(Patient("Michael", "General Checkup"));
priorityQueue.push(Patient("Sarah", "Serious"));
priorityQueue.push(Patient("David", "Non-serious"));
priorityQueue.push(Patient("Emily", "General Checkup"));
// Serve patients based on their priority
while (!priorityQueue.empty()) {
Patient patient = priorityQueue.top();
priorityQueue.pop();
std::cout << "Serving patient: " << patient.name << " (" << patient.priority << ")" <<
std::endl;
}
return 0;
}
