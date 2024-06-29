/*
Loan Payment

Query que actualiza la cantidad de dinero abonada y faltante

Parametros:
- {0}: ID del prestamo
- {1}: Cantidad a abonar
*/

UPDATE PrestamosClientes
SET TotalAbonado = TotalAbonado + {1}, MontoFaltante = MontoFaltante - {1}
WHERE ID = {0};
