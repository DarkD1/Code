CREATE TABLE employee (
	employeeName VARCHAR(255) PRIMARY KEY NOT NULL,
	street VARCHAR(255),
	city VARCHAR(255)
);

CREATE TABLE company (
	companyName VARCHAR(255) PRIMARY KEY NOT NULL,
	city VARCHAR(255)
);

CREATE TABLE works (
	employeeName VARCHAR(255),
	companyName VARCHAR(255),
	salary INT,
	FOREIGN KEY (employeeName) REFERENCES employee(employeeName) ON DELETE CASCADE ON UPDATE CASCADE,
	FOREIGN KEY (companyName) REFERENCES company(companyName) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE manages (
	employeeName VARCHAR(255),
	managerName VARCHAR(255),
	FOREIGN KEY (employeeName) REFERENCES employee(employeeName) ON DELETE CASCADE ON UPDATE CASCADE
);


----- QUERIES -----

--- Find the names, cities and salaries of all employees who work for Datalink Ltd.

SELECT works.employeeName, employee.city, works.salary
FROM employee
INNER JOIN works ON works.employeeName = employee.employeeName
WHERE companyName = 'Datalink Ltd.';


--- Find the total salaries of each company

SELECT companyName, SUM(salary) AS totalSalary  FROM works GROUP BY companyName;