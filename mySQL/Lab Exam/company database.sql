create database company;
use company;

create table employee(
	employee_name varchar(50) primary key not null,
	employee_street varchar(50) not null,
	employee_city varchar(50) not null
);


create table company(
	company_name varchar(50) primary key not null,
	city varchar(50) not null
);

create table works(
	employee_name varchar(50) not null,
	company_name varchar(50) not null,
	salary int not null,
	foreign key (employee_name) references employee(employee_name),
	foreign key (company_name) references company(company_name)
);

create table manages(
	employee_name varchar(50) not null,
	manager_name varchar(50) not null,
	foreign key (employee_name) references employee(employee_name),
	foreign key (manager_name) references employee(employee_name)
);


insert into employee values ('Sazzad', 'Mirpur', 'Dhaka'),
	('Ahadul', 'Mirpur', 'Dhaka'),
	('Riad', 'Jatrabari', 'Dhaka'),
	('Saif', 'Mogh Bazar', 'Dhaka'),
	('Saiful', 'Agargaon', 'Dhaka'),
	('Akash', 'Jatrabari', 'Dhaka');

insert into company values ('regeX Inc.', 'Dhaka'), ('dreaMWave', 'Dhaka');

insert into works values ('Sazzad', 'dreaMWave', 100000),
	('Riad', 'regeX Inc.', 20000),
	('Ahadul', 'dreaMWave', 20000),
	('Saif', 'dreaMWave', 10000);


insert into manages values ('Sazzad', 'Akash'),
	('Riad', 'Saiful'),
	('Ahadul', 'Akash'),
	('Saif', 'Akash');


--- Find all employees names, cities and salaries who work for dreaMWave
	select employee.employee_name, employee_city, salary
	from employee
	inner join works on employee.employee_name = works.employee_name
	where company_name = 'dreaMWave';

--- Modify the database to change Saif's living city to a new one
	update employee
	set employee_city = 'Khulna'
	where employee_name = 'Saif';

--- Delete employeee whos salary less than Tk. 5000.
	delete from employee
	where employee_name in (
		select employee_name from works where salary < 5000
	);

--- Find the total salary of each company
	select company_name, sum(salary) as totalSalary
	from works
	group by company_name;

--- Find alll employess in the database who do not work for dreaMWave
	select employee_name
	from works
	where company_name != 'dreaMWave';

--- Insert recor into the employee table with proper value
	insert into employee values ('Mahir', 'Mirpur', 'Dhaka');

--- Find the number of tuples in the works relations
	select count(employee_name) as numberOfTuples
	from works;

--- Find all employees in the database who earn more than each employee of regeX Inc.
	select employee_name
	from works
	where salary > (select MAX(salary) from works where company_name = 'regeX Inc.');