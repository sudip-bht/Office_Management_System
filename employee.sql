drop database if exists employee;
create database employee;
use employee;
create table employeedetails(
employeeId int primary key,
employeeName varchar(200) not null,
employeeEmail varchar(200) not null,
employeeDepartment varchar(200) not null,
employeePost varchar(200) not null,
employeePhone long not null
);	
create table employeeLogin(
employeeId int not null,
employeeUsername varchar(200) primary key not null,
employeePassword varchar(200) not null,
foreign key(employeeId) references employee.employeeDetails(employeeId)
);
create table employeeAppointment(
employeeId int not null,
clientname varchar(200) not null,
appointmentDate date not null,
foreign key (employeeId) references employee.employeeDetails(employeeId)
);
