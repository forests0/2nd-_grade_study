create table mybook(
bookid number,
price number,
primary key(bookid)
);

insert into mybook values(1,10000);
insert into mybook values(2,20000);
insert into mybook(bookid) values(3);

select * from mybook;

create view v_mybook
as select *
from mybook;

select * from v_mybook;
select bookid,nvl(price,0) from v_mybook;
select * from v_mybook where price is null;
select * from v_mybook where price = '';
select bookid, price + 100 from v_mybook;
select sum(price), avg(price), count(*) from v_mybook where bookid <= 4;
select count(*), count(price) from v_mybook;
select sum(price), avg(price) from v_mybook;