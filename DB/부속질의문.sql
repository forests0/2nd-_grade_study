SELECT bookname FROM (SELECT * FROM book ORDER BY bookname DESC);


SELECT bookname,price FROM book
WHERE price IN(SELECT price FROM book);

SELECT bookname, price FROM book
WHERE price IN(
SELECT price FROM book 
WHERE price >= 10000 and price <=30000
);


SELECT name FROM customer
WHERE custid IN(
SELECT custid FROM orders
WHERE bookid IN (
SELECT bookid FROM book
WHERE publisher = '대한미디어'
));

SELECT name FROM customer, orders, book
WHERE customer.custid = orders.custid and orders.bookid = book.bookid and book.publisher = '대한미디어';