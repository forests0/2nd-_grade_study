create table employee (
    empno number,
    name varchar2(20),
    phoneno varchar2(20),
    address varchar2(20),
    sex varchar2(2),
    position varchar2(20),
    deptno number,
    primary key(empno)
);

create table department (
    deptno number,
    deptname varchar2(20),
    manager varchar2(20),
    primary key(deptno)
);

create table projects(
    projno number,
    projname varchar2(20),
    deptno number,
    primary key(projno)
);

create table works(
    empno number,
    projno number,
    workhours number,
    primary key(empno, projno),
    foreign key(empno) references employee,
    foreign key (projno) references projects
);

drop table projects;
drop table department;
drop table works;
drop table employee;

insert into department values(1,'dev','eone');
insert into department values(2,'gam','eeleven');
insert into department values(3,'des','efour');
insert into department values(4,'mar','enight');
insert into department values(5,'com','홍길동');
insert into department values(6, 'IT', 'efive');

insert into projects values(1,'pro1',2);
insert into projects values(2,'pro2',4);
insert into projects values(3,'pro3',1);
insert into projects values(4,'pro4',5);
insert into projects values(5,'pro5',3);

insert into works values(1,3,20);
insert into works values(2,1,80);
insert into works values(3,6,100);
insert into works values(4,2,305);
insert into works values(5,4,250);

insert into employee values(1,'홍길동','011','SD','M','com',5);
insert into employee values(2,'eone','012','EW','F','dev',1);
insert into employee values(3,'efour','013','JY','M','des',3);
insert into employee values(4,'eeleven','014','WG','F','gam',2);
insert into employee values(5,'enight','015','HT','M','mar',4);
insert into employee values(6,'etwo','016','YX','F','des',3);
insert into employee values(7,'esix','017','GU','M','com',5);
insert into employee values(8,'ethree','018','EK','F','dev',1);
insert into employee values(9,'efive','019','EG','M','IT',6);
insert into employee values(10,'etwelve','020','KR','M','IT',6);


select name from employee;
select name from employee where sex = 'F';
select name from employee where name in(select manager from department);
select name, address from employee where position = 'IT';
select count(*) from employee 
    where deptno in (select deptno from department
    where manager like '홍길동');
select department.deptname, employee.name, works.workhours from works, employee, department
    where works.empno = employee.empno and employee.deptno = department.deptno 
    order by workhours;
select projno, projname, count(name) from employee, projects
    where projects.deptno = employee.deptno
    group by projects.projno, projects.projname
    having count(*) >= 2;
select name from employee 
    where deptno in (select deptno from employee group by deptno having count(*) >= 3);
