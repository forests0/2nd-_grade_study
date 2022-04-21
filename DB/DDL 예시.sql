CREATE TABLE Newbook (
    bookid NUMBER,
    bookname VARCHAR(20),
    publisher VARCHAR(20),
    price NUMBER
);

DROP TABLE Newbook;
DROP TABLE NewOrders;

CREATE TABLE Newbook (
    bookid NUMBER,
    bookname VARCHAR(20),
    publisher VARCHAR(20),
    price NUMBER,
    PRIMARY KEY (bookid)
);

CREATE TABLE Newbook (
    bookid NUMBER PRIMARY KEY,
    bookname VARCHAR(20),
    publisher VARCHAR(20),
    price NUMBER
);

CREATE TABLE Newbook (
    bookname VARCHAR(20) NOT NULL,
    publisher VARCHAR(20) UNIQUE,
    price NUMBER DEFAULT 10000 CHECK(price > 1000),
    PRIMARY KEY(bookname,publisher)
);

INSERT INTO Newbook (bookname, publisher)
VALUES ('D', 'D');
commit;

CREATE TABLE NewCustomer (
    custid NUMBER PRIMARY KEY,
    name VARCHAR2(40),
    address VARCHAR2(40),
    phone VARCHAR2(30)
);

CREATE TABLE NewOrders (
    orderid NUMBER,
    custid NUMBER,
    bookid NUMBER NOT NULL,
    saleprice NUMBER,
    PRIMARY KEY(orderid),
    FOREIGN KEY(custid) REFERENCES NewCustomer(custid) ON DELETE CASCADE
);

ALTER TABLE Newbook add isbn VARCHAR2(13);
ALTER TABLE Newbook modify isbn number;
ALTER TABLE Newbook drop column isbn;
ALTER TABLE Newbook MODIFY bookid number not null;
alter table Newbook add primary key(bookid);

CREATE TABLE Newbook (
    bookid NUMBER,
    bookname VARCHAR(20),
    publisher VARCHAR(20),
    price NUMBER
);

alter table Newbook drop constraint SYS_C008436;
alter table Newbook add constraint book_pk primary key(bookid); 
alter table Newbook drop constraint book_pk;