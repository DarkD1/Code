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
	FOREIGN KEY (employeeName) REFERENCES employee(employeeName),
	FOREIGN KEY (companyName) REFERENCES company(companyName)
);

CREATE TABLE manages (
	employeeName VARCHAR(255),
	managerName VARCHAR(255),
	FOREIGN KEY (employeeName) REFERENCES employee(employeeName)
);


----- QUERIES -----

--- Find the names, streets and cities of all employees who works for Prime Bank Ltd. and earn more than Tk. 10000

SELECT employeeName, street, city
FROM employee
WHERE employeeName IN (SELECT employeeName FROM works WHERE companyName LIKE 'Prime Bank Ltd.' AND salary > 10000); 


--- Find all employee in the database who earn more than each employee of Prime Bank Ltd.

SELECT * FROM employee WHERE employeeName IN (SELECT employeeName FROM works WHERE salary > (SELECT MAX(salary) FROM works WHERE companyName LIKE 'Prime Bank Ltd.'));