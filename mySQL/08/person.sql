CREATE TABLE lives(
	personName VARCHAR(255) PRIMARY KEY NOT NULL,
	street VARCHAR(255) NOT NULL,
	city VARCHAR(255) NOT NULL
);

CREATE TABLE location(
	companyName VARCHAR(255) PRIMARY KEY NOT NULL,
	city VARCHAR(255) NOT NULL
);

CREATE TABLE works(
	personName VARCHAR(255) NOT NULL,
	companyName VARCHAR(255) NOT NULL,
	salary INT NOT NULL,
	FOREIGN KEY(personName) REFERENCES lives(personName) ON DELETE CASCADE ON UPDATE CASCADE,
	FOREIGN KEY(companyName) REFERENCES location(companyName) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE manages(
	personName VARCHAR(255) NOT NULL,
	managerName VARCHAR(255) NOT NULL,
	FOREIGN KEY(personName) REFERENCES lives(personName) ON DELETE CASCADE ON UPDATE CASCADE
);

-- Query
-- Modify the databse to change Karim's living city to a new one
UPDATE lives SET city = 'NEW CITY', street = 'NEW STREET' WHERE personName = 'Karim';
-- Find the number of tuples in works relation
SELECT COUNT(personName) AS totalNumberOfTuples
FROM works;