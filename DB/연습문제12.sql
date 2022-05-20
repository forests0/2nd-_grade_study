create table salesperson (
    name varchar2(20),
    age number,
    salary number,
    primary key (name)
);

drop table salesperson;
drop table customer;
drop table orders;

create table customer (
  name varchar2(20),
  city varchar2(20),
  industrytype varchar2(20),
  primary key (name)
);

create table orders(
    numbers number,
    custname varchar2(20),
    salesperson varchar2(20),
    amount number,
    primary key(custname, salesperson),
    foreign key (custname) references customer,
    foreign key (salesperson) references salesperson
);

insert into salesperson values('sone', 24, 1000);
insert into salesperson values('stwo', 35, 1200);
insert into salesperson values('sthree', 40, 800);
insert into salesperson values('sfour', 19, 700);
insert into salesperson values('sfive', 29, 1300);
insert into salesperson values('ssix', 38, 2000);
insert into salesperson values('sseven', 26, 850);
create table salesperson (
    name varchar2(20),
    age number,
    salary number,
    primary key (name)
);
drop table salesperson;
create table customer (
  name varchar2(20),
  city varchar2(20),
  industrytype varchar2(20),
  primary key (name)
);

create table orders(
    numbers number,
    custname varchar2(20),
    salesperson varchar2(20),
    amount number,
    primary key(custname, salesperson),
    foreign key (custname) references customer,
    foreign key (salesperson) references salesperson
);

insert into salesperson values('sone', 24, 1000);
insert into salesperson values('stwo', 35, 1200);
insert into salesperson values('sthree', 40, 800);
insert into salesperson values('sfour', 19, 700);
insert into salesperson values('sfive', 29, 1300);
insert into salesperson values('ssix', 38, 2000);
insert into salesperson values('sseven', 26, 850);
insert into salesperson values('tom', 31, 1900);

insert into customer values('cone','LA','com'); 
insert into customer values('ctwo','AN','mar');
insert into customer values('cthree','NE','zxc');
insert into customer values('cfour','LA','qwe');
insert into customer values('cfive','AS','hgj');
insert into customer values('csix','EB','dfg');
insert into customer values('cseven','AN','ter');
insert into customer values('ceight','MS','mrd');

insert into orders values(1,'cone','sfour',10);
insert into orders values(2,'cthree','tom',2);
insert into orders values(3,'ctwo','ssix',12);
insert into orders values(4,'cseven','sone',130);
insert into orders values(5,'ceight','sfive',23);
insert into orders values(6,'cone','sthree',2);
insert into orders values(7,'ctwo','tom',65);
insert into orders values(8,'cfour','sone',33);

select distinct age, salary from salesperson;
select name from salesperson where age < 30;
select name from customer where city like('%S');
select custname, count(custname) from orders group by custname;
select salesperson, count(salesperson) from orders group by salesperson;
select name, age from salesperson where name in
    (select salesperson from orders where custname in
    (select name from customer where city = 'LA'));
select salesperson.name , salesperson.age from salesperson, customer, orders 
    where salesperson.name = orders.salesperson and
    customer.name = orders.custname and
    customer.city = 'LA';
select salesperson from orders group by salesperson having count(salesperson) >= 2;
update salesperson set salary = 45000 where name = 'tom';

