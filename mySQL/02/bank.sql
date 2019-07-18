CREATE TABLE account( 
a_no INT NOT NULL PRIMARY KEY, 
balance INT
);

CREATE TABLE branch( 
b_name varchar(255) NOT NULL PRIMARY KEY, 
address varchar(255)
);

CREATE TABLE customer( 
c_name varchar(255) NOT NULL PRIMARY KEY, 
c_address varchar(255)
);

CREATE TABLE loan( 
loan_no INT NOT NULL PRIMARY KEY, 
amount INT
);

CREATE TABLE accountBranch(
a_no INT,
b_name varchar(255),
FOREIGN KEY (a_no) REFERENCES account(a_no),
FOREIGN KEY (b_name) REFERENCES branch(b_name)
);


CREATE TABLE borrower(
c_name varchar(255),
loan_no INT,
FOREIGN KEY (c_name) REFERENCES customer(c_name),
FOREIGN KEY (loan_no) REFERENCES loan(loan_no)
);


CREATE TABLE loanBranch(
loan_no INT,
b_name varchar(255),
FOREIGN KEY (loan_no) REFERENCES loan(loan_no),
FOREIGN KEY (b_name) REFERENCES branch(b_name)
);

CREATE TABLE depositor(
a_no INT,
c_name varchar(255),
FOREIGN KEY (a_no) REFERENCES account(a_no),
FOREIGN KEY (c_name) REFERENCES customer(c_name)
);

--- QUERIES ---

--- Find all customers who have an account but no loan in bank

SELECT c_name 
FROM depositor
LEFT OUTER JOIN borrower ON depositor.c_name = borrower.c_name  
WHERE depositor.c_name != borrower.c_name;

--- Delete all loans with loan amounts between 13,000 and 20,000
DELETE FROM loan_no
WHERE WHERE amount BETWEEN 13000 AND 20000;
