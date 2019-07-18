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
	accountNumber VARCHAR(255) NOT NULL PRIMARY KEY,
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
	accountNumber VARCHAR(255),
	FOREIGN KEY(accountNumber) REFERENCES account(accountNumber)
);



--- QUERIES ---

--- Find all customers having a loan, an account or both at the bank

SELECT *
FROM customer
WHERE customerName IN ((SELECT customerName FROM borrower) UNION (SELECT customerName FROM depositor));

--- Insert one tuple into the relation account with value, the account number is SB_0055 at Mohakhali Branch and the balance is 250000

INSERT INTO account VALUES ('SB_0055', 'Mohakhali', 250000);