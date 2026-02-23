CREATE DATABASE Videogame;
USE Videogame;
CREATE TABLE Avatar (
	identificador INT AUTO_INCREMENT PRIMARY KEY,
	nombre VARCHAR(30),
	nivel INT,
	baneado BOOL
);