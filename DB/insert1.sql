create table 극장(
    극장번호 number,
    극장이름 varchar2(40),
    위치 varchar2(40),
    primary key (극장번호)
);
drop table 상영관;

create table 상영관(
    극장번호 number,
    상영관번호 number check(상영관번호 > 0 and 상영관번호 < 11),
    영화제목 varchar2(40),
    가격 number check(가격 < 20000),
    좌석수 number,
    primary key(극장번호, 상영관번호),
    foreign key (극장번호) references 극장(극장번호)
); 

create table 예약(
    극장번호 number,
    상영관번호 number,
    고객번호 number,
    좌석번호 number,
    날짜 date,
    primary key(극장번호, 상영관번호, 고객번호),
    foreign key (극장번호, 상영관번호) references 상영관(극장번호, 상영관번호),
    foreign key (고객번호) references 고객(고객번호)
);

create table 고객(
    고객번호 number,
    이름 varchar2(40),
    주소 varchar2(40),
    primary key(고객번호)
);

insert into 극장 values(1,'롯데','잠실');
insert into 극장 values(2,'메가','강남');
insert into 극장 values(3,'대한','잠실');

insert into 고객 values(3,'홍길동','강남');
insert into 고객 values(4,'김철수','잠실');
insert into 고객 values(9,'박영희','강남');

insert into 상영관 values(1,1,'어려운 영화',15000,48);
insert into 상영관 values(3,1,'멋진 영화',7500,120);
insert into 상영관 values(3,2,'재밌는 영화',8000,110);

insert into 예약 values(3,2,3,15,'2020-09-01');
insert into 예약 values(3,1,4,16,'2020-09-01');
insert into 예약 values(1,1,9,48,'2020-09-01');
