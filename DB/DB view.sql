create view vw_book as select *
from book
where bookname like '%축구%';

select * from vw_book;

create view vw_orders(orderid,custid, name, bookid, bookname, saleprice, orderdate)
as select od.orderid, od.custid, cs.name, od.bookid, bk.bookname, od.saleprice, od.orderdate
from orders od, customer cs, book bk
where od.custid = cs.custid and od.bookid = bk.bookid;

select * from vw_orders;

create or replace view vw_orders(orderid,custid, name, bookid, bookname, saleprice, orderdate)
as select od.orderid, od.custid, replace(cs.name, substr(cs.name,2,1), '*'), od.bookid, bk.bookname, od.saleprice, od.orderdate
from orders od, customer cs, book bk
where od.custid = cs.custid and od.bookid = bk.bookid;

