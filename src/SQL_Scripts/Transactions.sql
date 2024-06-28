/*
Transactions

Query que consulta el reporte de transacciones

Parametros:
- {0}: ID del cliente
*/

SELECT 
	C.Nombre "Cliente"
    ,TT.Transaccion "Transaccion"
    ,Cu.ID "Cuenta Fuente"
    ,Cu2.ID "Cuenta Destino"
    ,D.Denominacion "Denominacion"
    ,T.CantidadPrevio "Cantidad Previo"
    ,T.CantidadPosterior "Cantidad Antes"
    ,T.Diferencia "Diferencia"
FROM 
Transacciones T
LEFT JOIN Clientes C ON C.ID = T.ClienteID
LEFT JOIN TipoTransaccion TT ON TT.ID = T.TipoTransaccionID
LEFT JOIN Cuentas Cu ON Cu.ID = T.CuentaFuenteID
LEFT JOIN Cuentas Cu2 ON Cu2.ID = T.CuentaDestinoID
LEFT JOIN Denominaciones D ON D.ID = T.DenominacionID
WHERE T.ClienteID = {0};