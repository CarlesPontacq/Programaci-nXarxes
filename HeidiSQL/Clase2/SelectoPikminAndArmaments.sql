SELECT pikmin.* FROM personajes, pikmin WHERE pikmin.IdentificadorPersonaje = personajes.Identificador AND personajes.Nombre = 'Olimar';

SELECT armamento.* FROM armamento, arma, soldado WHERE 
armamento.ReferenciaSoldado = soldado.Identificador 
AND armamento.ReferenciaArma = arma.Identificador 
AND arma.Peso >= 20 
AND soldado.Nombre = 'Radev';