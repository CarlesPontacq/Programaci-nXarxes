UPDATE arma, soldado, armamento SET arma.Cargador = arma.Cargador + 10 
WHERE armamento.ReferenciaSoldado = soldado.Identificador 
AND armamento.ReferenciaArma = arma.Identificador
AND soldado.Nombre = 'Radev';