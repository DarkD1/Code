CREATE TABLE branch(
	branchName VARCHAR(255) NOT NULL PRIMARY KEY,
	city VARCHAR(255),
	assets INT
);

CREATE TABLE customer(
	customerName VARCHAR(255) NOT NULL PRIMARY KEY,
	street VARCHAR(255),
	city VARCHAR(255)
);

CREATE TABLE loan(
	loanNumber INT NOT NULL PRIMARY KEY,
	branchName VARCHAR(255),
	amount INT,
	FOREIGN KEY(branchName) REFERENCES branch(branchName)
);

CREATE TABLE account(
	accountNumber INT NOT NULL PRIMARY KEY,
	branchName VARCHAR(255),
	balance INT,
	FOREIGN KEY(branchName) REFERENCES branch(branchName)
);

CREATE TABLE borrower(
	customerName VARCHAR(255),
	loanNumber INT,
	FOREIGN KEY(customerName) REFERENCES customer(customerName),
	FOREIGN KEY(loanNumber) REFERENCES loan(loanNumber)
);

CREATE TABLE depositor(
	customerName VARCHAR(255),
	accountNumber INT,
	FOREIGN KEY(accountNumber) REFERENCES account(accountNumber)
);



--- QUERIES ---

--- Find the names and loan numbers of all the customers who have a loan from the bank

SELECT * FROM borrower;

--- List all customer names in alphabetic order that have an account at Dhanmondi Branch

SELECT customerName
FROM depositor
WHERE accountNumber IN (SELECT accountNumber FROM account WHERE branchName LIKE 'Dhanmondi')
ORDER BY customerName;