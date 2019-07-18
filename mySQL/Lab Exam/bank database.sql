create database bank;
use bank;

create table branch(
	branch_name varchar(50) primary key not null,
	branch_city varchar(50) not null,
	asesets int not null
);

create table customer(
	customer_name varchar(50) primary key not null,
	customer_street varchar(50) not null,
	customer_city varchar(50)
);

create table loan(
	loan_number varchar(50) primary key not null,
	branch_name varchar(50) not null,
	amount int not null
);

create table borrower(
	customer_name varchar(50) not null,
	loan_number varchar(50) not null,
	foreign key (customer_name) references customer(customer_name),
	foreign key (loan_number) references loan(loan_number)
);

create table account(
	account_number varchar(50) primary key not null,
	branch_name varchar(50) not null,
	balance int not null,
	foreign key (branch_name) references branch(branch_name)
);

create table depositor(
	customer_name varchar(50) not null,
	account_number varchar(50) not null,
	foreign key (customer_name) references customer(customer_name),
	foreign key (account_number) references account(account_number)
);



insert into branch values ('Gabtoli', 'Dhaka', 1000000),
('Dhanmondi', 'Dhaka', 50000),
('Jatrabari', 'Dhaka', 750000),
('Motijheel', 'Dhaka', 100);

insert into customer values ('Sazzad', 'Mirpur', 'Dhaka'),
('Ahad', 'Mirpur', 'Dhaka'),
('Riad', 'Area 51', 'Nevada'),
('Saif', 'Moghbazar', 'Dhaka');

insert into loan values ('0001AB', 'Gabtoli', 1000),
('0001AS', 'Jatrabari', 5000);

insert into borrower values ('Sazzad', '0001AB'), ('Riad', '0001AS');

insert into account values ('1111AB', 'Gabtoli', 10000),
('1111AC', 'Jatrabari', 5000),
('1111AD', 'Gabtoli', 5000);

insert into depositor values ('Sazzad', '1111AB'), ('Riad', '1111AC'), ('Ahad', '1111AD');



--- Find all customers who have both a loan and an account at the bank

select borrower.customer_name
from borrower
inner join depositor on borrower.customer_name = depositor.customer_name;


--- Find the average account balance at the 'Gabtoli' branch

select AVG(balance)
from account
where branch_name = 'Gabtoli';


--- Insert record into the account relation with the balues of account number is 'AC-101' at 'Dhanmondi' Branch and the balance is Tk. 30000

insert into account values ('AC-101', 'Dhanmondi', 30000);




--- Find the number of depositor of each branch

select account.branch_name, count(depositor.account_number) as numberOfDepositor
from account
inner join depositor on account.account_number = depositor.account_number
group by account.branch_name;



--- List in alphabetical order all customers who have a loan at the 'Gabtoli' branch

select customer_name
from borrower
inner join loan on borrower.loan_number = loan.loan_number
where loan.branch_name = 'Gabtoli'
order by customer_name;


--- Update a customer current street

update customer
set customer_street = 'Mazar Road'
where customer_name = 'Sazzad';


--- Find the loan numbers of those loans with loan amount between Tk. 10000 and Tk. 20000.

select loan_number
from loan
where amount between 10000 and 20000;


--- Find all customer who have account but no loan at the bank

select depositor.customer_name
from depositor
left join borrower on depositor.customer_name = borrower.customer_name
where borrower.customer_name is null;