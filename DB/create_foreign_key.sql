drop table newbook;
drop table newcustomer;
drop table neworders;

create table newbook (
    bookid number,
    bookname varchar2(20),
    publisher varchar2(20),
    price number,
    primary key (bookid)
);

create table newcustomer (
    custid number,
    name varchar2(40),
    address varchar2(40),
    phone varchar2(30),
    primary key (custid)
);

CREATE TABLE NewOrders (
    orderid NUMBER,
    custid NUMBER,
    bookid NUMBER NOT NULL,
    saleprice NUMBER,
    PRIMARY KEY(orderid),
    FOREIGN KEY(custid) REFERENCES NewCustomer(custid) ON DELETE CASCADE
);
