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

--- List the employee names and their salaries by manager name.
SELECT works.employeeName, salary, managerName
FROM works
INNER JOIN manages ON works.employeeName = manages.employeeName;


--- Find those companies whose employee earn a higher salary on an average than the average salary of Datalink Ltd.

SELECT companyName
FROM works
GROUP BY companyName
HAVING AVG(salary) > (SELECT AVG(salary) FROM works WHERE companyName = 'Datalink Ltd.');
-- HAVING is used instead of WHERE because WHERE keyword could not be used with aggregate functions. 
