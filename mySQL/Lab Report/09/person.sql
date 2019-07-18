CREATE TABLE lives(
	personName VARCHAR(255) PRIMARY KEY NOT NULL,
	street VARCHAR(255) NOT NULL,
	city VARCHAR(255) NOT NULL
);
INSERT INTO lives VALUES ('Sazzad Hossain', 'Mirpur', 'Dhaka'), ('Ahadul Islam', 'Mirpur', 'Dhaka');
CREATE TABLE location(
	companyName VARCHAR(255) PRIMARY KEY NOT NULL,
	city VARCHAR(255) NOT NULL
);
INSERT INTO location VALUES ('Brac Bank Ltd.', 'Dhaka'), ('Prime Bank Ltd.', 'Dhaka');
CREATE TABLE works(
	personName VARCHAR(255) NOT NULL,
	companyName VARCHAR(255) NOT NULL,
	salary INT NOT NULL,
	FOREIGN KEY(personName) REFERENCES lives(personName) ON DELETE CASCADE ON UPDATE CASCADE,
	FOREIGN KEY(companyName) REFERENCES location(companyName) ON DELETE CASCADE ON UPDATE CASCADE
);
INSERT INTO works VALUES ('Sazzad Hossain', 'Brac Bank Ltd.', 1000000), ('Ahadul Islam', 'Prime Bank Ltd.', 50000);
CREATE TABLE manages(
	personName VARCHAR(255) NOT NULL,
	managerName VARCHAR(255) NOT NULL,
	FOREIGN KEY(personName) REFERENCES lives(personName) ON DELETE CASCADE ON UPDATE CASCADE
);
INSERT INTO manages VALUES ('Sazzad Hossain', 'Sanjida Hoque Shoshey'), ('Ahadul Islam', 'Tasmi Sultana');
-- Query
-- Find the name, city and manager name of all employees who work for Brac Bank Ltd.

SELECT lives.personName, lives.city, managerName
FROM lives
INNER JOIN works ON lives.personName = works.personName
INNER JOIN manages ON lives.personName = manages.personName
WHERE companyName = 'Brac Bank Ltd.';


-- Find all employees who do not work for Beximo Ltd.

SELECT lives.personName, street, city
FROM lives
INNER JOIN works ON lives.personName = works.personName
WHERE companyName != 'Beximo Ltd.';