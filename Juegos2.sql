DROP DATABASE IF EXISTS Juegos2;
CREATE DATABASE Juegos2;
USE Juegos2;

CREATE TABLE Jugador(
id INTEGER NOT NULL,
nombre VARCHAR(20) NOT NULL,
password VARCHAR(20) NOT NULL,
PRIMARY KEY (id),
)ENGINE=InnoDB;

CREATE TABLE Partidas(
id INTEGER NOT NULL,
fecha INTEGER,   
hora VARCHAR(20),
duracion INTEGER(20),
ganador VARCHAR(20),
PRIMARY KEY (id),
)ENGINE=InnoDB;

CREATE TABLE Datos(
idJu INTEGER NOT NULL,
idPa INTEGER NOT NULL,
Puntos INTEGER NOT NULL,
FOREIGN KEY (idJu) REFERENCES   Jugador(id),
FOREIGN KEY (idPa) REFERENCES   Partidas(id),
)ENGINE=InnoDB;

INSERT INTO Jugador(id,nombre,password) VALUES(1,'Juan','perrito1');
INSERT INTO Jugador(id,nombre,password) VALUES(2,'Pablo','compañero1');
INSERT INTO Jugador(id,nombre,password) VALUES(3,'Alberto','anuel');

INSERT INTO Partidas(id,fecha,hora,duracion,ganador) VALUES(1,02,'14:00',47,'Pablo');
INSERT INTO Partidas(id,fecha,hora,duracion,ganador) VALUES(2,05,'18:00',24,'Juan');
INSERT INTO Partidas(id,fecha,hora,duracion,ganador) VALUES(3,10,'19:00',30,'Juan');



SELECT ganador, COUNT( ganador ) AS total
FROM  Partidas
GROUP BY ganador
ORDER BY total DESC 


SELECT COUNT(*) FROM Partidas WHERE fecha = 02;



SELECT COUNT (*) FROM Partidas WHERE nombre("Juan") AND puntos >=30;
