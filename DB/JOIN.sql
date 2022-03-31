SELECT * FROM orders
INNER JOIN book
ON orders.bookid = book.bookid;
/*INNER JOIN = FROM 테이블을 중심으로 NULL 이 아닌 조건이 같은 값을 꺼냄*/
SELECT * FROM orders
INNER JOIN customer
ON orders.custid = customer.custid;
/*LEFT JOIN = FROM 테이블을 중심으로 오른쪽을 NULL 값으로 바꿈*/
SELECT * FROM orders
LEFT JOIN customer
ON orders.custid = customer.custid;
/*RIGHT JOIN = FROM 테이블을 중심으로 왼쪽을 NULL 값으로 바꿈*/
SELECT * FROM orders
RIGHT JOIN customer
ON orders.custid = customer.custid;
/*FULL JOIN = FROM 테이블을 중심으로 양쪽을 NULL 값으로 바꿈*/
SELECT * FROM orders
FULL JOIN customer
ON orders.custid = customer.custid;

SELECT * FROM orders, customer
WHERE orders.custid(+) = customer.custid;