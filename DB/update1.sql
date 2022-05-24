update customer set address='부산' where custid = 4;
select * from customer;

update customer 
set address=(select address from customer where name = '김연아')
where name = '추신수';

