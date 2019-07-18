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

--- Find all customers who have an account but no loan in the bank
 	SELECT depositor.customerName
	FROM depositor
	INNER JOIN borrower ON depositor.customerName != borrower.customerName;

--- Find the average account balance at the Mohakhali Branch
	SELECT AVG(balance) AS averageBalanceAtMohakhali FROM account WHERE branchName LIKE 'Mohakhali';