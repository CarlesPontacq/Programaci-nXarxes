DELETE arma FROM arma, armamento, soldado WHERE armamento.ReferenciaSoldado = soldado.Identificador
AND armamento.ReferenciaArma = arma.Identificador
AND arma.Cadencia <= 5;