select 극장이름, 위치 from 극장;
select * from 극장 where 위치 = '잠실';
select 이름 from 고객 where 주소 = '잠실' order by 이름 ASC;
select 극장번호, 상영관번호, 영화제목 from 상영관 where 가격 >= 8000;
select * from 고객, 극장 where 고객.주소 like 극장.위치;

select count(극장번호) from 극장;
select avg(가격) from 상영관;
select count(고객번호) from 예약 where 날짜 = '2020-09-01';


select 영화제목 from 상영관 where 극장번호 = (select 극장번호 from 극장 where 극장이름 = '대한');
select 이름 from 고객, 예약, 극장 where 고객.고객번호 = 예약.고객번호 and 극장.극장번호 = 예약.극장번호 and 극장.극장이름= '대한';
select 영화제목, 가격*좌석수 from 상영관 where 극장번호 in (select 극장번호 from 극장 where 극장이름 = '대한');

select 극장번호, count(극장번호) from 상영관 group by 극장번호;
select 상영관.극장번호, 상영관.상영관번호, 상영관.영화제목, 상영관.가격, 상영관.좌석수 from 상영관, 극장 where 위치 = '잠실' and 극장.극장번호 = 상영관.상영관번호;
select avg(count(고객번호)) from 예약 group by 날짜;


insert into 극장 values(4,'테스트','부산');
insert into 고객 values(4,'이경신','부산');
insert into 상영관 values(1,2,'무난한 영화',10000,60);
insert into 예약 values(1,2,4,34,'2020-09-01');

update 상영관 set 가격 = 가격*1.1;
select * from 상영관;

