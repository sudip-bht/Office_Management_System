drop database if exists clients;
create database clients;
use clients;
create table clientDetails(
clientId int primary key not null auto_increment,
clientName varchar(200) not null,
clientEmail varchar(200) not null,
clientPhone long not null
);
create table clientLogin(
clientId int not null auto_increment,
clientUsername varchar(200) primary key not null,
clientPassword varchar(200)not null ,
foreign key(ClientId) references clients.clientDetails(clientId)
);
create table clientAppointment(
clientId int not null auto_increment,
employeeName varchar(200) not null,
appointmentDate date not null,
foreign key (clientId) references clients.clientDetails(clientId)
);
insert into clients.clientDetails
values(1,'sudip','sudip@gmail.com',9840000000);
insert into clients.clientLogin
values(1,'sud','1234');
insert into clients.clientAppointment
values(1,'ram','2022-03-26');

