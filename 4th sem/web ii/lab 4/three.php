<?php

class Employee {
    private $employeeId;
    private $fullName;
    private $email;
    private $monthlySalary;

    public function __construct($employeeId, $fullName, $email, $monthlySalary) {
        $this->employeeId = $employeeId;
        $this->fullName = $fullName;
        $this->email = $email;
        $this->monthlySalary = $monthlySalary;
    }

    public function calculateYearlySalary() {
        return $this->monthlySalary * 12;
    }

    public function displayInfoInTable() {
        echo "<tr>";
        echo "<td>{$this->employeeId}</td>";
        echo "<td>{$this->fullName}</td>";
        echo "<td>{$this->email}</td>";
        echo "<td>\${$this->monthlySalary}</td>";
        echo "<td>\${$this->calculateYearlySalary()}</td>";
        echo "</tr>";
    }
}

// Create employee objects
$employee1 = new Employee(1, "Chamber Smith", "chamber@example.com", 4400);
$employee2 = new Employee(2, "Reyna Costa", "reyna@example.com", 6500);
$employee3 = new Employee(3, "Sajjit Shrestha", "sajjit@example.com", 8500);

// Display employee information in an HTML table
echo "<table border='1'>";
echo "<tr><th>Employee ID</th><th>Full Name</th><th>Email</th><th>Monthly Salary</th><th>Yearly Salary</th></tr>";
$employee1->displayInfoInTable();
$employee2->displayInfoInTable();
$employee3->displayInfoInTable();
echo "</table>";

?>
