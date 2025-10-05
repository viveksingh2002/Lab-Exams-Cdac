DROP table if exists users;
DROP table if exists products;

create table users(
    user_id int auto_increment primary key,
    username varchar(50) unique not null,
    password varchar(255) Not Null,
    role Enum("ADMIN", "USER") not null
);

create table products(
    p_id int auto_increment primary key,
    p_name varchar(100) not null,
    p_desc varchar(255), 
    p_qnty int not null,
    p_price decimal(10, 2) not null,
    user_id int,
    foreign key(user_id) references users(user_id)
);

insert into users(username, password, role) values 
("Herra", "test@123", "USER"),
("Meena", "test@123", "USER"),
("John", "test@123", "ADMIN");