create table menu(
    menuid number,
    name varchar2(200),
    primary key(menuid)
);

create table category(
    catoid number,
    menuid number,
    name varchar2(200),
    enname varchar2(200),
    primary key(catoid, menuid),
    foreign key(menuid) references menu(menuid)
);

create table item(
    itemid number,
    name varchar2(200),
    intro varchar2(4000),
    price number,
    link varchar2(4000),
    kcal number,
    catoid number,
    menuid number,
    primary key(itemid),
    foreign key(catoid, menuid) references category(catoid, menuid)
);

drop table menu;
drop table category;
drop table item;


select distinct menu.name, category.name, item.name, item.price, item.intro from item, category, menu 
where menu.menuid = item.menuid and category.catoid = item.catoid and category.menuid = menu.menuid and item.name = ('딸기주스 190ML');
