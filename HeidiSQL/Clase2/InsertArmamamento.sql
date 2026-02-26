INSERT INTO soldado (Nombre) VALUES ('Radev');

INSERT INTO arma (Danyo, Peso, Cargador, Cadencia, Modificadores) VALUES (5, 20, 60, 10, 'Mira');
INSERT INTO arma (Danyo, Peso, Cargador, Cadencia, Modificadores) VALUES (20, 50, 5, 1, 'Ninguno');

INSERT INTO armamento (ReferenciaSoldado, ReferenciaArma) VALUES (1, 1);
INSERT INTO armamento (ReferenciaSoldado, ReferenciaArma) VALUES (1, 2);