import java.util.Scanner;

class Employee {
    String name;
    int age;
    String address;
    String phone_no;
    double salary;

    public void printSalary() {
        System.out.println("Salary: Rs " + this.salary);
    }

    Employee(String name, int age, String address, String phone_no, double salary) {
        this.name = name;
        this.age = age;
        this.address = address;
        this.phone_no = phone_no;
        this.salary = salary;
    }
}

class Officer extends Employee {
    String specialization;

    Officer(String name, int age, String address, String phone_no, double salary, String specialization) {
        super(name, age, address, phone_no, salary);
        this.specialization = specialization;
    }

    public void displayDetails() {
        System.out.println("Officer Details:");
        System.out.println("Name: " + this.name);
        System.out.println("Age: " + this.age);
        System.out.println("Address: " + this.address);
        System.out.println("Phone Number: " + this.phone_no);
        System.out.println("Specialization: " + this.specialization);
        this.printSalary();
    }
}

class Manager extends Employee {
    String department;

    Manager(String name, int age, String address, String phone_no, double salary, String department) {
        super(name, age, address, phone_no, salary);
        this.department = department;
    }

    public void displayDetails() {
        System.out.println("Manager Details:");
        System.out.println("Name: " + this.name);
        System.out.println("Age: " + this.age);
        System.out.println("Address: " + this.address);
        System.out.println("Phone Number: " + this.phone_no);
        System.out.println("Department: " + this.department);
        this.printSalary();
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter details for Officer:");
        System.out.print("Name: ");
        String officerName = scanner.nextLine();
        System.out.print("Age: ");
        int officerAge = scanner.nextInt();
        scanner.nextLine();
        System.out.print("Address: ");
        String officerAddress = scanner.nextLine();
        System.out.print("Phone Number: ");
        String officerPhoneNumber = scanner.nextLine();
        System.out.print("Salary: ");
        double officerSalary = scanner.nextDouble();
        scanner.nextLine();
        System.out.print("Specialization: ");
        String officerSpecialization = scanner.nextLine();

        Officer officer = new Officer(officerName, officerAge, officerAddress, officerPhoneNumber, officerSalary, officerSpecialization);

        System.out.println("\nEnter details for Manager:");
        System.out.print("Name: ");
        String managerName = scanner.nextLine();
        System.out.print("Age: ");
        int managerAge = scanner.nextInt();
        scanner.nextLine();
        System.out.print("Address: ");
        String managerAddress = scanner.nextLine();
        System.out.print("Phone Number: ");
        String managerPhoneNumber = scanner.nextLine();
        System.out.print("Salary: ");
        double managerSalary = scanner.nextDouble();
        scanner.nextLine();
        System.out.print("Department: ");
        String managerDepartment = scanner.nextLine();

        Manager manager = new Manager(managerName, managerAge, managerAddress, managerPhoneNumber, managerSalary, managerDepartment);

        System.out.println();
        officer.displayDetails();
        System.out.println();
        manager.displayDetails();

        scanner.close();
    }
}
