create user c##2205 identified by 1234;
grant connect, resource, dba, create view to c##2205;

create table teacher (
    tno number,
    name varchar2(20),
    mgrade number,
    mclass number,
    primary key(tno)
);
--drop table teacher;

create table ateacher(
    atno number,
    name varchar2(20),
    agrade number,
    aclass number,
    primary key(atno)
);
--drop table ateacher;

create table student(
    sno number,
    grade number,
    sclass number,
    cnum number,
    sname varchar2(20),
    sex varchar2(20),
    dep varchar2(30),
    mtch number,
    atch number,
    primary key(sno),
    foreign key(mtch) references teacher(tno),
    foreign key(atch) references ateacher(atno)
);
--drop table student;

create table room(
    rno number,
    name varchar2(10),
    primary key(rno)
);

create table reservation(
    resno number,
    restdno number,
    resrno number,
    primary key(resno),
    foreign key(restdno) references student(sno),
    foreign key(resrno) references room(rno)
);
--drop table reservation;


insert into teacher values(1,'구*영',1,1);
insert into teacher values(2,'조*겸',1,2);
insert into teacher values(3,'김*영',1,3);
insert into teacher values(4,'유*찬',1,4);
insert into teacher values(5,'차*민',2,1);
insert into teacher values(6,'박*현',2,2);
insert into teacher values(7,'김*태',2,3);
insert into teacher values(8,'김*봉',2,4);

insert into ateacher values(1,'이*숙',1,1);
insert into ateacher values(2,'진*빈',1,2);
insert into ateacher values(3,'김*정',1,3);
insert into ateacher values(4,'김*필',1,4);
insert into ateacher values(5,'이*영',2,1);
insert into ateacher values(6,'최*준',2,2);
insert into ateacher values(7,'정*진',2,3);
insert into ateacher values(8,'서*희',2,4);

insert into room values(1,'베르1실');
insert into room values(2,'베르2실');
insert into room values(3,'베르3실');
insert into room values(4,'베르4실');
insert into room values(5,'베르5실');

insert into student values(1,1,1,1,'강*석','남','',1,1);
insert into student values(2,1,1,2,'김*민','남','',1,1);
insert into student values(3,1,2,1,'강*제','남','',2,2);
insert into student values(4,1,3,2,'강*훈','남','',2,2);
insert into student values(5,1,3,1,'고*영','여','',3,3);
insert into student values(6,1,3,2,'김*건','남','',3,3);
insert into student values(7,1,4,1,'강*빈','남','',4,4);
insert into student values(8,1,4,2,'구*하','여','',4,4);

insert into student values(9,2,1,1,'김*서','남','소프트웨어개발과',5,5);
insert into student values(10,2,1,2,'김*울','여','소프트웨어개발과',5,5);
insert into student values(11,2,2,1,'권*서','남','소프트웨어개발과',6,6);
insert into student values(12,2,2,2,'김*민','남','소프트웨어개발과',6,6);
insert into student values(13,2,3,1,'권*욱','남','임베디드소프트웨어과',7,7);
insert into student values(14,2,3,2,'김*형','남','임베디드소프트웨어과',7,7);
insert into student values(15,2,4,1,'김*수','남','임베디드소프트웨어과',8,8);
insert into student values(16,2,4,2,'김*진','여','임베디드소프트웨어과',8,8);

insert into reservation values(1,10,2);
insert into reservation values(2,3,1);
insert into reservation values(3,14,5);
insert into reservation values(4,6,4);
insert into reservation values(5,1,3);

create view v_std(grade, class, cnum, name, sex, dep, mteacher, ateacher)
as select st.grade, st.sclass, st.cnum, st.sname, st.sex, st.dep, te.name, at.name
from teacher te, ateacher at, student st
where mtch = tno and atch = atno;

select * from v_std;

create view v_res(renum, name, room)
as select res.resno, st.sname, rm.name
from student st, room rm, reservation res
where res.restdno = st.sno and res.resrno = rm.rno; 

select * from v_res order by renum ASC;